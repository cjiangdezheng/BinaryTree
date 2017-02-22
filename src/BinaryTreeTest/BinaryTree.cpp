// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <deque>

using namespace std;

typedef struct BiNode
{  
	int data;  
	struct BiNode *lchild;  
	struct BiNode *rchild;  
}BiNode, *BiTree; 


bool SearchT(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)
	{
		*p = f;
		return false;
	}
	else if(key == T->data)
	{
		*p = T;
		return true;
	}
	else if(key < T->data)
		return SearchT(T->lchild,key,T,p);
	else
		return SearchT(T->rchild,key,T,p);
}
bool InsertT(BiTree *T,int key)
{
	BiTree p,s;
	if(!SearchT(*T,key,NULL,&p))
	{
		s = (BiTree)malloc(sizeof(BiNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p)
			*T = s;
		else if(key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return true;
	}
	else
		return false;
}

bool Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
		q = NULL;
	}
	else if ((*p)->lchild == NULL)
	{
		q = *p;
		(*p) = (*p)->rchild;
		free(q);
		q = NULL;
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q != (*p))
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
		s = NULL;
	}
	return true;
}
bool DeleteT(BiTree *T,int key)
{
	if(!(*T))
		return false;
	else
	{
		if(key == (*T)->data)
			return Delete(T);
		else if(key < (*T)->data)
			return DeleteT(&(*T)->lchild,key);
		else
			return DeleteT(&(*T)->rchild,key);
	}
}
void ShowTree(BiTree T)
{
	cout << T->data << endl;
}
void DLR_T(BiTree T)
{
	if(!T)
		return;
	else
	{
		ShowTree(T);
		DLR_T(T->lchild);
		DLR_T(T->rchild);
	}
}
void LDR_T(BiTree T)
{
	if(!T)
		return;
	else
	{
		LDR_T(T->lchild);
		ShowTree(T);
		LDR_T(T->rchild);
	}
}
void LRD_T(BiTree T)
{
	if(!T)
		return;
	else
	{
		LRD_T(T->lchild);
		LRD_T(T->rchild);
		ShowTree(T);
	}
}
void TopToBottom(BiTree T)
{
	if(!T)
		return;
	BiTree temp;
	deque<BiTree> dequeBiTree;
	dequeBiTree.push_back(T);

	while(dequeBiTree.size())
	{
		temp = dequeBiTree.front();
		dequeBiTree.pop_front();
		cout << temp->data << endl;

		if (temp->lchild)
		{
			dequeBiTree.push_back(temp->lchild);
		}
		if (temp->rchild)
		{
			dequeBiTree.push_back(temp->rchild);
		}

	}
}
int main(int argc, char* argv[])
{
	BiTree T=NULL;  
	InsertT(&T,8);
	InsertT(&T,3);
	InsertT(&T,10);

	/*InsertT(&T,1);
	InsertT(&T,6);
	InsertT(&T,2);
	InsertT(&T,4);*/

	InsertT(&T,1);
	InsertT(&T,6);
	InsertT(&T,14);
	InsertT(&T,4);
	InsertT(&T,7);
	InsertT(&T,13);
	

	TopToBottom(T);
	  
	
	system("PAUSE");
	return 0;
}

