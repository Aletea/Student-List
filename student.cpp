//Aletea, 10-3-17
//This program can create students, delete students, and print them out

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> //setprecision for the GPA


using namespace std;

//objects of students
struct Students {
  char firstName[30];
  char lastName[30];
  int ID;
  float GPA;
};


  int main() {
    //continuing keeps track of whether you've quit
    bool continuing = true;
    //vector to hold the students. Must be student pointers so they can be referenced and manipulated later
    vector<Students *> studentList;
    while (continuing == true) {
    cout << "\nWelcome to Student List!Enter:\n'ADD' to add a student\n'PRINT' to see the all students currently stored\n'DELETE' to delete a student by ID\n'QUIT' to exit" << endl;
    //user inputs into a char array
    char input[7];
    cin.get(input, 7);
    cin.ignore(80, '\n');
    //make sure input matches a key word
    while (!(input == "DELETE" || input == "PRINT" || input == "ADD" || "QUIT")) {
      cout << "Invalid Input." << endl;
      cin.get(input, 7);
      cin.ignore(80, '\n');
    }
    //if add
    if (strcmp(input, "ADD") == 0) {
      //create a new student pointer
      //use input to add the first name, last name, ID, and GPA
      Students* student = new Students();
      cout << "First Name: ";
      cin.get(student->firstName, 30);
      cin.get();
      cout << "Last Name: ";
      cin.get(student->lastName, 30);
      cin.get();
      cout << "ID: ";
      cin >> student->ID;
      //use cin.ignore() to help remove terminatng characters that can be left behind in the cin
      cin.ignore(80, '\n');
      cout << "GPA: ";
      cin >> student-> GPA;
      cin.ignore(80, '\n');
      //add the pointer to the vector of students
      studentList.push_back(student);
    }
    else if (strcmp(input, "DELETE") == 0) {
      //get the student ID input
      int studentID;
      cout << "Student ID: ";
      cin >> studentID;
      cin.ignore(80, '\n');
      //create an iterator
      vector<Students*>::iterator studentDelete;
      bool found = false;
      //run through the iterator similar to a for loop, except instead of going through integer values, go from the beginning of student list to the end
      for (studentDelete = studentList.begin();
	   studentDelete != studentList.end(); studentDelete++) {
	//locate the student idea of the student that studentDelete is pointing to from studentList
	//check if it matched the input ID
	if ((*studentDelete)->ID == studentID) {
	  delete *studentDelete;
	  //if so, erase the student in studentList that studentDelete is pointing to
	  studentDelete = studentList.erase(studentDelete);
	  found = true;
	  //break now so you don't run through the rest, and get an error cause you just deleted part of studentList and the whole for loops is screwed up and I'm too lazy to make it run backwards
	  break;
	}
      }
      if (found == false) {
	cout << "No Such Student Exists" << endl;
      }
    }
    
    else if (strcmp(input, "PRINT") == 0) {
      cout << '\n' << endl;
      //another iterator
      vector<Students*>::iterator studentListIterator;
      for (studentListIterator = studentList.begin();
	   studentListIterator != studentList.end(); studentListIterator++) {
	//locate the elements of the student pointer that the iterator is pointing at
	cout << (*studentListIterator)->firstName<< " " << (*studentListIterator) ->lastName << ", " <<
	  (*studentListIterator)-> ID << ", ";
	//use fixed to allow for zeros, and set precision to only go to two decimal placed
	cout << fixed << setprecision(2) << (*studentListIterator)-> GPA << endl;
      }
      cout << endl;
    }
    //continuing is false, exit
    else if (strcmp(input, "QUIT") == 0){
      cout << "Quitting Now." << endl;
      continuing = false;
    }
    else {
      cout << "can't find input" << endl;
    }
    }
    return 0;
  }
