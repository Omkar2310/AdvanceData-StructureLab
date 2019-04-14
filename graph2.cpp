//============================================================================
// Name        : graph2.cpp
// Author      : OMKAR MANKAR
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#define MAX 20
using namespace std;
class node
{
public:
	int data;
	node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
class queue
{
public:
	int front,rear;
	int q[MAX];
	queue()
	{
		front=rear=-1;
	}
	int isempty()
	{
		if(front==-1)
			return 1;
		else
			return 0;
	}
	int isfull()
	{
		if(front==0 && rear==MAX-1)
		{
			return 1;
		}
		return 0;
	}
	void enqueue(int x)
	{
		if(!isfull())
		{
			if(isempty())
			{
				front++;
				rear++;
				q[rear]=x;
			}
			else
				rear++;
			q[rear]=x;
		}
		else
			cout<<"Queue is full\n";
	}
	int dequeue()
	{
		int g;
		if(!isempty())
		{

			if(front==rear)
			{
				g=q[front];
				//delete q[front];
				front++;
				front=rear=-1;
				return g;
			}
			else
			{
				g=q[front];
				front++;
				return g;
			}
		}
		else
			cout<<"EMpty queue\n";
		return g;
	}
};
class graph
{
	int n,ne;
	node *head[20];
	string city[20];
	int data[20][20];
public:
	graph()
	{
		for(int i=0;i<20;i++)
		{
			head[i]=NULL;
		}
	}
	int search(string m)
	{
		for(int i=0;i<n;i++)
		{
			if(city[i]==m)
			{
				return i;
			}

		}
		return -1;
	}
	void create_list()
	{
		string u,v,w;
		int dist;
		cout<<"ENter number of citites\n";
		cin>>n;
		cout<<"ENter city names\n";
		for(int i=0;i<n;i++)
		{
			cin>>city[i];
		}
		cout<<"ENter number of edges\n";
		cin>>ne;
		for(int i=0;i<ne;i++)
		{
			cout<<"ENter source city\n";
			cin>>u;
			cout<<"Enter destination city\n";
			cin>>v;
			cout<<"Enter distance between cities\n";
			cin>>dist;
			addinlist(u,v,dist);
		}
	}
	void addinlist(string u,string v,int dist)
	{
		int k,j;
		k=search(u);//k is source
		j=search(v);//j is destin
		data[k][j]=dist;
		node *p;
			if(head[k]==NULL)
			{
				head[k]=new node (j);
			}
			else
			{
				p=head[k];
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=new node(j);
			}
	}

	void display()
	{
		node *p;
		for(int i=0;i<n;i++)
		{
			p=head[i];
			//now in display i denotes headcha index and p->data is index of destination
			while(p!=NULL)
			{
				cout<<city[i]<<" connected to "<<city[p->data]<<" distance is "<<data[i][p->data]<<" "<<endl;
				p=p->next;
			}
		}
	}
	void outdegree()
	{
		node *p;
		for(int i=0;i<n;i++)
		{
			int count=0;
			p=head[i];
			while(p!=NULL)
			{
				count++;
				p=p->next;
			}
			cout<<"Outdegree of "<<city[i]<<" is "<<count<<endl;
		}
	}
	void indegree()
	{

		for(int j=0;j<n;j++)
		{
			node* k;
			int cnt=0;
		for(int i=0;i<n;i++)
		{
			k=head[i];
			while(k!=NULL)
			{
				if(k->data==j)
				{
					cnt++;
				}
				k=k->next;
			}
		}
		cout<<"Indegree of "<<city[j]<<" is "<<cnt<<endl;
		}
	}
	void delete1()
	{
		string m,n;
		int i;
		cout<<"ENter an edge to be deleted as source-destination\n";
		cin>>m>>n;
		i=search(m);//m is source
		head[i]=deleteanedge(m,n);
	}
	node* deleteanedge(string m,string n)
	{
		int i,j;
		node *p,*q;
		i=search(m);//m is source
		j=search(n);//n is destin
		p=head[i];
		while(p!=NULL)
		{
			q=p;
			if(p->data==j)
			{
				break;
			}
			else
			{
				p=p->next;
			}
		}
		if(p->next==NULL)
		{
			delete p;
			return NULL;
		}
		else
		{
			q->next=p->next;
			delete p;
			return NULL;
		}
	}
	void dfs(string m)
	{
		int i=search(m);
		int visited[20]={0};
		dfs1(i,visited);
	}
	void dfs1(int x,int visited[])
	{
		cout<<city[x]<<" is visited "<<endl;
		visited[x]=1;
		node *p;
		p=head[x];
		while(p!=NULL)
		{
			if(visited[p->data]==0)
			{
				dfs1(p->data,visited);
			}
			p=p->next;
		}
	}
	void bfs1(string m)
	{
		int i=search(m);
		int visited[10]={0};
		bfs(i,visited);
	}
	void bfs(int x,int visited[])
	{
		queue q;
		cout<<city[x]<<" is visited "<<endl;
		q.enqueue(x);
		visited[x]=1;
		int s;
		node *p=head[x];
		while(!q.isempty())
		{
			s=q.dequeue();
			while(p!=NULL)
			{
				if(visited[p->data]==0)
				{
					bfs(p->data,visited);
				}
				p=p->next;
			}
		}
	}
};
int main()
{
	graph g;
	int k,v;
	string m,n;
	do
	{
		cout<<"1.ENter cities\n2.display\n3.Outdegree&Indegree\n4.addanedge\n5.dleteanedge\n6.traversal\n";
		cin>>k;
		switch(k)
		{
		case 1:
				g.create_list();
				break;
		case 2:
				g.display();
				break;
		case 3:
				g.outdegree();
				g.indegree();
				break;
		case 4:
				cout<<"ENter an edge as source-destination-value\n";
				cin>>m>>n>>v;
				g.addinlist(m,n,v);
				break;
		case 5:
				g.delete1();
				break;
		case 6:
				cout<<"Enter from where u want to start\n";
				cin>>m;
				g.dfs(m);
				g.bfs1(m);
				break;
		}
	}while(k!=0);
	return 0;

}
