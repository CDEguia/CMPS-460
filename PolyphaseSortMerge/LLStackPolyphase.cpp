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
		//cout << "\t";
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
		//return n;
	}
};
int PFDtable(int N, int Min, LLQUE Temp, LLQUE &Create){
	for (int i = 1; i < N; ++i){ Create.Pushllque(1); }
	while (Create.GetTotal() < Min){

		for (int i = 2; i < N; ++i){ Temp.Pushllque(Create.GetNumber(1) + Create.GetNumber(i)); }
		//cout << Create.GetTotal() << endl; //Used to display the PDF
		Temp.Pushllque(Create.GetNumber(1));
		Create = Temp;
		Temp.Clearllque(); Temp.Pushllque(0);
	}
	return Create.GetTotal();
}
int main(){
	char Ans;
	do{
		char Choice; int PDF, Size;
		LLQUE PFDset; PFDset.Clearllque(); PFDset.Pushllque(0);
		LLQUE TempSet; TempSet.Clearllque(); TempSet.Pushllque(0);

		//	Create Menu
		cout << "------- PDF Menu -------\n";
		cout << "\tEnter the file size: "; cin >> Size;
		cout << "\t\tPFD of order: "; cin >> PDF; PDF++;

		//		Create and save the Perfect Fibinachi Distribution
		int FibTotal = PFDtable(PDF, Size, TempSet, PFDset);

		//		Display the the Polyphase Sort/Merge table
		cout << "\t\tF1";	for (int i = 1; i < PDF; ++i){ cout << "______T" << i; }	cout << endl;
		cout << "\t\t" << Size; for (int i = 1; i < PDF; ++i){ cout << "\t--"; }	cout << endl;
		//PFDset.Display();

		//		Displays each of the record mergers
		int x = Size, sortcount = 0; TempSet.Clearllque();
		do{

			sortcount++;
			cout << "\t" << sortcount;	PFDset.Display();
			PFDset.GetNonZero(x);

			for (int i = 0; i < PDF; ++i){ TempSet.Pushllque(abs(PFDset.GetNumber(i) - x)); }
			PFDset = TempSet;
			TempSet.Clearllque();
			//PFDset.Display();
		} while (PFDset.OneCount());
		//		Do another one
		cout << "\nContinue(y/n)? "; cin >> Ans;
		Ans = toupper(Ans);
		cout << endl;
	} while (Ans == 'Y');

	system("pause");
	return(0);
}

/*----------------------------------------- OUTPUT -----------------------------------------------
------ - PDF Menu------ -
a.PFD of order 3
b.PFD of order 4
Enter the file size : 17
Enter your choice(a / b) : a
F1______T1______T2______T3
17      --      --      --
--      7       6       4
4       3       2       --
2       1       --      2
1       --      1       1
--      1       --      --
Continue(y / n) ? y

------ - PDF Menu------ -
a.PFD of order 3
b.PFD of order 4
Enter the file size : 25
Enter your choice(a / b) : b
F1______T1______T2______T3______T4
25      --      --      --      --
--      8       7       6       4
4       4       3       2       --
2       2       1       --      2
1       1       --      1       1
--      --      1       --      --
Continue(y / n) ? n

Press any key to continue . . .
------------------------------------------------------------------------------------------------*/