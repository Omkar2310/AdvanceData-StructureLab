/*
PROBLEM STATEMENT:A Dictionary stores keywords & its meanings. Provide facility for adding
new keywords, deleting keywords, updating values of any entry, assign a given tree into another tree (=). 
Provide facility to display whole data sorted in ascending/ Descending order. 
Also find how many maximum comparisons may require for finding any keyword. Use Binary Search
Tree for implementation.
*/

//============================================================================
// Name        : diction.cpp
// Author      : OMKAR MANKAR
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;
class node
{
public:
	string word,meaning;
	node *right,*left;
	node(string m,string n)
	{
		word=m;
		meaning=n;
		left=right=NULL;
	}
};
class Dictionary
{
	node *root;
public:
		Dictionary()
	{
		root=NULL;
	}
		void create_bst(string m,string n)
		{
			node *temp;
			temp=new node(m,n);
			if(root==NULL)
			{
				root=temp;
				return;
			}
			node *p,*q;
			p=root;
			q=NULL;
			while(true)
			{
				q=p;
				if(m<p->word)
				{
					p=p->left;
					if(p==NULL)
					{
						q->left=temp;
						return;
					}
				}
				else
				{
					p=p->right;
					if(p==NULL)
					{
						q->right=temp;
						return;
					}
				}
			}
		}
		void create1()
		{
			int x;
			string m,n;
			do
			{

				cout<<"ENter word and meaning \n";
				cin.ignore();
				getline(cin,m);
				getline(cin,n);
				createnon(m,n);
				cout<<"Do u want to continue?Press -1 to stop\n";
				cin>>x;
				if(x==-1)
					{
						break;
					}
			}while(1);
		}
		void createnon(string m,string n)
		{
			node *t=root,*q;
			if(t==NULL)
			{
				root=new node(m,n);
				return;
			}
			while(t!=NULL)
			{
				q=t;
				if(m<t->word)
				{
					t=t->left;
				}
				else
				{
					t=t->right;
				}
			}
			if(q->word>m)
			{
				q->left=new node(m,n);
			}
			else
			{
				q->right=new node(m,n);
			}
		}
		void inorder()
		{
			inorder_rec(root);
		}
		void inorder_rec(node *t)
		{

			if(t!=NULL)
			{
				inorder_rec(t->left);
				cout<<t->word<<" - \t"<<t->meaning<<endl;
				inorder_rec(t->right);
			}
		}
		void create()
		{
			int x;
			string m,n;
			do
			{

				cout<<"ENter word and meaning"<<endl;
				cin.ignore();
				getline(cin,m);

				getline(cin,n);
				root=bst_rec(root,m,n);
				cout<<"Do u want to continue?Press -1 to stop\n";
				cin>>x;
				if(x==-1)
					{
						break;
					}
			}while(1);
		}
		node* bst_rec(node *t,string a,string b)
		{
			if(t==NULL)
			{
				return new node(a,b);
			}
			if(a<t->word)
			{
				t->left=bst_rec(t->left,a,b);
			}
			if(a>t->word)
			{
				t->right=bst_rec(t->right,a,b);
			}
			return t;

		}
		node* search(string key)
		{
			int i=0;
			node *temp;
			temp=root;
			while(temp!=NULL)
			{
				if(temp->word>key)
				{
					i++;
					temp=temp->left;

				}
				else if(temp->word<key)
				{
					i++;
					temp=temp->right;

				}
				else
				{
					cout<<"comparisons are"<<i<<endl;
					return temp;
				}
			}
			return NULL;
		}
		void update(string key)
		{
			node *temp;
			string s;
			temp=search(key);
			if(temp==NULL)
			{
				cout<<"Word not present\n";
				return;
			}
			else
			{
				cout<<"ENter new meaning for"<<temp->word<<endl;
				cin.ignore();
				getline(cin,s);
				temp->meaning=s;
			}
		}
		node* findmin(node *t)
		{
			if(t->left!=NULL)
			{
				return findmin(t->left);
			}
			return t;
		}
		void delete1()
		{
			string m;
			cout<<"Enter word to delete"<<endl;
			cin.ignore();
			getline(cin,m);
			root=delete_rec(root,m);
		}
		node* delete_rec(node *t,string key)
		{
			node *temp;
			if(t==NULL)
			{
				cout<<"Word not found\n";
				return NULL;
			}
			if(key<t->word)
			{
				t->left=delete_rec(t->left,key);
				return t;
			}
			else if(key>t->word)
			{
				t->right=delete_rec(t->right,key);
				return t;
			}
			//now t will be on node u want to delete
			if((t->left==NULL) && (t->right==NULL))
			{
				delete t;
				return NULL;
			}
			if(t->right==NULL)
			{
				temp=t->left;
				delete t;
				return temp;
			}
			if(t->left==NULL)
			{
				temp=t->right;
				delete t;
				return temp;
			}
			node *p;
			p=findmin(t->right);
			t->word=p->word;
			t->meaning=p->meaning;
			t->right=delete_rec(t->right,p->word);
			return t;
		}
};
int main()
{
	int x;
	node *p;
	Dictionary d;
	string a,b;
	do
	{
		cout<<"1.Create Dictionary\n2.Create Dictionary Recursive\n3.Display\n4.Search\n5.Update\n6.Delete\nEnter UR choice\n";
		cin>>x;
		switch(x)
		{
		case 0:
				return 0;
		case 1:
				/*cout<<"ENter word"<<endl;
				cin.ignore();
				getline(cin,a);
				cout<<"ENter meaning"<<endl;
				//cin.ignore();
				getline(cin,b);
				d.create_bst(a,b);
				*/
				d.create1();
				break;
		case 2:
				d.create();
				break;
		case 3:

				d.inorder();
				break;
		case 4:
				cout<<"ENter word to search";
				cin>>a;
				p=d.search(a);
				if(p==NULL)
				{
					cout<<"NOt present\n";
				}
				if(p!=NULL)
				{
					cout<<p->word<<"\t"<<p->meaning<<endl;
				}
				break;
		case 5:
				cout<<"ENter word u want to update\n";
				cin>>a;
				d.update(a);
				break;
		case 6:
				d.delete1();
				break;
		}
	}while(x!=0);

	return 0;
}
