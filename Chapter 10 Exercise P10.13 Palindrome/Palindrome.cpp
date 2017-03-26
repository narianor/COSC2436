#include "stdafx.h"
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

//Goes through a for loop based on the length of the given string and checks to see if each element in the string is alphabetical.
//If the element is proven to be alphabetical then that element is added on to the string "result" which is then returned back to the caller.
string strip(string s)
{
	string result;
	for (int i = 0; i < s.length(); i++)
	{

		if (isalpha(s[i]))
			result += s[i];
	}
	return result;
}

string capitalize(string s)
{
	//Goes through all characters in the string based on the length of the string and uses Toupper to capitalize them.
	//It then goes on and returns the finalized string.
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}

	return s;

}
//Compares the start and end of a string to see if they're identical and returns true or false on
//the result.
bool is_palindrome(string s)
{

	if (s.length() <= 1)
		return true;
	// If the palindrome is one letter like "a" , "b", then it's automatically a valid palindrome.
	// Also with recursion, as the string gets smaller and smaller, this will be the line that returns true to the function check on whether the long string that was comprised into shorter
	// strings was in fact a palindrome.

	char first = s[0];
	char last = s[s.length() - 1];
	//Defines the first and last characters of the current string.

	//Checks to see if the ending of both strings are identical
	//Able was I ere I saw Elba, ble was I ere I saw elb, le was I ere I saw el, e was I ere I saw e, was I ere I saw, as I ere I sa, s I ere I s, I ere I, ere, "r".
	// "r" is then equal to 1 so it's automatically a palindrome.
	// The multiple instances of is_palindrome(shorter) then finish processing and the check is complete.
	if (first == last)
	{
		string shorter = s.substr(1, s.length() - 2);
		//Creates all the instances for the checks on shorter versions of the original string.

		return is_palindrome(shorter);
	}
	else
		return false;
};




int main()
{
	for (int i = 0; i < 1000; i++)
	{
		//Asks the user to enter a Palindrome and stores it in "palindrome" as well as "backup_palindrome".
		string palindrome;
		cout << "Insert possible Palindrome: ";
		getline(cin, palindrome);
		cout << endl;

		//Backup string made just for ease of use. Instead of converting the end result of the string back into its original form, I just decided
		//to store it and recall the original string later.
		string backup_palindrome = palindrome;

		//Calls the Capitalize function on the "palindrome" which changes all characters in the string to their uppercase counterparts.
		palindrome = capitalize(palindrome);

		//Calls the strip function on the "palindrome" string and replaces palindrome with the new
		//return from the strip function.
		palindrome = strip(palindrome);

		//Checks to see if the string is a palindrome and prints out the correct response.
		if (is_palindrome(palindrome))
		{
			cout << "'" << backup_palindrome << "', is a palindrome." << endl;
		}
		else
			cout << "'" << backup_palindrome << "', is not a palindrome." << endl;


	}
	return 0;
}

/* TEST CASES:
Mr. Owl ate my metal worm
Able was I ere I saw Elba
A car, a man, a maraca.
Al lets Della call Ed Stella.
Amy, must I jujitsu my ma?
*/