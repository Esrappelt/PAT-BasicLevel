#include <bits/stdc++.h>
using namespace std;

int isPrime(int num)
{
    if(num == 1 || num == 0) return 0;
    for(int i = 2; i * i <= num; i++ )
        if(num % i == 0)return 0 ;
    return 1;
}

int main()
{
    int l,k;
    scanf("%d%d",&l,&k);
    string str;
    cin >> str;
    for(int i = 0; i < l - k + 1; i++){
        string s = str.substr(i,k);
        int tmp = stoi(s);
        if(isPrime(tmp)) {
            cout << s << endl;
            return 0;
        }
    }
    printf("404\n");
    return 0;
}
