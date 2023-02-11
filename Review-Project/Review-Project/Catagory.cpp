#include "Catagory.h"

Catagory::Catagory(std::string name) {
	this->name = name;
	this->weight = NULL;
}
Catagory::Catagory(std::string name, float weight) {
	this->name = name;
	this->weight = weight;
}
std::string Catagory::GetName() {
	return this->name;
}
double Catagory::GetWeight() {
	return this->weight;
}
void Catagory::SetWeight(float weight) {
	this->weight = weight;
}
std::vector<Assignment> Catagory::GetAssignment() {

	return this->assignments;
}
void Catagory::AddAssignment(Assignment assingment) {
	this->assignments.push_back(assingment);
}

std::string Catagory::to_string() {
	std::string str = "";


	return str;
}