#include <iostream>

using namespace std;

//Link List Object
class LLQUE{
private:
	struct NODE {
		int info;	NODE *next_node;
	};
	NODE *llque, *rear_of_que;
public:
	void Clearllque(){ llque = NULL; rear_of_que = NULL; }
	void Push_into_llque(int x)	{
		NODE *temp;
		temp = new (NODE); temp->info = x; temp->next_node = NULL;
		if (rear_of_que == NULL){
			llque = temp; rear_of_que = temp;
		}
		else{ rear_of_que->next_node = temp; rear_of_que = temp; }
	}

	//Add each node in the list together and return the sum
	int GetTotal(){
		NODE *temp = llque;	int x = 0;
		while (temp != NULL)	{ x += temp->info;	temp = temp->next_node; }
		return x;
	}

	//returns false if only one link in the list contains a 1 : sort is complete
	bool OneCount(){
		NODE *temp = llque;	int x = 0;
		while (temp != NULL)	{
			if (temp->info >= 1)++x;
			temp = temp->next_node;
		}
		return (x == 1 ) ? false : true;
	}

	//Returns the data contained in the specified link
	int GetNumber(int loc){
		NODE *temp = llque;
		for (int i = 0; i < loc; ++i){ temp = temp->next_node; }
		return temp->info;
	}

	//Outputs the current Link List to std console
	void Display(){
		NODE *temp = llque;
		while (temp != NULL)	{
			cout << "\t"; (temp->info == 0) ? cout << "--" : cout << temp->info;
			temp = temp->next_node;
		}
		cout << endl;
	}

	//Returns the lowest non Zero number in the link list
	void GetNonZero(int &n){
		NODE *temp = llque;
		while (temp != NULL)	{
			if (temp->info != 0 && temp->info < n) n = temp->info;
			temp = temp->next_node;
		}
	}
};

// Finds the Perfect Fibonacci Distribution
int PFDtable(int N, int Min, LLQUE Temp, LLQUE &Create){
	for (int i = 1; i < N; ++i){ Create.Push_into_llque(1); }
	while (Create.GetTotal() < Min){
		// Create.Display(); //use to view the PFD table
		for (int i = 2; i < N; ++i){ Temp.Push_into_llque(Create.GetNumber(1) + Create.GetNumber(i)); }

		Temp.Push_into_llque(Create.GetNumber(1));
		Create = Temp;
		Temp.Clearllque(); Temp.Push_into_llque(0);
	}
	// Create.Display(); //use to view the PFD table
	return Create.GetTotal();
}

char Again(){
    char Ans;
    cout << "\nContinue(y/n)? "; cin >> Ans;
    Ans = toupper(Ans);
    if(Ans == 'Y' || Ans == 'N'){
        cout << endl;
        return Ans;
    }
    Again();
}

int main(){
	char Answer;
	do{
		int PFD_Size, num_of_items;
		LLQUE PFDset; PFDset.Clearllque(); PFDset.Push_into_llque(0);
		LLQUE TempSet; TempSet.Clearllque(); TempSet.Push_into_llque(0);

		//	Create Menu
		cout << "\t--- Perfect Fibinachi Distribution ---\n";
		cout << "\t---------------- Menu ----------------\n";
		cout << "\tEnter the number of items to sort: "; cin >> num_of_items;
		cout << "\t\tPFD of order: "; cin >> PFD_Size; PFD_Size++;

		//		Create and save the Perfect Fibinachi Distribution
		int FibTotal = PFDtable(PFD_Size, num_of_items, TempSet, PFDset);

		//		Display the the Polyphase Sort/Merge table
		cout << "\n   Sort #\tF1";	for (int i = 1; i < PFD_Size; ++i){ cout << "______T" << i; }	cout << endl;
		cout << "\t\t" << num_of_items; for (int i = 1; i < PFD_Size; ++i){ cout << "\t--"; }	cout << endl;

		//		Displays each of the record mergers
		int x = num_of_items, sortcount = 0; TempSet.Clearllque();
		while (PFDset.OneCount()){
			sortcount++;
			cout << "\t" << sortcount;	PFDset.Display();
			PFDset.GetNonZero(x);
			for (int i = 0; i < PFD_Size; ++i)
			{
				TempSet.Push_into_llque(abs(PFDset.GetNumber(i) - x));
			}
			PFDset = TempSet;
			TempSet.Clearllque();
		}
		//		Displays the location of the final sorted set
		sortcount++;
		cout << "\t" << sortcount;	PFDset.Display();

		//		Do another one
		Answer = Again();

	} while (Answer == 'Y');

	// system("pause"); // uncomment if building for windows only
	return(0);
}


