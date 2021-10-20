#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll MOD = 1e9 + 7;
vector<int> tree[101];
bool goal=false;




void dfid(int src,int dest,string &path,int curlvl,int lvl,int par)
{ 

  if(path!="")
    path=path+" -> ";
  path+='0'+src;
  if(src==dest)
  {  
    goal=true;
    return;
  }
  if(lvl==curlvl)
  {
    return;
  }
  for(auto x:tree[src])
  {   
    if(x==par)
      continue;
    dfid(x,dest,path,curlvl+1,lvl,src);
    if(goal)
      break;
  }
  return;
}

void solve()
{ 
  cout<<"Enter number of nodes in tree"<<endl;
  int n;
  cin>>n;
  cout<<"Enter edges of tree"<<endl;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  cout<<"Enter source and destination"<<endl;
  int src,dest;
  cin>>src>>dest;
  cout<<"Enter maximum depth of tree"<<endl;
  int maxdepth;
  cin>>maxdepth;
  for(int cur_lvl=1;cur_lvl<=maxdepth;cur_lvl+=1)
  { 
    string path="";
    dfid(src,dest,path,1,cur_lvl,-1);
    if(goal)
    {
      cout<<"The required path is : "<<path<<endl;
      return;
    }
  }
  cout<<"Path not found"<<endl;
  return; 
}
    



int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("opts.txt", "w", stdout);
// #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t-- )
  {
    solve();
  }
  return 0;

}
