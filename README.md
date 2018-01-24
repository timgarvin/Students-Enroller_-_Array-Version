# Description
Students Enroller (Array Version) is a C++ program that allows the user to enroll students, remove students, or print students' information using a Finite Set data structure (represented as an array). This program is made-from-scratch and does not utilize the C++ Standard Template Library (STL).

# Compilation and Execution
* Compile: g++ \*.cpp
* Run Program: ./a.out

# Program Commands
* add <first-name> <last-name> <student-id> <classification> <major>: Adds a student to the Finite Set.
	* Examples:
		<pre>
		students> add Bugs Bunny 3229 Junior Business
		students> add Donald Duck 230 Junior ComputerScience
		</pre>
* remove <student-id>: Removes a student from the Finite Set. Returns true if that student has been removed. Returns false if that student does not exist.
	* Examples:
		<pre>
		students> remove 123
		false
		students> remove 230
		true
		</pre>
* print <attribute>: Prints a students' information from the Finite Set.
	* Possible Attributes: firstname | lastname | id | classification | major
	* Examples:
		<pre>
		students> print firstname
		Bugs-Donald
		students> print major
		Business-ComputerScience
		</pre>
* quit: Exits the program.

# Technologies Used
* C++
* Linux
* PuTTY
* WinSCP

# Data Structures Used
* Finite Set

# Notes
* This program should be compiled and executed in a Linux Operating System environment.
* This program has been tested extensively, without error, through the University of North Texas's Praktomat testing system.