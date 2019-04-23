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
#include <iostream>
#include<string.h>
using namespace std;
class node
{
public:
	char word[10],mean[10];
	node *right,*left;
	node(char a[],char b[])
	{
		strcpy(word,a);
		strcpy(mean,b); // @suppress("Function cannot be resolved")
		right=left=NULL;
	}
};

class avltree
{
	node *root;
public:
	avltree()
	{
		root=NULL;
	}

	int height(node *t)
	{
		if(t==NULL)
		{
			return 0;
		}
		if(t->left==NULL && t->right==NULL)
		{
			return 0;
		}
		int a,b;
		a=height(t->left);
		b=height(t->right);
		if(a<b)
		{
			return b+1;
		}
		return a+1;
	}

	int balfact(node *t)
	{
		int a,b;

		a=height(t->left);
		b=height(t->right);
		if(t->left!=NULL)
		{
			a++;
		}
		if(t->right!=NULL)
		{
			b++;
		}
		return (a-b);
	}

	node* ll(node *t)
	{
		node *y=t->left;
		t->left=y->right;
		y->right=t;
		return y;
	}

	node* rr(node *t)
	{
		node *y=t->right;
		t->right=y->left;
		y->left=t;
		return y;
	}

	node* lr(node *t)
	{
		node *y=t->left;
		node *p=y->right;
		y->right=p->left;
		p->left=y;
		t->left=p;
		return ll(t);
	}

	node* rl(node *t)
	{
		node *y=t->right;
		node *p=y->left;
		y->left=p->right;
		p->right=y;
		t->right=p;
		return rr(t);
	}

	void insert(char a[],char b[])
	{
		root=in(root,a,b);
	}

	node* in(node *t,char a[],char b[])
	{
		if(t==NULL)
		{
			return new node(a,b);
		}

		if(strcmp(t->word,a)>0)
		{
			//a is small
			t->left=in(t->left,a,b);
			if(balfact(t)==2)
			{
				if(strcmp(t->left->word,a)>0)
				{
					t=ll(t);
					return t;
				}
				else
				{
					t=lr(t);
					return t;
				}
			}
		}
		else
		{
		if(strcmp(t->word,a)<0)
		{
			//a is small
			t->right=in(t->right,a,b);
			if(balfact(t)==-2)
			{
				if(strcmp(t->right->word,a)>0)
				{
					t=rl(t);
					return t;
				}
				else
				{
					t=rr(t);
					return t;
				}
			}
		}
		else
		{
			cout<<"Data already present\n";
		}
		}
		return t;
	}
	void in(){
		inorder(root);
	}
	void inorder(node *t)
	{
		if(t!=NULL)
		{
			inorder(t->left);
			cout<<t->word<<" : "<<t->mean<<" "<<balfact(t)<<endl;
			inorder(t->right);
		}
	}

	void del(char a[])
	{
		root=del_rec(root,a);
	}

	node* del_rec(node *t,char a[])
	{
		if(t==NULL)
		{
			cout<<"data not found\n";
			return t;
		}
			if(strcmp(t->word,a)>0)
			{
				//a is small so we need to balance rr and rl condition
				//rl is used if r->right bal is > than 0 else rr
				t->left=del_rec(t->left,a);
				if(balfact(t)==-2)
				{
					if(balfact(t->right)>0)
					{
						//do rl;
						t=rl(t);
						return t;
					}
					else
					{
						t=rr(t);
						return t;
					}
				}
			}
			else
			{
				if(strcmp(t->word,a)<0)
				{
					//right delete do lr and ll
					t->right=del_rec(t->right,a);
					if(balfact(t)==2)
					{
						if(balfact(t->left)>0)
						{
							t=ll(t);
							return t;
						}
						else
						{
							t=lr(t);
							return t;
						}
					}
				}
				else
				{
					//data found to delete
					if(t->left==NULL && t->right==NULL)
					{
						delete t;
						return NULL;
					}
					if(t->left==NULL)
					{
						node *p=t->right;
						delete t;
						return p;
					}
					if(t->right==NULL)
					{
						node *p=t->left;
						delete t;
						return p;
					}

					node *temp=findmin(t->right);
					strcpy(t->word,temp->word);
					strcpy(t->mean,temp->mean);
					t->right=del_rec(t->right,temp->word);
					//data delete from right we do ll and lr
					if(balfact(t)==2)
					{
					if(balfact(t->left)>0)
					{
						t=ll(t);
						return t;
					}
					else
					{
						t=lr(t);
						return t;
					}
					}
					return t;
				}
			}
		return t;
	}

	node* findmin(node *t)
	{
		if(t->left!=NULL)
		{
			t=t->left;
		}
		return t;
	}
};

int main()
{
	int k;
	char a[10],b[10];
	avltree t;
	do
	{
		cout<<"1.create\n2.display\n";
		cin>>k;
		switch(k)
		{
		case 1:
			cout<<"Enter word and meaning\n";
			cin.ignore();
			cin.getline(a,9);
			cin.getline(b,9);
			t.insert(a,b);
			break;
		case 2:
			t.in();
			break;
		case 3:
			cout<<"Enter word \n";
			cin.ignore();
			cin.getline(a,9);
			t.del(a);
			break;

		}
	}while(k!=0);
	return 0;
}
