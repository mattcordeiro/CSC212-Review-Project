#include "Gradebook.h"
#include <fstream>
#include <sstream>

std::string ConcatInputs(std::string input) {
    int i;
    std::vector<std::string> tokens;
    std::stringstream check1(input);
    std::string temp;
    if(input.find(' ', 0) != std::string::npos){
        while(std::getline(check1, temp, ' ')){
            tokens.push_back(temp);
        }
        input = tokens[0];
        for(i = 1; i < tokens.size(); i++){
            input += "-" + tokens[i];
        }
    }
    return input;
}

//Validate integer input
int ValidIntInput() {
	bool valid = false;
	std::string s_input;
	int input = -1;

	std::cin >> s_input;
	while (!valid) {
		for (int i = 0; i < s_input.length(); i++) {
			if (isalpha(s_input[i]) || !isalnum(s_input[i])){
				std::cout << "Invalid input! \nRe-Enter: ";
				std::cin >> s_input;
				valid = false;
				continue;
			}
			else valid = true;
		}
	}
	return std::stoi(s_input);
}

// Builds data file for gradebook
void SaveGradebook(Gradebook & a_gradebook, std::vector<std::string> load_initializer) {
	bool found = false; //used to check if gradebook exists in init_load.txt
	Catagory t_catagory = Catagory(" ");
	std::ofstream out_file;
	out_file.open(a_gradebook.GetName() + ".txt", std::ofstream::trunc); // opens txt file with gradebook name

	out_file << a_gradebook.GetName();

	//cycle through each catagory and adds its fields and its assignments fields to the data file
	for(int i = 0; i < a_gradebook.GetCatagory().size();i++) {
		out_file << "\n" << a_gradebook.GetCatagory()[i].GetName() + " " + std::to_string(a_gradebook.GetCatagory()[i].GetWeight());
		//out_file << a_gradebook->GetCatagory()[i].GetAssignment().size() + "\n";
		t_catagory = a_gradebook.GetCatagory()[i];
		out_file << "\n" << std::to_string(t_catagory.GetAssignment().size()) ;

		for (int j = 0; j < t_catagory.GetAssignment().size(); j++) {
			out_file <<  "\n" << a_gradebook.GetCatagory()[i].GetAssignment()[j].GetName() + " " + std::to_string(a_gradebook.GetCatagory()[i].GetAssignment()[j].GetMaxScore())
				+ " " + std::to_string(a_gradebook.GetCatagory()[i].GetAssignment()[j].GetScore());
		}
	}
	out_file.close();

	// Checks if current gradebook exists in init_load.txt
	for (int i = 0; i < load_initializer.size(); i++) {
		if (load_initializer[i].compare(a_gradebook.GetName()) == 0) {
			found = true;
		}
	}

	// adds gradebook to init_load.txt if not found
	if (!found) {
		out_file.open("init_load.txt", std::ofstream::trunc);

		for (int i = 0; i < load_initializer.size(); i++) {
			out_file << load_initializer[i] + "\n";
		}
		out_file << a_gradebook.GetName();
		out_file.close();
	}

}

Catagory EditCatagory(Catagory category) {
	int input;
	std::string name;
	double weight;
	std::cout << "What would you like to edit(1 - Category name, 2 - Category weight): ";
	input = ValidIntInput();
	if (input == 1) {
		std::cout << "Enter new name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        name = ConcatInputs(name);
		category.SetName(name);
	}
	else if (input == 2) {
		std::cout << "Enter new weight: ";
		std::cin >> weight;
		category.SetWeight(weight);
	}
	return category;
}

int ChooseCategory(Gradebook & a_gradebook) {
	int input;
	if (a_gradebook.GetCatagory().size() > 0) {
		std::cout << "Choose a catagory:\n";
		for (int i = 1; i <= a_gradebook.GetCatagory().size(); i++) {
			std::cout << i << " - " << a_gradebook.GetCatagory()[i - 1].GetName() << "\n";
		}
		std::cout << a_gradebook.GetCatagory().size() + 1 << " - back\n";
		input = ValidIntInput();
	}
	else {
		std::cout << "No catagories available.\n";
		input = 0;
	}

	return (input - 1);
}

