//============================================================================
// Name        : krusprim.cpp
// Author      : Omkar Mankar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include<string.h>
#define infi 9999
using namespace std;
class graph
{
	int n,ne,no_of_edges;
	string city[20];
	int data[20][20],visited[20],from[20],dist[20];
	int cost[20][20];
public:
	graph()
	{
		n=ne=no_of_edges=0;
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				data[i][j]=0;
		     }
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
	void create()
	{
		int dist,p,q;
		string m,n1;
		cout<<"ENter no. of cities\n";
		cin>>n;
		cout<<"Enter names of city";
		for(int i=0;i<n;i++)
		{
			cin>>city[i];
		}
		cout<<"Enter no. of edges\n";
		cin>>ne;
		for(int i=0;i<ne;i++)
		{
			cout<<"ENter source\n";
			cin>>m;
			cout<<"Enter destination\n";
			cin>>n1;
			cout<<"Enter distance\n";
			cin>>dist;
			p=search(m);
			q=search(n1);
			data[p][q]=dist;
			data[q][p]=dist;
		}
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(data[i][j]==0)
				{
					cost[i][j]=infi;
				}
				else
				{
					cost[i][j]=data[i][j];
				}
			}
		}
	}
	void prims(string s)
	{
		int x=search(s);
		int res[10][10]={0};
		int min,v,u;
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
			dist[i]=cost[x][i];
			from[i]=x;
		}
		visited[x]=1;//1st is visited
		no_of_edges=n-1;
		while(no_of_edges > 0)
		{
			min=infi;
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && min>dist[i])
				{
					min=dist[i];
					v=i;	//v has index of minimum element
				}
			}
			visited[v]=1;
			u=from[v];
			res[u][v]=cost[u][v];
			res[v][u]=cost[u][v];
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && dist[i]>cost[v][i])
				{
					dist[i]=cost[v][i];
					from[i]=v;
				}
			}
			no_of_edges--;
		}
		/*int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<n;i++)
		{
			sum=sum+dist[i];
		}
		cout<<"MINIMUM cost is"<<sum<<endl;
		*/
	}
	void display()
	{
		int sum=0;
		for(int i=1;i<n;i++)
		{
			cout<<city[from[i]]<<" to "<< city[i]<<" distance is "<<dist[i]<<endl;
			sum=sum+dist[i];
		}
		cout<<"MIniumum weight of spanning tree is"<<sum<<endl;
	}
};
int main()
{
	graph g;
	string m;
	g.create();
	cout<<"ENter string from where u want prims\n";
	cin>>m;
	g.prims(m);
	g.display();

}
