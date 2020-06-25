//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Queue::Add(TPicture* pic)
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
}

void Queue::DeleteF()
{
	if(head == NULL) return;
	Node* temp = head->next;
	delete head;
	head = temp;
	size--;
}

void Queue::Show(int index, TImage* Image)
{
	Node* temp = tail;
	temp = head;
    if (index >= size) return;
	for (int i = 0; i < index; i++)
	{
		if(temp == NULL) return;
		temp = temp->next;
	}
	Image->Picture = temp->pic;
}
