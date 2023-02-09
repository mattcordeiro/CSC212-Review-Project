#include "Catagory.h"

Catagory::Catagory(std::string name) {
	this->name = name;
}
Catagory::Catagory(std::string name, float weight) {
	this->name = name;
	this->weight = weight;
}
void Catagory::SetWeight(float weight) {
	this->weight = weight;
}
void Catagory::AddAssignment(Assignment assingment) {
	this->assignments.push_back(assingment);
}
std::string Catagory::to_string() {
	std::string str = "";


	return str;
}