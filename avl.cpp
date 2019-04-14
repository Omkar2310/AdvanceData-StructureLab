/*
Create a Dictionary by using Height Balanced tree,(AVL TREE)
*/

//============================================================================
// Name        : avl.cpp
// Author      : Omkar Mankar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<string.h>
using namespace std; 
class node
{
public:
	node *right,*left;
	string w,m;
	node(string x,string y)
	{
		w=x;
		m=y;
		right=left=NULL;
	}
	node()
	{
		right=left=NULL;
		w=m=" ";
	}
};
class dictionary
{
	node *root;
public:
	dictionary()
	{
		root=NULL;
	}
	node *LL(node *t)
	{
		node *p=t->left;
		node *y=p->right;
		t->left=y;
		p->right=t;
		return p;
	}
	node *RR(node *t)
	{
		node *p=t->right;
		node *y=p->left;
		t->right=y;
		p->left=t;
		return p;
	}
	node *LR(node *t)
	{
		node *p=t->left;
		node *y=p->right;
		p->right=y->left;
		y->left=p;
		y->right=t;
		return p;
	}
	node *RL(node *t)
	{
		node *p=t->right;
		node *y=p->left;
		p->left=y->right;
		y->right=p;
		y->left=t;
		return p;
	}
	node* insert(node *root,string x,string y)
	{
		node *t=root;
		if(t==NULL)
		{
			return new node(x,y);
		}
		if(x<t->w)
		{
			t->left=insert(t->left,x,y);
			if(bal_fact(t)==2)
			{
				if(x<t->left->w)
				{//add left
					t=LL(t);
				}
				else
				{//add right of left
					t=LR(t);
				}
			}
			return t;
		}
		if(x>t->w)
		{
			t->right=insert(t->right,x,y);
			if(bal_fact(t)==2)
			{
				if(x<t->right->w)
				{
					t=RL(t);
				}
				else
				{
					t=RR(t);
				}
			}
		return t;
		}

	}
	void insertdata()
	{
		string m,n;
		cout<<"ENter word\n";
		cin>>m;
		cout<<"Enter meaning\n";
		cin>>n;
		root=insert(root,m,n);
	}
	void inorder()
	{
		in_rec(root);
	}
	void in_rec(node *t)
	{
		if(t!=NULL)
		{
			in_rec(t->left);
			cout<<t->w<<" "<<t->m<<" "<<bal_fact1(t)<<height(t)<<endl;
			in_rec(t->right);
		}
	}
	int height(node *t)
	{
		int lh,rh;
		if(t==NULL)
		{
			return 0;
		}
		if(t->left==NULL)
		{
			lh=0;
		}
		else
		{
			lh=1+bal_fact(t->left);
		}
		if(t->right==NULL)
		{
			rh=0;
		}
		else
		{
			rh=1+bal_fact(t->right);
		}
		return (lh>rh?lh:rh);
	}
	int bal_fact(node *t)
	{
		int lh,rh;
		if(t==NULL)
		{
			return 0;
		}
		if(t->left==NULL)
		{
			lh=0;
		}
		else
		{
			lh=1+bal_fact(t->left);
		}
		if(t->right==NULL)
		{
			rh=0;
		}
		else
		{
			rh=1+bal_fact(t->right);
		}
		if(lh<rh)
		{
			return (-1)*(lh-rh);
		}
		else
		return (lh-rh);
	}
	int bal_fact1(node *t)
	{
		int lh,rh;
		if(t==NULL)
		{
			return 0;
		}
		if(t->left==NULL)
		{
			lh=0;
		}
		else
		{
			lh=1+bal_fact(t->left);
		}
		if(t->right==NULL)
		{
			rh=0;
		}
		else
		{
			rh=1+bal_fact(t->right);
		}
		return (lh-rh);
	}
	void del()
	{
		string m;
		cout<<"ENter key\n";
		cin>>m;
		root=del1(root,m);
	}
	node* del1(node *root,string x)
	{
		node *t=root;
		if(x<t->w)
		{
			t->left=del1(t->left,x);
			return t;
			if(bal_fact1(t)==-2)
			{
				if(bal_fact1(t->right)<=0)
				{
					t=RR(t);
				}
				else
				{
					t=RL(t);
				}
			}
			return t;
		}
		else if(x>t->w)
		{
			t->right=del1(t->right,x);
			return t;
			if(bal_fact1(t)==2)
			{
				if(bal_fact1(t->left)>=0)
				{
					t=LL(t);
				}
				else
				{
					t=LR(t);
				}
			}
			return t;
		}
		//data found
		if(t->right==NULL && t->left==NULL)
		{
			delete t;
			return NULL;
		}
		if(t->right==NULL)
		{
			node *p=t->right;
			delete t;
			return p;
		}
		if(t->left==NULL)
		{
			node *p=t->left;
			delete t;
			return p;
		}
		//else two children
		node *temp;
		temp=findmin(t->right);
		t->w=temp->w;
		t->m=temp->m;
		t->right=del1(t->right,temp->w);
		if(bal_fact1(t)==2)
		{
			if(bal_fact1(t->left)>=0)
			{
				t=LL(t);
			}
			else
			{
				t=LR(t);
			}
		}
		return t;
	}
	node *findmin(node *t)
	{
		if(t==NULL)
		{
			return NULL;
		}
		while(t->left!=NULL)
		{
			t=t->left;
		}
		return t;
	}
};
int main()
{
	int k;
	dictionary d;
	do
	{
		cout<<"1.INSERT\n2.DISPLAY\n3.DELETE\nEnter ur choice\n";
		cin>>k;
		switch(k)
		{
			case 1:
				d.insertdata();
				break;
			case 2:
				d.inorder();
				break;
			case 3:
				d.del();
				break;
		}

	}while(k!=0);
}
