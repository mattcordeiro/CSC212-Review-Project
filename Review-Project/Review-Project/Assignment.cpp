#include "Assignment.h"

Assignment::Assignment(std::string name) {
	this->name = name;
}

Assignment::Assignment(std::string name, int max_score) {
	this->name = name;
	this->max_score = max_score;
}

Assignment::Assignment(std::string name, int max_score, int score) {
	this->name = name;
	this->max_score = max_score;
	this->score = score;
}

void Assignment::SetMaxScore(int max_score) {
	this->max_score = max_score;
}

void Assignment::SetScore(int score) {
	this->score = score;
}

float Assignment::CalculateGrade() {
	return this->score / this->max_score;
}

std::string Assignment::to_string() {
	std::string str = "";
	str += "Assignment: " + this->name + " Grade: " + std::to_string(this->score) + "/"
		+ std::to_string(this->max_score) + " - " + std::to_string(CalculateGrade()) + "%\n";

	return str;
}