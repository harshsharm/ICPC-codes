#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ld;
#define v 200006
#define mod 1000000007
#define fori(i,l,n) for(int i=int(l);i<int(n);i++)
#define forI(i,n,l) for(int i=int(n);i>=int(l);i--)
#define in(n) scanf("%d",&n);
#define In(n) scanf("%lld",&n);
#define iin(n,m) scanf("%d %d",&n,&m);
#define IIN(n,m) scanf("%lld %lld",&n,&m);
#define Pr(n) printf("%d\n",n);
#define pr(n,m) printf("%d %d\n",n,m);
#define flush fflush(stdout);
#define S(a) a.size()
#define pb push_back
#define sr(a) sort(a.begin(),a.end())
#define Sr(a,n) sort(a,a+n);
#define rv(a) reverse(a.begin(),a.end())
#define mp(u,w) make_pair(u,w)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >heapp;
priority_queue<pair<int,int> >heapp2;
vector<int>tree1[v];
vector<pair<int,int> >tree2[v];
class comp{
	public:
		bool operator()(pair<int,int> n1,pair<int,int> n2)
		{
			return(n1.second > n2.second);
		}
};
int dp[v];
int si[v];
bool color[v];
int dp2[v];
int par[v];
void dfs(int x)
{
	fori(i,0,S(tree1[x]))
	{
		int child = tree1[x][i];
		if(dp[child]==0)
		{
			dp[child]=1;
			dfs(child);
			si[x]+=si[child];
			par[child]=x;
		}
	}
	return;
}
void dfs2(int x)
{
	si[x]=1;
	fori(i,0,S(tree1[x]))
	{
		int child = tree1[x][i];
		if(dp2[child]==0)
		{
			dp2[child]=1;
			dfs2(child);
			si[x]+=si[child];
		}
	}
	return;
}
int main()
{
	int n;
	in(n);
	fori(i,0,n+1)
		si[i]=1;
	fori(i,0,n-1)
	{
		int u,w;
		iin(u,w);
		tree1[u].pb(w);
		tree1[w].pb(u);
	}
	dp[1]=1;
	par[1]=1;
	dfs(1);
	pair<int,int>pa[n+1];
	fori(i,0,n)
	{
		pa[i] = mp(si[i+1],i+1);
		//cout<<si[i+1]<<" ";
	}
//	cout<<endl;
	Sr(pa,n);
	int ru;
	int j=0;
	int mini = INT_MAX;
	int p;
	while(si[pa[j].second]==1)
	{
		if(par[pa[j].second] == 1)
		{
			ru=pa[j].second;
			break;
		}
		if(mini>si[par[pa[j].second]])
		{
			p=par[pa[j].second];
			ru=pa[j].second;
			mini = si[par[pa[j].second]];
		}
		else if(mini = si[par[pa[j].second]] )
		{
	//		cout<<"ZDF"<<endl;
	//		cout<<ru<<" "<<p<<" "<<pa[j].second<<" "<<par[pa[j].second]<<endl;
			int ch=par[pa[j].second];
			int tp = p;
			while(1)
			{
				if(si[tp] == si[ch] && tp!=ch)
				{
					ch = par[ch];
					tp = par[tp];
				}
				else
				{
					if(si[ch]<si[tp])
					{
						p = tp;
						ru = pa[j].second;
					}
					break;
				}
			}
		//	cout<<ru<<" "<<p<<endl;
		}
		j++;
	}
	dp2[ru]=1;
//	cout<<ru<<endl;
	dfs2(ru);
	int ans=0;
	fori(i,1,n+1)
	{
	//	cout<<si[i]<<" ";
		ans+=si[i];
	}
	//cout<<endl;
	Pr(ans);
	return 0;
}
