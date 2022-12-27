#include "Student.h"
#include "Date.h"

bool isValidPoint(int p);

Student::Student(){
	
};
Student::Student(int Id, string Fullname, Date DoB, int Math, int Phys, int Chem){
	this->setId(Id);
	this->setFullname(Fullname);
	this->setDoB(DoB);
	this->setMath(Math);
	this->setPhys(Phys);
	this->setChem(Chem);
};
		
int Student::getId(){
	return this->Id;
};
string Student::getFullname(){
	return this->Fullname;
};
Date Student::getDoB(){
	return this->DoB;
};
int Student::getMath(){
	return this->Math;
};
int Student::getPhys(){
	return this->Phys;
};
int Student::getChem(){
	return this->Chem;
};
		
void Student::setId(int Id){
	this->Id = Id;
};
void Student::setFullname(string Fullname){
	this->Fullname = Fullname;
};
void Student::setDoB(Date DoB){
	this->DoB = DoB;
};
void Student::setMath(int Math){
	if (isValidPoint){
		this->Math = Math;
	}
};
void Student::setPhys(int Phys){
	if (isValidPoint){
		this->Phys = Phys;
	}
};
void Student::setChem(int Chem){
	if (isValidPoint){
		this->Chem = Chem;
	}
};
		
int Student::getAvg(){
	float avg = (this->Math + this->Phys + this->Chem) / 3.0;
	return avg;
};

bool isValidPoint(int p){
	if (p > 10 || p < 0){
		return false;
	}
	return true;
};