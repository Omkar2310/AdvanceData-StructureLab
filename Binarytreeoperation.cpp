/*
 =====================================================
 Name        : Binarytree.cpp
 Author      : Omkar Mankar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++, Ansi-style
 =====================================================
*/

#include<iostream>
#define MAX 20
using namespace std;
class node
{
	public:
		int data;
		node *right,*left;
		node(int x)
		{
			data=x;
			left=right=NULL;
		}
};
class stack
{
	int top;
	node *data[MAX];
	
	public:
		stack()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}			
			return 0;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void push(node *t)
		{
			if(!full())
			{
				top++;
				data[top]=t;
			}
			else
			{
				cout<<"full";
			}
			
		}
		node* pop()
		{
			node *temp;
			if(!empty())
			{
				temp=data[top];
				top--;
				return temp;
			}
			else
			{
				cout<<"empty";
			}
		}
};
struct stacknode
{
	node *link;
	int flag;
};
class stack1
{
	int top;
	
	stacknode data[MAX];
	
	public:
		stack1()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}			
			return 0;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void push(stacknode t)
		{
			if(!full())
			{
				top++;
				data[top]=t;
			}
			else
			{
				cout<<"full";
			}
			
		}
		stacknode pop()
		{
			stacknode temp;
			if(!empty())
			{
				temp=data[top];
				top--;
				return temp;
			}
			else
			{
				cout<<"empty";
			}
		}
};

class Btree
{
	node* root;
	public:
		Btree()
		{
			root=NULL;
		}
		void create()
		{
			root=create_rec();
		}
		node* create_rec()
		{
			int x;
			node *p;
			cout<<"Enter data or -1 to stop\n";
			cin>>x;
			if(x==-1)
			return NULL;
			p=new node(x);
			cout<<"Enter left of "<<x<<"\n";
			p->left=create_rec();
			cout<<"Enter right of "<<x<<"\n";
			p->right=create_rec();
			return p;
		}
		void pre_rec(node *T)
		{
			if(T!=NULL)
			{
				cout<<T->data<<"\t";
				pre_rec(T->left);
				pre_rec(T->right);
			}
		}
		void preor()
		{
			pre_rec(root);
		}
		void in_rec(node *T)
		{
			if(T!=NULL)
			{
				in_rec(T->left);
				cout<<T->data<<"\t";
				in_rec(T->right);
			}
		}
		void inor()
		{
			in_rec(root);
		}
		void post_rec(node* T)
		{
			if(T!=NULL)
			{
				post_rec(T->left);
				post_rec(T->right);
				cout<<T->data<<"\t";
			}
		}
		void postor()
		{
			post_rec(root);
		}
		void non_pre()
		{
			node *t=root;
			stack s;
			while(t!=NULL)
			{
				cout<<t->data<<"\t";
				s.push(t);
				t=t->left;
			}
			while(!s.empty())
			{
				t=s.pop();
				t=t->right;
				while(t!=NULL)
				{
					cout<<t->data<<"\t";
					s.push(t);
					t=t->left;
				}
			}
		}
		void non_in()
		{
			node *t=root;
			stack s;
			while(t!=NULL)
			{
				s.push(t);
				t=t->left;
			}
			while(!s.empty())
			{
				t=s.pop();
				cout<<t->data<<"\t";
				t=t->right;
				while(t!=NULL)
				{
					s.push(t);
					t=t->left;
				}
			}
		}
		void non_post()
		{
			node *t=root;
			stack1 s;
			stacknode st;
			while(t!=NULL)
			{
				st.link=t;
				st.flag=0;
				s.push(st);
				t=t->left;
			}
			while(!s.empty())
			{
				st=s.pop();
				if(st.flag==1)
				{
					cout<<st.link->data<<"\t";
				}
				else
				{
					st.flag=1;
					s.push(st);
					t=st.link;
					t=t->right;
					while(t!=NULL)
					{
						st.link=t;
						st.flag=0;
						s.push(st);
						t=t->left;
					}
				}
			}
		}
		int count_rec(node *t)
		{
			if(t==NULL)
			{
				return 0;	
			}	
			return 1+count_rec(t->left)+count_rec(t->right);
		}	
		void count()
		{
			
			cout<<"No. of nodes ="<<count_rec(root);
		}
		void non_count()
		{
			int i=0;
			node *t=root;
			stack s;
			while(t!=NULL)
			{
				s.push(t);
				t=t->left;
			}
			while(!s.empty())
			{
				t=s.pop();
				i++;
				t=t->right;
				while(t!=NULL)
				{
					s.push(t);
					t=t->left;
				}
			}
		cout<<"No. of nodes= "<<i<<endl;
		}
	
