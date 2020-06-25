//---------------------------------------------------------------------------

#ifndef StudentsListH
#define StudentsListH
//---------------------------------------------------------------------------
#endif

#include <Student.h>

class StudentsList {
	Student* head = nullptr;
	Student* tail = nullptr;
    float GetMinIncome();
public:
	void Add(Student* newStudent);
	void Add(Student* newStudent, int index);
	void Delete(int index);
	TStringList* GetData();
	TStringList* Search(UnicodeString name);
	TStringList* GetBiggerIncome(float minIncome);
	TStringList* GetLesserMark(float maxMark);
};