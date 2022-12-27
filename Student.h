#pragma once

#include "Date.h"

#include <iostream>

using namespace std;

class Student{
	private:
		int Id;
		string Fullname;
		Date DoB;
		int Gender; // 0 Male 1 Female 2 Other
		int Math;
		int Phys;
		int Chem;
	public:
		Student();
		Student(int Id, string Fullname, Date DoB, int Gender, int Math = 0, int Phys = 0, int Chem = 0);
		
		int getId();
		string getFullname();
		Date getDoB();
		int getMath();
		int getPhys();
		int getChem();
		int getGender();
		
		Student* setId(int Id);
		Student* setFullname(string Fullname);
		Student* setDoB(Date DoB);
		Student* setMath(int Math);
		Student* setPhys(int Phys);
		Student* setChem(int Chem);
		Student* setGender(int Gender);
		
		int getAvg();
};

class StudentNode{
	public:
		StudentNode* next;
		Student data;
		
		StudentNode();
		StudentNode(Student& s);	
};

class StudentList{
	private:
		StudentNode* HEAD;
	public:
		StudentList();
		
		StudentNode* addNode(Student& s);
		void removeNode(int Id);
		StudentNode* getNode(int Id);
		
		StudentNode* editNode(int Id, Student& s);
		
		StudentNode* getHead();
		
		unsigned long long getSize();
		Student** toArray();
};