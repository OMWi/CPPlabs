//---------------------------------------------------------------------------

#ifndef CellsH
#define CellsH
//---------------------------------------------------------------------------
#endif

class Cells
{
	int key;
	Cells* next;
public:
	Cells()
	{
		next = NULL;
		key = NULL;
	}
	Cells(int key)
	{
		this->key = key;
        next = NULL;
	}
	int GetKey();
	Cells* Push(int key);
	Cells* Pop();
    bool IsFilled();
};
