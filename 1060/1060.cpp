#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 1000
int n,pa,pb,ta=-1,tb=-1;
string a,b;
string temp="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
int main()
{
	cin>>n>>a>>b;
	pa=a.find('.');
	pb=b.find('.');
	if(pa==-1)
		a=a+'.',pa=a.length()-1;
	if(pb==-1)
		b=b+'.',pb=b.length()-1;
	a=a+temp;b=b+temp;
	for(int i=0;i<a.length();i++)
		if(a[i]!='0'&&a[i]!='.')
		{
			ta=i;break;
		}
	for(int i=0;i<b.length();i++)
		if(b[i]!='0'&&b[i]!='.')
		{
			tb=i;break;
		}
	if((ta==-1&&tb==-1)||n<=0)
		cout<<"YES"<<' '<<"0."<<a.substr(pb+1,n)<<"*10^0"<<endl;
	else if(ta==-1||tb==-1)
	{
		cout<<"NO"<<' ';
		int x=ta,y=tb;
		if(x==-1)
			x=0;
		if(y==-1)
			y=0;
		string aa=a.substr(x,n+1);
		if(aa.find('.')!=-1)
			aa.erase(aa.find('.'),1);
		else
			aa.erase(aa.length()-1,1);
		string bb=b.substr(y,n+1);
		if(bb.find('.')!=-1)
			bb.erase(bb.find('.'),1);
		else
			bb.erase(bb.length()-1,1);
		if(ta==-1)
			cout<<"0."<<a.substr(pb+1,n)<<"*10^0"<<' ';
		else
			cout<<"0."<<aa<<"*10^"<<(pa-ta>0?pa-ta:pa-ta+1)<<' ';
		if(tb==-1)
			cout<<"0."<<a.substr(pb+1,n)<<"*10^0"<<' ';
		else
			cout<<"0."<<bb<<"*10^"<<(pb-tb>0?pb-tb:pb-tb+1)<<endl;		
	}
	else
	{
		bool flag=0;
		if(pa-ta<n||pb-tb<n)
			flag=(a.substr(ta,n+1)==b.substr(tb,n+1));
		else
	 		flag=(a.substr(ta,n)==b.substr(tb,n));
		flag=(flag&&((pa-ta)==(pb-tb)));
		if(flag)
		{
			string aa=a.substr(ta,n+1);
			if(aa.find('.')!=-1)
				aa.erase(aa.find('.'),1);
			else
		 		aa.erase(aa.length()-1,1);
			cout<<"YES"<<' '<<"0."<<aa<<"*10^"<<(pa-ta>0?pa-ta:pa-ta+1)<<endl;
		}
		else
		{
			string aa=a.substr(ta,n+1);
			if(aa.find('.')!=-1)
				aa.erase(aa.find('.'),1);
			else
		 		aa.erase(aa.length()-1,1);
			string bb=b.substr(tb,n+1);
			if(bb.find('.')!=-1)
				bb.erase(bb.find('.'),1);
			else
				bb.erase(bb.length()-1,1);
			cout<<"NO"<<' '<<"0."<<aa<<"*10^"<<(pa-ta>0?pa-ta:pa-ta+1)<<' ';
			cout<<"0."<<bb<<"*10^"<<(pb-tb>0?pb-tb:pb-tb+1)<<endl;	
		}
	}
	return 0;
}
