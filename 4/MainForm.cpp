//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Calculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Calculator* calc = new Calculator();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	char smb = 'a';
	Edit1->Text = "a / (b + c - d*e)";
	for(int i = 0; i < 5; i++, smb++)
	{
		StringGrid1->Cells[0][i] = smb;
	}
	StringGrid1->Cells[1][0] = "7,6";
	StringGrid1->Cells[1][1] = "4,8";
	StringGrid1->Cells[1][2] = "3,5";
	StringGrid1->Cells[1][3] = "9,1";
	StringGrid1->Cells[1][4] = "0,2";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Edit2->Text = calc->Convert(Edit1->Text);
    Button2->Enabled = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	float arr[201];
	for(int i = 0; i < 5; i++)
	{
		arr[StringGrid1->Cells[0][i][1]] = StrToFloat(StringGrid1->Cells[1][i]);
	}
	Edit3->Text = calc->Calculate(Edit2->Text, arr);
}
//---------------------------------------------------------------------------
