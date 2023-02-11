#pragma once
#include "Assignment.h"
#include <vector>

class Catagory
{
private:
	std::string name;
	std::vector<Assignment> assignments;
	double weight;
public:
	Catagory(std::string name);
	Catagory(std::string name, float weight);
	std::string GetName();
	double GetWeight();
	void SetWeight(float weight);
	std::vector<Assignment> GetAssignment();
	void AddAssignment(Assignment assingment);
	std::string to_string();

};

