//---------------------------------------------------------------------------

#include <vcl.h>
#include <ctime>
#pragma hdrstop

#include "Unit1.h"
#include "CandidateContainer.h"
#include "FirmContainer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Candidate candidate;
CandidateContainer candidates;
Firm firm;
FirmContainer firms;
UnicodeString jobs;
bool candidateEdit = false;
bool firmEdit = false;

void ActivateGroup1()
{
	Form1->ComboBox1->Style = csDropDown;
	Form1->Edit1->ReadOnly = False;
	Form1->Edit2->ReadOnly = False;
	Form1->Edit3->ReadOnly = False;
	Form1->Edit4->ReadOnly = False;
	Form1->Button1->Enabled = True;
	Form1->ComboBox3->Style = csDropDown;
	Form1->Edit12->ReadOnly = False;
	Form1->Button3->Enabled = True;
}

void DeactivateGroup1()
{
	Form1->ComboBox1->Style = csDropDownList;
	Form1->Edit1->ReadOnly = True;
	Form1->Edit2->ReadOnly = True;
	Form1->Edit3->ReadOnly = True;
	Form1->Edit4->ReadOnly = True;
	Form1->Button1->Enabled = False;
	Form1->ComboBox3->Style = csDropDownList;
	Form1->Edit12->ReadOnly = True;
	Form1->Button3->Enabled = False;
}

void ActivateGroup2()
{
	Form1->ComboBox2->Style = csDropDown;
	Form1->Edit5->ReadOnly = False;
	Form1->Edit6->ReadOnly = False;
	Form1->Edit7->ReadOnly = False;
	Form1->Edit8->ReadOnly = False;
	Form1->Edit9->ReadOnly = False;
	Form1->Edit10->ReadOnly = False;
	Form1->Edit11->ReadOnly = False;
	Form1->Button2->Enabled = True;
}

void DeactivateGroup2()
{
	Form1->ComboBox2->Style = csDropDownList;
	Form1->Edit5->ReadOnly = True;
	Form1->Edit6->ReadOnly = True;
	Form1->Edit7->ReadOnly = True;
	Form1->Edit8->ReadOnly = True;
	Form1->Edit9->ReadOnly = True;
	Form1->Edit10->ReadOnly = True;
	Form1->Edit11->ReadOnly = True;
	Form1->Button2->Enabled = False;
}

UnicodeString GetCurrentYear()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char buffer[6];
	strftime(buffer, 6, "%Y", timeinfo);
	UnicodeString currentYear;
	int i = 0;
	while (buffer[i] != '\0')
	{
		currentYear += buffer[i];
		i++;
	}
	return currentYear;
}

void ShowPossibleCandidates()
{
	Form1->Memo1->Lines->Clear();
	int index = Form1->ComboBox2->ItemIndex - 1;
	if (index < 0) {
		return;
	}
	Firm tempFirm = firms.GetFirm(index);
	Candidate tempCandidate;
	TStringList *jobsPeriod = new TStringList;
	UnicodeString post = tempFirm.GetPost();
	post.LowerCase();
	for (int candidateIndex = 0; candidateIndex < candidates.GetLength(); candidateIndex++) {
		tempCandidate = candidates.GetCandidate(candidateIndex);
		if (tempCandidate.GetMinSalary().ToInt() > tempFirm.GetSalary().ToInt()) {
			continue;
		}
		if (tempFirm.GetHighEducation().LowerCase() == "да") {
			if (tempCandidate.GetHighEducation().LowerCase() == "нет") {
				continue;
			}
		}

		int age = GetCurrentYear().ToInt() - tempCandidate.GetBirthday().ToInt();
		if (age < tempFirm.GetAgeMin().ToInt() || age > tempFirm.GetAgeMax().ToInt()) {
			continue;
		}
		jobsPeriod = tempCandidate.GetJobsPeriod();
		if (tempCandidate.GetDesiredPost().LowerCase() == post) {
			int practice = 0;
			for (int i = 0; i < tempCandidate.GetJobsNumber(); i++) {
				practice += jobsPeriod->Strings[i].ToInt();
			}
			if (practice >= tempFirm.GetPractice()) {
				Form1->Memo1->Lines->Add(tempCandidate.GetFio());
			}
		}
	}
}

