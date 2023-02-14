#include "main2.h"
#include "Gradebook.h"
/*
* 
* This is just for testing 
* 
*/


int main(int argc, char* argv[]) {
	Gradebook a_gradebook("csc212");
	Catagory a_catagory("Labs", .2);
	Assignment a_assignment("Lab1", 20, 0);

	a_catagory.AddAssignment(a_assignment);
	a_gradebook.AddCatagory(a_catagory);
	//a_gradebook.GetCatagory()[0].AddAssignment(a_assignment);

	std::cout << std::to_string(a_gradebook.GetCatagory().size());
	std::cout << a_gradebook.GetCatagory()[0].to_string();
	std::cout << a_gradebook.GetCatagory()[0].GetAssignment()[0].to_string();





}