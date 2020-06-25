//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
//---------------------------------------------------------------------------
#endif

struct Node
{
	TPicture* pic;
	Node* next;
	Node* prev;
};

class Queue
{
protected:
	Node* head;
	Node* tail;
	int size;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void Add(TPicture* pic);
	void DeleteF();
	void Show(int index, TImage* Image);
	~Queue()
	{
		while(head)
		{
			tail = head->next;
			delete head;
			head = tail;
        }
    }
};
