//Tim Garvin

#include "student.h"

//Constructor implementation (Initialization of variables)
Student::Student()
{
	//Initializes the students array elements
	for(int i = 0; i < 20; i++)
	{
		students[i] = NULL;
	}
	
	firstName = "none";
	lastName = "none";
	studentID = "none";
	classification = "none";
	major = "none";
	
	command = "none";
	validEntry = true;
	counter = -1;
}

//Executes an Add/Remove/Print command based on user input
void Student::execute_command()
{
	cout<<"students> ";
	cin>>command;

	//Checks if the user wants to add a student and if the next character is a space
	if(command == "add" && cin.peek() == ' ')
	{
		cin>>firstName;
		cin>>lastName;
		cin>>studentID;
		cin>>classification;
		cin>>major;
		
		check_entry(); //Checks for valid user input
		
		if(validEntry) //If user input is valid, then adds a student.
		{
			add_student(firstName, lastName, studentID, classification, major); //Adds a student to the students array
		}
		else //If user input is invalid, resets validEntry back to true for next input
		{
			validEntry = true;
		}
	}
	
	//Checks if the user wants to remove a student and if the next character is a space
	if(command == "remove" && cin.peek() == ' ')
	{
		cin>>studentID;
		
		remove_student(studentID); //Removes a student from the students array
	}
	
	//Checks if the user wants to print student records and if the next character is a space
	if(command == "print" && cin.peek() == ' ')
	{
		string studentAttribute = "none";
		
		cin>>studentAttribute;
		
		print_student(studentAttribute); //Prints student records based on the category of information (the attribute) requested by the user
	}
}

//Returns the current command value
string Student::get_command()
{
	return command;
}

//Adds a student to the students array
void Student::add_student(string fName, string lName, string id, string class_level, string mjr)
{
	//Creates a new Student class object
	Student *new_student;
	new_student = new Student;
	
	//Loads entered data into the new Student class object
	new_student->firstName = fName;
	new_student->lastName = lName;
	new_student->studentID = id;
	new_student->classification = class_level;
	new_student->major = mjr;
	
	if(counter == -1) //If no student records yet, add new student to beginning of students array
	{
		students[0] = new_student;
		counter++;
	}
	else //If student records already exist, add new student to the next available empty element of the students array
	{
		students[counter+1] = new_student;
		counter++;
	}
}

//Validates user input
void Student::check_entry()
{
	//Checks that the entered Student ID # only contains numbers
	for(int i = 0; i < studentID.size(); i++)
	{
		//Displays error message if a non-numerical value is found
		if(!isdigit(studentID[i]))
		{
			cout<<"Error! Student ID must contain only numbers!"<<endl;
			validEntry = false;
			break;
		}
	}

	//Checks that the Student ID # entered doesn't already exist
	for(int i = 0; i <= counter; i++)
	{
		//Displays error message if Student ID # already exists
		if(students[i]->studentID == studentID)
		{
			cout<<"Error! Student ID already exists!"<<endl;
			validEntry = false;
			break;
		}
	}
}

//Removes a student from the students array
void Student::remove_student(string id)
{
	bool idExists = false;
	int idIndex;
	
	//Loops through the students array to see if Student ID # already exists
	for(int i = 0; i <= counter; i++)
	{
		//If Student ID # exists, save the Index location and exit the loop
		if(id == students[i]->studentID)
		{
			idIndex = i;
			idExists = true;
			break;
		}
	}
	
	//If Student ID # exists, removes the student
	if(idExists)
	{
		//Removes the existing student and moves the students after it to eliminate gaps in the students array
		for(int j = idIndex; j <= counter; j++)
		{
			if(j == counter)
			{
				students[j] = NULL;
				counter--;
				break;
			}
			else
			{
				students[j] = students[j+1];
			}
		}

		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
}

//Prints student records based on the category of information (the attribute) requested by the user
void Student::print_student(string attribute)
{
	//Displays all Students' First Names in the students array
	if(attribute == "firstname")
	{
		for(int i = 0; i <= counter; i++)
		{
			if(i != counter)
			{
				cout<<students[i]->firstName<<"-";
			}
			else
			{
				cout<<students[i]->firstName<<endl;
			}
		}
	}
	
	//Displays all Students' Last Names in the students array
	if(attribute == "lastname")
	{
		for(int i = 0; i <= counter; i++)
		{
			if(i != counter)
			{
				cout<<students[i]->lastName<<"-";
			}
			else
			{
				cout<<students[i]->lastName<<endl;
			}
		}
	}
	
	//Displays all Students' ID Numbers in the students array
	if(attribute == "id")
	{
		for(int i = 0; i <= counter; i++)
		{
			if(i != counter)
			{
				cout<<students[i]->studentID<<"-";
			}
			else
			{
				cout<<students[i]->studentID<<endl;
			}
		}
	}
	
	//Displays all Students' Classifications in the students array
	if(attribute == "classification")
	{
		for(int i = 0; i <= counter; i++)
		{
			if(i != counter)
			{
				cout<<students[i]->classification<<"-";
			}
			else
			{
				cout<<students[i]->classification<<endl;
			}
		}
	}
	
	//Displays all Students' Majors in the students array
	if(attribute == "major")
	{
		for(int i = 0; i <= counter; i++)
		{
			if(i != counter)
			{
				cout<<students[i]->major<<"-";
			}
			else
			{
				cout<<students[i]->major<<endl;
			}
		}
	}
}

//Destructor
Student::~Student()
{
	delete [] students;
}