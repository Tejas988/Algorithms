#include <iostream>

using namespace std;
int ans=0;
void Merge(int A[],int low,int mid,int high)
{   int i=low,j=mid+1,k=low;
    int B[100];
    // int cnt=0;
    while(i<=mid && j<=high)
    {
        if(A[i]<=A[j])
            B[k++]=A[i++];
        else
        {    
            B[k++]=A[j++];
            ans+=mid-i+1;
        }

    }
        for(;i<=mid;i++)
            B[k++]=A[i];
        for(;j<=high;j++)
            B[k++]=A[j];

        for(i=low;i<=high;i++)
            A[i]=B[i];
        return ;
}

void MergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
     {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);  
     }
}


int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("opts.txt", "w", stdout);
    #endif
    
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    MergeSort(A,0,n-1);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
