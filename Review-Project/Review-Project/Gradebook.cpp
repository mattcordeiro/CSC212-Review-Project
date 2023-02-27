#include "Gradebook.h"


//default constructor
Gradebook::Gradebook(std::string name) {
	this->name = name;
}
//returns the name of a gradebook
std::string Gradebook::GetName() {
	return this->name;

}void Gradebook::SetCategory(int idx, Category catagory) {
	this->catagories[idx] = catagory;
}

std::vector<Category> Gradebook::GetCategory() {
	return this->catagories;
}

//This pushes back a new category in order to create a new grading criteria (Labs/Assignments/Exam/etc)
void Gradebook::AddCategory(Category catagory) {
	this->catagories.push_back(catagory);
}

//deletes a category within the gradebook at a given index
void Gradebook::DeleteCategory(int idx)
{
	this->catagories.erase(catagories.begin() + idx);
}

double Gradebook::CalculateTotalGradePoints(bool weighted)
{
	int total_max_score = 0;
	int total_score = 0;
	double total_weight = 0.0;
	double weight_diff = 0.0;
	double final_grade = 0.0;
	bool has_scores = false;

	for (int i = 0; i < catagories.size(); i++) {
		has_scores = false;
		for (int j = 0; j < catagories[i].GetAssignment().size(); j++) {
			if (catagories[i].GetAssignment()[j].GetScore() >= 0) {
				total_max_score += catagories[i].GetAssignment()[j].GetMaxScore();
				total_score += catagories[i].GetAssignment()[j].GetScore();
				has_scores = true;
			}
		}
		if (weighted && has_scores) {
			final_grade += (((double)total_score / (double)total_max_score) * 100) * (catagories[i].GetWeight());
			total_weight += catagories[i].GetWeight();
			total_max_score = 0;
			total_score = 0;
		}
	}
	if (weighted) {
		weight_diff = 1 - total_weight;
		return (final_grade + (100 * weight_diff));
	}
	else return (((double)total_score / (double)total_max_score) * 100);
}

//gradebook output string
std::string Gradebook::to_string() {
	std::string str = "";
	str += this->name + " gradebook\n";
	return str;
}