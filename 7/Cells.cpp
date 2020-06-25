//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cells.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Cells::GetKey()
{
	return key;
}

Cells* Cells::Push(int key)
{
	Cells* temp = new Cells(key);
	temp->next = this;
	return temp;
}

Cells* Cells::Pop()
{
	Cells* temp = this->next;
	delete this;
	return temp;
}

bool Cells::IsFilled()
{
    return next != NULL;
}
