//Tim Garvin

#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:		
		Student* students[20];
		
		string firstName;
		string lastName;
		string studentID;
		string classification;
		string major;
		
		string command;
		bool validEntry;
		int counter;
	public:
		Student(); //Constructor
		~Student(); //Destructor
		
		void execute_command(); //Declares a function to execute an Add/Remove/Print command based on user input
		
		string get_command(); //Declares a function to get the command entered
		
		//Declares a function to add a student to the students array
		void add_student(string fName, 
			string lName, 
			string id, 
			string class_level, 
			string mjr);
		
		void remove_student(string id); //Declares a function to remove a student from the students array
		
		void print_student(string attribute); //Declares a function to print student records from the students array
		
		void check_entry(); //Declares a function to validate user input
};