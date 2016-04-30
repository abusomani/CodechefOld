#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<set>
using namespace std;
int count=0;
class vertex
{
	public:
	list<int> adjl;
	list<int>:: iterator p;
	public:
	int name;
	void addedge(int d)
	{  adjl.push_back(d);  }
	bool contains(int d)
	{
		p=adjl.begin();
		while(p!=adjl.end())
		{  if(*p==d) return 1;   p++;    }
		return 0;
	}
	void adjacent()
	{
		p=adjl.begin();
		while(p!=adjl.end())
		{
			cout<<*p<<" ";	p++;
		}
	}
};
class Graph
{
	public:
		map< int , set<int> > m;
		int numberofv;
		vertex* v;
    public:
	Graph() {   }                                                        // create empty graph
	Graph(int n) 
    {  numberofv=n;    v=new vertex[numberofv];  for(int i=0;i<n;i++) { v[i].name=i; } }        // create graph with given vertices
	void inputgraph(int n)
	{
		char l;
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
		{
			cin>>l;
			if(l=='1')  
			{
				v[i].addedge(j);
			}
		}
		}
	}
	void showgraph()
	{
		list<int>:: iterator p;
		for(int i=0;i<numberofv;i++)
    	{
		cout<<"Vertex "<<i<<" : ";
		v[i].adjacent();
		cout<<endl;
	    }
	}
    void result(int n)
    {
    	for(int i=0;i<n;i++)
    	{
    		m[i].insert(i);
    		list<int>:: iterator p=v[i].adjl.begin();
		    while(p!=v[i].adjl.end())
	    	{
			list<int>:: iterator p1=v[*p].adjl.begin();
			while(p1!=v[*p].adjl.end())
	    	{
	    	    int flag=0;
	    		set<int> :: iterator lol=m[i].find(*p1);
	    		if(lol!=m[i].end())
	    		flag=1;
	    		if(!v[i].contains(*p1)  &&  !flag)
	    		{
	    			cout<<i<<"  -> "<<*p<<"   "<<*p1<<endl;
	    			m[i].insert(*p1);
	    			count++;
	    		}
	    		p1++;
	    	}
	    	
			p++;
	     	}
    	}
    	
    }
};
int main()
{
	int n,choice;
	cin>>n;
    Graph g(n);
    	g.inputgraph(n);
    	g.showgraph();
    g.result(n);
    cout<<count<<endl;
}
