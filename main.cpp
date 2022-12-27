#include "Student.h"
#include "Date.h"

#include <iostream>
#include <conio.h>
#include <utility>

using namespace std;

StudentList db;
Student** dbIndex = 0;
unsigned long long dbIndexSize = 0;

int Menu(string menuTitle, int maxItems, string* itemsList);
void scanfStudent(Student& s);
void printfStudent(Student& s);
void scanfDate(Date& d);

void InputStudent(StudentList& db);
void DumpList(StudentList& db);
void RemoveStudent(StudentList& db);
void EditStudent(StudentList& db);
void PrintDecendList(StudentList& db);
void RebuildIndex(StudentList& db, Student**& dbIndex);
void DumpIndex(Student** dbIndex, unsigned long long dbIndexSize);
void SortIndexByAvgAsc(Student**& dbIndex, unsigned long long dbIndexSize);
void FindStudentByName(Student**& dbIndex, unsigned long long dbIndexSize);

int main(){
	string MainMenuItems[] = {"Input", "Edit", "Delete", "Find by name", "Show full list", "Exit"};
	int usr;
	do {
		usr = Menu("Quan li diem thi", 6, MainMenuItems);
		switch(usr){
			case 1: {
				InputStudent(db);
				RebuildIndex(db, dbIndex);
				break;
			}
			case 2: {
				EditStudent(db);
				RebuildIndex(db, dbIndex);
				break;
			}
			case 3: {
				RemoveStudent(db);
				RebuildIndex(db, dbIndex);
				break;
			}
			case 4: {
				FindStudentByName(dbIndex, dbIndexSize);
				break;
			}
			case 5: {
				DumpIndex(dbIndex, dbIndexSize);
				break;
			}
		}
		
		cout << "Press any key to continue..." << endl;
		getch();
	} while (usr != 6);
	return 0;
}

int Menu(string menuTitle, int maxItems = 0, string itemsList[] = NULL){
	cout << "\033[2J\033[1;1H";
	cout << menuTitle << endl;
	if (maxItems == 0){
		return 0;
	}
	for (int i = 0; i < maxItems; i++){
		cout << "[" << i+1 << "]" << "\t" << itemsList[i] << endl;
	}
	int usr = -1;
	cout << "Choice: ";
	cin >> usr;
	while (usr < 0 || usr > maxItems){
		cout << "Invalid!" << endl;
		cin >> usr;
	}
	cout << "\033[2J\033[1;1H";
	return usr;
};

void scanfStudent(Student& s){
	int Id;
	string Fullname;
	Date DoB;
	int Gender;
	int Math;
	int Phys;
	int Chem;
	cout << "StudentId: ";
	cin >> Id;
	cout << "StudentName: ";
	cin.ignore();
	getline(cin, Fullname);
	cout << "DayOfBirth: ";
	scanfDate(DoB);
	cout << "Gender: ";
	cin >> Gender;
	cout << "Math: ";
	cin >> Math;
	cout << "Phys: ";
	cin >> Phys;
	cout << "Chem: ";
	cin >> Chem;
	s = Student(Id, Fullname, DoB, Gender, Math, Phys, Chem);
};
void printfStudent(Student& s){
	cout << "ID:" << s.getId() << "\t\t" << "Name:" << s.getFullname() << endl;
	cout << "G:" << ((s.getGender() == 0) ? "Male" : (s.getGender() == 1 ? "Female" : "Others")) << '\t' << "DoB:" << s.getDoB().toString() << endl;
	cout << "Avg:" << s.getAvg() << "\t\t" << "M:" << s.getMath() << '\t' << "P:" << s.getPhys() 	<< '\t' << "C:" << s.getChem() << endl;
	cout << "----" << endl;
};
void scanfDate(Date& d){
	int day, month, year;
	cout << "Input date (DD MM YYYY): ";
	cin >> day;
	cin >> month;
	cin >> year;
	d = Date(day, month, year);
};

void InputStudent(StudentList& db){
	Menu("Input Student List");
	char usr = '\0';
	while (usr != '/'){
		Student* s = new Student();
		scanfStudent(*s);
		db.addNode(*s);
		cout << "--ReCheck Info--" << endl;
		printfStudent(db.getHead()->data);
		cout << "Continue? Type / to exit" << endl;
		usr = getch();
	}
};

void DumpList(StudentList& db){
	Menu("Student List");
	StudentNode* p = db.getHead();
	while (p != NULL){
		printfStudent(p->data);
		p = p->next;
	}
};

void DumpIndex(Student** dbIndex, unsigned long long dbIndexSize){
	cout << "Student list" << endl;
	for (unsigned long long i = 0; i < dbIndexSize; i++){
		printfStudent(*dbIndex[i]);
	}	
};

void EditStudent(StudentList& db){
	Menu("Edit Student");
	Student* s = new Student();
	scanfStudent(*s);
	db.editNode(s->getId(), *s);
};

void RemoveStudent(StudentList& db){
	Menu("Remove Student");
	int Id;
	cout << "StudentId: ";
	cin >> Id;
	db.removeNode(Id);
};

void RebuildIndex(StudentList& db, Student**& dbIndex){
	cout << "Rebuilding index...";
	if (dbIndex != 0){
		delete[] dbIndex;
	}
	dbIndexSize = db.getSize();
	dbIndex = db.toArray();
	SortIndexByAvgAsc(dbIndex,dbIndexSize);
	cout << "Completed." << endl;
};

void FindStudentByName(Student**& dbIndex, unsigned long long dbIndexSize){
	cout << "Find by name" << endl;
	string input;
	cout << "Name: ";
	cin.ignore();
	getline(cin, input);
	// brute-force find
	for (unsigned long long i = 0; i < dbIndexSize - 1; i++){
		if (dbIndex[i]->getFullname().find(input) != string::npos){
			printfStudent(*dbIndex[i]);
		}
	}	
};

void merge(Student* a[], unsigned long long lo1, unsigned long long hi1, unsigned long long lo2, unsigned long long hi2){
	unsigned long long tmpSize = hi2-lo2+hi1-lo1+2;
	Student* tmpArr[tmpSize];
	unsigned long long tmpInd = 0, ind1 = lo1, ind2 = lo2;
	while ((ind1 <= hi1) && (ind2 <= hi2)){
		if (a[ind1]->getAvg() > a[ind2]->getAvg()){
			tmpArr[tmpInd++] = a[ind1++];
		} else {
			tmpArr[tmpInd++] = a[ind2++];
		}
	}
	while (ind1 <= hi1){
		tmpArr[tmpInd++] = a[ind1++];
	}
	while (ind2 <= hi2){
		tmpArr[tmpInd++] = a[ind2++];
	}
	tmpInd = 0;
	for (ind1 = lo1; ind1 <= hi1; ind1++){
		a[ind1] = tmpArr[tmpInd++];
	}
	for (ind2 = lo2; ind2 <= hi2; ind2++){
		a[ind2] = tmpArr[tmpInd++];
	}
}

void mergeSort(Student* a[], unsigned long long lo, unsigned long long hi){
	if (lo < hi){
		unsigned long long mid = (lo+hi)/2;
		mergeSort(a, lo, mid);
		mergeSort(a, mid+1, hi);
		merge(a, lo, mid, mid+1, hi);
	}
}

void SortIndexByAvgAsc(Student**& dbIndex, unsigned long long dbIndexSize){
	// merge sort
	mergeSort(dbIndex, 0, dbIndexSize - 1);
};