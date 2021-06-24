#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


class Node
{
public:
	char data;
	unordered_map<char,Node*> children;
	bool terminal;

	Node(char d)
	{
		data=d;
		terminal=false;
	}
};

class Trie
{
	Node* root;
	int cnt;//denotes no of words inserted

public:
	Trie()
	{
		root=new Node('\0');
		cnt=0;
	}
	void insert(string w)
	{
		Node* temp=root;
		for(int i=0;i<w.length();i++)
		{
			char ch=w[i];
			if(temp->children[ch])//checking if that character exists
			{
				temp=temp->children[ch];
			}
			else
			{
				Node* newnode=new Node(ch);
				temp->children[ch]=newnode;
				temp=newnode;
			}
		}
		temp->terminal=true;//word ends here
	}

	bool find(string w)
	{
		Node* temp=root;
		for(int i=0;i<w.size();i++)
		{
			char ch=w[i];
			if(temp->children.count(ch)==0)
			{
				return false;
			}
			else
			{
				temp=temp->children[ch];
			}
		}
		return temp->terminal;
	}
};

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	Trie t;
	vector<string> v;
	int n;
	cin>>n;
	while(n--)
	{	string s;
		cin>>s;
		t.insert(s);
	}
	string ss;
	cin>>ss;
	cout<<t.find(ss);
	return 0;
}