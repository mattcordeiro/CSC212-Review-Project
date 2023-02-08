//
// Created by matt cordeiro on 2/8/23.
//

#ifndef REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H
#include <vector>
#include <fstream>
#include <sstream>


class gradebook {
    //things that will not be accessed explicitly
private:
    std::vector<int> labs;
    std::vector<int> assignments;
    std::vector<int> projects;
    std::vector<int> exam;
    //things that will be accessed explicitly
public:
    //constructor holder
    gradebook::gradebook(); 

    //void calculate labs
    void labCalculation(std::vector<int> labs, int finalLabScore);
    
    //void calculate assignments
    void assignmentCalculation(std::vector<int> assignments, int finalAssignmentScore);

    //void calculate projects
    void projectCalculation(std::vector<int> project, int finalProjectScore);

    //void calculate exam
    void examCalculation(std::vector<int> exam, int finalExamScore);

    //read file
    void ReadFile(std::string file_name, std::vector<std::vector<double>> * image_data);
    //write file
    void WriteFile(std::string file_name, std::vector<std::vector<double>> * const image_data);
};


#endif //REVIEW_PROJECT_GRADEBOOK_H

//Notes from meeting
/*
Dan - data intake or format

Built for CSC 212;

Start off with initial file; add to a list of file references
new, load, .txt; file CLA; 
*/