#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
double a[1001],b[1001],c[1001];int k,x;
double y,ans=0;
int main()
{
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y;a[x]+=y;	
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y;b[x]+=y;	
	}
	for(int i=0;i<=1000;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i]!=0)
			ans++;
	}
	cout<<ans;
	for(int i=1000;i>=0;i--)
	{
		if(c[i]!=0)
			printf(" %d %.1f",i,c[i]);
	}
	cout<<endl;
	return 0;
}
