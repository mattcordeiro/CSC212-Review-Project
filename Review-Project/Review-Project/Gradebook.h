#include "Catagory.h"

class Gradebook
{
private:
	std::string name;
	std::vector<Catagory> catagories;
public:
	Gradebook(std::string name);
	std::string GetName();
	void SetCatagory(int idx, Catagory catagory);
	std::vector<Catagory> GetCatagory();
	void AddCatagory(Catagory catagory);
	void DeleteCategory(int idx);
	std::string to_string();
};

