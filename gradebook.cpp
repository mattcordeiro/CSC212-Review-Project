//
// Created by matt cordeiro on 2/8/23.
//

#include "gradebook.h"
void examCalculation(std::vector<int> exam, int finalExamScore){
    

}


void ReadFile(std::string file_name, std::vector<std::vector<double>> * image_data){

    // Opens the file for reading
    std::ifstream file(file_name);
    
    // Creates a string to hold each line in temporarily
    std::string str;
    
    // Iterates over the file, storing one line at a time into `str`
    while (std::getline(file, str)) {
        
        // Create a temporary 1D Vector of doubles
        std::vector<double> new_row;
    
        // Create a stringstream object with our line of integers from the file
        std::istringstream ss(str);
    
        // Create a double that will hold our extracted value from the string
        double token;
    
        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
        }
    
        // The line is empty, push our completed row into our 2D vector
        image_data->push_back(new_row);
    }
}
void WriteFile(std::string file_name, std::vector<std::vector<double>> * const image_data){
    
    // Open our file with write permissions
    std::ofstream output_file(file_name);
    
    // Use an iterator to traverse the outer dimension
    for(std::vector<std::vector<double>>::const_iterator i = (*image_data).begin(); i != (*image_data).end(); ++i){
        
        // Use an interator to traverse the inner dimention
        for(std::vector<double>::const_iterator j = i->begin(); j != i->end(); ++j){
            
            // Output each element to the file with a space at the end
            output_file << *j << " ";
       
         }
       
         // Output a newline symbol to the file
        output_file << "\n";
    }
}