#pragma once

#include "Date.h"
#include <string>

int DaysOfMonth(int m, int y);
bool LeapYear(int y);

Date::Date(){
	this->setYear(1);
	this->setMonth(1);
	this->setDay(2000);
}

Date::Date(int d = 1, int m = 1, int y = 2000){
	this->setYear(1);
	this->setMonth(1);
	this->setDay(2000);
	
	this->setYear(y);
	this->setMonth(m);
	this->setDay(d);
}

int Date::getDay(){
	return this->date;
}

int Date::getMonth(){
	return this->month;
}

int Date::getYear(){
	return this->year;
}

Date* Date::setDay(int d){
	if (d > DaysOfMonth(this->month, this->year) || d <= 0){
		return this;
	}
	this->date = d;
	return this;
}

Date* Date::setMonth(int m){
	if (m > 12 || m <= 0){
		return this;
	}
	if (m == 2){
		if (this->date > DaysOfMonth(2, this->year)){
			return this;
		}
	}
	this->month = m;
	return this;
}

Date* Date::setYear(int y){
	if (y <= 0){
		return this;
	}
	this->year = y;
	return this;
}

int DaysOfMonth(int m, int y){
	int d = 0;
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:{
			d = 31;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:{
			d = 30;
			break;
		}
		case 2:{
			if (LeapYear(y)){
				d = 29;
			} else {
				d = 28;
			}
			break;
		}
	}
	return d;
}

bool LeapYear(int y){
	if (y % 4 == 0){
		if (y % 100 == 0){
			return false;
		}
		return true;
	}
	return false;
}

string Date::toString(){
	string str = to_string(this->date) + "/" + to_string(this->month) + "/" + to_string(this->year);
	return str;
}