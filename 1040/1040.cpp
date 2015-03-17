#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 1000
using namespace std;
int ans=0,num[MAXN+1];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	string a,b;
	getline(cin,a);
	for(int i=a.length()-1;i>=0;i--)
		b+=a[i];
	for(int i=0;i<a.length();i++)
	{
		memset(num,0,sizeof(num));
		for(int k=0;k<a.length();k++)
		{
			if(i+k<a.length()&&b[k]==a[i+k])
			{
				if(k!=0)
					num[k]=num[k-1]+1;
				else
					num[k]=1;
				ans=max(ans,num[k]);
			}
		}
	}
	swap(a,b);
	for(int i=0;i<a.length();i++)
	{
		memset(num,0,sizeof(num));
		for(int k=0;k<a.length();k++)
		{
			if(i+k<a.length()&&b[k]==a[i+k])
			{
				if(k!=0)
					num[k]=num[k-1]+1;
				else
					num[k]=1;
				ans=max(ans,num[k]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