		int count0_deg(node *t)
		{
			if(t==NULL)
			{
				return 0;
			}
			if(t->left==NULL && t->right==NULL)
			{
				return 1;
			}
			return count0_deg(t->left)+count0_deg(t->right);
		}
			void count0()
		{
			cout<<"No. of nodes with degree 0 ="<<count0_deg(root);
		}
		int count1_deg(node *t)
		{
			if(t==NULL)
			{
			return 0;
			}
			if(t->left==NULL && t->right==NULL)
			{
				return 0;
			}
			if(t->left==NULL || t->right==NULL)//if anyone null we count
			{
				return 1 + count1_deg(t->right) + count1_deg(t->left);
			}
			return count1_deg(t->left) + count1_deg(t->right);//if both not null
		}
			void count1()
		{
			cout<<"No. of nodes with degree 1 ="<<count1_deg(root);
		}
		int  count2_deg(node *t)
		{
			if(t==NULL)
			{
				return 0;
			}
			if(t->left==NULL || t->right==NULL)
			{
				return 0;
			}
			if(t->left!=NULL && t->right!=NULL)
			{
				return 1+ count2_deg(t->left) + count2_deg(t->right);
			}
		}
		void count2()
		{
			cout<<"No. of nodes with degree 2 ="<<count2_deg(root);
		}
		void height_rec()
		{
			cout<<"height is "<<height(root);
		}
		int height(node *t)
		{
			if(t==NULL)
			{
				return 0;
			}
			else
			{
				return max(height(t->left),height(t->right)) +1;
			}			
		}
};
int main()
{
	Btree b;
	int k,x,p;
	do
	{
		cout<<"1.Create\n2.Display\n3.Count\n4.heightENter ur choice\n";
		cin>>k;
		switch(k)
		{
			case 1:
					b.create();
					break;
			case 2:
					do
					{
						cout<<"\n1.Recursive\n2.Nonrecursive\nEnter ur choice\n";
						cin>>p;
						switch(p)
						{
							case 1:
									do
									{
										cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\nEnter ur choice\n";
										cin>>x;
										switch(x)
										{
											case 1:
													b.preor();
													break;
											case 2:
													b.inor();
													break;
											case 3:
													b.postor();
													break;
										}
									}while(x!=0);
									break;
									
							case 2:
									do
									{
										cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\nEnter ur choice\n";
										cin>>x;
										switch(x)
										{
											case 1:
													b.non_pre();
													break;
											case 2:
													b.non_in();
													break;
											case 3:
													b.non_post();
													break;		
													
												
										}
									}while(x!=0);
									break;		
						}
					}while(p!=0);
					break;
			case 3:
					do
					{
						cout<<"\n1.Recursive count\n2.Nonrecursive count\n3.0degree nodes recursive\n4.1deg node rec\n5.2deg node recur\nEnter ur choice\n";
						cin>>x;
						switch(x)
						{
							case 1:
									b.count();
									break;
							case 2:
									b.non_count();
									break;
							case 3:
									b.count0();
									break;
							case 4:
									b.count1();
									break;
							case 5:
									b.count2();
									break;
						}
					}while(x!=0);
					break;
			case 4:
					b.height_rec();
				//	cout<<"Height is ="<<x;
					break;
		}
	}while(k!=0);
	return 0;
}
