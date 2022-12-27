#pragma once

#include <iostream>

using namespace std;

class Date{
	private:
		int date;
		int month;
		int year;
	public:
		Date();
		Date(int d, int m, int y);
		
		int getDay();
		int getMonth();
		int getYear();
		
		Date* setDay(int d);
		Date* setMonth(int m);
		Date* setYear(int y);
		
		string toString();
};