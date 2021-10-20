// #include <iostream>
// #include<bits/stdc++.h>
// #include <math.h>
// using namespace std;
// float ND=cos(M_PI/2);


// void Shifting()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//     }
//     int k,origin;
//     cout<<"Enter shift value and origin"<<endl;
//     cin>>k>>origin;
//     int y[n]={0};
//     for(int i=0;i<n;i++)
//     {
//         int ni=i-k+origin;
//         if(ni>=0 and ni<n)
//         {

//             y[i]=x[ni];
//         }
//     }
//     cout<<" y(n) is : ";
//     for(int i=0;i<n;i++)
//     {

//         cout<<y[i]<<" ";
//     }
//     cout<<endl;
//     cout<<"New origin is :"<<y[origin]<<endl;
//     return;
// }
// void Reversal()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//     }
//     int y[n]={0};
//     cout<<"Enter origin"<<endl;
//     int origin;
//     cin>>origin;
//     for(int i=0;i<n;i++)
//     {
//         y[i]=-x[i];
//     }
//     cout<<" y(n) is : ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<y[i]<<" ";
//     }
//     cout<<"New origin is : "<<y[origin]<<endl;
// }
// void ReversalShifting()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//     }
//     int y[n]={0};
//     cout<<"Enter origin "<<endl;
//     int origin;
//     cin>>origin;
//     for(int i=0;i<n;i++)
//     {
//         y[i]=-x[i];
//     }
//     cout<<" reversed y(n) is : ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<y[i]<<" ";
//     }
//     cout<<"New origin is : "<<y[origin]<<endl;
//     cout<<"Enter k"<<endl;
//     int k;
//     cin>>k;
//     int y1[n]={0};
//     for(int i=0;i<n;i++)
//     {
//         int ni=i-k+origin;
//         if(ni>=0 and ni<n)
//         {

//             y1[i]=y[ni];
//         }
//     }
//     cout<<"Reversed and Shifted y(n) is : ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<y1[i]<<" ";
//     }
//     cout<<"New origin is : "<<y1[origin]<<endl;
//     return;
// }
// void TimeScaling()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//     }
//     int y[n]={0};
//     float lambda=0;
//     cout<<"Enter scaling factor (lambda)"<<endl;
//     cin>>lambda;
   
//     for(int i=0;i<n;i++)
//     {
//         float ni=lambda*i;
//         int nint=(int)ni;
//         if(ni==nint)
//         {
//             if(nint>=0 and nint<n)
//             {
//                 y[i]=x[nint];
//             }
//         }
//     }
//     cout<<" y(n) is : ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<y[i]<<" ";
//     }
//     cout<<endl;
//     return;
// }

// void ScalarMultiplication()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//     }
//     cout<<"Enter value of a\n";
//     int y[n]={0};
//     int a;
//     cin>>a;
//     for(int i=0;i<n;i++)
//     {
//         y[i]=a*x[i];
//     }
//     cout<<" y(n) is :";
//     for(int i=0;i<n;i++)
//     {
//         cout<<y[i]<<" ";
//     }
//     cout<<endl;
//     return;
// }
// void SignalMultiplier()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x1(n)"<<endl;
//     int x1[n],x2[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x1[i];
//     }
//     cout<<"Enter x2(n)"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cin>>x2[i];
//     }
//     cout<<"Enter origin of both signals respectively"<<endl;
//     int o1,o2;
//     cin>>o1>>o2;
//     list<int> yn;
//     int i=o1,j=o2;
//     int cnt=0;
//     while(i!=0 and j!=0)
//     {
//         i-=1;
//         j-=1;
//     }
//     if(i==0)
//     {
//         int cj=0;
//         while(cj<j)
//             yn.push_back(0),cj++;
//     }
//     if(j==0)
//     {
//         int ci=0;
//         while(ci<i)
//             yn.push_back(0),ci++;
//     }
//     while(i<n and j<n)
//     {   
//         cnt+=1;
//         yn.push_back(x1[i]*x2[j]);
//         i+=1;
//         j+=1;
//     }  
//     while(j<n)
//     {
//          yn.push_back(0);
//          j+=1;
//     }
//     while(i<n)
//     {
//          yn.push_back(0);
//          i+=1;
//     }
//     cout<<" y(n) is :";
//     for(auto x:yn)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     return;