int ChooseAssignment(Catagory category) {
	int input;
	if (category.GetAssignment().size() > 0) {
		std::cout << "Choose assignment:\n";
		for (int i = 1; i <= category.GetAssignment().size(); i++) {
			std::cout << i << " - " << category.GetAssignment()[i - 1].GetName() << "\n";
		}
	}
	else std::cout << "No assignments available.\n";
	std::cout << category.GetAssignment().size() + 1 << " - back\n";
	input = ValidIntInput();
	return input - 1;
}

Catagory EditAssignment(int idx, Catagory category) {
	int input;
	std::string name = category.GetAssignment()[idx].GetName();
	int max_score = category.GetAssignment()[idx].GetMaxScore();
	int score = category.GetAssignment()[idx].GetScore();
	std::cout << "What would you like to edit(1 - Assignment name, 2 - Assignment max score, 3 - Assignment score): ";
	input = ValidIntInput();
    //Set an assignment name
	if (input == 1) {
		std::cout << "Enter new name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        name = ConcatInputs(name);
		category.SetAssignment(idx,Assignment(name, max_score, score));

	}
    //Set an assignment max score
	else if (input == 2) {
		std::cout << "Enter new max score: ";
		std::cin >> max_score;
		category.SetAssignment(idx, Assignment(name, max_score, score));
	}
    //set an assignment score
	else if (input == 3) {
		std::cout << "Enter score: ";
		std::cin >> score;
		category.SetAssignment(idx, Assignment(name, max_score, score));
	}
	return category;
}

Catagory DeleteAssignment(int idx, Catagory category) {
    //Deletes assignment from category at a given index
	category.DeleteAssignment(idx);
	return category;
}

Catagory BuildCatagoryAssignment(Catagory category, std::string ass_name, int max_score, int score = 0) {
    //this catagory method takes in category, assignment_name, the max_score, and the inital score
	Assignment assignment(ass_name, max_score, score);
    //adds assignment to the catagory
	category.AddAssignment(assignment);
	if (!(category.GetAssignment().size() > 0))std::cout << "BuildCategoryAssignment not working, size i: " << category.GetAssignment().size() << std::endl;
	return category;
}

