#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 1290

int m,n,l,T,ans;
int map1[MAXN+1][MAXN+1],map2[MAXN+1][MAXN+1],tmap2[MAXN+1][MAXN+1];
bool used[MAXN+1][MAXN+1];
int color[MAXN*MAXN+1],colornum=1;
bool colorused[MAXN*MAXN+1];

struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){}
	node(){}	
};

int main()
{
	scanf("%d %d %d %d",&n,&m,&l,&T);
	while(l--)
	{
		memset(used,0,sizeof(used));
		memset(tmap2,0,sizeof(tmap2));
		for(int i=1;i<=n;i++)
			for(int k=1;k<=m;k++)
			{
				scanf("%d",&map1[i][k]);
			}
		queue<node> q;
		for(int i=1;i<=n;i++)
			for(int k=1;k<=m;k++)
			{
				if(!used[i][k]&&map1[i][k])
				{
					used[i][k]=1;
					q.push(node(i,k));
					tmap2[i][k]=colornum++;
					if(map2[i][k]!=0&&!colorused[map2[i][k]])
						color[tmap2[i][k]]+=color[map2[i][k]],colorused[map2[i][k]]=1;
					while(!q.empty())
					{
						node t=q.front();q.pop();
						color[tmap2[t.x][t.y]]++;
						if(map2[t.x][t.y]&&!colorused[map2[t.x][t.y]])
							color[tmap2[t.x][t.y]]+=color[map2[t.x][t.y]],colorused[map2[t.x][t.y]]=1;
						node left(t.x-1,t.y);
						node right(t.x+1,t.y);
						node up(t.x,t.y-1);
						node down(t.x,t.y+1);
						if(!used[left.x][left.y]&&map1[left.x][left.y])
						{
							used[left.x][left.y]=1;
							tmap2[left.x][left.y]=tmap2[t.x][t.y];
							q.push(left);
						}
						if(!used[right.x][right.y]&&map1[right.x][right.y])
						{
							used[right.x][right.y]=1;
							tmap2[right.x][right.y]=tmap2[t.x][t.y];
							q.push(right);
						}
						if(!used[up.x][up.y]&&map1[up.x][up.y])
						{
							used[up.x][up.y]=1;
							tmap2[up.x][up.y]=tmap2[t.x][t.y];
							q.push(up);
						}
						if(!used[down.x][down.y]&&map1[down.x][down.y])
						{
							used[down.x][down.y]=1;
							tmap2[down.x][down.y]=tmap2[t.x][t.y];
							q.push(down);
						}
					}
				}
			}
		for(int i=1;i<=n;i++)
			for(int k=1;k<=m;k++)
				map2[i][k]=tmap2[i][k];
	}
	for(int i=1;i<colornum;i++)
	{
		if(color[i]>=T&&!colorused[i])
			ans+=color[i];
	}
	cout<<ans<<endl;
	return 0;
}
