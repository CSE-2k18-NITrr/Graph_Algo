#include<bits/stdc++.h>

using namespace std;

int bfs(int s,vector <int> graph[],int nodes)
{
	bool visited[nodes];
	memset(visited,false,sizeof(bool)*nodes);
	
	queue <int> tovisit;
	
	tovisit.push(s);
	
	while(!tovisit.empty())
	{
		if(visited[tovisit.front()]==false)
		{
			visited[tovisit.front()]=true;
			for(int i=0;i<graph[tovisit.front()].size();i++)
				tovisit.push(graph[tovisit.front()].at(i));
			printf("%d ",tovisit.front());
			tovisit.pop();
		}
		else
		{
			//printf("%d ",tovisit.front());
			tovisit.pop();
		}
	}
	
}

int main()
{	
	
	int nodes,edges,m,temp;
	scanf("%d %d",&nodes, &edges);
	vector <int> graph[nodes+1];
	vector <int>::iterator it;
	
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
	
	bfs(1,graph,nodes+1);
	
	return 0;	
}
