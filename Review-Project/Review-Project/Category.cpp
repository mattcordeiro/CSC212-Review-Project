#include "Category.h"

//default constructor
Category::Category(std::string name) {
	this->name = name;
	this->weight = 0;
}
Category::Category(std::string name, float weight) {
	this->name = name;
	this->weight = weight;
}
void Category::SetName(std::string name)
{
	this->name = name;
}
std::string Category::GetName() {
	return this->name;
}
double Category::GetWeight() {
	return this->weight;
}
void Category::SetWeight(float weight) {
	this->weight = weight;
}
double Category::CalculateWeightedGrade(Assignment assignment){
    return (assignment.CalculateGrade() * this->weight);
}
std::vector<Assignment> Category::GetAssignment() {

	return this->assignments;
}
void Category::SetAssignment(int idx, Assignment assingment)
{
	this->assignments[idx] = assingment;
}
void Category::AddAssignment(Assignment assingment) {
	this->assignments.push_back(assingment);
}

void Category::DeleteAssignment(int idx)
{
	this->assignments.erase(assignments.begin() + idx);
}

double Category::CalculateCategoryGradePoints()
{
	int total_max_score=0;
	int total_score=0;
	for (int i = 0; i < this->assignments.size(); i++) {		
		total_max_score += assignments[i].GetMaxScore();
		total_score += assignments[i].GetScore();
	}
	return (((double)total_score / (double)total_max_score) * 100);
}

std::string Category::to_string() {
	std::string str = "";
	str += this->name + " Has " + std::to_string(this->assignments.size()) + " Assignments, with a total score of "+ std::to_string(CalculateCategoryGradePoints()) +"\n";

	return str;
}