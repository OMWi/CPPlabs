//---------------------------------------------------------------------------

#pragma hdrstop

#include "Calculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Calculator::Priority(char symb)
{
	switch(symb){
		case '^': return 4;
		case '*': return 3;
		case '/': return 3;
		case '+': return 2;
		case '-': return 2;
		case '(': return 1;
	}
	return 0;
}

UnicodeString Calculator::Convert(UnicodeString input)
{
	UnicodeString outStr = "";
	char tempChar;
	char tempCharStr;
	int len = input.Length();

	for(int i = 1; i <= len; i++)
	{
		tempChar = input[i];
		if(tempChar == '(')
		{
			tail = tail->Push(tail, tempChar);
		}
		if(tempChar == ')')
		{
			while(tail->GetInfo() != '(')
			{
				tail = tail->Pop(tail, &tempCharStr);
				outStr += tempCharStr;
			}
			tail = tail->Pop(tail, &tempCharStr);
		}
		if(tempChar >= 'a' && tempChar <= 'e')
		{
			outStr += tempChar;
		}
		if (tempChar == '*' || tempChar == '/' || tempChar == '+' ||
				 tempChar == '-' || tempChar == '^') {
			while (tail != NULL && Priority(tail->GetInfo()) >= Priority(tempChar)){
				tail = tail->Pop(tail, &tempCharStr);
				outStr += tempCharStr;
			}
			tail = tail->Push(tail, tempChar);
		}
	}
    while(tail != NULL)
	{
		tail = tail->Pop(tail, &tempChar);
		outStr += tempChar;
	}
	return outStr;
}

double Calculator::Calculate(UnicodeString input, float arr[201])
{
	char tempChar, temp1, temp2;
	float op1, op2, result = 0;
	char smb = 'z' + 1;
	for(int i = 1; i <= input.Length();i++)
	{
		tempChar = input[i];
		if(!(tempChar == '*' || tempChar == '/' || tempChar == '+' ||
			tempChar == '-' || tempChar == '^'))
			{
				tail = tail->Push(tail, tempChar);
			}
		else
		{
			tail = tail->Pop(tail, &temp1);
			tail = tail->Pop(tail, &temp2);
			op1 = arr[temp1];
			op2 = arr[temp2];
			switch(tempChar)
			{
				case '*': result = op2 * op1; break;
				case '/': result = op2 / op1; break;
				case '-': result = op2 - op1; break;
				case '+': result = op2 + op1; break;
				case '^': result = pow(op2, op1); break;
			}
			arr[smb] = result;
			tail = tail->Push(tail, smb);
			smb++;
		}
	}
    return result;
}