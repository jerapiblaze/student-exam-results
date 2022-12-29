#pragma once

#include "Student.h"
#include "Date.h"

bool isValidPoint(float p);

Student::Student(){
	
};
Student::Student(int Id, string Fullname, Date DoB, int Gender, float Math, float Phys, float Chem){
	this->setId(Id);
	this->setFullname(Fullname);
	this->setDoB(DoB);
	this->setMath(Math);
	this->setPhys(Phys);
	this->setChem(Chem);
	this->setGender(Gender);
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
float Student::getMath(){
	return this->Math;
};
float Student::getPhys(){
	return this->Phys;
};
float Student::getChem(){
	return this->Chem;
};
int Student::getGender(){
	return this->Gender;
}
		
Student* Student::setId(int Id){
	this->Id = Id;
	return this;
};
Student* Student::setFullname(string Fullname){
	this->Fullname = Fullname;
	return this;
};
Student* Student::setDoB(Date DoB){
	this->DoB = DoB;
	return this;
};
Student* Student::setMath(float Math){
	if (isValidPoint(Math)){
		this->Math = Math;
	} else {
		this->Math = 0;
	}
	return this;
};
Student* Student::setPhys(float Phys){
	if (isValidPoint(Phys)){
		this->Phys = Phys;
	} else {
		this->Phys = 0;
	}
	return this;
};
Student* Student::setChem(float Chem){
	if (isValidPoint(Chem)){
		this->Chem = Chem;
	} else {
		this->Chem = 0;
	}
	return this;
};
Student* Student::setGender(int Gender){
	this->Gender = Gender;
	return this;
}
		
float Student::getAvg(){
	float avg = (float)(this->Math + this->Phys + this->Chem) / 3;
	return avg;
};

bool isValidPoint(float p){
	if (p > 10.0 || p < 0.0){
		return false;
	}
	return true;
};