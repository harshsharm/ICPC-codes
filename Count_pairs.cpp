#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ld;
#define v 100006
#define mod 1000000007
#define fori(i,l,n) for(int i=int(l);i<int(n);i++)
#define forI(i,n,l) for(int i=int(n);i>=int(l);i--)
#define in(n) scanf("%d",&n);
#define In(n) scanf("%lld",&n);
#define iin(n,m) scanf("%d %d",&n,&m);
#define IIN(n,m) scanf("%lld %lld",&n,&m);
#define Pr(n) printf("%lld\n",n);
#define pr(n,m) printf("%d %d\n",n,m);
#define flush fflush(stdout);
#define s(a) a.size()
#define pb push_back
#define sr(a) sort(a.begin(),a.end())
#define Sr(a,n) sort(a,a+n);
#define rv(a) reverse(a.begin(),a.end())
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >heapp;
priority_queue<pair<int,int> >heapp2;
vector<int>tree[v];
vector<pair<int,int> >tree1[v];
class comp{
	public:
		bool operator()(pair<int,int> n1,pair<int,int> n2)
		{
			return(n1.second > n2.second);
		}
};
map<ld,int>mp;
int main()
{
	int n;
	ld k,p;
	in(n);
	IIN(p,k);
	ld a[n+1];
	ld c=0;
	fori(i,0,n)
	{
		In(a[i]);
		ld temp = (a[i]*a[i])%p;
		ld ans = ((temp*temp)%p - (k*a[i])%p+p)%p;
		c+=mp[ans];
		mp[ans]++;
	}
	Pr(c);	
	return 0;
}
