/*Exercise P12.15. Implement a Stack class, using a linked list of strings. Supply opera-
tions size, push, pop, and top, just like in the standard stack template.					*/

/**

@Exercise P12.15 Implementing a stack.cpp

@author Bertin Perez

@date 3-29-2017

@version 1.0

*/

#include "stdafx.h"
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Stack
{
	public:
		Stack() {};
		list<string> top();
		int size();
		void push_back(list<string>);
		void pop_back();
		bool empty();

		void empty_test();
private:
	vector<list<string>> data;
};

//Amount of elements in the current stack.
int Stack::size()
{	
	return data.size();

}
//What element is at the top of the stack.
list<string> Stack::top()
{
	return data.back();
}
//Adds an element to the top of the stack.
void Stack::push_back(list<string> l)
{
	data.push_back(l);

}
//Removes an element from the top of the stack.
void Stack::pop_back()
{
	data.erase(remove(data.begin(), data.end(), data.back()), data.end());

}
//Checks to see if the stack is empty.
bool Stack::empty()
{
	if (data.size() > 0)
		return false;
	else
		return true;

}
//Function that outputs certain strings depending on whether the stack is empty or not.
void Stack::empty_test()
{
	if (data.empty())
		cout << "Book Stack is currently empty." << endl;
	else
	{
		cout << "Book Stack is not empty. It currently has " << data.size() << " books on it." << endl;
	}
}

int main()
{
	list<string> book1;
	list<string> book2;
	list<string> book3;
	
	//Writing a bunch of lists with multiple elements in the form of a book.
	book1.push_back("Book One");
	book1.push_back("There once was a book named book one.");
	book1.push_back("It was very short.");

	book2.push_back("Book Two");
	book2.push_back("There was once a book named book two.");
	book2.push_back("It was a little longer.");

	book3.push_back("Book Three");
	book3.push_back("There was once a book named book three.");
	book3.push_back("It was the longest of all.");

	Stack book_pile;

	//Sending the "book_pile" stack to see if it's empty.
	book_pile.empty_test();


	//Putting my collection of hand-typed books onto the stack.
	//Book One ends up at the top of the stack.
	book_pile.push_back(book3);
	book_pile.push_back(book2);
	book_pile.push_back(book1);

	//Sending the book_pile stack to see if it's empty.
	cout << "*	Three books have now been added on to the book pile.	* " << endl;
	book_pile.empty_test();
	
	//Creating a new list which holds the list at the top of the "book_pile" stack.
	list<string> current_book = book_pile.top();
	list<string>::iterator i;

	//Using the iterator "i" and making it go through all the elements of the list "current_book".
	//For every element, it outputs the string that is at the current pointer to which it's appointed.
	for (i = current_book.begin(); i != current_book.end(); i++)
	{
		cout << *i << endl;
	}
	
	//Removing the top element of the the stack "book_pile" and storing the new top element into "current_book".
	book_pile.pop_back();
	current_book = book_pile.top();

	for (i = current_book.begin(); i != current_book.end(); i++)
	{
		cout << *i << endl;
	}

	book_pile.pop_back();
	current_book = book_pile.top();

	for (i = current_book.begin(); i != current_book.end(); i++)
	{
		cout << *i << endl;
	}


	return 0;
	

}

