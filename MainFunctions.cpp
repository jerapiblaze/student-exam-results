#pragma once

#include "Student.h"
#include "StudentList.h"
#include "StudentNode.h"
#include "Date.h"

#include "MainFunctions.h"

#include <conio.h>

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
	float Math;
	float Phys;
	float Chem;
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
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout.width(10);
	cout << s.getId() << '|';
	cout.width(25);
	cout << s.getFullname() << '|';
	cout.width(2);
	cout << ((s.getGender() == 0) ? "M" : (s.getGender() == 1 ? "F" : "O")) << '|';
	cout.width(12);
	cout << s.getDoB().toString() << '|';
	cout.width(6);
	cout << s.getMath() << '|';
	cout.width(6);
	cout << s.getPhys() << '|';
	cout.width(6);
	cout << s.getChem() << '|';
	cout.width(6);
	cout << s.getAvg() << '|';
	cout << endl;
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

void DumpIndex(Student**& dbIndex, unsigned long long& dbIndexSize){
	cout << "Student list" << endl;
	
	cout.width(10);
	cout << "ID" << '|';
	cout.width(25);
	cout << "Fullname" << '|';
	cout.width(2);
	cout << "G" << '|';
	cout.width(12);
	cout << "DoB" << '|';
	cout.width(6);
	cout << "Math" << '|';
	cout.width(6);
	cout << "Phys" << '|';
	cout.width(6);
	cout << "Chem" << '|';
	cout.width(6);
	cout << "Avg" << '|';
	cout << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	
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

void RebuildIndex(StudentList& db, Student**& dbIndex, unsigned long long& dbIndexSize){
	cout << "Rebuilding index...";
	if (dbIndex != 0){
		delete[] dbIndex;
	}
	dbIndexSize = db.getSize();
	dbIndex = db.toArray();
	SortIndexByAvgAsc(dbIndex,dbIndexSize);
	cout << "Completed." << endl;
};

void FindStudentByName(Student**& dbIndex, unsigned long long& dbIndexSize){
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

void SortIndexByAvgAsc(Student**& dbIndex, unsigned long long& dbIndexSize){
	// merge sort
	mergeSort(dbIndex, 0, dbIndexSize - 1);
};