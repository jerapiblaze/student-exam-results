#pragma once

#include "Student.h"

class StudentNode{
	public:
		StudentNode* next;
		Student data;
		
		StudentNode();
		StudentNode(Student& s);	
};