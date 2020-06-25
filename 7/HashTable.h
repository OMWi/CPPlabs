//---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------
#endif

#include "Cells.h"

class HashTable
{
	int size;
	Cells** hashes;
public:
	HashTable(int size)
	{
		this->size = size;
		hashes = new Cells*[size];
		for(int i = 0; i < size; i++)
		{
			hashes[i] = new Cells();
        }
	}
	void DeleteTable();
	void Add(int key);
	void Remove(int key);
	Cells* GetCells(int index);
	void SetCells(int index, Cells* cells);
};
