#include <bits/stdc++.h>
using namespace std; 
typedef complex<double> comp;
 
vector<comp> fft(vector<comp>& a)
{
    int n = a.size();
    if (n == 1)
        return vector<comp>(1, a[0]);
    vector<comp> w(n);
    for (int i = 0; i < n; i++) {
        double angle = -2 * M_PI * i / n;
        w[i] = comp(cos(angle), sin(angle));
    }
    vector<comp> P0(n / 2), P1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        P0[i] = a[i * 2];
        P1[i] = a[i * 2 + 1];
    }
    vector<comp> y0 = fft(P0);
    vector<comp> y1 = fft(P1);
    vector<comp> y(n);
    for (int k = 0; k < n / 2; k++) {
        y[k] = y0[k] + w[k] * y1[k];
        y[k + n / 2] = y0[k] - w[k] * y1[k];
    }
    return y;
}
 
int main()
{
    
    int n;
    cout<<"Give signal length\n";
    cin>>n;
    bool isvalid=false;
    for(int i=0;i<20;i++)
    {
        int mask=1<<i;
        if(n==mask)
            isvalid=true;
    }
    if(!isvalid)
    {
        cout<<"Invalid input\n";
        return 0;
    }
    cout<<"Give signal values\n";
    vector<comp> a(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
    }
    vector<comp> b = fft(a);
    cout<<"Output:\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << endl;
    return 0;
}