//Manages gradebook criteria
void ManageGradebook(Gradebook & a_gradebook, std::vector<std::string> load_initializer) {
	int input, input2;
	int max_score;
	std::string s_input;
	bool back = false;
	double f_input;

	//Enter gradebook management menu

	while (!back) {
        //while the user doesn't go back in the menu; the following logic will take place
		std::cin.clear();
		std::cout << "What would you like to do with gradebook: " << a_gradebook.GetName() << ":\n";
		std::cout << "1 - Manage Categories\n"<< "2 - Manage Assignment\n" << "3 - Show Grades\n" << "4 - Back\n";
        //the user will provide an input to the logic choices above to categorize
		input = ValidIntInput();

		//Outer switch main gradebook management menu
		switch (input) {
		//Catagory Management
		case 1:
			std::cout << "What would you like to do with the categories:\n1 - Add Category\n2 - Edit category\n3 - Delete Catagory\n4 - Back\n";
			input = ValidIntInput();

			//Inner switch Category management menu

			switch (input) {
			//Category Creation
			case 1:
                //
				std::cout << "Catagory name: ";
                    std::cin.ignore();
                    std::getline(std::cin, s_input);
                    s_input = ConcatInputs(s_input);
				std::cout << "Would you like to set the weight of " << s_input << " (1 - yes, 2 - no)? ";
				input = ValidIntInput();
                //if the user would not like to set the weight of the category the if statement will run
				if (input == 2) a_gradebook.AddCatagory(Catagory(s_input));
                //if the user would like to set the weight, they must enter it in decimal format
                //then the weight and name of the category will be entered into a_gradebook
				else if (input == 1) {
					std::cout << "Enter weight(decimal format): ";
					std::cin >> f_input;
					a_gradebook.AddCatagory(Catagory(s_input, f_input));
				}
                //all else fails, they'll see an invalid option
				else std::cout << "Invalid Option.\n";
				break;
			//Edit Category
			case 2:
				input = ChooseCategory(a_gradebook);
				if (input >= 0 && input < a_gradebook.GetCatagory().size()) a_gradebook.SetCatagory(input, EditCatagory(a_gradebook.GetCatagory()[input]));
				break;
			//Delete Category
			case 3:
				input = ChooseCategory(a_gradebook);
				if (input >= 0 && input < a_gradebook.GetCatagory().size()) a_gradebook.DeleteCategory(input);
				break;
			}
			break;

		//Assignment Management
		case 2:
			input = ChooseCategory(a_gradebook);
			if (input >= 0 && input < a_gradebook.GetCatagory().size()) {
				std::cout << "What would you like to do with " << a_gradebook.GetCatagory()[input].GetName() << " Assignments:\n1 - Add Assignment\n2 - Edit Assignment\n3 - Delete Assignment\n4 - Back\n";
				input2 = ValidIntInput();

        //switch statements to modify assignment within a gradebook

				switch (input2) {
				//Assignment Creation
				case 1:
                    // if input is greater than or equal to zero and input is less than the Category size
					if (input >= 0 && input < a_gradebook.GetCatagory().size()) {
                    //if there is an assignment to add, the two lines below will get the assignment title and display
						std::cout << "Assignment title: ";
                        std::cin.ignore();
                        std::getline(std::cin, s_input);
                        s_input = ConcatInputs(s_input);

                        //if there is an assignment to add, this will show its max score
						std::cout << "\nMax score: ";
						std::cin >> max_score;

                        //finally a_gradebook will use .SetCatagory with the initial input as the index, then will call on the BuildCatagorry Assignment to create the assignment with the s_input and the max score
						a_gradebook.SetCatagory(input, BuildCatagoryAssignment(a_gradebook.GetCatagory()[input], s_input, max_score));
					}
					break;
				//Edit Assignment
				case 2:
                    //input2 chooses the assignment at the index=input
					input2 = ChooseAssignment(a_gradebook.GetCatagory()[input]);
					if (input2 >= 0) a_gradebook.SetCatagory(input, EditAssignment(input2, a_gradebook.GetCatagory()[input]));
					break;
				//Delete Assignment
				case 3:
					input2 = ChooseAssignment(a_gradebook.GetCatagory()[input]);
					if (input2 >= 0) a_gradebook.SetCatagory(input, DeleteAssignment(input2, a_gradebook.GetCatagory()[input]));
					break;
				}
			}
			break;


		//Display grades - not finished/implemented
		case 3:
			for (int i = 0; i < a_gradebook.GetCatagory().size(); i++) {
				std::cout << "******************************\n" << a_gradebook.GetCatagory()[i].to_string() << "******************************\n";
				for (int j = 0; j < a_gradebook.GetCatagory()[i].GetAssignment().size(); j++) {
					std::cout << a_gradebook.GetCatagory()[i].GetAssignment()[j].to_string();
				}
				std::cout << "\n\n";
			}
			break;
		//exit gradebook
		case 4:
			SaveGradebook(a_gradebook, load_initializer);
			back = true;
			break;
		}
	}

}

//builds gradebook from data file
void LoadGradebook(Gradebook & a_gradebook, std::string load_file, std::vector<std::string> load_initializer) {
	std::ifstream in_file;
	std::string gb_name;
	std::string cat_name;
	std::string ass_name;
	int num_assignments;
	int max_score;
	int score;
	int cat_count = 0; //used to track which catagory to add assignments to
	float weight;

	in_file.open(load_file + ".txt");   //opens string name with the .txt extension
	in_file >> gb_name;                    //takes in the gradebook name
	a_gradebook = Gradebook(gb_name);   //creates a_gradebook, with the gradebook class

	//cycle through gradebook data file
	while (in_file.peek() != EOF) {
		//pull category name, weight and number of assignments from data file
		in_file >> cat_name;
		in_file >> weight;
		in_file >> num_assignments;

		//creates Catagory
		a_gradebook.AddCatagory(Catagory(cat_name, weight));

		//cycle through assignments adding them to the Category
		for (int i = 0; i < num_assignments; i++) {
			in_file >> ass_name;
			in_file >> max_score;
			in_file >> score;
			a_gradebook.SetCatagory(cat_count, BuildCatagoryAssignment(a_gradebook.GetCatagory()[cat_count], ass_name, max_score, score));
		}
		cat_count++;
	}
	// passes gradebook to the manager after loading
	ManageGradebook(a_gradebook, load_initializer);
}

