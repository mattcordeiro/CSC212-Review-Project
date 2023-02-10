#include "Gradebook.h"

Gradebook::Gradebook(std::string name) {
	this->name = name;
}
std::string Gradebook::GetName() {
	return this->name;
}
std::vector<Catagory> Gradebook::GetCatagory() {
	return this->catagories;
}
void Gradebook::AddCatagory(Catagory catagory) {
	this->catagories.push_back(catagory);
}
std::string Gradebook::to_string() {
	std::string str = "";
	str += this->name + "\n";
	return str;
}