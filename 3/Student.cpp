//---------------------------------------------------------------------------

#pragma hdrstop

#include "Student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TStringList* Student::GetInfo()
{
	TStringList* info = new TStringList();
	info->Add(name);
	info->Add(IntToStr(group));
	info->Add(FloatToStrF(avMark, ffGeneral, 3, 2));
	info->Add(FloatToStrF(avIncome, ffGeneral, 8, 2));
    info->Add("");
	return info;
}
