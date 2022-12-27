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

int main(){
	string MainMenuItems[] = {"Nhap diem", "Sua diem", "Xoa", "Tim thi sinh", "In danh sach", "Thoat"};
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
				
				break;
			}
			case 5: {
				DumpIndex(dbIndex, dbIndexSize);
				break;
			}
		}
		
		cout << "Bam phim bat ki de tiep tuc..." << endl;
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
	cout << "Dang xay dung lai chi muc...";
	if (dbIndex != 0){
		delete[] dbIndex;
	}
	dbIndexSize = db.getSize();
	dbIndex = db.toArray();
	cout << "Hoan tat." << endl;
};