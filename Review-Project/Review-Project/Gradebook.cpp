#include "Gradebook.h"

Gradebook::Gradebook(std::string name) {
	this->name = name;
}
std::string Gradebook::GetName() {
	return this->name;
}void Gradebook::SetCatagory(int idx, Catagory catagory) {
	this->catagories[idx] = catagory;
}
std::vector<Catagory> Gradebook::GetCatagory() {
	return this->catagories;
}
void Gradebook::AddCatagory(Catagory catagory) {
	this->catagories.push_back(catagory);
}
void Gradebook::DeleteCategory()
{
}
std::string Gradebook::to_string() {
	std::string str = "";
	str += this->name + "\n";
	return str;
}