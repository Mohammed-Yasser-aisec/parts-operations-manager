
#include<iostream>
#include<string>
#include<limits>
using namespace std;
class part {
public: int ID; string name, category, statues;

};
class arr {
public: int capacity = 2, count = 0;
	  int logcapacity = 2, logcount = 0;
	  part* arr1 = nullptr;
	  string* Dynamic = nullptr;

	  arr() {
		  arr1 = new part[capacity];
		  Dynamic = new string[logcapacity];
	  }
	  ~arr() {
		  delete[]arr1;
		  delete[]Dynamic;
	  }
	  void expand() {
		  int oldcapacity = capacity;
		  capacity *= 2;
		  part* newarr1 = new part[capacity];
		  for (int i = 0; i < oldcapacity; i++) { newarr1[i] = arr1[i]; }
		  delete[]arr1;
		  arr1 = newarr1;
	  }
	  void logexpand() {
		  int oldlogcapacity = logcapacity;
		  logcapacity *= 2;
		  string* newDynamic = new string[logcapacity];
		  for (int i = 0; i < oldlogcapacity; i++) { newDynamic[i] = Dynamic[i]; }
		  delete[]Dynamic;
		  Dynamic = newDynamic;
	  }




	  void Add() {
		  if (count == capacity)expand();
		  cout << "Enter the part" << endl;
		  cout << "Enter the ID: " << endl;
		  int id; bool B;
		  do {
			  B = false;
			  cin >> id;
			  for (int i = 0; i < count; i++) { if (id == arr1[i].ID) { cout << "The ID is repeated , Enter new ID: "; B = true; break; } }
		  } while (B == true);
		  arr1[count].ID = id; stat = "Adding the part , ID is " + to_string(arr1[count].ID); logadd(stat);


		  cin.ignore(numeric_limits<streamsize>::max(), '\n');

		  cout << "Enter the name: " << endl; getline(cin, arr1[count].name);
		  cout << "Enter the category" << endl; getline(cin, arr1[count].category); cout << "choose the statues , 1- available , 2- non available" << endl; int ch;
		  cin >> ch;
		  if (ch == 1) { arr1[count].statues = "availble"; cout << endl; }
		  else if (ch == 2) { arr1[count].statues = "non availble"; cout << endl; }
		  count++;

	  }
	  string stat;

	  void logadd(string message) {
		  if (logcount == logcapacity)logexpand();
		  Dynamic[logcount] = message; logcount++;
	  }


