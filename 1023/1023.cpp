#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MAXN 20
string a;
int num[MAXN+1],t[10],n,tt[10];
int main()
{
	cin>>a;
	n=a.length();
	for(int i=0;i<n;i++)
	{
		num[n-i-1]=a[i]-'0';
		t[a[i]-'0']++;
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		num[i]=num[i]*2+flag;
		flag=0;
		if(num[i]>=10)
		{
			flag=1;
			num[i]-=10;
		}
		tt[num[i]]++;
	}
	if(flag)
		cout<<"No"<<endl;
	else
	{
		bool temp=0;
		for(int i=0;i<10;i++)
			if(t[i]!=tt[i])
				temp=1;
		if(temp)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	if(flag)
		cout<<"1";
	for(int i=n-1;i>=0;i--)
		cout<<num[i];
	cout<<endl;
	return 0;
}