int main(int argc, char* argv[]) {
	int input;
	int menu_count = 0;
	std::string s_input;    //declaration for string input from the test file
	std::string s_tmp;      //temporary string holder
	std::string load_file = "init_load.txt";    //string for holding data from the initial gradebook file
	bool quit = false;               //setting the quit option for the gradebook to false so that way when user would like to exit it is set to true
	Gradebook a_gradebook = Gradebook("");   //using the Gradebook class to make an empty gradebook that will take in a name
	std::vector<std::string> load_initializer;      //taking in the strings into a vector of strings in order to hold data from load
	std::ifstream in_file;                          ////creating the file stream in order to manipulate file contents

	while (!quit) {             //while the user does not hit quit, we progress into some logic for creating/outputting the gradebook

		//opens txt file with list of saved gradebooks
		if (argc == 1) in_file.open(load_file);
		else if (argc == 2) in_file.open(argv[1]);
		else {
			quit = true;                            //all else fails quit the program
            std::cout << "Invalid Argument";		//Will show the user that they entered an Invalid Arguement
		}

		//builds lists of saved grade-books in a vector<string> call load_initializer
		load_initializer.clear();       //clears the vector of strings in order to hold new data from user
		while (in_file.peek() != EOF && !quit) {    //while peak is not the end of file and the user doesn't quit, the temporary string
			in_file >> s_tmp;                       //will go into the temp file stream
			load_initializer.push_back(s_tmp);      //the vector of strings is then taking in the string temp values
		}
		in_file.close();                            //once the while loop if finished, this will then close the file

        //initial look of the gradebook during run time

		std::cout << "***********\n" << "*Gradebook*\n" << "***********\n";
		std::cout << "1 - New Gradebook\n" << "2 - Load Gradebook\n" << "3 - Import Gradebook\n" << "4 - Quit\n";

		//std::cin >> input;  //taking in user selection to envoke the gradebook options above.
		input = ValidIntInput();
		switch (input) {

			//initializes new gradebook and passes it to the gradebook manager
            //case 1: creating a new Gradebook
		case 1:
			std::cout << "Name of new gradebook's course\n";
            std::cin.ignore();
            std::getline(std::cin, s_input);
            s_input = ConcatInputs(s_input);
			a_gradebook =  Gradebook(s_input); //creating a gradebook from Gradebook class with the string that is taken in from the user. and is assigned to a_gradebook
			ManageGradebook(a_gradebook, load_initializer); //Calls void function from above with the gradebook that was just created and the load initializer that
            //previously filled while going through the in file
			break;

		//load gradebook
		case 2:
			//loops through load_initializer printing out choices of gradebooks available to load
			std::cout << "Which Gradebook would you like to load:\n";
			menu_count = 0; //counter for gradebook menu
			for (int i = 0; i < load_initializer.size(); i++) {
                //traverses through the load_initializer if there are any gradebooks that were previously added
				std::cout << i + 1 << " - " << load_initializer[i] << "\n";
                //increments the count of gradebooks each time a new one is created and loaded in
				menu_count++;
			}

			std::cout << menu_count + 1 << " - Back\n"; //will allow the user to go back depending on the menu size +1 to ensure that it is always last
			input = ValidIntInput();

			//if choice is within range call LoadGradeook()
			if (input > 0 && input < menu_count + 1 ) LoadGradebook(a_gradebook, load_initializer[input - 1], load_initializer);
			break;


			//import - TODO: Import gradebook from a formatted txt file - be sure to check for duplication in init_load.txt and adjust init_load.txt
		case 3: {
            //takes in a string input, pull in an externally created gradebook
            // some starter code below to take in the import file logic
            //should probably use some LoadGradebook functionality to complete

//            std::cout << "Which Gradebook would you like to import?\n";
//            std::fstream imported_gradebook;
//            imported_gradebook.open("init_load.txt"); //open a file to perform read operation using file object
//            if (imported_gradebook.is_open()){ //checking whether the file is open
//                std::string tp;
//                while(getline(imported_gradebook, tp)){ //read data from file object and put it into string.
//                    std::cout << tp << "\n"; //print the data of the string
//                }
//
//            }
            break;
        }

			//breaks loop and exits app
		case 4: {
            quit = true;
            break;
        }
		}
	}
}


