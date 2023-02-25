#include "Gradebook.h"


//default constructor
Gradebook::Gradebook(std::string name) {
	this->name = name;
}
//returns the name of a gradebook
std::string Gradebook::GetName() {
	return this->name;

}void Gradebook::SetCatagory(int idx, Catagory catagory) {
	this->catagories[idx] = catagory;
}

std::vector<Catagory> Gradebook::GetCatagory() {
	return this->catagories;
}

//This pushes back a new category in order to create a new grading criteria (Labs/Assignments/Exam/etc)
void Gradebook::AddCatagory(Catagory catagory) {
	this->catagories.push_back(catagory);
}

//deletes a category within the gradebook at a given index
void Gradebook::DeleteCategory(int idx)
{
	this->catagories.erase(catagories.begin() + idx);
}

//gradebook output string
std::string Gradebook::to_string() {
	std::string str = "";
	str += this->name + "\n";
	return str;
}