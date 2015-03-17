#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

deque<int> q;
int main()
{
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c<0)
		cout<<'-',c=-c;
	if(c==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	while(c)
	{
		q.push_back(c%1000);
		c/=1000;
	}
	cout<<q.back();q.pop_back();
	while(!q.empty())
	{
		cout<<",";
		int t=q.back();
		if(t/100==0)
			cout<<"0";
		if(t/10==0)
			cout<<"0";
		if(t==0)
			cout<<"0";
		else
			cout<<t;
		q.pop_back();
	}
	cout<<endl;
	return 0;
}
