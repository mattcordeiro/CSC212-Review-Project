#include "Gradebook.h"

Gradebook::Gradebook(std::string name) {
	this->name = name;
}
void Gradebook::AddCatagory(Catagory catagory) {
	this->catagories.push_back(catagory);
}
std::string Gradebook::to_string() {
	std::string str;

	return str;
}