#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 500
#define MAXINT 2147483647
using namespace std;
int n,m,c1,c2,tans=0,price=0,a,b;
int p[MAXN+1],used[MAXN+1];
int c,map[MAXN+1][MAXN+1],dis[MAXN+1],ans=0;
int max(int a,int b)
{
	return a>b?a:b;
}

void dfs(int now,int road,int pp)
{
	if(now==c2)
	{
		if(road==ans)
		{
			tans++;
			price=max(price,pp);
		}
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i]&&map[now][i])
		{
			used[i]=1;
			dfs(i,road+map[now][i],pp+p[i]);
			used[i]=0;
		}
	}
}

int main()
{
	memset(map,0,sizeof(map));
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;dis[i]=MAXINT,i++)
		cin>>p[i];
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	int k;
	dis[c1]=0;
	for(int i=0;i<n-1;i++)
	{
		int tmin=MAXINT;k=-1;
		for(int j=0;j<n;j++)
			if(!used[j]&&tmin>dis[j])
			{
				tmin=dis[j];
				k=j;
			}
		if(k==-1)
			break;
		used[k]=1;
		for(int j=0;j<n;j++)
		{
			if(dis[k]+map[k][j]<dis[j]&&map[k][j])
				dis[j]=dis[k]+map[k][j];
		}
	}
	ans=dis[c2];
	memset(used,0,sizeof(used));
	used[c1]=1;
	dfs(c1,0,p[c1]);
//	cout<<ans<<endl;
	cout<<tans<<' '<<price<<endl;
	return 0;
}
