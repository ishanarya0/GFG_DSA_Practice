#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
ll sold[10005];
ll mx,injured=0,killed=0;
vector<ll>tent[10005];
bool vis[10005]={false};
vector<ll>id;
void dfs(ll x)
{    mx=x;
     injured+=sold[x];
    deque<ll>q;
    q.push_front(x);
    while(!q.empty())
    {   
        ll f=q.front();
        q.pop_front();
        for(auto i:tent[f])
        {
            if(!vis[i])
            {
                vis[i]=true;
                q.push_front(i);
                injured+=sold[i];
                if(sold[mx]<sold[i])
                {
                     mx=i;
                }
                else if(sold[mx]==sold[i])
                {
                    mx=min(mx,i);
                }
            }
        }
    }
    killed+=sold[mx];
    injured-=sold[mx];
    id.pb(mx);

}
int main()
{
    ll n,m,x,y;
    cin>>n>>m;
    lp(i,1,n+1)
    {
        cin>>sold[i];
    }
    while(m--)
    {
         cin>>x>>y;
         tent[x].pb(y);
         tent[y].pb(x);
    }
    lp(i,1,n+1)
    {
        if(!vis[i])
        {   vis[i]=true;
            dfs(i);
        }
    }
    sort(id.begin(),id.end());
    cout<<killed<<" "<<injured<<"\n";
    lp(i,0,id.size())
    {
        cout<<id[i]<<" ";
    }
}
