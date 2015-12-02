#include <iostream>

using namespace std;

#include "LLQueue.h"

void PFDtable(int N, int Min, LL Temp, LL &Create){
	Create.Pushllque(0);
	for (int i = 1; i < N; ++i){ Create.Pushllque(1); }
	while (Create.GetTotal() < Min){
		 Temp.Pushllque(0);

		//Create.Display(); //use to view the PFD table
		 int dummy=Create.Deque();
		 int a= Create.Deque();
		 for (int i = 2; i < N; ++i){ Temp.Pushllque(a + Create.Deque()); }

		Temp.Pushllque(a);
		Create = Temp;
		Temp.Clear();
	}
	
	//Create.Display(); //use to view the PFD table
}

int main(){
	char Ans;
	do{
		int PDF, Size;

		//		Display Menu
		cout << "\t------- PDF Menu -------\n";
		cout << "\tEnter the file size: "; cin >> Size;
		cout << "\t\tPFD of order: "; cin >> PDF; PDF++;

		//		Create and save the Perfect Fibinachi Distribution; FibTotal = used to calculate the dummy files needed.
		LL TempSet;
		LL PFDset; 
		PFDtable(PDF, Size, TempSet, PFDset);
		
		//		Display the the Polyphase Sort/Merge table
		cout << "\n   Sort #\tF1";	for (int i = 1; i < PDF; ++i){ cout << "______T" << i; }	cout << endl;
		cout << "\t\t" << Size; for (int i = 1; i < PDF; ++i){ cout << "\t--"; }	cout << endl;

		//		Displays each of the record mergers
		int x = Size, sortcount = 1;

		while (PFDset.GetTotal()>1)
		{
			cout << "\t" << sortcount;	PFDset.Display();
			PFDset.GetNonZero(x);
			
			for (int i = 0; i < PDF; ++i)
			{
				TempSet.Pushllque(abs(PFDset.Deque() - x));
			}
			PFDset = TempSet;
			TempSet.Clear();
			sortcount++;
		}

		//		Displays the location of the final sorted set
		cout << "\t" << sortcount;	PFDset.Display();

		//		Do another one
		cout << "\nContinue(y/n)? "; cin >> Ans;
		cout << endl;
	} while (toupper(Ans) == 'Y');

	system("pause");
	return(0);
}