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
    