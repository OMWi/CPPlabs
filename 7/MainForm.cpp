//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "HashTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int size = 0;
HashTable* table;
HashTable* table1;
HashTable* table2;

void CompsSwitch()
{
	if(Form1->btnAdd->Enabled == False)
	{
		Form1->btnAdd->Enabled = True;
		Form1->btnRemove->Enabled = True;
		Form1->edtAdd->Enabled = True;
		Form1->edtRemove->Enabled = True;
		Form1->edtRnd->Enabled = True;
		Form1->btnRnd->Enabled = True;
		Form1->edtSplit->Enabled = True;
		Form1->btnSplit->Enabled = True;
	}
	else
	{
		Form1->btnAdd->Enabled = False;
		Form1->btnRemove->Enabled = False;
		Form1->edtAdd->Enabled = False;
		Form1->edtRemove->Enabled = False;
		Form1->edtRnd->Enabled = False;
		Form1->btnRnd->Enabled = False;
		Form1->edtSplit->Enabled = False;
		Form1->btnSplit->Enabled = False;
    }
}

UnicodeString GetLine(Cells* line)
{
	UnicodeString data;
	Cells* copy = new Cells();
	while(line->IsFilled())
	{
		copy = copy->Push(line->GetKey());
		line = line->Pop();
	}
	while(copy->IsFilled())
	{
		data += IntToStr(copy->GetKey()) + " ";
		line = line->Push(copy->GetKey());
		copy = copy->Pop();
	}
	return data;
}

void PrintTable(HashTable* table, TMemo* memo)
{
	memo->Clear();
	for(int i = 0; i < size; i++)
	{
		memo->Lines->Add("table[" + IntToStr(i) + "]:"
			 + GetLine(table->GetCells(i)));
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnAddClick(TObject *Sender)
{
	if(edtAdd->Text != "")
	{
		table->Add(StrToInt(edtAdd->Text));
		edtAdd->Text = "";
		PrintTable(table, Memo1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnRemoveClick(TObject *Sender)
{
	if(edtRemove->Text != "")
	{
		table->Remove(StrToInt(edtRemove->Text));
		edtRemove->Text = "";
		PrintTable(table, Memo1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnSizeClick(TObject *Sender)
{
	if(edtSize->Text != "")
	{
		size = StrToInt(edtSize->Text);
		table = new HashTable(size);
		edtSize->Visible = False;
		btnSize->Visible = False;
		CompsSwitch();
		PrintTable(table, Memo1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnRndClick(TObject *Sender)
{
	if(edtRnd->Text != "")
	{
		srand(time(NULL));
		int amount = StrToInt(edtRnd->Text);
		for(int i = 0; i < amount; i++)
		{
            table->Add(rand()%200 + 1);
		}
		PrintTable(table, Memo1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnSplitClick(TObject *Sender)
{
	if(edtSplit->Text != "")
	{
		int key = StrToInt(edtSplit->Text);
		table1 = new HashTable(size);
		table2 = new HashTable(size);
		for(int i = 0; i < size; i++)
		{
			Cells* temp = table->GetCells(i);
			while(temp->IsFilled())
			{
				if (temp->GetKey() >= key)
				{
					table1->Add(temp->GetKey());
				}
				else
				{
					table2->Add(temp->GetKey());
				}
				temp = temp->Pop();
			}
			table->SetCells(i, temp);
		}
		PrintTable(table1, Memo1);
		PrintTable(table2, Memo2);
		Memo1->Lines->Insert(0, "K >= " + IntToStr(key));
		Memo2->Lines->Insert(0,"K < " + IntToStr(key));
        CompsSwitch();
    }
}
//---------------------------------------------------------------------------


