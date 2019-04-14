//============================================================================
// Name        : hash.cpp
// Author      : Omkar Mankar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#define MAX 10
using namespace std;
class node
{
public:
	string word,me;
	int key;
	node()
	{
		word=" ";
		me=" ";
		key=-1;
	}
	node(string x,string y,int p)
	{
		word=x;
		me=y;
		key=p;
	}
};
class hashing
{
	node arr[MAX];
	int flag[MAX];
	int cnt;
public:
	hashing()
	{
		for(int i=0;i<MAX;i++)
		{
			flag[i]=i;
		}
	}
	int hashfun(int x)
	{
	int ind;
	ind=x%10;
	return ind;
	}
	
	void create(int x)
	{
		int index;
		index=hashfun(x);
		string m,n;
		cout<<"Enter word and its meaning\n";
		cin>>m>>n;
		//if(!check())
		{
		if(arr[index].key==-1)
		{
			arr[index].word=m;
			arr[index].me=n;
			arr[index].key=x;
			return;
		}
		else
		{
			for(int i=index+1;i<MAX;i=(i+1)%MAX)
			{
				if(arr[i].key==-1)
				{
					arr[i].word=m;
					arr[i].me=n;
					arr[i].key=x;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		}
	}
	void display()
	{
		for(int i=0;i<MAX;i++)
		{
			{
			cout<<flag[i]<<" "<<arr[i].key<<" "<<arr[i].word<<" : "<<arr[i].me<<endl;
			}
		}
		return;
	}
	void search(int s)
	{
		int i;
		int flag1=-1;
		for(i=0;i<MAX;i++)
		{
			if(arr[i].key==s)
			{
				flag1=0;
				cout<<"Key FOund\n";
				cout<<arr[i].key<<" "<<arr[i].word<<" "<<arr[i].me<<endl;
				break;
			}
			else
			{
				continue;
			}
			if(flag1==-1)
			{
				cout<<"KEy not found\n";
			}
			return;
		}
		return;
	}
	void update(int key)
	{
		string m,n;
		if(flag[key]==-1)
		{
			cout<<"Key does not exist\n";
			return;
		}
		int i;
		for(i=0;i<MAX;i++)
		{
		if(flag[i]!=-1 && flag[i]==key)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		cout<<"ENter new  Word and meaning\n";
		cin>>m>>n;
		arr[i].word=m;
		arr[i].me=n;
		return;
	}
	void deletewithout(int x)
	{
		int p=hashfun(x);
		if(flag[p]==-1)
		{
			cout<<"Key does not exist\n";
			return;
		}
		for(int i=0;i<MAX;i++)
		{
			if(arr[i].key==x)
			{
				arr[i].key=-1;
				arr[i].word=" ";
				arr[i].me=" ";
			}
			else
			{
				continue;
			}
		}
	}
	void deletewith(int x)
	{
		int flag=0;
		int ind=hashfun(x);
		for(int i=0;i<MAX;i++)
		{
			if(arr[i].key==x)
			{
				flag=1;
				for(int j=i+1;j<MAX;j=(j+1)%MAX)
				{
					if(arr[i].key!=-1 && hashfun(arr[j].key)==ind)
					{
						arr[i].key=arr[j].key;
						arr[i].word=arr[j].word;
						arr[i].me=arr[j].me;
						arr[j].key=-1;
						arr[j].word=" ";
						arr[j].me=" ";
						return;
					}
				}
			}
			else
			{
				continue;
			}
		}
		if(flag==0)
		{
			cout<<"KEY does not exist\n";
			return;
		}
	}
	void createwith(int x)
	{
		string m,n;
		int ind;
		ind=hashfun(x);
		cout<<"ENter new  Word and meaning\n";
		cin>>m>>n;
		for(int i=0;i<MAX;i=(i+1)%MAX)
		{
			if(arr[i].key==-1 && ind==i)
			{
				arr[ind].key=x;
				arr[ind].word=m;
				arr[ind].me=n;
				return;
			}
			else if(flag[ind]!=-1 && ind!=hashfun(arr[ind].key))
			{
				for(int k=ind+1;k<MAX;k++)
				{
					arr[k].key=arr[ind].key;
					arr[k].word=arr[ind].word;
					arr[k].me=arr[ind].me;
					arr[ind].key=x;
					arr[ind].word=m;
					arr[ind].me=n;
					return;
				}
			}
			else
			{
				for(int j=i+1;j<MAX;j++)
				{
					if(arr[i].key==-1)
					{
						arr[i].key=x;
						arr[i].word=m;
						arr[i].me=n;
						return;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
};
int main()
{
	hashing h;
	int p;
	int k,s,a;
	do
	{
		cout<<"1.Without Replacement\n2.With replacement\nEnter ur choice";
		cin>>s;
		switch(s)
		{
			case 1:
				do
				{
					cout<<"1.Insert\n2.Display\n3.Search\n4.Update\n5.Delete\nEnter your choice\n";
					cin>>k;
					switch(k)
					{
						case 1:
							cout<<"Enter key\n";
							cin>>p;
							h.create(p);
							break;
						case 2:
							h.display();
							break;
						case 3:
							cout<<"Enter key to search\n";
							cin>>p;
							h.search(p);
							break;
						case 4:
							cout<<"Enter key to update\n";
							cin>>p;
							h.update(p);
							break;
						case 5:
							cout<<"ENter key to delete\n";
							cin>>p;
							h.deletewithout(p);
							break;
					}
				}while(k!=0);
				break;
				case 2:
				do
				{
					cout<<"1.Insert\n2.Display\n3.Search\n4.Update\n5.Delete\nEnter your choice\n";
					cin>>a;
					switch(a)
					{
						case 1:
							cout<<"Enter key\n";
							cin>>p;
							h.createwith(p);
							break;
						case 2:
							h.display();
							break;
						case 3:
							cout<<"Enter key to search\n";
							cin>>p;
							h.search(p);
							break;
						case 4:
							cout<<"Enter key to update\n";
							cin>>p;
							h.update(p);
							break;
						case 5:
							cout<<"ENter key to delete\n";
							cin>>p;
							h.deletewith(p);
							break;
					}
				}while(a!=0);
				break;				

		}
	}while(s!=0);
	
}
