//---------------------------------------------------------------------------

#pragma hdrstop

#include "FirmContainer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void FirmContainer::Save()
{
	TStringList *list = new TStringList;
	for (int i = 0; i < length; i++) {
		list->Add(firmArray[i].GetName());
		list->Add(firmArray[i].GetPost());
		list->Add(firmArray[i].GetSalary());
		list->Add(firmArray[i].GetVacationDays());
		list->Add(firmArray[i].GetHighEducation());
		list->Add(firmArray[i].GetAgeMin());
		list->Add(firmArray[i].GetAgeMax());
		list->Add(firmArray[i].GetPractice());
	}
	list->SaveToFile(name);
}

void FirmContainer::Add(Firm newFirm)
{
	length++;
	Firm *tempArray = new Firm[length];
	if (length == 1) {
		tempArray[0] = newFirm;
		firmArray = tempArray;
	}
	else {
		for (int i = 0; i < length - 1; i++) {
			tempArray[i] = firmArray[i];
		}
		tempArray[length - 1] = newFirm;
		firmArray = tempArray;
	}
    Save();
}

int FirmContainer::GetLength()
{
    return length;
}

UnicodeString FirmContainer::GetName(int index)
{
	return firmArray[index].GetName();
}

TStringList* FirmContainer::GetData(int index)
{
	TStringList *list = new TStringList;
	list->Add(firmArray[index].GetName());
	list->Add(firmArray[index].GetPost());
	list->Add(firmArray[index].GetSalary());
	list->Add(firmArray[index].GetVacationDays());
	list->Add(firmArray[index].GetHighEducation());
	list->Add(firmArray[index].GetAgeMin());
	list->Add(firmArray[index].GetAgeMax());
	list->Add(firmArray[index].GetPractice());
	return list;
}

void FirmContainer::DeleteFirm(int index)
{
	length--;
	Firm *tempArray = new Firm[length];
	if (length == 0) {

	}
	else
	{
		for (int i = 0, j = 0; i < length; j++) {
			if (j == index) {
				continue;
			}
			tempArray[i] = firmArray[j];
			i++;
		}
	}
	firmArray = tempArray;
	Save();
}

void FirmContainer::InsertFirm(int index, Firm firm)
{
	length++;
	Firm *tempArray = new Firm[length];
	for (int i = 0, j = 0; i < length; i++) {
		if (i == index) {
			tempArray[i] = firm;
			continue;
		}
		tempArray[i] = firmArray[j];
		j++;
	}
	firmArray = tempArray;
	Save();
}

void FirmContainer::Sort()
{
	Firm firm;
	for (int startIndex = 0; startIndex < length - 1; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
		{
			if (firmArray[currentIndex].GetName() < firmArray[smallestIndex].GetName()) {
				smallestIndex = currentIndex;
			}
		}
		firm = firmArray[startIndex];
		firmArray[startIndex] = firmArray[smallestIndex];
		firmArray[smallestIndex] = firm;
	}
	Save();
}

Firm FirmContainer::GetFirm(int index)
{
    return firmArray[index];
}