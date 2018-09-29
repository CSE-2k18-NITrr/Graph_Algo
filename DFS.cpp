#include<bits/stdc++.h>

using namespace std;

int dfs(int s,vector <int> graph[],int nodes,bool visited[])
{
	int c;
	printf("%d ",s);
	visited[s]=true;
	for(int i=0;i<graph[s].size();i++)
	{
		c = graph[s].at(i);
		if(visited[c]==false)
		{
			visited[c]=true;
			dfs(c, graph, nodes,visited);
		}
	}
}

int main()
{	
	
	int nodes,edges,m,temp;
	scanf("%d %d",&nodes, &edges);
	vector <int> graph[nodes+1];
	vector <int>::iterator it;
	bool visited[nodes+1];
	memset(visited,false,sizeof(bool)*(nodes+1));
	int x,y;
	for(int i=1;i<=edges;i++)
	{
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);	
	}
	
	/*for(int i=1;i<=nodes;i++)
	{
		printf("%d : ",i);
		for(it=graph[i].begin();it!=graph[i].end();it++)
		{
			printf("%d ",*it);
		}
		printf("\n");
	}*/
	
	//printf("1 ");
	dfs(1,graph,nodes+1,visited);
	
	return 0;	
}
