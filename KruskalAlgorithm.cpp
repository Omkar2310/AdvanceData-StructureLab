#include<iostream>
using namespace std;
struct edge
{
	int u,v,w;
};
edge edge1[20],edge2[20];

class krus
{
	int n,ne;
	string city[20],u2,v2;
	int w2;
	public:
		
		int search(string m){
			
			for(int i=0;i<n;i++)
			{
				if(city[i]==m)
				{
					return i;
				}
				return -1;
			}
			
			
		}
		
	void scan()
	{
		cout<<"Enter no of cities\n";
		cin>>n;
		cout<<"Enter cities\n";
		for(int i=0;i<n;i++)
		{
			cin>>city[i];
		}
		
		cout<<"Enter edges\n";
		cin>>ne;
		for(int i=0;i<ne;i++)
		{
			cout<<"Enter source city\n";
			cin>>u2;
			cout<<"Enter destination city\n";
			cin>>v2;
			cout<<"Enter distance between them\n";
			cin>>w2;
			edge1[i].u=search(u2);
			edge1[i].v=search(v2);
			edge1[i].w=w2;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(edge1[i].w>edge1[j].w)
				{
					edge temp;
					temp=edge1[i];
					edge1[i]=edge1[j];
					edge1[j]=temp;
				}
			}
		}
		
		int component[20];
		for(int i=0;i<n;i++)
		{
			component[i]=i;
		}
		
		ne=n-1;
		while(ne>0)
		{
			int i=0,j;
			int u1=edge1[i].u;
			int v1=edge1[i].v;
			int cou=component[u1];
			int cov=component[v1];
			if(cou!=cov)
			{
				edge2[j]=edge1[i];
				j++;
			}
			ne--;
			for(int k=0;k<n-1;k++)
			{
				if(component[k]==cou)
				{
					component[k]=cov;
				}
			}
		}
		
	}
	
	void print()
	{
		for(int i=0;i<n;i++)
		{
			cout<<"City "<<city[i]<<" weight "<<edge1[i].w<<endl;
		}
	}
};

int main()
{
	krus k;
	k.scan();
	k.print();
}
