#pragma once

#include "Date.h"

#include <iostream>

using namespace std;

class Student{
	private:
		int Id;
		string Fullname;
		Date DoB;
		int Math;
		int Phys;
		int Chem;
	public:
		Student();
		Student(int Id, string Fullname, Date DoB, int Math, int Phys, int Chem);
		
		int getId();
		string getFullname();
		Date getDoB();
		int getMath();
		int getPhys();
		int getChem();
		
		void setId(int Id);
		void setFullname(string Fullname);
		void setDoB(Date DoB);
		void setMath(int Math);
		void setPhys(int Phys);
		void setChem(int Chem);
		
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
};