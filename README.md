# CSC212-Review-Project 
## Summary

For our first project of the semester in CSC 212, we were tasked with creating a virtual gradebook that can assist us to keep track of our progress 
throughout this course. Our gradebook gives the user the option to create a gradebook for either CSC 212 or another course of their choice. Our submission 
includes the minimum files for the project such as "*main.cpp, gradebook.cpp, and gradebook.h*" and there is an addition to this file configurations by 
adding a couple of classes for Assignments and Categories. By adding these classes, we were able to give the end user more flexibility and editing
capabilities. For our end result, we are able to modify and output all deliverables required by the project criteria.

## Planning
```
User runs program to imput a library of graded data and/or class data
    The user can then configure their gradebook to their liking to 
    include a loaded gradebook (shown in the format below), importing,
    or creating.
        Once the Gradebook is created, Category, Individual, and Course
        grades can be entered in
        The user can toggle show grades.
            The user can then select from course, individual, and category
            if individual
              then cout the individual grade and name
            else if category
              then return all grades from the category and category total
            else
              then course deliverables can be returned in 3 different ways
                  if all grades
                    then all grades within their respective categories and a course overall
                  else if only category
                    then only category totals and course overall
                  else
                    only the course overall    
```
<img src="https://github.com/mattcordeiro/CSC212-Review-Project/blob/main/Planning-Materials/reviewproject%20flow.jpg" width=50% height=50%>

## Compilation Instructions
To compile our program, the run and debug option within the end users IDE is sufficent to compile and execute the program. The user does not need to insert any command line arguments at the initial run time.

In addition, the program can be compiled in the directory with:

**"g++ -std=c++11 main.cpp Assignment.cpp Category.cpp Gradebook.cpp -o Gradebook && ./Gradebook"**

## Runtime Instructions
At run time, the user meets a menu with different gradebook options. These options include...
  1. New Gradebook
  2. Load Gradebook
  3. Import Gradebook
  4. Quit Virtual Gradebook
 Within each choice, the user is then prompted with various options. 
 
 When the user chooses to create a new Gradebook, they are then prompted with different logical operations in regards to the gradebook such as Managing categories or assignments, and the option to output their grades. 
 
 In order for the Gradebooks to be read and displayed properly, they must be formatted like the example below in order to be read and written over.

## Evidence
