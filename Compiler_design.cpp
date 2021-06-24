#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;


void solve(string s)
{

    string beta = "";
    string alpha = "";
    vector<string> v;
    bool f = false;
    for (int i = 2; i < s.length(); i++)
    {
        if (s[i] == '/')
        {

            for (int j = 0; j < beta.size(); j++)
            {
                if (beta[j] == s[0])
                {
                    f = true;
                    break;
                }
            }
            if (!f)
                break;
            f = false;
            v.push_back(beta);
            beta = "";
        }
        else
        {
            beta += s[i];
        }
    }
    // cout<<beta<<endl;
    for (auto x : v)
    {
        string word = "";
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] != s[0])
                word += x[i];
        }
        // cout<<word<<endl;
        string ww = "";
        ww += s[0];
        ww += '\'';
        cout << s[0] << s[1] << beta << ww << endl;
        cout << ww << "=" << word << ww << "/epsilon" << endl;
    }
    return;
}

string recurse(string s, unordered_map<char, string> &mp, char par)
{
    string ss = "";
    ss += s[0];
    ss += s[1];
    for (int i = 2; i < s.length(); i++)
    {
        if (s[i] >= 'A' and s[i] <= 'Z' and s[i] != s[0] and s[i] != par)
        {
            ss.append(recurse(mp[s[i]], mp, par));
        }
        else
            ss += s[i];
    }
    cout << s << " Substituted to ";
    cout << ss << endl;
    return ss.substr(2, ss.length() - 2);
}



void Solve_Left_Recursion() {
    cout << "Enter Number of productions\n";
    int prod;
    cin >> prod;
    unordered_map<char, string> mp;
    string start = "";
    bool f = false;
    for (int i = 0; i < prod; i++)
    {
        string s;
        cin >> s;
        if (!f)
        {   for (int k = 2; k < s.length(); k++)
            {
                if (s[k] >= 'A' and s[k] <= 'Z')
                {
                    if (s[k] != s[0])
                    {
                        start = s;
                        f = true;
                    }
                }
            }
        }
        char init = s[0];
        mp[init] = s;
    }
    if (start.length())
        cout << "Indirect left recursion is found in " << start << endl;
    else
    {
        cout << "No indirect recursion found\n";
        for (auto x : mp)
        {
            string cur = x.second;
            for (int i = 2; i < cur.length(); i++)
            {
                if (cur[i] == x.first)
                {
                    cout << "Direct Left Recursion found in " << x.second << endl;
                    solve(x.second);
                    break;
                }
            }
        }
        return;

    }
    string direct = start.substr(0, 2) + recurse(start, mp, start[0]);
    for (int i = 2; i < direct.length(); i++)
    {
        if (direct[i] == direct[0])
        {
            cout << "Direct Left Recursion found in " << direct << endl;
            solve(direct);
            break;
        }
    }
    return;
}




void Solve_Left_Factoring()
{
    cout << "Enter parent Non terminal letter\n";
    char par;
    cin >> par;
    cout << "Enter no of productions\n";
    int prod;
    cin >> prod;
    vector<string> v;
    string inp;
    for (int i = 0; i < prod; i++)
    {
        string x;
        cin >> x;
        inp.append(x);
        if (i != prod - 1)
            inp += '|';
        v.push_back(x);
    }
    cout << "Input is " << par << "-->" << inp << endl;
    string beta = "";
    string common = v[0];
    string nn = "";
    for (int i = 1; i < v.size(); i++)
    {
        string sm = "";
        int k = 0;
        for (int j = 0; j < v[i].length(); j++)
        {
            if (j == 0 and v[i][j] != common[j])
            {
                nn += '|';
                nn.append(v[i]);
                sm = common;
                break;
            }
            if (j < common.length() and v[i][j] == common[j])
            {
                sm += v[i][j];
            }
            else
            {
                break;
            }
        }
        common = sm;
    }
    int l = common.length() - 1;
    for (int i = 0; i < v.size(); i++)
    {
        string sm = "", bg = "";
        bool f = false;
        if (v[i][0] != common[0])
        {

            f = true;
        }
        else
            bg = v[i].substr(l, v[i].length() - (l + 1));
        if (!f)
        {
            if (!bg.length())
                bg = "epsilon";
            if (beta != "")
            {
                beta += '|';
                beta.append(bg);
            }
            else
                beta.append(bg);
        }
    }
    string ss = "";
    ss += par;
    ss += '\'';
    cout << par << "-->" << common << ss << nn << endl;
    cout << ss << "-->" << beta << endl;

}

vector<string> splitStr(string s, char c)
{
    string cur = "";
    vector<string> v;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            v.push_back(cur);
            cur = "";
        }
        else
            cur += s[i];
    }
    if (cur != "")
        v.push_back(cur);
    return v;
}