// }
// void SignalAdder()
// {
//     int n;
//     cout<<"Enter number of points"<<endl;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x1[n],x2[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>x1[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cin>>x2[i];
//     }
//     cout<<"Enter origin of both signals respectively"<<endl;
//     int o1,o2;
//     cin>>o1>>o2;
//     list<int> yn;
//     int i=o1,j=o2;
//     int cnt=0;
//     while(i!=0 and j!=0)
//     {
//         i-=1;
//         j-=1;
//     }
//     if(i==0)
//     {
//         int cj=0;
//         while(cj<j)
//             yn.push_back(x2[cj++]);
//     }
//     if(j==0)
//     {
//         int ci=0;
//         while(ci<i)
//             yn.push_back(x1[ci++]);
//     }
//     while(i<n and j<n)
//     {   
//         cnt+=1;
//         yn.push_back(x1[i]+x2[j]);
//         i+=1;
//         j+=1;
//     }  
//     while(j<n)
//     {
//          yn.push_back(x2[j]);
//          j+=1;
//     }
//     while(i<n)
//     {
//          yn.push_back(x1[i]);
//          i+=1;
//     }
//     cout<<" y(n) is :";
//     for(auto x:yn)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     return;

// }


// void LinearConvolution()
// {
//     cout<<"Enter size of x(n) and origin\n";
//     int n;
//     cin>>n;
//     int o1,o2,o;
//     cin>>o1;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//         cin>>x[i];
//     cout<<"Enter size of h(n) and origin\n";
//     int m;
//     cin>>m>>o2;
//     o=o1-o2;
//     cout<<"Enter h(n)\n";
//     int h[m];
//     for(int i=0;i<m;i++)
//         cin>>h[i];
//     int mat[n][m];
//     memset(mat,0,sizeof mat);
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             mat[i][j]=h[i]*x[j];
//         }
//     }
//     vector<int> y;
//     for(int i=0;i<m;i++)
//     {
//         int xi=i;
//         int j=0;
//         int sum=0;
//         while(xi>=0 and j<n)
//         {
//             sum+=mat[xi][j];
//             xi-=1;
//             j+=1;
//         }
//         y.push_back(sum);
//     }
//     for(int j=1;j<n;j++)
//     {
//         int i=m-1;
//         int xj=j;
//         int sum=0;
//         while(xj<n and i>=0)
//         {
//             sum+=mat[i][xj];
//             i-=1;
//             xj+=1;
//         }
//         y.push_back(sum);
//     }
//     cout<<"y(n) is :"<<endl;
//     for(auto &z:y)
//     {
//         cout<<z<<" ";
//     }
//     if(o>=0)
//     {
//         cout<<"New origin is : "<<y[0]<<endl;
//         return;
//     }
//     int i=0;
//     while(o!=0)
//     {
//         o+=1;
//         i+=1;
//     }
//     cout<<"New origin is : "<<y[i]<<endl;
    
//     return;
// }

// void CircularConvolution()
// {
//     cout<<"Enter size of x1(n)\n";
//     cout<<"Enter size of x2(n)\n";
//     int n,m;
//     cin>>n>>m;
//     int ms=max(n,m);
    
//     cout<<"Enter x1(n)\n";
//     int x1[ms];
//     memset(x1,0,sizeof x1);
//     for(int i=0;i<n;i++)
//         cin>>x1[i];
//     int x2[ms];
//     cout<<"Enter x2(n)\n";

//     memset(x2,0,sizeof x2);
//     for(int i=0;i<m;i++)
//         cin>>x2[i];
//     int mat[ms][ms];
//     memset(mat,0,sizeof mat);
//     for(int i=0;i<ms;i++)
//     {
        
//         for(int k=0;k<ms;k++)
//         {   
//             mat[i][k]=x1[k]*x2[i];    
//         }
//     }
//     vector<int> y;
//     for(int i=0;i<ms;i++)
//     {   
//         int sum=0;
        
//         if(sum!=0)
//         y.push_back(sum);
//     }
//     cout<<"y(n) is :"<<endl;
//     for(auto &x:y)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }

