#include "Catagory.h"

//default constructor
Catagory::Catagory(std::string name) {
	this->name = name;
	this->weight = 0;
}
Catagory::Catagory(std::string name, float weight) {
	this->name = name;
	this->weight = weight;
}
void Catagory::SetName(std::string name)
{
	this->name = name;
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
void Catagory::SetAssignment(int idx, Assignment assingment)
{
	this->assignments[idx] = assingment;
}
void Catagory::AddAssignment(Assignment assingment) {
	this->assignments.push_back(assingment);
}

void Catagory::DeleteAssignment(int idx)
{
	this->assignments.erase(assignments.begin() + idx);
}

double Catagory::CalculateCategoryGradePoints()
{
	int total_max_score=0;
	int total_score=0;
	for (int i = 0; i < this->assignments.size(); i++) {		
		total_max_score += assignments[i].GetMaxScore();
		total_score += assignments[i].GetScore();
	}
	return (((double)total_score / (double)total_max_score) * 100);
}

std::string Catagory::to_string() {
	std::string str = "";
	str += this->name + " Has " + std::to_string(this->assignments.size()) + " Assignments, with a total score of "+ std::to_string(CalculateCategoryGradePoints()) +"\n";

	return str;
}