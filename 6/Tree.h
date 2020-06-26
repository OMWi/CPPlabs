//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#endif

struct Node
{
	UnicodeString login;
	int id;
	Node* left;
	Node* right;
	Node(UnicodeString login, int id)
	{
		this->login = login;
		this->id = id;
        left = right = NULL;
    }
};

class Tree
{
	Node* root;
	void DeleteTree(Node* node);
	void AddNode(Node* newNode, Node** current);
	Node* DeleteNode(int id, Node** current);
	Node* Search(int id, Node* current);
	void SortedObh(Node* current, TMemo *memo);
	void PrObh(Node* current, TMemo *memo);
	void ObrObh(Node* current, TMemo* memo);
	Node* GetNearest(Node* current, Node* min, float minDist, float average);
	void Print(TTreeView* treeView, Node* current, int kl);
	int GetAmount(int amount, Node* current);
	void FillArr(Node* current, int* arr, UnicodeString* logArr, int* index);
	void SortArr(int *arr, UnicodeString *logArr, int amount);
	void Balance(Node **current, int* intArr, UnicodeString* strArr, int start, int end);
public:
	Tree()
	{
		root = NULL;
	}
	void AddNode(UnicodeString login, int id);
	void DeleteNode(int id);
	Node* Search(int id);
	Node* Min(Node* node);
	Node* Max(Node* node);
	void SortedObh(TMemo *memo);
	void PrObh(TMemo *memo);
	void ObrObh(TMemo* memo);
	Node* GetNearest();
	void Print(TTreeView* treeView);
	void Foo();
	~Tree()
	{
		DeleteTree(root);
	}
};