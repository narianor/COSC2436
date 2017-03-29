/*Exercise P12.16. Implement a Queue class, using a linked list of strings. Supply opera-tions size, 
push, pop, front, and back, just like in the standard stack template.
*/

/*

Exercise P12.16 Implementing a queue.cpp

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

class Queue
{
public:
	Queue() {};
	list<string> front();
	list<string> back();
	int size();
	void push(list<string>);
	void pop();
	bool empty();
	
	void back_test();
	void empty_test();
private:
	vector<list<string>> data;
};

//Amount of elements in the queue.

list<string> Queue::front()
{
	return data[0];

}

//Returns the last element of the queue or the most recent entry.
list<string> Queue::back()
{
	return data.back();
}
//Checks the size of the queue.
int Queue::size()
{
	return data.size();

}

//Inserts an element to the end of the queue.
void Queue::push(list<string> l)
{
	data.push_back(l);

}
/*Removes the next element in the queue, effectively reducing its size by one.
The element removed is the "oldest" element in the queue.
*/
void Queue::pop()
{
	data.erase(remove(data.begin(), data.end(), data[0]), data.end());

}
//Checks to see if the queue is empty.
bool Queue::empty()
{
	if (data.size() > 0)
		return false;
	else
		return true;

}
//Checks to see which customer is at the end of the queue.
void Queue::back_test()
{
	list<string> current_customer = data.back();
	list<string>::iterator i = current_customer.begin();
	cout << "Customer at end of the line: " << *i << endl;

}

//Function that outputs certain strings depending on whether the stack is empty or not.
void Queue::empty_test()
{
	if (data.empty())
		cout << "Queue is currently empty." << endl;
	else
	{
		cout << "Queue is not empty. It currently has " << data.size() << " customers waiting for service." << endl;
	}
}


int main()
{	
	//Initiating a bunch of empty lists as customers.
	list<string> customer1;
	list<string> customer2;
	list<string> customer3;
	list<string> customer4;
	
	//Giving each customer their backstories.
	customer1.push_back("Allison Carmichael (Customer 1)");
	customer1.push_back("Customer:	My computer turned off after I spilled water on it. Can you fix it?");
	customer1.push_back("Tech:		I'm sorry, maam. Your computer is dead, there's nothing we can do about it.");
	customer1.push_back("Customer:	<Rage Intensifies>");

	customer2.push_back("Carson Adelaide (Customer 2)");
	customer2.push_back("Customer:	My grandson was playing on his laptop and it got slow all of a sudden, can you fix it?");
	customer2.push_back("Tech:		Sure, I can run maintenance on it right away. But this is the fourth time that you've been in here.");
	customer2.push_back("Tech:		It seems that the same spyware/adware was installed once again.");


	customer3.push_back("Jenny Miller (Customer 3)");
	customer3.push_back("Customer:	I bought this new monitor but when I plug it in it doesn't work. Can you fix it?");
	customer3.push_back("Tech:		I'm not sure how it's possible, but you put this DVI connector into an HDMI port.");
	customer3.push_back("Tech:		I have no idea how you fit it in there, but that's not where it belongs.");
	customer3.push_back("Tech:		I could have recommended some adaptors but now the port is destroyed.");
	customer3.push_back("Customer:	Oh.");


	customer4.push_back("Jonathan Rodriguez (Customer 4)");
	customer4.push_back("Customer:	I keep turning on the computer and the screen comes on, but it just keeps popping up that there is no input. Can you fix it?");
	customer4.push_back("Tech:		Sir, that's not the whole computer. That's just a monitor.");
	
	//Creating an empty queue and checking to see if it's empty or not.
	Queue customer_support_line;
	customer_support_line.empty_test();

	//Pushing the customers into the queue.
	customer_support_line.push(customer1);
	customer_support_line.push(customer2);
	customer_support_line.push(customer3);
	customer_support_line.push(customer4);

	//Checking to see if the queue is empty and checking who is at the back of the queue.
	customer_support_line.empty_test();
	customer_support_line.back_test();
	
	//Creating a new list that for the current customer and setting up the iterator i.
	list<string> current_customer = customer_support_line.front();
	list<string>::iterator i;

	//Going through all the entries for the customer.
	for (i = current_customer.begin(); i != current_customer.end(); i++)
		cout << *i << endl;

	//Removing the first customer from the queue and setting the current_customer as the next element in the queue.
	customer_support_line.pop();
	current_customer = customer_support_line.front();

	for (i = current_customer.begin(); i != current_customer.end(); i++)
		cout << *i << endl;

	customer_support_line.pop();
	current_customer = customer_support_line.front();

	for (i = current_customer.begin(); i != current_customer.end(); i++)
		cout << *i << endl;

	customer_support_line.pop();
	current_customer = customer_support_line.front();

	for (i = current_customer.begin(); i != current_customer.end(); i++)
		cout << *i << endl;


}

