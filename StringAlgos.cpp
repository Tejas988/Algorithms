

// z func gives length of max suffix starting at ith index which is equal to prefix
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// pi func used in KMP
 void calcPrefSuf(string &s,vector<int> &prefsuf)
    {
        int n=s.length();
        int i=0,j=1;
        while(j<n and i<j)
        {
            if(s[i]==s[j])
            {
                prefsuf[j]=i+1;
                i+=1;
                j+=1;
            }
            else
            {   
                if(i==0)
                {   
                    j+=1;
                    i=0;
                }
                else
                {   
                    i=prefsuf[i-1];
                }
            }
        }
        return;
    }