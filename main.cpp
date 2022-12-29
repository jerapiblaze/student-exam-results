#include "MainFunctions.h"
#include "Student.h"
#include "StudentList.h"
#include "StudentNode.h"
#include "Date.h"

#include <iostream>
#include <conio.h>

using namespace std;

// global data store
StudentList db;
// global index store
Student** dbIndex = 0;
unsigned long long dbIndexSize = 0;

int main(){
	string MainMenuItems[] = {"Input", "Edit", "Delete", "Find by name", "Show full list", "Exit"};
	int usr;
	do {
		usr = Menu("Quan li diem thi", 6, MainMenuItems);
		switch(usr){
			case 1: {
				InputStudent(db);
				RebuildIndex(db, dbIndex, dbIndexSize);
				break;
			}
			case 2: {
				EditStudent(db);
				RebuildIndex(db, dbIndex, dbIndexSize);
				break;
			}
			case 3: {
				RemoveStudent(db);
				RebuildIndex(db, dbIndex, dbIndexSize);
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