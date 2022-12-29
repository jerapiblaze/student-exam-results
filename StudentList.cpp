#pragma once

#include "Student.h"
#include "Date.h"

#include "StudentList.h"
#include "StudentNode.h"

StudentList::StudentList(){
	this->HEAD = NULL;
};
		
StudentNode* StudentList::addNode(Student& s){
	StudentNode* tmp = new StudentNode(s);
	tmp->next = this->HEAD;
	this->HEAD = tmp;
	return tmp;
};
void StudentList::removeNode(int Id){
	if (this->HEAD == NULL){
		return;
	}
	StudentNode* tmp;
	if (this->HEAD->data.getId() == Id){
		tmp = this->HEAD;
		this->HEAD = this->HEAD->next;
		delete tmp;
		return;
	}
	StudentNode* p = this->HEAD;
	while (p->next != NULL){
		if (p->next->data.getId() == Id){
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		} else {
			p = p->next;
		}
	}
	
};
StudentNode* StudentList::getNode(int Id){
	if (this->HEAD == NULL){
		return NULL;
	}
	StudentNode* p = HEAD;
	while (p != NULL){
		if (p->data.getId() == Id){
			return p;
		}
		p = p->next;
	}
	return NULL;
};
		
StudentNode* StudentList::editNode(int Id, Student& s){
	this->removeNode(Id);
	return this->addNode(s);
};
		
StudentNode* StudentList::getHead(){
	return this->HEAD;
};

unsigned long long StudentList::getSize(){
	if (this->HEAD == NULL){
		return 0;
	}
	StudentNode* p = this->HEAD;
	unsigned long long Size = 0;
	while (p != NULL){
		Size++;
		p = p->next;
	}
	return Size;
};
Student** StudentList::toArray(){
	unsigned long long Size = this->getSize();
	unsigned long long i = 0;
	if (Size == 0){
		return NULL;
	}
	Student** Arr = new Student*[Size];
	StudentNode* p = this->HEAD;
	while (p != NULL){
		Arr[i++] = &(p->data);
		p = p->next;
	}
	return Arr;
};