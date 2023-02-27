# CSC212-Review-Project 
## Summary

For our first project of the semester in CSC 212, we were tasked with creating a virtual gradebook that can assist us to keep track of our progress 
throughout this course. Our gradebook gives the user the option to create a gradebook for either CSC 212 or another course of their choice. Our submission 
includes the minimum files for the project such as "*main.cpp, gradebook.cpp, and gradebook.h*" and there is an addition to this file configurations by 
adding a couple of classes for Assignments and Categories. By adding these classes, we were able to give the end user more flexibility and editing
capabilities. For our end result, we are able to modify and output all deliverables required by the project criteria.

## Planning
```
User runs program to input a library of graded data and/or class data
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
<img src="https://github.com/mattcordeiro/CSC212-Review-Project/blob/main/Planning-Materials/reviewproject%20flow.jpg" width=40% height=40%><img src="https://github.com/mattcordeiro/CSC212-Review-Project/blob/main/Planning-Materials/Screen%20Shot%202023-02-26%20at%208.30.53%20PM.jpeg" width=60% height=60%>

## Compilation Instructions
To compile our program, the run and debug option within the end users IDE is sufficent to compile and execute the program. The user does not need to insert any command line arguments at the initial run time, but there is an option of using the filename for an empty gradebook such as: 

**./Gradebook sample-cla.txt** 

to load another dataset within the same directory. In addition, the program can be compiled in the directory with:

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

 <img src="https://github.com/mattcordeiro/CSC212-Review-Project/blob/main/Planning-Materials/csc212%20input%20file.png" width=20% height=20%>  
 
 Here we see that the first line should be the class title or the title of the gradebook you'd like to create. Then, we see different categories with assignments applicable to each category if any exist and the size of said category. 
 
 For example, we see that Labs has 4 assignments within the category, and since all of the assignments are currently not graded except for the initial lab, the rest of the labs contain a 0 out of weight 20 for a score.


## Evidence

Here we see the output for an Individual assignment within one of Matt's Gradebooks for ART-251:

<img src="https://github.com/mattcordeiro/CSC212-Review-Project/blob/main/Planning-Materials/Screen%20Shot%202023-02-26%20at%208.01.31%20PM%20Small.jpeg" width=25% height=25%>

The following was created as an output of our Gradebook as it creates a Gradebook for the user with the following outputs to present each person their own 
dataset. In addition, we can also see the output of Daniel's MTH180 total course grade:

<img src="https://github.com/mattcordeiro/CSC212-Review-Project/blob/main/Planning-Materials/Screen%20Shot%202023-02-26%20at%207.55.02%20PM.png" width=45%
height=45%>

