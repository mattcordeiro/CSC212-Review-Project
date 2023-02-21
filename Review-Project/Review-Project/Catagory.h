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
	void SetName(std::string name);
	std::string GetName();
	double GetWeight();
	void SetWeight(float weight);
	std::vector<Assignment> GetAssignment();
	void SetAssignment(int idx, Assignment assingment);
	void AddAssignment(Assignment assingment);
	void DeleteAssignment();
	std::string to_string();

};

