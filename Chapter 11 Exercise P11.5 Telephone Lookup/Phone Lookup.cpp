#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//Initialization of multiple functions to be used later on.
string get_name();
string get_phone_number();
string seperate_name(string);
string seperate_number(string);
string lookup_name(string, vector<string>, vector<string>);
string lookup_number(string, vector<string>, vector<string>);

int main()
{
	//Initialization of multiple variables to be used later on.
	int selection = 0;
	bool is_true = true;
	string buffer, name, number = "";
	vector<string> name_directory, number_directory;
	
	ifstream file;
	//I am opening a text file named "Phone Directory.txt."
	file.open("Phone Directory.txt");
	//Statement that makes sure that the file is properly opened.
	if (!file)
		cout << "Couldn't open the directory." << endl;
	
	//Loop that runs through every line in text file "Phone Directory.txt" and stores it in a temporary string named <buffer>.
	while (getline(file, buffer))
		{
		//The <buffer> string is sent to the <seperate_name> function and reduced to a string only containing the name
		//of the phone number holder which is then stored as an element in the <name_directory> vector.
		name_directory.push_back(seperate_name(buffer));
		//The <buffer> string is sent to the <seperate_number> function and reduced to a tsring only containing the number
		//of the phone number holder which is then stored as an element in the <number_directory> vector.
		number_directory.push_back(seperate_number(buffer));
		}

	//"Phone Directory.txt" is then closed.
	file.close();
	
	//Loop that runs as long as the <is_true> boolean is set to <true>.
	while (is_true)
	{	
		//Just some choices for the user.
		cout << "Phone Line Directory Service:" << endl;
		cout << "Search by name:   [1]" << endl;
		cout << "Search by number: [2]" << endl;
		cout << "Exit:		  [3]" << endl;
		cout << "Please enter your selection: ";
		//User inputs what choice they want depending on the corresponding numbers next to the choices.
		cin >> selection;
		//Switch statement based on the <selection> integer that the user entered previously.
		switch (selection)
		{
		case 1:
		{
			//Get the name of the user through the <get_name> function and store it in the <name> string.
			name = get_name();
			//Get the number of the user by sending the user's <name>, the <name_directory>, and the <number_directory>.
			number = lookup_number(name, name_directory, number_directory);
			//Prints out the name and number of the user.
			cout << name << ": " << number << endl << endl;
			break;
		}

		case 2:
		{	
			//Get the number of the user through the <get_phone_number> function and store it in the <number> string.
			number = get_phone_number();
			//Get the name of the user by sending the user's <number>, the <name_directory>, and the <number_directory>.
			name = lookup_name(number, name_directory, number_directory);
			//Prints out the name and number of the user.
			cout << number << ": " << name << endl << endl;
			break;
		}
		case 3:
		{	//If <selection> is 3 then the loop is closed by setting <is_true> to <false>
			is_true = false;
			break;
		}
		default:
			//Any other input for <selection> goes to the default which also closes the loop by setting
			//<is_true> to false.
			is_true = false; 
			cout << "Bad input." << endl;
			break;
		}
	}
	return 0;
}
//Iterates through the received string <line> and stores each character into a new string named <seperated_name> until
//it reaches a "," in the string. Once it reaches the ",", the for loop closes itself and <seperated_name> is sent back
//to the caller.
string seperate_name(string line)
{
	string seperated_name;
	for (int i = 0; i <= line.length(); i++)
	{
		if (line[i] != ',')
		{
			seperated_name += line[i];
		}
		else
			i = line.length();
	}
	return seperated_name;
}
//Iterates through the received string <line> and stores each character into a new string named <seperated_number> until
//it reaches a "," in the string. Once it reaches the ",", the for loop closes itself and <seperated_name> is sent back
//to the caller.
//The only difference with this function is that it starts at the end of the <line> string and stores it in <seperated_number>
//backwards to how it's supposed to be.
//To resolve this, <seperated_string> is reversed with the <reverse> algorithm and then returned back to the caller.
string seperate_number(string line)
{
	string seperated_number;
	for (int i = line.length() - 1; i >= 0; i--)
	{
		if (line[i] != ',')
			seperated_number += line[i];
		else
			i = 0;
	}
	reverse(seperated_number.begin(), seperated_number.end());
	return seperated_number;
}


string get_name()
{
	//Initialization of the variables for the function.
	string first_name, last_name, full_name, middle_name, backup_name;
	//Prompts the user for their first name and stores their response in the <first_name> string.
	cout << "What is your first name?: ";
	cin >> first_name;
	//Prompts the user for their last name and stores their response in the <last_name> string.
	cout << "What is your last name? : ";
	cin >> last_name;
	//Prompts the user for their middle name or middle initial and stores their response in the <middle_name> string.
	cout << "What is your middle name/initial? (If no middle name/initial available then just type in 'none' ): ";
	cin >> middle_name;
	//Makes a backup of the <middle_name> and stores it in <backup_name>.
	backup_name = middle_name;
	//Iterates through the <middle_name> string and capitalizes each character.
	for (int i = 0; i < middle_name.length(); i++)
	{
		middle_name[i] = toupper(middle_name[i]);
	}
	//Checks to see if the user selected "NONE" as their input and sets <full_name> to just <first_name> and <last_name>.
	if (middle_name == "NONE")
	{
		full_name = first_name + " " + last_name;
	}
	//If the user didn't select "NONE" then it sets <full_name> to <first_name>, <backup_name>(from before), and <last_name>.
	else
		full_name = first_name + " " + backup_name + " " + last_name;
	return full_name;
}
//Prompts the user for their phone number and stores it in the <phone_number> string which is then returned.
string get_phone_number()
{
	string phone_number;
	cout << "What is your phone number?: ";
	cin >> phone_number;
	return phone_number;
}


//Looks up the name of the user by checking to see if <num> is inside of the <num_dir> vector.
//If it is in the directory then it takes the index in which it found the correct number and uses it to find the corresponding
//name at the same index in the <name_dir> vector which is automatically returned.
//If the number is not found in <num_dir> then it returns "Not in our directory."
string lookup_name(string num , vector<string> name_dir, vector<string> num_dir)
{
	for (int i = 0; i < num_dir.size(); i++)
	{
		if (num_dir[i] == num)
			return name_dir[i];
	}
	return "Not in our directory.";
	
	
}
//Looks up the name of the user by checking to see if <nam> is inside of the <name_dir> vector.
//If it is in the directory then it takes the index in which it found the correct name and uses it to find the corresponding
//number at the same index in the <num_dir> vector which is automatically returned.
//If the name is not found in <name_dir> then it returns "Not in our directory."
string lookup_number(string nam, vector<string> name_dir, vector<string> num_dir)
{
	for (int i = 0; i < name_dir.size(); i++)
	{
		if (name_dir[i] == nam)
			return num_dir[i];
	}
	return "Not in our directory.";
}
