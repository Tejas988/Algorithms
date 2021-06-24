#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
ll cost[101];
ll dp[101][101][101];
ll maxprof[101];
//dp[g of i][g of j][extra]
int n;
ll solve(vector<ll> &grp,int i,int j,int extra)
{
    if(i>j)return 0;
    if(dp[i][j][extra]!=-1)
        return dp[i][j][extra];
    ll ans=0;
    ans=maxprof[grp[i]+extra]+solve(grp,i+1,j,0);//solving the current grp and recursing on next
    for(int k=i+2;k<=j;k+=2)
    {
        ans=max(ans,solve(grp,i+1,k-1,0)+solve(grp,k,j,extra+grp[i]));
    }
    return dp[i][j][extra]=ans;

}

void rodcut()
{
    memset(dp,-1,sizeof(dp));
    memset(maxprof,0,sizeof(maxprof));
    for(int len=1;len<=n;len++)
    {
        for(int cut=1;cut<=len;cut++)
        {
            maxprof[len]=max(maxprof[len],cost[cut]+maxprof[len-cut]);
        }
    }

    return;
}

int main(){
    // write your code
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("otpt.txt","w",stdout);
    #endif
    ll t=1;
    // cin>>t;
    while(t--)
    {
       cin>>n;
       string s;
       cin>>s;
       s+='A';
       memset(cost,0,sizeof(cost));
       for(int i=0;i<n;i++)cin>>cost[i+1];
       rodcut();
       vector<ll> grp;
       int cnt=1;
       for(int i=0;i<s.length()-1;i++)
       {    
            if(s[i]==s[i+1])
                cnt+=1;
            else
            {
                grp.push_back(cnt);
                cnt=1;
            }
       }  
       cout<<solve(grp,0,grp.size()-1,0)<<endl;
    }
    return 0;
}




// bool cmp(pair<ll,ll> a,pair<ll,ll> b)
// {
//     if(a.first<b.first)
//         return false;
//     return true;
// }