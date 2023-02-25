#include "Assignment.h"
#include <vector>

class Category
{
    //Category holds the category name, assignments within that category and the weight of the assignments.
private:
	std::string name;
	std::vector<Assignment> assignments;
	double weight;
    //lower functions to manipulate various categories
public:
    //constructor
	Category(std::string name);
    //constructor to return the name and weight of a category
	Category(std::string name, float weight);
    //sets the name of the category
	void SetName(std::string name);
    //returns the name of a category
	std::string GetName();
    //gets weight of a category
	double GetWeight();
    //sets the weight of a category
	void SetWeight(float weight);
    //a vector of assignments to get an assignment within a category
	std::vector<Assignment> GetAssignment();
    //setting an assignment at a given index
	void SetAssignment(int idx, Assignment assignment);
    //adding an assignment
	void AddAssignment(Assignment assignment);
    //deleting an assignment at a given index
	void DeleteAssignment(int idx);
	//calculate category grade
	double CalculateCategoryGradePoints();
	std::string to_string();

};

