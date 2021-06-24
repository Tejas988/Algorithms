#include<bits/stdc++.h>
using namespace std;

char returnASCI(char x,int key,int type)
{	
	key%=26;
    if(x>='a' and x<='z')
    {   
        if(type==1)
        return (char)(((x-'a'+key+26)%26)+'a');
        return (char)(((x-'a'-key+26)%26)+'a');
    }
    else if(x>='A' and x<='Z')
    {   

        if(type==1)
        return (char)(((x-'A'+key+26)%26)+'A');
        return (char)(((x-'A'-key+26)%26)+'A');
    }
    else if(x>='0' and x<='9')
    {   
        key%=10;
        if(type==1)
        return (char)(((x-'0'+key+10)%10)+'0');  
        return (char)(((x-'0'-key+10)%10)+'0');
    }
    return ' ';
}

char returnMulASCI(char x,int inv)
{
    if(x>='a' and x<='z')
    {   
    	int asci=x-'a';
       	asci=(inv*asci)%26;
        return (char)(asci+'a');
     
    }
    else if(x>='A' and x<='Z')
    {   
        int asci=x-'A';
       	asci=(inv*asci)%26;
       
        return (char)(asci+'A');
      
    }
    else if(x>='0' and x<='9')
    {   
    	inv%=10;
        int asci=x-'0';
       	asci=(inv*asci)%10;
        return (char)(asci+'0');
    }
    return ' ';
}
void Decrypt_Ceaser(string &s)
{
	
	cout<<"\n";
	cout<<"Decryption using Brute Attack\n";
	for(int key=1;key<=26;key++)
	{

		string text="";
		for(int i=0;i<s.length();i++)
		{	
		    if(s[i]==' ')
		    {
		        text+=s[i];
		        continue;
		    }
			text+=returnASCI(s[i],key,0);
		}
		cout<<"Plain text for key "<<key<<" is "<<text<<endl;
	}		
	return;
}

void Decrypt_Multiplicative(string &s)
{
	
	cout<<"\n";
	cout<<"Decryption using Brute Attack\n";
	for(int key=1;key<=26;key++)
	{

		string text="";
		int a_inverse=-1;
		for (int i = 0; i < 26; i++) 
		{	

	     int  flag = (key * i) % 26;
	     
	      if (flag == 1) {
	         a_inverse = i;
			}
		}
		if(a_inverse==-1)
			{
				cout<<"INVALID\n"<<endl;
				continue;
			}
		for(int i=0;i<s.length();i++)
		{	
		    if(s[i]==' ')
		    {
		        text+=s[i];
		        continue;
		    }
		    text+=returnMulASCI(s[i],a_inverse);
   		}
		cout<<"Plain text for key "<<key<<" is "<<text<<endl;
	}		
	return;
}
void Ceaser_Encrypt()
{	
	cout<<"Enter string to be encrypted : ";
	string s;
	getline(cin,s);
	while (s.length()==0 ) 
            getline(cin, s); 
	cout<<"Enter Key for Ceaser Cipher\n";
	int key;
	cin>>key;
	string ans;
	for(int i=0;i<s.length();i++)
	{		
		if(s[i]==' ')
		{	
			ans+=' ';
			continue;		
		}
		ans+=returnASCI(s[i],key,1);
	}
	cout<<"Encrypted text is "<<ans<<endl;
	Decrypt_Ceaser(ans);
}
void Multiplicative_Encrypt()
{	
	cout<<"Enter string to be encrypted\n";
	string s;
	getline(cin,s);
	while (s.length()==0 ) 
            getline(cin, s); 
	cout<<"Enter Key for Multiplicative Cipher\n";
	int key;
	cin>>key;
	string ans="";
	for(int i=0;i<s.length();i++)
	{		
		if(s[i]==' ')
		{	
			ans+=' ';
			continue;		
		}
		ans+=returnMulASCI(s[i],key);
	}
	cout<<"Encrypted text is "<<ans<<endl;
	Decrypt_Multiplicative(ans);
}




void DecryptColumnar(string cipher,string keyword)
{	
	int col=keyword.length();
	int ar[26]={0};
	string cpy;
	cpy=keyword;
	sort(cpy.begin(),cpy.end());
	for(int i=0;i<cpy.length();i++)
	{	
		int x=cpy[i]-'A';
		ar[x]=i;
	}
	int seq[col];
	for(int i=0;i<col;i++)
	{	
		int x=keyword[i]-'A';
		seq[ar[x]]=i;
	}
	int row;
	row=cipher.length()/col;
	char mat[row][col];
	int l=0;
	for(int i=0;i<col;i++)
	{	
		int k=seq[i];
		for(int j=0;j<row;j++)
		{
			mat[j][k]=cipher[l++];
		}
	}
	cout<<"The decrypted text is : ";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<mat[i][j];
	}
 
}


