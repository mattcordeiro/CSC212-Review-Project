#pragma once
#include <iostream>
#include <string>

class Assignment {
private:
	std::string name;
	int max_score;
	int score;
public:
	Assignment();
	Assignment(std::string name);
	Assignment(std::string name, int max_score);
	Assignment(std::string name, int max_score, int score);
	std::string GetName();
	void SetName(std::string name);
	int GetMaxScore();
	void SetMaxScore(int max_score);
	int GetScore();
	void SetScore(int score);
	float CalculateGrade();
	std::string to_string();
};