void ShowScarcePosts()
{
	Form1->Memo1->Lines->Clear();
	Firm tempFirm;
	Candidate tempCandidate;
	TStringList *jobsPeriod = new TStringList;
	for (int firmIndex = 0; firmIndex < firms.GetLength(); firmIndex++) {
		tempFirm = firms.GetFirm(firmIndex);
		bool candidateFound = false;
		for (int candidateIndex = 0; candidateIndex < candidates.GetLength(); candidateIndex++) {
			tempCandidate = candidates.GetCandidate(candidateIndex);
			if (tempCandidate.GetMinSalary().ToInt() > tempFirm.GetSalary().ToInt()) {
				continue;
			}
			if (tempFirm.GetHighEducation().LowerCase() == "да") {
				if (tempCandidate.GetHighEducation().LowerCase() == "нет") {
					continue;
				}
			}
			int age = GetCurrentYear().ToInt() - tempCandidate.GetBirthday().ToInt();
			if (age < tempFirm.GetAgeMin().ToInt() || age > tempFirm.GetAgeMax().ToInt()) {
				continue;
			}
			jobsPeriod = tempCandidate.GetJobsPeriod();
			if (tempCandidate.GetDesiredPost().LowerCase() == tempFirm.GetPost().LowerCase()) {
				int practice = 0;
				for (int i = 0; i < tempCandidate.GetJobsNumber(); i++) {
					practice += jobsPeriod->Strings[i].ToInt();
				}
				if (practice >= tempFirm.GetPractice()) {
					candidateFound = true;
					break;
				}
			}
		}
		if (!candidateFound) {
			Form1->Memo1->Lines->Add(tempFirm.GetName());
		}
	}
}

