#include "main.h"
#include "Gradebook.h"
#include <fstream>

// Builds data file for gradebook
void SaveGradebook(Gradebook* a_gradebook, std::vector<std::string> load_initializer) {
	bool found = false; //used to check if gradebook exists in init_load.txt
	std::ofstream out_file;
	out_file.open(a_gradebook->GetName() + ".txt", std::ofstream::trunc); // opens txt file with gradebook name

	out_file << a_gradebook->GetName() + "\n";

	//cycle through each catagory and adds its fields and its assignments fields to the data file
	for(int i = 0; i < a_gradebook->GetCatagory().size();i++) {
		out_file << a_gradebook->GetCatagory()[i].GetName() + " " + std::to_string(a_gradebook->GetCatagory()[i].GetWeight()) + "\n";
		out_file << a_gradebook->GetCatagory()[i].GetAssignment().size() + "\n";
		std::cout << a_gradebook->GetCatagory()[i].GetAssignment().size() + "\n";
		for (int j = 0; j < a_gradebook->GetCatagory()[i].GetAssignment().size(); j++) {
			out_file << a_gradebook->GetCatagory()[i].GetAssignment()[j].GetName() + " " + std::to_string(a_gradebook->GetCatagory()[i].GetAssignment()[j].GetMaxScore())
				+ " " + std::to_string(a_gradebook->GetCatagory()[i].GetAssignment()[j].GetScore()) + "\n";
		}
	}
	out_file.close();

	// Checks if current gradebook exists in init_load.txt
	for (int i = 0; i < load_initializer.size(); i++) {
		if (load_initializer[i].compare(a_gradebook->GetName()) == 0) {
			found = true;
		}
	}

	// adds gradebook to init_load.txt if not found
	if (!found) {
		out_file.open("init_load.txt", std::ofstream::trunc);
		
		for (int i = 0; i < load_initializer.size(); i++) {
			out_file << load_initializer[i] + "\n";
		}
		out_file << a_gradebook->GetName();
		out_file.close();
	}

}

Catagory BuildCatagoryAssignment(Catagory catagory, std::string ass_name, int max_score, int score = 0) {
	Assignment assingment(ass_name, max_score, score);
	catagory.AddAssignment(assingment);
	if (!(catagory.GetAssignment().size() > 0))std::cout << "BCA not working, size i: " << catagory.GetAssignment().size() << std::endl;
	return catagory;
}

