//---------------------------------------------------------------------------

#ifndef CandidateContainerH
#define CandidateContainerH
//---------------------------------------------------------------------------
#endif
#include "Candidate.h"

class CandidateContainer
{
	int length;
	int candidateSize;
	UnicodeString name;
	Candidate *candidateArray;
public:
    void Save();
	void Add(Candidate newCandidate);
	Candidate GetCandidate(int index);
    void Sort();
	int GetLength();
	UnicodeString GetFio(int index);
	TStringList* GetData(int index);
	TStringList* GetPeriods(int index);
	TStringList* GetNames(int index);
	int GetJobsNumber(int index);
	void DeleteCandidate(int index);
	void InsertCandidate(int index, Candidate candidate);
	CandidateContainer()
	{
		length = 0;
		candidateSize = 7;
		name = "candidates.txt";
		TStringList *list = new TStringList;
		list->LoadFromFile(name);
		int fileLength = (list->Count) / candidateSize;
		Candidate candidate;
		if (fileLength != 0) {
			for (length = 0; length < fileLength;) {
				candidate.SetFio(list->Strings[length * candidateSize]);
				candidate.SetBirthday(list->Strings[length * candidateSize + 1]);
				candidate.SetHighEducation(list->Strings[length * candidateSize + 2]);
				candidate.SetDesiredPost(list->Strings[length * candidateSize + 3]);
				candidate.SetMinSalary(list->Strings[length * candidateSize + 4]);
				candidate.SetJobsArrays(list->Strings[length*candidateSize+5], list->Strings[length*candidateSize+6]);

				this->Add(candidate);
			}
		}
	}
};