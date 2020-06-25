//---------------------------------------------------------------------------

#pragma hdrstop

#include "DList.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

void DList::MakeRing()
{
	if(head == NULL) return;
	head->prev = tail;
	tail->next = head;
}

void DList::BreakRing()
{
	if(head == NULL) return;
	head->prev = NULL;
    tail->next = NULL;
}

void DList::ShowNext(TImage *Image)
{
	if(current == NULL) return;
	Image->Picture = current->pic;
	current = current->next;
}

void DList::Add(TPicture* pic)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->pic = pic;
	if(head != NULL)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else
	{
		temp->prev = NULL;
		head = tail = temp;
	}
	size++;
	if(size == 1) current = head;
}

void DList::DeleteF()
{
	Queue::DeleteF();
	if(head != NULL) current = current->prev;
}

void DList::EnsureTail()
{
    if(current == head) current = tail;
}
