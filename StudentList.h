#pragma once

#include "Student.h"
#include "StudentNode.h"

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