#include <iostream>  
#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;   


int main()  
{   

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("opps.txt","w",stdout);
    #endif    
    string s;
    cin>>s;
    stack<char> st;
    int pc=0,nc=0;
    for(int i=0;i<s.length();i++)
    {   
        if(st.empty())
            {st.push(s[i]);
            continue;}
        if(st.top()==s[i])
        {
            st.pop();
        }
        else
            st.push(s[i]);

    }
    if(st.empty())
        cout<<"YES";
    else
        cout<<"NO";
}  