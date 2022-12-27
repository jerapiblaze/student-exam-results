#include "Student.h"
#include "Date.h"

StudentList::StudentList(){
	this->HEAD = NULL;
};
		
StudentNode* StudentList::addNode(Student& s){
	StudentNode* tmp = new StudentNode(s);
	if (this->HEAD == NULL){
		this->HEAD = tmp;
		return tmp;
	}
	StudentNode* p = this->HEAD;
	while (p->next != NULL){
		if (p->data.getAvg() < tmp->data.getAvg() && p->next->data.getAvg() > tmp->data.getAvg()){
			p = p->next;
			continue;
		} else {
			break;
		}
	}
	if (p->next == NULL){
		p->next = tmp;
		tmp->next = NULL;
	} else {
		tmp->next = p->next;
		p->next = tmp;
	}
	return tmp;
};
void StudentList::removeNode(int Id){
	if (this->HEAD == NULL){
		return;
	}
	StudentNode* p = this->HEAD;
	if (p->data.getId() == Id){
		this->HEAD = p->next;
		delete p;
	}
	while (p->next != NULL){
		if (p->next->data.getId() == Id){
			StudentNode* target = p->next;
			p->next = target->next;
			delete target;
		} 
		p = p->next;
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