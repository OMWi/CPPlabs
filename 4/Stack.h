//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------
#endif

class Stack
{
	char symb;
	Stack* next;
public:
	Stack()
	{
		next = NULL;
		symb = NULL;
	}
	Stack* Push(Stack* tail, char symb);
	Stack* Pop(Stack* tail, char * symb);
	char GetInfo();
};