//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h".h"
#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree* tree = new Tree();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(Edit1->Text != "" && Edit2->Text != "")
	{
		tree->AddNode(Edit1->Text, StrToInt(Edit2->Text));
		tree->Print(TreeView1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1->Clear();
    tree->SortedObh(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Clear();
    tree->PrObh(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Clear();
    tree->ObrObh(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Clear();
	Node* temp = tree->GetNearest();
	Memo1->Lines->Add("login:" + temp->login + "\tid:" + temp->id + "\n");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if(Edit3->Text != "")
	{
		Memo1->Clear();
		Node* temp = tree->Search(StrToInt(Edit3->Text));
		if(temp)
		{
            Memo1->Lines->Add("login:" + temp->login + "\tid:" + temp->id + "\n");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if(Edit4->Text != "")
	{
		tree->DeleteNode(StrToInt(Edit4->Text));
		tree->Print(TreeView1);
	}

}
//---------------------------------------------------------------------------

