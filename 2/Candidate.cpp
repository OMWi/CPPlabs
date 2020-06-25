//---------------------------------------------------------------------------

#pragma hdrstop

#include "Candidate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Candidate::AddJobs(UnicodeString job, UnicodeString period)
{
	if (job.IsEmpty() || period.IsEmpty()) {
		return 1;
	}
	try
	{
		StrToInt(period);
	}
	catch(...)
	{
		return 2;
    }
	jobsNumber++;
	UnicodeString *tempNames = new UnicodeString[jobsNumber];
	UnicodeString *tempPeriods = new UnicodeString[jobsNumber];
	if (jobsNumber == 1) {
		tempNames[0] = job;
		tempPeriods[0] = period;
		jobsName = tempNames;
		jobsPeriod = tempPeriods;
	}
	else {
		for (int i = 0; i < jobsNumber - 1; i++) {
			tempNames[i] = jobsName[i];
			tempPeriods[i] = jobsPeriod[i];
		}
		tempNames[jobsNumber - 1] = job;
		tempPeriods[jobsNumber - 1] = period;
        jobsName = tempNames;
		jobsPeriod = tempPeriods;
	}
	return 0;
}

void Candidate::SetJobsNumber(int number)
{
	jobsNumber = number;
}

int Candidate::GetJobsNumber()
{
	return jobsNumber;
}

TStringList* Candidate::GetJobsName()
{
	TStringList *list = new TStringList;
	for (int i = 0; i < jobsNumber; i++) {
		list->Add(jobsName[i]);
	}
	return list;
}

TStringList* Candidate::GetJobsPeriod()
{
	TStringList *list = new TStringList;
	for (int i = 0; i < jobsNumber; i++) {
		list->Add(jobsPeriod[i]);
	}
	return list;
}

UnicodeString Candidate::GetNameString()
{
	UnicodeString nameString;
	for (int i = 0; i < jobsNumber; i++) {
		nameString += jobsName[i] + "|";
	}
	return nameString;
}

UnicodeString Candidate::GetPeriodString()
{
	UnicodeString periodString;
	for (int i = 0; i < jobsNumber; i++) {
		periodString += jobsPeriod[i] + "|";
	}
	return periodString;
}

void Candidate::SetJobsArrays(UnicodeString nameString, UnicodeString periodString)
{
	jobsNumber = 0;
	int pos = 1;
	while (pos <= periodString.Length())
	{
		if (periodString[pos] == '|') {
			jobsNumber++;
		}
		pos++;
	}
	UnicodeString* tempNames = new UnicodeString[jobsNumber];
	UnicodeString* tempPeriods = new UnicodeString[jobsNumber];
	for (int i = 0; i < jobsNumber ; i++) {
		tempNames[i] = nameString.SubString(1, nameString.Pos("|") - 1);
		nameString.Delete(1, nameString.Pos("|"));
		tempPeriods[i] = periodString.SubString(1, periodString.Pos("|") - 1);
		periodString.Delete(1, periodString.Pos("|"));
	}
	jobsName = tempNames;
	jobsPeriod = tempPeriods;
}


int Candidate::SetFio(UnicodeString fio)
{
	if (fio.IsEmpty()) {
		return 1;
	}
	this->fio = fio;
	return 0;
}

UnicodeString Candidate::GetFio()
{
	return fio;
}

int Candidate::SetBirthday(UnicodeString birthday)
{
	if (birthday.IsEmpty())
	{
		return 1;
	}
	birthday.Trim();
	if (birthday.Length() != 4) {
		return 2;
	}
	try
	{
		StrToInt(birthday);
	}
	catch (...)
	{
		return 3;
	}
	this->birthday = birthday;
	return 0;
}

UnicodeString Candidate::GetBirthday()
{
	return birthday;
}

int Candidate::SetHighEducation(UnicodeString highEducation)
{
	if (highEducation.IsEmpty()) {
		return 1;
	}
	if (highEducation.LowerCase() != "да" && highEducation.LowerCase() != "нет") {
		return 2;
	}
	this->highEducation = highEducation.LowerCase();
	return 0;
}

UnicodeString Candidate::GetHighEducation()
{
	return highEducation;
}

int Candidate::SetMinSalary(UnicodeString minSalary)
{
	if (minSalary.IsEmpty()) {
		return 1;
	}
	try {
		StrToInt(minSalary);	
	}
	catch (...) {
		return 2;
	}
	this->minSalary = minSalary;
	return 0;
}

UnicodeString Candidate::GetMinSalary()
{
	return minSalary;
}

int Candidate::SetDesiredPost(UnicodeString desiredPost)
{
	if (desiredPost.IsEmpty()) {
		return 1;
	}
	this->desiredPost = desiredPost;
	return 0;
}

UnicodeString Candidate::GetDesiredPost()
{
	return desiredPost;
}

void Candidate::Clear()
{
	fio = NULL;
	birthday = NULL;
	highEducation = NULL;
	desiredPost = NULL;
	minSalary = NULL;
	jobsNumber = 0;
	jobsPeriod = NULL;
	jobsName = NULL;
}
