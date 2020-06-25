//---------------------------------------------------------------------------

#pragma hdrstop

#include "HashTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void HashTable::DeleteTable()
{
    if(this == NULL) return;
	for(int i = 0; i < size; i++)
	{
		Cells* temp = hashes[i];
		while(temp->IsFilled())
		{
			temp = temp->Pop();
		}
		delete hashes[i];
	}
	delete hashes;
}

void HashTable::Add(int key)
{
	hashes[key % size] = hashes[key % size]->Push(key);
}

void HashTable::Remove(int key)
{
	int index = key % size;
	Cells* copy = new Cells();
	while(hashes[index]->IsFilled())
	{
		if(key != hashes[index]->GetKey())
			copy = copy->Push(hashes[index]->GetKey());
		hashes[index] = hashes[index]->Pop();
	}
	while(copy->IsFilled())
	{
		hashes[index] = hashes[index]->Push(copy->GetKey());
		copy = copy->Pop();
	}
	delete copy;
}

Cells* HashTable::GetCells(int index)
{
	return hashes[index];
}

void HashTable::SetCells(int index, Cells* cells)
{
	if(index < size)
	{
		hashes[index] = cells;
	}
}
