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
#define MAXN 1000
int n;
double m;
struct node
{
	double price;
	int num;
	node(){}
};
double a[MAXN+1],b[MAXN+1],ans=0;
node c[MAXN+1];

/*int cmp(const void *a,const void *b)
{
	return ((*(node *)b).price>(*(node *)a).price);
}*/
int cmp(node a,node b)
{
	return a.price>b.price;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		c[i].price=b[i]/a[i],c[i].num=i;
	//qsort(c,n,sizeof(node),cmp);
	sort(c,c+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(a[c[i].num]!=0&&m>0)
		{
			if(m>=a[c[i].num])
			{
				ans+=b[c[i].num];
				m-=a[c[i].num];
				a[c[i].num]=0;
			}
			else
			{
				ans+=(m*c[i].price);
				m=0;
				a[c[i].num]=0;
			}
		}
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