void ShowWorklessCandidates()
{
	Form1->Memo1->Lines->Clear();
	Firm tempFirm;
	Candidate tempCandidate;
	TStringList *jobsPeriod = new TStringList;
	for (int candidateIndex = 0; candidateIndex < candidates.GetLength(); candidateIndex++) {
		tempCandidate = candidates.GetCandidate(candidateIndex);
		bool jobFound = false;
		int age = GetCurrentYear().ToInt() - tempCandidate.GetBirthday().ToInt();
		int practice = 0;
		jobsPeriod = tempCandidate.GetJobsPeriod();
		for (int i = 0; i < tempCandidate.GetJobsNumber(); i++) {
			practice += jobsPeriod->Strings[i].ToInt();
		}
		for (int firmIndex = 0; firmIndex < firms.GetLength(); firmIndex++) {
			tempFirm = firms.GetFirm(firmIndex);
			if (tempCandidate.GetMinSalary().ToInt() > tempFirm.GetSalary().ToInt()) {
				continue;
			}
			if (tempFirm.GetHighEducation().LowerCase() == "да") {
				if (tempCandidate.GetHighEducation().LowerCase() == "нет") {
					continue;
				}
			}
			if (age < tempFirm.GetAgeMin().ToInt() || age > tempFirm.GetAgeMax().ToInt()) {
				continue;
			}
			if (tempCandidate.GetDesiredPost().LowerCase() == tempFirm.GetPost().LowerCase()) {
				if (practice >= tempFirm.GetPractice()) {
					jobFound = true;
					break;
				}
			}
		}
		if (!jobFound) {
			Form1->Memo1->Lines->Add(tempCandidate.GetFio());
		}
	}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	candidate.SetFio(ComboBox1->Text);
	candidate.SetBirthday(Edit1->Text);
	candidate.SetHighEducation(Edit2->Text);
	candidate.SetDesiredPost(Edit3->Text);
	candidate.SetMinSalary(Edit4->Text);
	candidates.Add(candidate);
	candidate.Clear();
	ComboBox3->Items->Clear();
	ComboBox3->Items->Add("Новая должность");
	ComboBox1->Items->Add(ComboBox1->Text);
	ComboBox1->ItemIndex = 0;
    ComboBox1->OnSelect(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	firm.SetName(ComboBox2->Text);
	firm.SetPost(Edit5->Text);
	firm.SetSalary(Edit6->Text);
	firm.SetVacationDays(Edit7->Text);
	firm.SetHighEducation(Edit8->Text);
	firm.SetAgeMin(Edit9->Text);
	firm.SetAgeMax(Edit10->Text);
	firm.SetPractice(Edit11->Text);
	firms.Add(firm);
	firm.Clear();
	ComboBox2->Items->Add(ComboBox2->Text);
	ComboBox2->ItemIndex = 0;
	ComboBox2->OnSelect(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Select(TObject *Sender)
{
	if (ComboBox1->ItemIndex == 0 || ComboBox1->ItemIndex == -1) {
		ActivateGroup1();
		Edit1->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
		candidate.SetJobsNumber(0);
		ComboBox3->Items->Clear();
		ComboBox3->Items->Add("Новая должность");
		ComboBox3->ItemIndex = 0;
		Edit12->Text = "";
	}
	else {
		DeactivateGroup1();
		TStringList *candidateList = new TStringList;
		candidateList = candidates.GetData(ComboBox1->ItemIndex - 1);
		candidate.SetJobsNumber(candidates.GetJobsNumber(ComboBox1->ItemIndex - 1));
		Edit1->Text = candidateList->Strings[1];
		Edit2->Text = candidateList->Strings[2];
		Edit3->Text = candidateList->Strings[3];
		Edit4->Text = candidateList->Strings[4];
		ComboBox3->Items->Clear();
		ComboBox3->Items->AddStrings(candidates.GetNames(ComboBox1->ItemIndex - 1));
		ComboBox3->ItemIndex = 0;
		Edit12->Text = candidates.GetPeriods(ComboBox1->ItemIndex - 1)->Strings[ComboBox3->ItemIndex];
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Select(TObject *Sender)
{
	if (ComboBox2->ItemIndex == 0 || ComboBox2->ItemIndex == -1) {
		ActivateGroup2();
		Edit5->Text = "";
		Edit6->Text = "";
		Edit7->Text = "";
		Edit8->Text = "";
		Edit9->Text = "";
		Edit10->Text = "";
		Edit11->Text = "";
	}
	else {
		DeactivateGroup2();
		TStringList* firmList = new TStringList;
		firmList = firms.GetData(ComboBox2->ItemIndex - 1);
		Edit5->Text = firmList->Strings[1];
		Edit6->Text = firmList->Strings[2];
		Edit7->Text = firmList->Strings[3];
		Edit8->Text = firmList->Strings[4];
		Edit9->Text = firmList->Strings[5];
		Edit10->Text = firmList->Strings[6];
		Edit11->Text = firmList->Strings[7];
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	for (int i = 0; i < firms.GetLength(); i++) {
		ComboBox2->Items->Add(firms.GetName(i));
	}
	for (int i = 0; i < candidates.GetLength(); i++) {
		ComboBox1->Items->Add(candidates.GetFio(i));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	candidate.AddJobs(ComboBox3->Text, Edit12->Text);
	ComboBox3->Items->Add(ComboBox3->Text);
	ComboBox3->ItemIndex = 1;
	ComboBox3->OnSelect(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Select(TObject *Sender)
{
	if (ComboBox1->ItemIndex > 0) {
		Edit12->Text = candidates.GetPeriods(ComboBox1->ItemIndex - 1)->Strings[ComboBox3->ItemIndex];

	}
	else if (ComboBox3->ItemIndex == 0 || ComboBox3->ItemIndex == -1) {
		ComboBox3->Style = csDropDown;
		Edit12->ReadOnly = False;
		Edit12->Text = "";
	}
	else {
		ComboBox3->Style = csDropDownList;
		Edit12->ReadOnly = True;
		Edit12->Text = candidate.GetJobsPeriod()->Strings[ComboBox3->ItemIndex - 1];
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if (ComboBox1->ItemIndex > 0) {
		int index = ComboBox1->ItemIndex;
		candidates.DeleteCandidate(ComboBox1->ItemIndex - 1);
		ComboBox1->Items->Delete(ComboBox1->ItemIndex);
		ComboBox1->ItemIndex = index - 1;
        ComboBox1->OnSelect(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	if (ComboBox2->ItemIndex > 0) {
		int index = ComboBox2->ItemIndex;
		firms.DeleteFirm(ComboBox2->ItemIndex - 1);
		ComboBox2->Items->Delete(ComboBox2->ItemIndex);
		ComboBox2->ItemIndex = index - 1;
		ComboBox2->OnSelect(Sender);
	}
}
//---------------------------------------------------------------------------

int indexCandidate;
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if (ComboBox1->ItemIndex > 0) {

		if (!candidateEdit) {
			ActivateGroup1();
			ComboBox1->Visible = False;
			Edit13->Text = ComboBox1->Text;
			Edit13->Visible = True;
			ComboBox3->Style = csDropDownList;
			Edit12->ReadOnly = true;
			Button6->Caption = "Confirm changes";
			candidateEdit = true;
			indexCandidate = ComboBox1->ItemIndex - 1;
		}
		else {
			DeactivateGroup1();
			ComboBox1->Visible = True;
			ComboBox1->Items->Strings[indexCandidate + 1] = Edit13->Text;
			ComboBox1->ItemIndex = indexCandidate + 1;
			Edit13->Visible = False;
			candidate = candidates.GetCandidate(indexCandidate);
			candidate.SetFio(Edit13->Text);
			candidate.SetBirthday(Edit1->Text);
			candidate.SetHighEducation(Edit2->Text);
			candidate.SetDesiredPost(Edit3->Text);
			candidate.SetMinSalary(Edit4->Text);
			candidates.DeleteCandidate(indexCandidate);
			candidates.InsertCandidate(indexCandidate, candidate);
			Button6->Caption = "Edit";
			candidateEdit = false;
		}
	}
}
//---------------------------------------------------------------------------

int indexFirm;
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if (ComboBox2->ItemIndex > 0) {

		if (!firmEdit) {
			ActivateGroup2();
			ComboBox2->Visible = False;
			Edit14->Text = ComboBox2->Text;
			Edit14->Visible = True;
			Button7->Caption = "Confirm changes";
			firmEdit = true;
			indexFirm = ComboBox2->ItemIndex - 1;
		}
		else {
			DeactivateGroup2();
			ComboBox2->Visible = True;
			ComboBox2->Items->Strings[indexFirm + 1] = Edit14->Text;
			ComboBox2->ItemIndex = indexFirm + 1;
			Edit14->Visible = False;
			firm.SetName(ComboBox2->Text);
			firm.SetPost(Edit5->Text);
			firm.SetSalary(Edit6->Text);
			firm.SetVacationDays(Edit7->Text);
			firm.SetHighEducation(Edit8->Text);
			firm.SetAgeMin(Edit9->Text);
			firm.SetAgeMax(Edit10->Text);
			firm.SetPractice(Edit11->Text);
			firms.DeleteFirm(indexFirm);
			firms.InsertFirm(indexFirm, firm);
			Button7->Caption = "Edit";
			firmEdit = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	firms.Sort();
	ComboBox2->Items->Clear();
	ComboBox2->Items->Add("Новая фирма");
	for (int i = 0; i < firms.GetLength(); i++) {
		ComboBox2->Items->Add(firms.GetName(i));
	}
	ComboBox2->ItemIndex = 0;
	ActivateGroup2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	candidates.Sort();
	ComboBox1->Items->Clear();
	ComboBox1->Items->Add("Новый кандидат");
	for (int i = 0; i < candidates.GetLength(); i++) {
		ComboBox1->Items->Add(candidates.GetFio(i));
	}
	ComboBox1->ItemIndex = 0;
	ComboBox1->OnSelect(Sender);
	ActivateGroup1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
    ShowPossibleCandidates();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->LoadFromFile("candidates.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->LoadFromFile("firms.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	ShowScarcePosts();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	ShowWorklessCandidates();
}
//---------------------------------------------------------------------------

