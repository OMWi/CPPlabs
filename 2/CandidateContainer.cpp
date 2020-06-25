//---------------------------------------------------------------------------

#pragma hdrstop

#include "CandidateContainer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CandidateContainer::Save()
{
	TStringList *list = new TStringList;
	for (int i = 0; i < length; i++) {
		list->Add(candidateArray[i].GetFio());
		list->Add(candidateArray[i].GetBirthday());
		list->Add(candidateArray[i].GetHighEducation());
		list->Add(candidateArray[i].GetDesiredPost());
		list->Add(candidateArray[i].GetMinSalary());
		list->Add(candidateArray[i].GetNameString());
		list->Add(candidateArray[i].GetPeriodString());
	}
	list->SaveToFile(name);
}

void CandidateContainer::Add(Candidate newCandidate)
{
	length++;
	Candidate *tempArray = new Candidate[length];
	if (length == 1) {
		tempArray[0] = newCandidate;
		candidateArray = tempArray;
	}
	else
	{
		for (int i = 0; i < length - 1; i++) {
			tempArray[i] = candidateArray[i];
		}
		tempArray[length - 1] = newCandidate;
		candidateArray = tempArray;
	}
	Save();
}

Candidate CandidateContainer::GetCandidate(int index)
{
    return candidateArray[index];
}

int CandidateContainer::GetLength()
{
	return length;
}

UnicodeString CandidateContainer::GetFio(int index)
{
	return candidateArray[index].GetFio();
}

TStringList* CandidateContainer::GetData(int index)
{
	TStringList *list = new TStringList;
	list->Add(candidateArray[index].GetFio());
	list->Add(candidateArray[index].GetBirthday());
	list->Add(candidateArray[index].GetHighEducation());
	list->Add(candidateArray[index].GetDesiredPost());
	list->Add(candidateArray[index].GetMinSalary());
	return list;
}

TStringList* CandidateContainer::GetPeriods(int index)
{
	return candidateArray[index].GetJobsPeriod();
}

TStringList* CandidateContainer::GetNames(int index)
{
	return candidateArray[index].GetJobsName();
}

int CandidateContainer::GetJobsNumber(int index)
{
	return candidateArray[index].GetJobsNumber();
}

void CandidateContainer::DeleteCandidate(int index)
{
	length--;
	Candidate *tempArray = new Candidate[length];
	if (length == 0) {

	}
	else
	{
		for (int i = 0, j = 0; i < length; j++) {
			if (j == index) {
				continue;
			}
			tempArray[i] = candidateArray[j];
			i++;
		}
	}
	candidateArray = tempArray;
	Save();
}

void CandidateContainer::InsertCandidate(int index, Candidate candidate)
{
	length++;
	Candidate *tempArray = new Candidate[length];
	for (int i = 0, j = 0; i < length; i++) {
		if (i == index) {
			tempArray[i] = candidate;
			continue;
		}
		tempArray[i] = candidateArray[j];
		j++;
	}
	candidateArray = tempArray;
    Save();
}

void CandidateContainer::Sort()
{
	Candidate candidate;
	for (int startIndex = 0; startIndex < length - 1; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
		{
			if (candidateArray[currentIndex].GetFio() < candidateArray[smallestIndex].GetFio()) {
				smallestIndex = currentIndex;
			}
		}
		candidate = candidateArray[startIndex];
		candidateArray[startIndex] = candidateArray[smallestIndex];
		candidateArray[smallestIndex] = candidate;
	}
	Save();

}