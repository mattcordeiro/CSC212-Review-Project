#include "main.h"
#include "Gradebook.h"
#include <memory>

void ManageGradebook(Gradebook* a_gradebook) {	
	int input;
	std::string s_input;
	bool back = false;
	double f_input;

	while (!back) {
		std::cout << "What would you like to do with gradebook: " << a_gradebook->GetName() << ":\n";
		std::cout << "1 - Add Catagory\n"<< "2 - Add Assignment\n" << "3 - Show Grades\n" << "4 - Back\n";
		std::cin >> input;
		
		switch (input) {
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
		case 2:
			if (a_gradebook->GetCatagory().size() > 0) {
			}
			else std::cout << "No catagories to add an assignment to.";
			break;
		case 3:
			break;
		case 4:
			back = true;
			break;
		}
	}

}

int main(int argc, char* argv[]) {
	int input;
	std::string s_input;
	bool quit = false;
	Gradebook* a_gradebook;

	while (!quit) {
		std::cout << "***********\n" << "*Gradebook*\n" << "***********\n";
		std::cout << "1 - New Gradebook\n" << "2 - Load Gradebook\n" << "3 - Import Gradebook\n" << "4 - Quit\n";

		std::cin >> input;

		switch (input) {
		case 1:
			std::cout << "Name of new gradebook's course\n";
			std::cin >> s_input;
			a_gradebook = new Gradebook(s_input);
			ManageGradebook(a_gradebook);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			quit = true;
			break;
		}
	}
	
	
}


