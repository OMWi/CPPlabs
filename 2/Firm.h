//---------------------------------------------------------------------------

#ifndef FirmH
#define FirmH
//---------------------------------------------------------------------------
#endif

class Firm
{
	UnicodeString name;
	UnicodeString post;
	UnicodeString salary;
	UnicodeString vacationDays;
	UnicodeString highEducation;
	UnicodeString ageMin;
	UnicodeString ageMax;
	UnicodeString practice;
public:
	int SetName(UnicodeString str);
	int SetPost(UnicodeString str);
	int SetSalary(UnicodeString str);
	int SetVacationDays(UnicodeString str);
	int SetHighEducation(UnicodeString str);
	int SetAgeMin(UnicodeString str);
	int SetAgeMax(UnicodeString str);
	int SetPractice(UnicodeString str);
	UnicodeString GetName();
	UnicodeString GetPost();
	UnicodeString GetSalary();
	UnicodeString GetVacationDays();
	UnicodeString GetHighEducation();
	UnicodeString GetAgeMin();
	UnicodeString GetAgeMax();
	UnicodeString GetPractice();
    void Clear();
};