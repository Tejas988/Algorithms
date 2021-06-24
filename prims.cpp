// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
//    //priority queue will hold the lowest one

//    int main()
//    {
//    	#ifndef ONLINE_JUDGE
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif
// 		int n,m;
// 		cin>>n>>m;
// 		vector<pair<int,int>> adj[n+1];
// 		for(int i=0;i<m;i++)
// 		{
// 			int x,y,w;
// 			cin>>x>>y>>w;
// 			adj[x].push_back({y,w});
// 			adj[y].push_back({x,w});
// 		}
// 	  unordered_map<int,int> edge_length;
//       unordered_map<int,bool> visited;
//       for(int i=0;i<n;i++)
//         {
//             edge_length[i]=INT_MAX;
//             visited[i]=false;
//         }
//       edge_length[0]=0;
//       priority_queue< pair<int,int>, vector < pair<int,int>> , greater< pair<int,int>> > pq; //will give the node with lowest edge_length
//       pq.push(make_pair(0,0));
//       int ans=0;
//        while(!pq.empty())
//       {	
//          auto p=pq.top();
//         bool f=false;
//          while(visited[p.second])
//          {    
//              pq.pop();//checking if it is already explored or not
//              if(pq.empty())
//              {  f=true;
//                  break;
//              }
//              p=pq.top();
//          }
//          if(f)
//          break;
//          visited[p.second]=1;
//          int node=p.second;
//          ans+=p.first;
//          pq.pop();
//          for(auto child:adj[node])
//          {
//          	if(!visited[child.first])
//             {
//             	if(child.second < edge_length[child.first])
//             {
//                pq.push({child.second,child.first});
//                edge_length[child.first]=child.second;
//             }
//         	}
//          }
//       }
//       cout<<ans<<endl;

//    	return 0;
//    }