	  void Viewall() {
		  if (count == 0) {
			  cout << "Nothing parts"; return;
	  }
		  int c = 1; for (int i = 0; i < count; i++) {
			  cout << "The part " + to_string(c); c++; cout << endl;
			  cout << "The ID: " << arr1[i].ID << "\t"; cout << "The name: " << arr1[i].name << "\t"; cout << "The category: " << arr1[i].category << "\t"
				  << "The Statues: " << arr1[i].statues << "\t" << "\n\n\n";

		  }
		  stat = "View all parts"; logadd(stat);
	  }
	  void Viewspecific() {
		  if (count == 0) { cout << "Nothing parts"; return; }
		  int id; bool b;
		  do {
			  b = false;
			  cout << "Enter the ID: " << endl;
			  cin >> id;
			  for (int i = 0; i < count; i++) {
				  if (id == arr1[i].ID) {
					  b = true;
					  cout << "The ID: " << arr1[i].ID << "\t" << "The name: " << arr1[i].name << "\t"
						  << "The category: " << arr1[i].category << "\t" << "The Statues: " << arr1[i].statues; stat = "View the part , ID is " + to_string(arr1[i].ID); logadd(stat);
					  break;
				  }
			  }
			  if (b == false) cout << "Unavailable ID";

		  } while (b == false);

	  }
	  void Update() {
		  bool B = false;
		  int id; cout << "Enter the part ID: "; cin >> id;
		  int C;
		  int b;

		  for (int i = 0; i < count; i++) {

			  if (id == arr1[i].ID) {
				  B = true;
				  cout << "Do you want to 1- update the entire part, or 2- just a portion of it ?\n";

				  cin >> C;
				  if (C == 1) {
					  cout << "Enter the new ID: "; bool B;   do {
						  cin >> b;  B = false; for (int j = 0; j < count; j++) {
							  if (j != i && arr1[j].ID == b) {
								  cout << "The new ID is repeated , Enter another ID: ";
								  B = true;
								  break;
							  }
						  }
					  } while (B == true); arr1[i].ID = b;
					  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  cout << "\t";
					  cout << "Enter the new name: "; getline(cin, arr1[i].name); cout << "\t";
					  cout << "Enter the new category: "; getline(cin, arr1[i].category); cout << "\t";
					  cout << "Enter the new statues: "; getline(cin, arr1[i].statues); cout << endl;
					  stat = "Update for part , ID is " + to_string(arr1[i].ID); logadd(stat);
				  }
				  else if (C == 2) {
					  cout << "What would you like to update? 1- ID , 2- name , 3- category , 4- statues\n";
					  int c; cin >> c;
					  if (c == 1) {
						  bool B; cout << "Enter the new ID: "; do {
							  cin >> b;  B = false; for (int j = 0; j < count; j++) {
								  if (j != i && arr1[j].ID == b) {
									  cout << "The new ID is repeated , Enter another ID: ";
									  B = true;
									  break;
								  }
							  }
						  } while (B == true); arr1[i].ID = b; stat = "Update the ID for this part , ID is " + to_string(arr1[i].ID); logadd(stat);
					  }






					  else if (c == 2) {
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');

						  cout << "Enter the new name: "; getline(cin, arr1[i].name); stat = "Update the name for this part , ID is " + to_string(arr1[i].ID); logadd(stat);
					  }
					  else if (c == 3) {
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
						  cout << "Enter the new category: "; getline(cin, arr1[i].category); stat = "Update the category for this part , ID is " + to_string(arr1[i].ID); logadd(stat);
					  }
					  else if (c == 4) {
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
						  cout << "Enter the new statues: "; getline(cin, arr1[i].statues); stat = "Update the statues for this part , ID is " + to_string(arr1[i].ID); logadd(stat);
					  }
					  break;

				  }

			  }
		  }
		  if (B == false)cout << "Unavailable ID: ";

	  }
	  void Remove() {
		  if (count == 0) { cout << "Nothing parts"; return; }
		  int id; cout << "Enter the part ID you want to delete: ";
		  bool B; do {
			  B = false;  cin >> id;


			  for (int i = 0; i < count; i++) {
				  if (id == arr1[i].ID) {
					  B = true;
					  stat = "Remove for the part this ID is " + to_string(arr1[i].ID); logadd(stat);
					  for (int j = i; j < count - 1; j++) { arr1[j] = arr1[j + 1]; }count--; break;
				  }

			  }
			  if (B == false) cout << "Un availablable ID , Enter available ID: ";

		  }

		  while (B == false);
	  }
	  void Dynamiclog() { if (logcount == 0) { cout << "Nothing operations"; return; } cout << "The dynamic log: \n"; for (int i = 0; i < logcount; i++) { cout << Dynamic[i] << "\t"; } }

};




int main() {
	cout << "WELCOME TO THE OPERATIONS MANAGEMENT PROGRAM FOR PARTS ! " << endl;
	cout << "Choose from list:  " << endl;
	cout << "1- Add part" << endl;
	cout << "2- View all parts" << endl;
	cout << "3- View specific part" << endl;
	cout << "4- Update" << endl;
	cout << "5- Remove" << endl;
	cout << "6- Dynamic log" << endl;
	cout << "7- Log out" << endl;
	arr A1;
	int choose;
	while (true) {
		cin >> choose;


		if (choose == 1) A1.Add();
		else if (choose == 2) A1.Viewall();
		else if (choose == 3) A1.Viewspecific();
		else if (choose == 4) A1.Update();
		else if (choose == 5) A1.Remove();
		else if (choose == 6) A1.Dynamiclog();
		else if (choose == 7) break;
		else { cout << "Wrong choice , try again" << endl; continue; }
	}
	return 0;
}