unordered_map<char, bool> hashNT;
bool follow = false;
set<char> findNTFirsts(char c, unordered_map<char, vector<string>> &mp, bool &f)
{
    set<char> s;
    for (int i = 0; i < mp[c].size(); i++)
    {
        char cur = mp[c][i][0];
        if (cur >= 'A' and cur <= 'Z')
        {
            int z = 0;
            bool ff = false;
            while (1)
            {
                set<char> cs;

                if (z <= mp[c][i].size())
                    cur = mp[c][i][z++];
                else
                    break;
                cs = findNTFirsts(cur, mp, ff);
                // cout<<ff<<" "<<cur<<endl;
                for (auto x : cs)
                {   if (ff and x == '#')
                        continue;
                    s.insert(x);
                }
                if (!ff)
                    break;
                ff = false;
            }
        }
        else if (cur == '#')
        {
            f = true;

            s.insert(cur);
        }
        else
            s.insert(cur);
    }
    if (!hashNT[c] and s.size() and follow == false)
    {   cout << "First of " << c << " is (";
        int i = 0;
        for (auto x : s)
        {
            cout << x;
            i++;
            if (i < s.size())
                cout << " , ";
        }
        cout << ")" << endl;
    }
    hashNT[c] = 1;
    return s;
}
unordered_map<char, set<char>> ans;
void findFollow(unordered_map<char, vector<string>> &mp)
{
    cout << "FOLLOWS" << endl;

    vector<char> v;
    v.push_back('S');
    for (auto x : mp)
    {
        if (x.first != 'S')
            v.push_back(x.first);
    }
    follow = true;
    for (auto x : v)
    {
        char c = x;
        // cout<<c<<" "<<ans[c].size()<<endl;
        if (!ans[c].size())
            ans[c].insert('$');
        vector<string> d;
        d = mp[c];
        for (int i = 0; i < mp[c].size(); i++)
        {
            for (int j = 0; j < d[i].size(); j++)
            {

                char cur = d[i][j];
                if (cur<'A' or cur>'Z')
                {
                    continue;
                }
                if (j != d[i].size() - 1)
                {
                    char nxt = d[i][j + 1];
                    if (nxt >= 'a' and nxt <= 'z')
                    {
                        ans[cur].insert(nxt);
                    }
                    else if (nxt >= 'A' and nxt <= 'Z')
                    {
                        bool f = false;
                        auto z = findNTFirsts(nxt, mp, f);
                        for (auto v : z)
                        {
                            // cout<<v<<endl;
                            ans[cur].insert(v);
                        }
                    }
                }
                else
                {

                    ans[cur] = ans[c];
                }
            }
        }
    }
    for (auto x : ans)
    {
        cout << "Follow of " << x.first << "(";
        int i = 0;
        for (auto y : x.second)
        {
            i++;
            cout << y;
            if (i != x.second.size())
            {
                cout << " , ";
            }

        }
        cout << ")";
        cout << endl;

    }
}
void PredectiveParser(unordered_map<char, vector<string>> &mp, unordered_map<char, int> &columns, int k)
{
    string matrix[mp.size() + 1][k];
    int n = mp.size() + 1;
    int m = k;
    matrix[0][0] = ' ';
    for (auto x : columns)
    {
        string dd = "";
        dd += x.first;
        matrix[0][x.second] = dd;
        // cout<<x.first<<" "<<x.second<<endl;
    }

    matrix[1][0] = "S";
    int i = 2;
    for (auto x : mp)
    {
        if (x.first == 'S')
            continue;
        string dd = "";
        dd += x.first;
        matrix[i++][0] = dd;

    }
    for (int i = 1; i < n; i++)
    {
        // cout<<matrix[i][0]<<endl;
        for (int j = 1; j < m; j++)
            matrix[i][j] = " ";
    }


    int cnt = -1;
    for (int i = 1; i < n; i++)
    {
        char c = matrix[i][0][0];

        for (int j = 0; j < mp[c].size(); j++)
        {
            
            cout<<c<<"="<<mp[c][j]<<" ---> "<<cnt+1<<endl;
            char cur = mp[c][j][0];
            cnt += 1;
            if (cur == '#')
            {
                auto st = ans[c];
                for (auto x : st)
                {
                    if (matrix[i][columns[x]]!=" " and matrix[i][columns[x]]!=to_string(cnt))
                        matrix[i][columns[x]] = matrix[i][columns[x]]+"," + to_string(cnt);
                    else
                        matrix[i][columns[x]] = to_string(cnt);
                }
                continue;
            }
            if (cur >= 'A' and cur <= 'Z')
            {
                int z = 0;
                bool ff = false;
                while (1)
                {
                    set<char> cs;

                    if (z <= mp[c][j].size())
                        cur = mp[c][j][z++];
                    else
                        break;
                    cs = findNTFirsts(cur, mp, ff);
                    // cout<<ff<<" "<<cur<<endl;
                    for (auto x : cs)
                    {   if (ff and x == '#')
                            continue;
                        if (matrix[i][columns[x]]!=" " and matrix[i][columns[x]]!=to_string(cnt))
                            matrix[i][columns[x]] =matrix[i][columns[x]]+ "," + to_string(cnt);
                        else
                            matrix[i][columns[x]] = to_string(cnt);
                    }
                    if (!ff)
                        break;
                    ff = false;
                }
            }
            else
            {
                if (matrix[i][columns[cur]]!=" " and matrix[i][columns[cur]]!=to_string(cnt))
                    matrix[i][columns[cur]] = matrix[i][columns[cur]]+"," + to_string(cnt);
                else
                    matrix[i][columns[cur]] = to_string(cnt);
            }
        }

    }
    cout << endl;
    cout << "PredectiveParser" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "       ";
        }
        cout << endl;
    }
}
void findFirst()
{
    cout << "Enter number of productions" << endl;
    int n;
    cin >> n;
    unordered_map<char, int> columns;
    unordered_map<char, vector<string>> mp;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != '|' and (s[j]<'A' or s[j]>'Z') and s[j] != '#' and s[j] != '=')
            {
                if (columns[s[j]])
                    continue;
                // cout<<s[j]<<" "<<k<<endl;
                columns[s[j]] = k;
                k += 1;
            }
        }
        mp[s[0]] = splitStr(s.substr(2, s.length() - 2), '|');
    }
    cout << "FIRSTS" << endl;
    for (auto x : mp)
    {
        bool f = false;
        auto z = findNTFirsts(x.first, mp, f);
    }
    findFollow(mp);
    columns['$'] = k++;
    PredectiveParser(mp, columns, k);
}



int main()
{
    cout << "Tejas Ghone 60004180110 B3\n";
    findFirst();
    return 0;
}