//---------------------------------------------------------------------------

#ifndef CandidateH
#define CandidateH
//---------------------------------------------------------------------------
#endif

class Candidate
{
	UnicodeString fio;
	UnicodeString birthday;
	UnicodeString highEducation;
	UnicodeString desiredPost;
	UnicodeString minSalary;
	UnicodeString *jobsName;
	UnicodeString *jobsPeriod;
	int jobsNumber;
public:
	int SetFio(UnicodeString str);
	int SetBirthday(UnicodeString str);
	int SetHighEducation(UnicodeString str);
	int SetMinSalary(UnicodeString str);
	int SetDesiredPost(UnicodeString str);
	UnicodeString GetFio();
	UnicodeString GetBirthday();
	UnicodeString GetHighEducation();
	UnicodeString GetMinSalary();
	UnicodeString GetDesiredPost();
	int AddJobs(UnicodeString job, UnicodeString period);
	void SetJobsNumber(int number);
	int GetJobsNumber();
	TStringList* GetJobsName();
	TStringList* GetJobsPeriod();
	UnicodeString GetNameString();
	UnicodeString GetPeriodString();
	void SetJobsArrays(UnicodeString nameString, UnicodeString periodString);
    void Clear();
};