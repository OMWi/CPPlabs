//---------------------------------------------------------------------------

#ifndef DListH
#define DListH
//---------------------------------------------------------------------------
#endif

#include "Queue.h"

class DList : Queue
{
	Node* current;
public:
	DList():Queue()
	{
		current = NULL;
	};
	void MakeRing();
    void BreakRing();
	void ShowNext(TImage* Image);
	void Add(TPicture* pic);
	void DeleteF();
    void EnsureTail();
	~DList()
    {
		while(head)
		{
			tail = head->next;
			delete head;
			head = tail;
        }
	}
};
