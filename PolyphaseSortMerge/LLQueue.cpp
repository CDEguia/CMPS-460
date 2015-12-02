#include "LLQueue.h"


LL::LL()
{
	llhead = NULL; endll = NULL;
}

LL::~LL()
{
	NODE *temp;
	while (llhead)	{
		temp = llhead;
		llhead = temp->next;
		if (llhead == NULL) endll = NULL;
		//cout << temp->info << "Deleted\n";
		delete temp;
	}
}

void LL::Clear()
{
	llhead = NULL; 
	endll = NULL;
}

void LL::Pushllque(int x)
{
	NODE *temp;
	temp = new (NODE); temp->info = x; temp->next = NULL;
	if (endll == NULL){
		llhead = temp; endll = temp;
	}
	else{ endll->next = temp; endll = temp; }
}

//Deque
int LL::Deque()
{
	NODE *temp = llhead;
	int data = temp->info;
	llhead = temp->next;
	if (llhead == NULL) endll = NULL;
	delete temp;
	return data;
}

//	Add each node in the list together and return the sum
int LL::GetTotal()
{
	int x = 0;
	for (NODE *temp = llhead; temp != NULL; temp = temp->next)	{ x += temp->info; }
	return x;
}

//	Outputs the current Link List to std console
void LL::Display()
{
	for (NODE *temp = llhead; temp != NULL; temp = temp->next)
	{
		cout << "\t"; (temp->info == 0) ? cout << "--" : cout << temp->info;
	}
	cout << endl;
}

//	Returns the lowest non Zero number in the link list
void LL::GetNonZero(int &n)
{
	for (NODE *temp = llhead; temp != NULL; temp = temp->next)
	{
		if (temp->info != 0 && temp->info < n) n = temp->info;
	}
}
