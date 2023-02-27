#include "Assignment.h"

Assignment::Assignment() {
	this->name = "";
	this->max_score = 0;
	this->score = -1;
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

double Assignment::CalculateGrade() {
	if(this->score >= 0) return (((double)this->score / (double)this->max_score)*100);
	else return ((0.0 / (double)this->max_score) * 100);
}

std::string Assignment::to_string() {
	std::string str = "";
	std::string s_score;
	if (this->score < 0) s_score = "ungraded";
	else s_score = std::to_string(this->score);
	str += "Assignment: " + this->name + " Grade: " + s_score + "/"
		+ std::to_string(this->max_score) + " - " + std::to_string(CalculateGrade()) + "%\n";

	return str;
}