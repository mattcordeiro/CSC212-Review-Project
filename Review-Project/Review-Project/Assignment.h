#pragma once
#include <iostream>
#include <string>

class Assignment {
private:
	std::string name;
	int max_score;
	int score;
public:
	Assignment(std::string name);
	Assignment(std::string name, int max_score);
	Assignment(std::string name, int max_score, int score);
	void SetMaxScore(int max_score);
	void SetScore(int score);
	float CalculateGrade();
	std::string to_string();
};

