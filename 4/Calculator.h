//---------------------------------------------------------------------------

#ifndef CalculatorH
#define CalculatorH
//---------------------------------------------------------------------------
#endif

#include "Stack.h"

class Calculator
{
	Stack* tail;
	int Priority(char symb);
public:
	Calculator()
	{
		tail = NULL;
	}
	UnicodeString Convert(UnicodeString input);
	double Calculate(UnicodeString input, float arr[201]);
};