	/*	

	Exercise P12.5. Provide a linked list of integers by modifying the Node, List, and Iterator classes of Section 
	12.2 to hold integers instead of strings.				

	@Exercise P12.5 Modifying a link list.cpp

	@author Bertin Perez

	@date 03-29-2017

	@version 1.0

	*/

#include "stdafx.h"
#include <assert.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class List;
class Iterator;

class Node
{
public:
	Node(int s);
private:
	int data;
	Node* previous;
	Node* next;
friend class List;
friend class Iterator;
};

class List
{
public:
	List();
	void push_back(int data);
	void insert(Iterator iter, int s);
	Iterator erase(Iterator iter);
	Iterator begin();
	Iterator end();

private:
	Node* first;
	Node* last;
	friend class Iterator;
};

class Iterator
{
public:
	Iterator();
	int get() const;
	void next();
	void previous();
	bool equals(Iterator b) const;

private:
	Node* position;
	List* container;
friend class List;
};

//Implementation of previously declared public functions

//										========= NODE ==========

//Constructs a node with a given data value.
Node::Node(int s)
{
	data = s;
	previous = NULL;
	next = NULL;
}

//										========= LIST ==========

//Constructs an empty list.
List::List()
{
	first = NULL;
	last = NULL;
}

//Appends an element to the list.
void List::push_back(int data)
{
	Node* new_node = new Node(data);
	if (last == NULL) //List is empty.
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}

/*	Inserts an element into the list.
"iter" - The position before which to insert.
"s"	   - The value to append.										*/
void List::insert(Iterator iter, int s)
{
	if (iter.position == NULL)
	{
		push_back(s);
		return;
	}

	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(s);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	if (before == NULL)	//Insert at beginning.
		first = new_node;
	else
		before->next = new_node;
}

/*	Removes an element from the list.
"iter" - The Position to remove.
Returns an iterator poiting to the element after the erased element.*/
Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

/*	Gets the beginning position of the list.
Returns an iterator pointing to the beginning of the list.			*/
Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

/*	Gets the past-the-end position of the list.
Returns an iterator pointing past the end of the list.				*/
Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

//										======== ITERATOR =========

//Constructs an iterator that does not point into any list.
Iterator::Iterator()
{
	position = NULL;
	container == NULL;
}

/*	Looks up the value at a position.
Returns the value of the node to which the iterator points.			*/
int Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

//	Advances the iterator to the next node.
void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

//	Moves the iterator to the previous node.
void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

/*	Compares two iterators.
"b" - The iterator to compare with this iterator.
Returns true if this iterator and b are equal.						*/
bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}

int main()
{
	List numbers;

	numbers.push_back(47);
	numbers.push_back(122);
	numbers.push_back(245);
	numbers.push_back(12);

	// Add a value in the fourth place.

	Iterator pos;
	pos = numbers.begin();
	pos.next();
	pos.next();
	pos.next();
	pos.next();

	numbers.insert(pos, 6687);

	//Remove the value in the second place.

	pos = numbers.begin();
	pos.next();

	numbers.erase(pos);

	//Print all values in the list.

	for (pos = numbers.begin(); !pos.equals(numbers.end()); pos.next())
		cout << pos.get() << "\n";
	return 0;
}