void ManageGradebook(Gradebook*& a_gradebook, std::vector<std::string> load_initializer) {
	int input, input2;
	int max_score;
	std::string s_input;
	bool back = false;
	double f_input;
	
	

	while (!back) {
		std::cout << "What would you like to do with gradebook: " << a_gradebook->GetName() << ":\n";
		std::cout << "1 - Add Catagory\n"<< "2 - Add Assignment\n" << "3 - Show Grades\n" << "4 - Back\n";
		std::cin >> input;
		
		switch (input) {
		//catagory creation
		case 1:
			std::cout << "Catagory name: ";
			std::cin >> s_input;
			std::cout << "Would you like to set the weight of " << s_input << " (1 - yes, 2 - no)? ";
			std::cin >> input;
			if (input == 2) a_gradebook->AddCatagory(Catagory(s_input));
			else if (input == 1) {
				std::cout << "Enter weight(decimal format): ";
				std::cin >> f_input;
				a_gradebook->AddCatagory(Catagory(s_input, f_input));
			}
			else std::cout << "Invalid Option.\n";
			break;

		//assignment creation - not finished/implemented
		case 2:
			//lists Catagories
			if (a_gradebook->GetCatagory().size() > 0) {
				std::cout << "Choose catagory for assignment:\n";
				for (int i = 1; i <= a_gradebook->GetCatagory().size(); i++) {
					std::cout << i << " - " << a_gradebook->GetCatagory()[i-1].GetName() << "\n";
				}
			}
			else std::cout << "No catagories to add an assignment to.\n";
			std::cout << std::to_string(a_gradebook->GetCatagory().size()) << "\n";
			std::cin >> input;

			if (input > 0 && input < (a_gradebook->GetCatagory().size() + 1)) {

				std::cout << "Assignment title: ";
				std::cin >> s_input;

				std::cout << "\nMax score: ";
				std::cin >> max_score;


				Catagory t_catagory = BuildCatagoryAssignment(a_gradebook->GetCatagory()[input - 1], s_input, max_score);
				if (!(t_catagory.GetAssignment().size()) > 0)std::cout << "#1 - Assingment creation failed, size i: " << a_gradebook->GetCatagory()[input - 1].GetAssignment().size() << std::endl;
				a_gradebook->SetCatagory(input - 1, t_catagory) ;
				if (!(a_gradebook->GetCatagory()[input - 1].GetAssignment().size()) > 0)std::cout << "#2 - Assingment creation failed, size i: " << a_gradebook->GetCatagory()[input - 1].GetAssignment().size() << std::endl;
			}
			break;
		//Display grades - not finished/implemented
		case 3:
			for (int i = 0; i < a_gradebook->GetCatagory().size(); i++) {
				for (int j = 0; j < a_gradebook->GetCatagory()[i].GetAssignment().size(); j++) {
					std::cout << a_gradebook->GetCatagory()[i].GetAssignment()[j].to_string();
				}
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
void LoadGradebook(Gradebook*& a_gradebook, std::string load_file, std::vector<std::string> load_initializer) {
	std::ifstream in_file;
	std::string gb_name;
	std::string cat_name;
	std::string ass_name;
	int num_assignments;
	int max_score;
	int score;
	int cat_count = 0; //used to track which catagory to add assignments to
	float weight;

	in_file.open(load_file + ".txt");
	in_file >> gb_name;
	a_gradebook = new Gradebook(gb_name);
	//cycle through gradebook data file
	while (in_file.peek() != EOF) {
		//pull catagory name, weight and number of assignments from data file
		in_file >> cat_name;
		in_file >> weight;		
		in_file >> num_assignments;

		//creates Catagory
		a_gradebook->AddCatagory(Catagory(cat_name, weight)); 

		//cycle through assignments adding them to the Catagory
		for (int i = 0; i < num_assignments; i++) {
			in_file >> ass_name;
			in_file >> max_score;
			in_file >> score;
			a_gradebook->GetCatagory()[cat_count].AddAssignment(Assignment(ass_name, max_score, score));
		}
		cat_count++;
	}

	// passes gradebook to the manager after loading
	ManageGradebook(a_gradebook, load_initializer);
}

int main(int argc, char* argv[]) {
	int input;
	int init_count = 0;
	int menu_count = 0;
	std::string s_input;
	std::string s_tmp;
	std::string load_file = "init_load.txt";
	bool quit = false;
	Gradebook* a_gradebook;
	std::vector<std::string> load_initializer;
	std::ifstream in_file;

	if (argc == 1) in_file.open(load_file);
	else if (argc == 2) in_file.open(argv[1]);
	else {
		quit = true;
		std::cout << "Invalid Argument";
	}

	load_initializer.clear();
	while (in_file.peek() != EOF && !quit) {
		in_file >> s_tmp;
		load_initializer.push_back(s_tmp);
		init_count++;
	}
	in_file.close();


	while (!quit) {
		std::cout << "***********\n" << "*Gradebook*\n" << "***********\n";
		std::cout << "1 - New Gradebook\n" << "2 - Load Gradebook\n" << "3 - Import Gradebook\n" << "4 - Quit\n";

		std::cin >> input;

		switch (input) {
			//initializes new gradebook and passes it to the gradebook manager
		case 1:
			std::cout << "Name of new gradebook's course\n";
			std::cin >> s_input;
			a_gradebook = new Gradebook(s_input);
			ManageGradebook(a_gradebook, load_initializer);
			break;

			//load gradebook
		case 2:
			//opens txt file with list of saved gradebooks
			if (argc == 1) in_file.open(load_file);
			else if (argc == 2) in_file.open(argv[1]);
			else {
				quit = true;
				std::cout << "Invalid Argument";
			}

			//builds lists of saved gradebooks in a vector<string> call load_initializer
			load_initializer.clear();
			while (in_file.peek() != EOF && !quit) {
				in_file >> s_tmp;
				load_initializer.push_back(s_tmp);
				init_count++;
			}
			in_file.close();

			//loops through load_initializer printing out choices of gradebooks available to load
			std::cout << "Which Gradebook would you like to load:\n";
			menu_count=0;
			for (int i = 0; i < load_initializer.size(); i++) {
				std::cout << i + 1 << " - " << load_initializer[i] << "\n";
				menu_count++;
			}
			std::cout << menu_count + 1 << " - Back\n";
			std::cin >> input;

			//if choice is within range call LoadGradeook() 
			if (input > 0 && input < menu_count + 1 ) LoadGradebook(a_gradebook, load_initializer[input - 1], load_initializer);
			break;

			//import - TODO: Import gradebook from a formatted txt file - be sure to check for duplication in init_load.txt and adjust init_load.txt
		case 3:
			break;

			//breaks loop and exits app
		case 4:
			quit = true;
			break;
		}
	}	
}


