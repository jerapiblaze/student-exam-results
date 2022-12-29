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
		float Math;
		float Phys;
		float Chem;
	public:
		Student();
		Student(int Id, string Fullname, Date DoB, int Gender, float Math = 0.0, float Phys = 0.0, float Chem = 0.0);
		
		int getId();
		string getFullname();
		Date getDoB();
		float getMath();
		float getPhys();
		float getChem();
		int getGender();
		
		Student* setId(int Id);
		Student* setFullname(string Fullname);
		Student* setDoB(Date DoB);
		Student* setMath(float Math);
		Student* setPhys(float Phys);
		Student* setChem(float Chem);
		Student* setGender(int Gender);
		
		float getAvg();
};