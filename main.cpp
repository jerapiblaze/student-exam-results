#include "Student.h"
#include "Date.h"

#include <iostream>
#include <conio.h>

using namespace std;

StudentList db;

int Menu(string menuTitle, int maxItems, string* itemsList);
void scanfStudent(Student& s);
void printfStudent(Student& s);
void scanfDate(Date& d);

void InputStudent(StudentList& db);
void DumpList(StudentList& db);
void RemoveStudent(StudentList& db);
void EditStudent(StudentList& db);

int main(){
	string MainMenuItems[] = {"Nhap diem", "Sua diem", "Xoa", "In danh sach", "Thoat"};
	int usr = Menu("Quan li diem thi", 5, MainMenuItems);
	do {
		switch(usr){
			case 1: {
				InputStudent(db);
				break;
			}
			case 2: {
				EditStudent(db);
				break;
			}
			case 3: {
				RemoveStudent(db);
				break;
			}
			case 4: {
				DumpList(db);
				break;
			}
		}
		getch();
		usr = Menu("Quan li diem thi", 5, MainMenuItems);
	} while (usr != 5);
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
	cout << "Math: ";
	cin >> Math;
	cout << "Phys: ";
	cin >> Phys;
	cout << "Chem: ";
	cin >> Chem;
	s = Student(Id, Fullname, DoB, Math, Phys, Chem);
};
void printfStudent(Student& s){
	cout << s.getId() << '\t' << s.getDoB().toString() << '\t' << s.getFullname() << endl;
	cout << "Avg:" << s.getAvg() << '\t' << "M:" << s.getMath() << '\t' << "P:" << s.getPhys() << '\t' << "C:" << s.getChem() << endl;
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
		printfStudent(*s);
		db.addNode(*s);
		cout << "Continue? Type / to exit\n";
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