#include <bits/stdc++.h>
using namespace std;
string unagain(string res) {
    string tmp;
    map<char,bool> flag;
    for(int i = 0; i < res.length(); i++) {
        if(flag[res[i]] == false) {
            tmp.push_back(res[i]);
            flag[res[i]] = true;
        }
    }
    return tmp;
}
int main()
{
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    string res = unagain(a+b);
    cout << res;
    return 0;
}
