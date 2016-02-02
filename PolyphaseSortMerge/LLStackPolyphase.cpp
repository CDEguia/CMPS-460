#include <iostream>

using namespace std;

//Link List Object
class LLQUE{
private:
	struct NODE {
		int info;	NODE *next;
	};
	NODE *llque, *rearllque;
public:
	void Clearllque(){ llque = NULL; rearllque = NULL; }
	void Pushllque(int x)	{
		NODE *temp;
		temp = new (NODE); temp->info = x; temp->next = NULL;
		if (rearllque == NULL){
			llque = temp; rearllque = temp;
		}
		else{ rearllque->next = temp; rearllque = temp; }
	}

	//Add each node in the list together and return the sum
	int GetTotal(){
		NODE *temp = llque;	int x = 0;
		while (temp != NULL)	{ x += temp->info;	temp = temp->next; }
		return x;
	}

	//returns false if only one link in the list contains a 1 : sort is complete 
	bool OneCount(){
		NODE *temp = llque;	int x = 0;
		while (temp != NULL)	{
			if (temp->info >= 1)++x;
			temp = temp->next;
		}
		return (x == 1 ) ? false : true;
	}

	//Returns the data contained in the specified link
	int GetNumber(int loc){
		NODE *temp = llque;
		for (int i = 0; i < loc; ++i){ temp = temp->next; }
		return temp->info;
	}

	//Outputs the current Link List to std console
	void Display(){
		NODE *temp = llque;
		while (temp != NULL)	{
			cout << "\t"; (temp->info == 0) ? cout << "--" : cout << temp->info;
			temp = temp->next;
		}
		cout << endl;
	}

	//Returns the lowest non Zero number in the link list
	void GetNonZero(int &n){
		NODE *temp = llque;
		while (temp != NULL)	{
			if (temp->info != 0 && temp->info < n) n = temp->info;
			temp = temp->next;
		}
	}
};

// Finds the Perfect Fibonacci Distribution
int PFDtable(int N, int Min, LLQUE Temp, LLQUE &Create){
	for (int i = 1; i < N; ++i){ Create.Pushllque(1); }
	while (Create.GetTotal() < Min){
		// Create.Display(); //use to view the PFD table
		for (int i = 2; i < N; ++i){ Temp.Pushllque(Create.GetNumber(1) + Create.GetNumber(i)); }

		Temp.Pushllque(Create.GetNumber(1));
		Create = Temp;
		Temp.Clearllque(); Temp.Pushllque(0);
	}
	// Create.Display(); //use to view the PFD table
	return Create.GetTotal();
}

int main(){
	char Ans;
	do{
		int PDF, Size;
		LLQUE PFDset; PFDset.Clearllque(); PFDset.Pushllque(0);
		LLQUE TempSet; TempSet.Clearllque(); TempSet.Pushllque(0);

		//	Create Menu
		cout << "\t-------------- PDF Menu --------------\n";
		cout << "\tEnter the number of items to sort: "; cin >> Size;
		cout << "\t\tPFD of order: "; cin >> PDF; PDF++;

		//		Create and save the Perfect Fibinachi Distribution
		int FibTotal = PFDtable(PDF, Size, TempSet, PFDset);

		//		Display the the Polyphase Sort/Merge table
		cout << "\n   Sort #\tF1";	for (int i = 1; i < PDF; ++i){ cout << "______T" << i; }	cout << endl;
		cout << "\t\t" << Size; for (int i = 1; i < PDF; ++i){ cout << "\t--"; }	cout << endl;

		//		Displays each of the record mergers
		int x = Size, sortcount = 0; TempSet.Clearllque();
		while (PFDset.OneCount()){
			sortcount++;
			cout << "\t" << sortcount;	PFDset.Display();
			PFDset.GetNonZero(x);
			for (int i = 0; i < PDF; ++i)
			{
				TempSet.Pushllque(abs(PFDset.GetNumber(i) - x));
			}
			PFDset = TempSet;
			TempSet.Clearllque();
		}
		//		Displays the location of the final sorted set
		sortcount++;
		cout << "\t" << sortcount;	PFDset.Display();
		
		//		Do another one
		cout << "\nContinue(y/n)? "; cin >> Ans;
		cout << endl;
	} while (toupper(Ans) == 'Y');

	system("pause");
	return(0);
}
