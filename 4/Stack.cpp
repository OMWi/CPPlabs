//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Stack* Stack::Push(Stack* tail, char symb)
{
	Stack* temp = new Stack;
	temp->symb = symb;
	temp->next = tail;
	return temp;
}

Stack* Stack::Pop(Stack* tail, char* symb)
{
	Stack* temp = tail;
	*symb = tail->symb;
	temp = temp->next;
	delete tail;
	return temp;
}

char Stack::GetInfo()
{
    return symb;
}
