#pragma once
#include "Catagory.h"

class Gradebook
{
private:
	std::string name;
	std::vector<Catagory> catagories;
public:
	Gradebook(std::string name);
	void AddCatagory(Catagory catagory);
	std::string to_string();
};

