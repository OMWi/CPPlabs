//---------------------------------------------------------------------------

#ifndef StudentH
#define StudentH
//---------------------------------------------------------------------------
#endif

struct Student
{
	UnicodeString name;
	int group;
	float avMark;
	float avIncome;
	Student* next;
	TStringList* GetInfo();
};