// void CrossCorrelation()
// {
//     cout<<"Enter size of x(n) \n";
//     int n;
//     cin>>n;
   
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//         cin>>x[i];
//     cout<<"Enter size of h(n) \n";
//     int m;
//     cin>>m;
//     cout<<"Enter h(n)\n";
//     int h[m];
//     for(int i=0;i<m;i++)
//         cin>>h[i];
//     int mat[m][n];
//     memset(mat,0,sizeof mat);
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             mat[i][j]=h[i]*x[j];
//         }
//     }
//     vector<int> y;
//     int origin=0;
//     for(int i=m-1;i>=0;i--)
//     {
//         int xi=i;
//         int j=0;
//         int sum=0;
//         while(xi<m and j<n)
//         {
//             sum+=mat[xi][j];
//             xi+=1;
//             j+=1;
//         }
//         origin=sum;
//         y.push_back(sum);
//     }
//     for(int j=1;j<n;j++)
//     {
//         int i=0;
//         int xj=j;
//         int sum=0;
//         while(xj<n and i<m)
//         {
//             sum+=mat[i][xj];
//             i+=1;
//             xj+=1;
//         }
//         y.push_back(sum);
//     }
//     cout<<"y(n) is :"<<endl;
//     for(auto &z:y)
//     {
//         cout<<z<<" ";
//     }
//     cout<<"\nOrigin is "<<origin<<endl;
// }

// void AutoCorrelation()
// {
//     cout<<"Enter size of x(n) \n";
//     int n;
//     cin>>n;
//     cout<<"Enter x(n)"<<endl;
//     int x[n];
//     for(int i=0;i<n;i++)
//         cin>>x[i];
//     int mat[n][n];
//     memset(mat,0,sizeof mat);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             mat[i][j]=x[i]*x[j];
//         }
//     }
//     vector<int> y;
//     int origin=0;
//     for(int i=n-1;i>=0;i--)
//     {
//         int xi=i;
//         int j=0;
//         int sum=0;
//         while(xi<n and j<n)
//         {
//             sum+=mat[xi][j];
//             xi+=1;
//             j+=1;
//         }
//         origin=sum;
//         y.push_back(sum);
//     }
//     for(int j=1;j<n;j++)
//     {
//         int i=0;
//         int xj=j;
//         int sum=0;
//         while(xj<n and i<n)
//         {
//             sum+=mat[i][xj];
//             i+=1;
//             xj+=1;
//         }
//         y.push_back(sum);
//     }
    
//     cout<<"y(n) is :"<<endl;
//     for(auto &z:y)
//     {
//         cout<<z<<" ";
//     }
//     cout<<"\nOrigin is "<<origin<<endl;
// }





// float roundoff(float value, unsigned char prec)
// {
//   float pow_10 = pow(10.0f, (float)prec);
//   return round(value * pow_10) / pow_10;
// }

// float returnCosValue(int n,int i)
// {
//     float angle=(2*i*M_PI)/(float)n;
//     return roundoff((float)cos(angle),2);
// }

// float returnSinValue(int n,int i)
// {
//     float angle=(2*i*M_PI)/(float)n;
//     return roundoff((float)sin(angle),2);
// }

 
// void DFFT()
// {
//     cout<<"Enter value of n\n";
//     int n;
//     cin>>n;
//     cout<<"Enter x(n)\n";
//     int x[n];
//     for(int i=0;i<n;i+=1)
//         cin>>x[i];
//     pair<float,float> W[n];
//     for(int i=0;i<n;i++)
//     {
//         W[i].first=returnCosValue(n,i);
//         W[i].second=-returnSinValue(n,i);
//         cout<<"W "<<n<<" of "<<i<<" : "<<W[i].first<<" "<<W[i].second<<endl;
//     }
//     pair<float,float> y[n];
//     for(int i=0;i<n;i++)
//     {
//         float real=0;
//         float img=0;
//         for(int j=0;j<n;j++)
//         {
//             real=real+W[(j*i)%n].first*x[j];
//             img=img+W[(j*i)%n].second*x[j];
//         }
//         y[i].first=real;
//         y[i].second=img;
//     }
//     cout<<"Y(n) is :"<<endl;
//     for(int i=0;i<n;i+=1)
//     {   
//         cout<<"("<<y[i].first<<" , "<<y[i].second<<")"<<"   magnitude is : "<<sqrt(pow(y[i].first,2)+pow(y[i].second,2))<<" &  phase is : "<<atan(y[i].second/y[i].first)<<endl;
//     }

// }


// void NQIST()
// {

//     cout<<"Enter analog signal"<<endl;
    

// }


// int main()
// {   

   
//     return 0;
// }