void EncryptColumnar()
{
	cout<<"Tejas Ghone B3 60004180110\n";
	cout<<"Enter text\n";
	string text;
	getline(cin,text);
	while (text.length()==0) 
            getline(cin, text); 
	cout<<"Enter keyword\n";
	string keyword;
	cin>>keyword;
	int col=keyword.length();
	int ar[26]={0};
	string cpy;
	cpy=keyword;
	sort(cpy.begin(),cpy.end());
	for(int i=0;i<cpy.length();i++)
	{	
		int x=cpy[i]-'A';
		ar[x]=i;
	}
	int seq[col];
	for(int i=0;i<col;i++)
	{	
		int x=keyword[i]-'A';
		seq[ar[x]]=i;
	}

	int row;
	if(text.length()%col)
	{
		row=text.length()/col + 1;
	}
	else
		row=text.length()/col;
	char mat[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			mat[i][j]=' ';
	}
	
	int k=0;
	for(int i=0;i<row;i++)
	{	

		for (int j = 0; j < col; ++j)
		{	
			if(k==text.length())
				break;
			mat[i][j]=text[k++];
		}
		if(k==text.length())
				break;
	}
	string encrypted="";
	for(int i=0;i<col;i++)
	{	
		int k=seq[i];
		for(int j=0;j<row;j++)
		{
			encrypted+=mat[j][k];
		}
	}
	cout<<"Encrypted text is : "<<encrypted<<endl;
	DecryptColumnar(encrypted,keyword);
}

void DecryptCustomColumnar(string cipher,string keyword)
{	
	int col=keyword.length();
	int ar[26]={0};
	string cpy;
	cpy=keyword;
	sort(cpy.begin(),cpy.end());
	for(int i=0;i<cpy.length();i++)
	{	
		int x=cpy[i]-'A';
		ar[x]=i;
	}
	int seq[col];
	for(int i=0;i<col;i++)
	{	
		int x=keyword[i]-'A';
		seq[ar[x]]=i;
	}
	int row;
	row=col;
	char mat[row][col];
	int l=0;
	for(int i=0;i<col;i++)
	{	
		int k=seq[i],st=0;
		int ed=row-1,j=col-1-k;
		while(st<=j)
		{
			mat[st][k]=cipher[l++];
			if(j!=st)
			{
				mat[j][ed]=cipher[l++];
			}
			st+=1;
			k++;
			j--;
			ed--;
		}
	}
	cout<<"The decrypted text is : ";
	for(int i=0;i<row;i++)
	{
		for(int j=i;j<col;j++)
			cout<<mat[i][j];
	}
 
}


void Decrypt_Custom_Ceiser(string &text,int key)
{
	
	cout<<"\n";
	cout<<"Decryption \n";
	
		string ans="";
		for(int i=0;i<text.length();i++)
	    {	
	    	if(text[i]==' ')
			{	
				ans+=' ';
				continue;		
			}
	    	int p=i%30;
	    	int mask=1<<p;
	    	int displace=1;
	    	if(mask & key)
	    	{
	    		displace=mask;
	    	}
			char c=returnASCI(text[i],displace,0);
			ans+=c;
			// cout<<c<<" "<<text[i]<<" "<<displace<<endl;

	    }
		cout<<"Plain text for key "<<key<<" is "<<ans<<endl;
	
	return;
}
void CustomCeiser()
{
	cout<<endl;
	cout<<"Siddharth Salvi B3 60004180105\n";
	cout<<"Tejas Ghone B3 60004180110\n";
	cout<<"    CUSTOM CEISER   "<<endl;
	cout<<"Enter text\n";
	string text;
	getline(cin,text);
	while (text.length()==0) 
            getline(cin, text); 
    cout<<"Enter key"<<endl;
    int key;
    cin>>key;
    // int i=0;
    string ans="";
    cout<<text<<endl;
    for(int i=0;i<text.length();i++)
    {	
    	if(text[i]==' ')
		{	
			ans+=' ';
			continue;		
		}
    	int p=i%30;
    	int mask=1<<p;
    	int displace=1;
    	if(mask & key)
    	{
    		displace=mask;
    	}
		char c=returnASCI(text[i],displace,1);
		// cout<<c<<" "<<text[i]<<" "<<displace<<endl;
		ans+=c;

    }
    cout<<"Encrypted text is : "<<ans<<endl;
    Decrypt_Custom_Ceiser(ans,key);
}

void EncryptCustomColumnar()
{	
	cout<<endl;
	cout<<"Siddharth Salvi B3 60004180105\n";
	cout<<"Tejas Ghone B3 60004180110\n";
	cout<<"    CUSTOM COLUMNAR TRANSPOSITION    "<<endl;
	cout<<"Enter text\n";
	string text;
	getline(cin,text);
	while (text.length()==0) 
            getline(cin, text); 
	cout<<"Enter keyword\n";
	string keyword;
	cin>>keyword;
	int col=keyword.length();
	int ar[26]={0};
	string cpy;
	cpy=keyword;
	sort(cpy.begin(),cpy.end());
	for(int i=0;i<cpy.length();i++)
	{	
		int x=cpy[i]-'A';
		ar[x]=i;
	}
	int seq[col];
	for(int i=0;i<col;i++)
	{	
		int x=keyword[i]-'A';
		seq[ar[x]]=i;
	}
	int row=col;
	char mat[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			mat[i][j]=' ';
	}
	int k=0;
	for(int i=0;i<row;i++)
	{	
		for(int j=i;j<col;j++)
		{
			if(k==text.length())
				break;
			mat[i][j]=text[k++];	
		}
		if(k==text.length())
				break;
	}
	string encrypted="";

	for(int i=0;i<col;i++)
	{	for(int j=0;j<col;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0;i<col;i++)
	{	
		int k=seq[i],st=0;
		int ed=row-1,j=col-1-k;
		while(st<=j)
		{
			encrypted+=mat[st][k];
			if(j!=st)
			{
				encrypted+=mat[j][ed];
			}
			st+=1;
			k++;
			j--;
			ed--;
		}
	}
	cout<<"Encrypted text is : "<<encrypted<<endl;
	DecryptCustomColumnar(encrypted,keyword);
}

int main()
{	
	
	CustomCeiser();
	return 0;
}