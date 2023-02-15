#include "Assignment.h"

Assignment::Assignment() {
	this->name = "";
	this->max_score = 0;
	this->score = 0;
}

Assignment::Assignment(std::string name) {
	this->name = name;
	this->max_score = 0;
	this->score = 0;
}

Assignment::Assignment(std::string name, int max_score) {
	this->name = name;
	this->max_score = max_score;
	this->score = 0;
}

Assignment::Assignment(std::string name, int max_score, int score) {
	this->name = name;
	this->max_score = max_score;
	this->score = score;
}

std::string Assignment::GetName()
{
	return this->name;
}

void Assignment::SetName(std::string name)
{
	this->name = name;
}

int Assignment::GetMaxScore()
{
	return this->max_score;
}

void Assignment::SetMaxScore(int max_score) {
	this->max_score = max_score;
}

int Assignment::GetScore()
{
	return this->score;
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
		+ std::to_string(this->max_score) + " - " + std::to_string(CalculateGrade() * 100) + "%\n";

	return str;
}