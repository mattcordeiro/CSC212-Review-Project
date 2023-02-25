#include "Catagory.h"

class Gradebook
{
private:
    //gradebook has a private name and a vector of categories that can include exams, assignments, labs and any other grading criteria.
	std::string name;
	std::vector<Catagory> catagories;

    //Different options for our gradebook such as Getting the name of a gradebook, creating a category and finding its location, in addition to adding and deleting a category
public:
	Gradebook(std::string name);
	std::string GetName();
	void SetCatagory(int idx, Catagory catagory);
	std::vector<Catagory> GetCatagory();
	void AddCatagory(Catagory catagory);
	void DeleteCategory(int idx);
	double CalculateTotalGradePoints();
	std::string to_string();
};

