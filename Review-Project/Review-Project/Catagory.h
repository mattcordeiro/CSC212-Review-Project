#pragma once
#include "Assignment.h"
#include <vector>

class Catagory
{
private:
	std::string name;
	std::vector<Assignment> assignments;
	float weight;
public:
	Catagory(std::string name);
	Catagory(std::string name, float weight);
	void SetWeight(float weight);
	void AddAssignment(Assignment assingment);
	std::string to_string();

};

