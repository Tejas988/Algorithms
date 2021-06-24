 int minimumSwaps(vector<int> arr) {
    
    int n=arr.size();
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++)
    {
        vp.push_back({arr[i],i});
    }
    sort(vp.begin(),vp.end());
    vector<int> vis(n,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {   
        int idx=vp[i].second;
        if(idx==i or vis[idx])
            continue;
        int cnt=-1;
        while(!vis[idx])
        {
            vis[idx]=1;
            idx=vp[idx].second;
            cnt+=1;
        }
        ans+=cnt;
    }
    return ans;
}