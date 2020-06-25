//---------------------------------------------------------------------------

#pragma hdrstop

#include "Firm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Firm::SetName(UnicodeString name)
{
	if (name.IsEmpty()) {
		return 1;
	}
	this->name = name;
	return 0;
}

int Firm::SetPost(UnicodeString post)
{
	if (post.IsEmpty()) {
		return 1;
	}
	this->post = post;
	return 0;
}

int Firm::SetSalary(UnicodeString salary)
{
	if (salary.IsEmpty()) {
		return 1;
	}
	try {
		StrToInt(salary);
	}
	catch (...) {
		return 2;
	}
	this->salary = salary;
	return 0;
}

int Firm::SetVacationDays(UnicodeString vacationDays)
{
	if (vacationDays.IsEmpty()) {
		return 1;
	}
	this->vacationDays = vacationDays;
	return 0;
}

int Firm::SetHighEducation(UnicodeString highEducation)
{
	if (highEducation.IsEmpty()) {
		return 1;
	}
	if (highEducation.LowerCase() != "да" && highEducation.LowerCase() != "нет") {
		return 2;
	}
	this->highEducation = highEducation;
	return 0;
}

int Firm::SetAgeMin(UnicodeString ageMin)
{
	if (ageMin.IsEmpty()) {
		return 1;
	}
    try {
		StrToInt(ageMin);
	}
	catch (...) {
		return 2;
	}
	this->ageMin = ageMin;
	return 0;
}

int Firm::SetAgeMax(UnicodeString ageMax)
{
	if (ageMax.IsEmpty()) {
		return 1;
	}
    try {
		StrToInt(ageMax);
	}
	catch (...) {
		return 2;
	}
	this->ageMax = ageMax;
	return 0;
}

int Firm::SetPractice(UnicodeString practice)
{
	if (practice.IsEmpty()) {
		return 1;
	}
	try {
		StrToInt(practice);
	}
	catch (...) {
		return 2;
	}
	this->practice = practice;
	return 0;
}

UnicodeString Firm::GetName()
{
	return name;
}

UnicodeString Firm::GetPost()
{
	return post;
}

UnicodeString Firm::GetSalary()
{
	return salary;
}

UnicodeString Firm::GetVacationDays()
{
	return vacationDays;
}

UnicodeString Firm::GetHighEducation()
{
	return highEducation;
}

UnicodeString Firm::GetAgeMin()
{
	return ageMin;
}

UnicodeString Firm::GetAgeMax()
{
	return ageMax;
}

UnicodeString Firm::GetPractice()
{
	return practice;
}

void Firm::Clear()
{
	name = NULL;
	post = NULL;
    salary = NULL;
    vacationDays = NULL;
    highEducation = NULL;
    ageMin = NULL;
    ageMax = NULL;
    practice = NULL;
}
