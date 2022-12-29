#pragma once

#include "Student.h"
#include "StudentNode.h"
#include "Date.h"

StudentNode::StudentNode(){
	this->next = NULL;
};
StudentNode::StudentNode(Student& s){
	this->next = NULL;
	this->data = s;
};