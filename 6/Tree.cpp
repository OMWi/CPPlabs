//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Tree::AddNode(UnicodeString login, int id)
{
	Node* newNode = new Node(login, id);
	AddNode(newNode, &root);
}

void Tree::AddNode(Node* newNode, Node** current)
{
	if(*current == NULL)
	{
		*current = newNode;
	}
	else
	{
		if(newNode->id > (*current)->id)
		{
			AddNode(newNode, &(*current)->right);
		}
		else if(newNode->id < (*current)->id)
		{
			AddNode(newNode, &(*current)->left);
        }
	}
}

void Tree::DeleteTree(Node* node)
{
	if(node != NULL)
	{
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
	}
}

void Tree::DeleteNode(int id)
{
	if(root == NULL) return;
	DeleteNode(id, &root);
}

Node* Tree::DeleteNode(int id, Node** current)
{
	if(id < (*current)->id)
	{
		(*current)->left = DeleteNode(id, &(*current)->left);
	}
	else if(id > (*current)->id)
	{
		(*current)->right = DeleteNode(id, &(*current)->right);
	}
	else if ((*current)->left != NULL || (*current)->right != NULL)
	{
		(*current)->id = Min((*current)->right)->id;
        (*current)->login = Min((*current)->right)->login;
		(*current)->right = DeleteNode((*current)->id ,&(*current)->right);
	}
	else
	{
		if((*current)->left != NULL) (*current) = (*current)->left;
		else if((*current)->right != NULL) (*current) = (*current)->right;
		else (*current) = NULL;
	}
	return (*current);
}

Node* Tree::Min(Node* node)
{
	if(node == NULL || node->left == NULL)
	{
		return node;
	}
	return Min(node->left);
}

Node* Tree::Max(Node* node)
{
	if(node == NULL || node->right == NULL)
	{
		return node;
	}
	return Max(node->right);
}

Node* Tree::Search(int id)
{
	return Search(id, root);
}

Node* Tree::Search(int id, Node* current)
{
	if(current == NULL || current->id == id) return current;
	else if(current->id < id) return Search(id, current->right);
	else if(current->id > id) return Search(id, current->left);
}

void Tree::SortedObh(Node* current, TMemo* memo)
{
	if(current != NULL)
	{
		SortedObh(current->left, memo);
		memo->Lines->Add("login:" + current->login + "\tid:" + current->id + "\n");
		SortedObh(current->right, memo);
	}
}

void Tree::SortedObh(TMemo* memo)
{
    SortedObh(root, memo);
}

void Tree::PrObh(Node* current, TMemo* memo)
{
	if(current != NULL)
	{
		memo->Lines->Add("login:" + current->login + "\tid:" + current->id + "\n");
		PrObh(current->left, memo);
		PrObh(current->right, memo);
	}
}

void Tree::PrObh(TMemo* memo)
{
	PrObh(root, memo);
}

void Tree::ObrObh(Node* current, TMemo* memo)
{
	if(current != NULL)
	{
		ObrObh(current->left, memo);
		ObrObh(current->right, memo);
		memo->Lines->Add("login:" + current->login + "\tid:" + current->id + "\n");
	}
}

void Tree::ObrObh(TMemo* memo)
{
	ObrObh(root, memo);
}

Node* Tree::GetNearest(Node* current, Node* min, float minDist, float average)
{
    if(current != NULL)
	{
		int dist = current->id - average;
		if(dist < 0) dist = -dist;
		if(dist < minDist)
		{
			min = current;
			minDist = dist;
		}
		min = GetNearest(current->left, min, minDist, average);
		min = GetNearest(current->right, min, minDist, average);
	}
	return min;
}

Node* Tree::GetNearest()
{
	if(root == NULL) return NULL;
	float average = (float)(Max(root)->id - Min(root)->id)/2;
	int dist = root->id - average;
	if(dist < 0) dist = -dist;
	return GetNearest(root, root, dist, average);
}

void Tree::Print(TTreeView* treeView)
{
	treeView->Items->Clear();
	Print(treeView, root, -1);
}

void Tree::Print(TTreeView* treeView, Node* current, int kl)
{
	if(kl == -1)
	{
		treeView->Items->AddFirst(NULL, current->login + " | " + IntToStr(current->id));
	}
	else
	{
		treeView->Items->AddChildFirst(treeView->Items->Item[kl],
			current->login + " | " + IntToStr(current->id));
	}
	kl++;
	if(current->left != NULL)
	{
		Print(treeView, current->left, kl);
	}
	if(current->right != NULL)
	{
		Print(treeView, current->right, kl);
	}
	kl--;
}