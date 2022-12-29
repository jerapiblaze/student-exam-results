#pragma once

#include "Student.h"
#include "StudentList.h"
#include "StudentNode.h"
#include "Date.h"

// menu
int Menu(string menuTitle, int maxItems, string* itemsList);

// front-end input experience
void scanfStudent(Student& s);
void printfStudent(Student& s);
void scanfDate(Date& d);

// work directly with the data store
void InputStudent(StudentList& db);
void DumpList(StudentList& db);
void RemoveStudent(StudentList& db);
void EditStudent(StudentList& db);
void PrintDecendList(StudentList& db);

// work via the index store
void RebuildIndex(StudentList& db, Student**& dbIndex, unsigned long long& dbIndexSize);
void DumpIndex(Student** dbIndex, unsigned long long& dbIndexSize);
void SortIndexByAvgAsc(Student**& dbIndex, unsigned long long& dbIndexSize);
void FindStudentByName(Student**& dbIndex, unsigned long long& dbIndexSize);