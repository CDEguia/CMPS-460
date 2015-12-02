#ifndef LLQUEUEH
#define LLQUEUEH

#include <iostream>
using namespace std;

struct NODE {
	int info;
	NODE *next;
};
class LL {

private:
	NODE *llhead, *endll;
public:
	LL();
	~LL();
	void Pushllque(int x);

	//Reset header and ender
	void LL::Clear();

	//Deque
	int Deque();
	
	//	Add each node in the list together and return the sum
	int GetTotal();

	//	Outputs the current Link List to std console
	void Display();

	//	Returns the lowest non Zero number in the link list
	void GetNonZero(int &n);
};
#endif