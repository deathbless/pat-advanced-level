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
#define MAXN 2000
map<string,int> c,m,e,a;
struct stu
{
	string idname;
	int data;
};

int N,M;
string name[MAXN+1];
int Tc[MAXN+1],Tm[MAXN+1],Te[MAXN+1],Ta[MAXN+1];
stu cc[MAXN+1],cm[MAXN+1],ce[MAXN+1],ca[MAXN+1];

bool cmp(stu a,stu b)
{
	return a.data>b.data;
}

int min(int a,int b)
{
	return a<b?a:b;
}

void query(string t)
{
	bool have=0;
	for(int i=0;i<N;i++)
		if(name[i]==t)
			have=1;
	if(!have)
	{
		cout<<"N/A"<<endl;
		return;
	}
	int tans=MAXN+1,type=0;//1=a 2=c 3=m 4=e
	if(tans>a[t])
		tans=a[t],type=1;
	if(tans>c[t])
		tans=c[t],type=2;
	if(tans>m[t])
		tans=m[t],type=3;
	if(tans>e[t]) 
		tans=e[t],type=4;
	cout<<tans+1<<' ';
	switch(type)
	{
		case 1:cout<<"A"<<endl;break;
		case 2:cout<<"C"<<endl;break;
		case 3:cout<<"M"<<endl;break;
		case 4:cout<<"E"<<endl;break;
	}
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		cin>>name[i]>>Tc[i]>>Tm[i]>>Te[i];
		Ta[i]=(int)((double)(Tc[i]+Tm[i]+Te[i])/3+0.5);
		cc[i].idname=name[i],cc[i].data=Tc[i];
		cm[i].idname=name[i],cm[i].data=Tm[i];
		ce[i].idname=name[i],ce[i].data=Te[i];
		ca[i].idname=name[i],ca[i].data=Ta[i];
	}
	sort(ca,ca+N,cmp);
	sort(cc,cc+N,cmp);
	sort(cm,cm+N,cmp);
	sort(ce,ce+N,cmp);
	for(int i=0;i<N;i++)
	{
		a[ca[i].idname]=(i==0?i:(ca[i].data==ca[i-1].data?a[ca[i-1].idname]:i));
		c[cc[i].idname]=(i==0?i:(cc[i].data==cc[i-1].data?c[cc[i-1].idname]:i));
		m[cm[i].idname]=(i==0?i:(cm[i].data==cm[i-1].data?m[cm[i-1].idname]:i));
		e[ce[i].idname]=(i==0?i:(ce[i].data==ce[i-1].data?e[ce[i-1].idname]:i));
	}
/*	map<string,int>::iterator i;
	for(i=e.begin();i!=e.end();i++)
		cout<<i->first<<' '<<i->second<<endl;*/
	for(int i=0;i<M;i++)
	{
		string t;
		cin>>t;
		query(t);
	}
	return 0;
}
