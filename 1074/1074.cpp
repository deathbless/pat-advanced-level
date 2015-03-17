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
#include<map>
using namespace std;
#define MAXN 100000
map<string,string> l;
map<string,string> pre;
map<int,string> changes;
map<string,int> changen;

string start;
int A[MAXN+10],n,k;

void exchange(int a,int b)
{
	string sa=changes[a],sb=changes[b];
	string pa=pre[sa],pb=pre[sb];
	string na=l[sa],nb=l[sb];
	pre[sa]=pb;pre[sb]=pa;
	l[sa]=nb;l[sb]=na;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin>>start>>n>>k;
	for(int i=0;i<n;i++)
	{
		string t1,t2;int t;
		cin>>t1>>t>>t2;
		changes[t]=t1;
		l[t1]=t2;pre[t2]=t1;
		changen[t1]=t;
	}
	pre[start]="0";
	int num=1,tn=0;string now,next;
	A[num]=changen[start];now=start;
	while(now!="-1")
	{
		next=l[now];tn=changen[now];
		A[num++]=tn;
		now=next;
	}
	for(int i=1;i<=((num-1)/k);i++)
	{
		int tx=(i-1)*k+1,ty=tx+k-1;
		int tnownum=A[tx],tendnum=A[ty];
		string nowx=changes[tnownum],nowy=changes[tendnum];
		string startpre=pre[nowx],endnext=l[nowy];
		for(int j=1;j<=k;j++)
		{
			int x=j+(i-1)*k;
			int nownum=A[x];
			string nowa=changes[nownum];
			string nexta=l[nowa],prea=pre[nowa];
			l[nowa]=prea;pre[nowa]=nexta;
		}
		for(int j=1;j<=k/2;j++)
		{
			int x=j+(i-1)*k,y=k-j+1+(i-1)*k;
//			exchange(x,y);
			int t=A[x];A[x]=A[y];A[y]=t;
		}
		pre[nowy]=startpre;l[nowx]=endnext;
	}
	for(int i=1;i<num;i++)
	{
		cout<<changes[A[i]]<<' '<<A[i]<<' '<<l[changes[A[i]]]<<endl;
	}
	return 0;
}
