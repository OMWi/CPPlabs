//---------------------------------------------------------------------------

#pragma hdrstop

#include "StudentsList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void StudentsList::Add(Student* newStudent)
{
	if (!head) {
		head = newStudent;
	}
	else {
		tail->next = newStudent;
	}
	tail = newStudent;
}

void StudentsList::Add(Student* newStudent, int index)
{
	if (!head) {
		head = newStudent;
		tail = newStudent;
	} else if (index == 0) {
		newStudent->next = head;
		head = newStudent;
	} else {
		Student* current = head;
		for (int i = 1; i < index && current->next; i++) {
			current = current->next;
		}
		if (!current->next) {
			tail = newStudent;
		}
		newStudent->next = current->next;
		current->next = newStudent;
    }
}

void StudentsList::Delete(int index)
{
	if (!head) {
		return;
	}
	if (index == 0) {
		Student* oldHead = head;
		head = head->next;
		delete oldHead;
		return;
	}
	Student* prev = head;
	Student* current = head->next;
	for (int i = 1; current; i++) {
		if (i == index) {
			if(!current->next)
				tail = prev;
			prev->next = current->next;
			delete current;
			return;
		}
		prev = current;
		current = current->next;
	}
}

TStringList* StudentsList::GetData()
{
	TStringList* data = new TStringList();
	Student* current = head;
	for (;current; ) {
		data->AddStrings(current->GetInfo());
		current = current->next;
	}
	return data;
}

TStringList* StudentsList::Search(UnicodeString name)
{
	TStringList* info = new TStringList();
	Student* current = head;
	for (;current; ) {
		if (current->name == name) {
			info = current->GetInfo();
			return info;
		}
		current = current->next;
	}
	return info;
}

TStringList* StudentsList::GetBiggerIncome(float minIncome)
{
	Student* current = head;
	TStringList* info = new TStringList();
	while (current) {
		if (current->avIncome >= minIncome) {
			info->AddStrings(current->GetInfo());
		}
		current = current->next;
	}
	return info;
}

float StudentsList::GetMinIncome()
{
	Student* current = head;
	float minIncome = current->avIncome;
	while(current) {
		if (current->avIncome < minIncome) {
			minIncome = current->avIncome;
		}
		current = current->next;
	}
	return minIncome;
}

TStringList* StudentsList::GetLesserMark(float maxMark)
{
	TStringList* info = new TStringList();
	Student* current = head;
	float minIncomeX2 = GetMinIncome() * 2;
	while (current) {
		if (current->avIncome > minIncomeX2 && current->avMark < maxMark) {
			info->AddStrings(current->GetInfo());
		}
		current = current->next;
	}
	return info;
}
