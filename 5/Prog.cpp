//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Prog.h"
#include "DList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
DList* pics = new DList();

TPicture* LoadPic(UnicodeString name)
{
	TPicture* pic = new TPicture();
	pic->LoadFromFile(name);
	return pic;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	pics->ShowNext(Image);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	UnicodeString path = "pics/";
    for(int i = 1; i <= 5;i++)
	{
		pics->Add(LoadPic(path + IntToStr(i) + ".bmp"));
	}
	pics->MakeRing();
    pics->ShowNext(Image);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		pics->BreakRing();
		pics->Add(LoadPic(OpenDialog1->FileName));
		pics->MakeRing();
        pics->EnsureTail();
	}
}
//---------------------------------------------------------------------------

