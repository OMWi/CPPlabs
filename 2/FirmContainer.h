//---------------------------------------------------------------------------

#ifndef FirmContainerH
#define FirmContainerH
//---------------------------------------------------------------------------
#endif
#include "Firm.h"

class FirmContainer
{
	int length;
	int firmSize;
	Firm *firmArray;
	UnicodeString name;
public:
	void Save();
	void Sort();
	Firm GetFirm(int index);
	void Add(Firm newFirm);
	int GetLength();
	UnicodeString GetName(int index);
	TStringList* GetData(int index);
	void DeleteFirm(int index);
    void InsertFirm(int index, Firm firm);
	FirmContainer()
	{
		length = 0;
		name = "firms.txt";
		firmSize = 8;
		TStringList *list = new TStringList;
		list->LoadFromFile(name);
		int fileLength = (list->Count) / firmSize;
		Firm firm;
		if (fileLength != 0) {
			for (length = 0; length < fileLength;) {
				firm.SetName(list->Strings[length * firmSize]);
				firm.SetPost(list->Strings[length * firmSize + 1]);
				firm.SetSalary(list->Strings[length * firmSize + 2]);
				firm.SetVacationDays(list->Strings[length * firmSize + 3]);
				firm.SetHighEducation(list->Strings[length * firmSize + 4]);
				firm.SetAgeMin(list->Strings[length * firmSize + 5]);
				firm.SetAgeMax(list->Strings[length * firmSize + 6]);
				firm.SetPractice(list->Strings[length * firmSize + 7]);
				this->Add(firm);
			}
		}
	}
};