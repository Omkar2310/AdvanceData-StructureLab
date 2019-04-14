//============================================================================
// Name        : tbt.cpp
// Author      : OMKAR MANKAR
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node *left,*right;
	int lbit,rbit;
	node(int x)
	{
		data=x;
		left=right=NULL;
		lbit=rbit=0;
	}
};
class tbt
{
	node *head;
	node *root;
public:
	tbt()
	{
		head=NULL;
		root=NULL;
	}

	void createtbt(int x)
	{

		if(root==NULL)
		{
			head=new node(-99);
			head->right=head;
			head->left=head;
			root=new node (x);
			root->left=head;
			root->right=head;
			head->left=root;
			head->lbit=1;
			return;
		}
		else
		{
			node *p=root;
			while(1)
			{
			if(x<p->data)
			{
				if(p->lbit!=0)
				{
					p=p->left;
				}
				else
				{
					node *temp;
					temp=new node(x);
					temp->left=p->left;
					temp->right=p;
					p->left=temp;
					p->lbit=1;
					return ;
				}
			}
			else
			{
				if(p->rbit!=0)
				{
					p=p->right;
				}
				else
				{
					node *temp;
					temp=new node(x);
					temp->left=p;
					temp->right=p->right;
					p->right=temp;
					p->rbit=1;
					return;
				}
			}
			}
		}

	}

	void inorder()
	{
		node *p=root;
		while(p->lbit!=0)
		{
			p=p->left;
		}
		while(p!=head)
		{
			cout<<p->data<<" ";
			if(p->rbit==0)
			{
				p=p->right;
			}
			else
			{
				p=p->right;
				while(p->lbit!=0)
				{
					p=p->left;
				}
			}
		}
	}
	void preorder()
	{
		int flag=0;
		node *p=head;
		if(p!=head)
		{
			if(flag==0)
			{
				cout<<p->data<<" ";
			}
			else if(flag==0 && p->lbit==1)
			{
				p=p->left;
			}
			else
			{
				if(p->rbit==1)
				{
					flag=0;
				}
				else
				{
					flag=1;
					p=p->right;
				}
			}
		}
	}
};
int main()
{
	tbt t;
	int x,k;
	do
	{
		cout<<"1.Create\n2.Inorder\n3.Preorder\nEnter your choice";
		cin>>k;
		switch(k)
		{
		case 1:
				cout<<"Enter data\n";
				cin>>x;
				t.createtbt(x);
				break;
		case 2:
				t.inorder();
				break;
		case 3:
				t.preorder();
				break;
		}
	}while(k!=0);
}
