//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Programm.h"
#include "StudentsList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
StudentsList* list = new StudentsList();

//TODO:Запилить проверку на ввод

void AddStudent()
{
	Student* newStudent = new Student();
	newStudent->name = Form1->Edit1->Text;
	newStudent->group = StrToInt(Form1->Edit2->Text);
	try
	{
		newStudent->avMark = StrToFloat(Form1->Edit3->Text);
	}
	catch(...)
	{
		Form1->Label1->Caption = "Неправильный ввод оценки";
		return;
	}
    try
	{
		newStudent->avIncome = StrToFloat(Form1->Edit4->Text);
	}
	catch(...)
	{
		Form1->Label2->Caption = "Неправильный ввод оценки";
		return;
	}
	list->Add(newStudent);
	Form1->Edit1->Text = "";
	Form1->Edit2->Text = "";
	Form1->Edit3->Text = "";
	Form1->Edit4->Text = "";
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Label1->Caption = "";
    Label2->Caption = "";
	AddStudent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	list->Delete(StrToInt(Edit5->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->AddStrings(list->GetData());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->AddStrings(list->Search(Edit6->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->AddStrings(list->GetBiggerIncome(StrToFloat(Edit7->Text)));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->AddStrings(list->GetLesserMark(StrToFloat(Edit8->Text)));
}
//---------------------------------------------------------------------------


