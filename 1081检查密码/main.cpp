#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    while(n--) {
        string ans;
        getline(cin,ans);
        if(ans.length() < 6) printf("Your password is tai duan le.");
        else {
            int flag1 = 0,flag2 = 0,flag3 = 0;
            for(int i = 0; i < ans.length(); ++i) {
                if(isalpha(ans[i])) flag1 = 1;
                else if(isdigit(ans[i])) flag2 = 1;
                else if(ans[i] != '.' ) flag3 = 1;
             }
             if(flag3) printf("Your password is tai luan le.");
             else {
                 if(flag1 && flag2) printf("Your password is wan mei.");
                 else if(flag1 && !flag2) printf("Your password needs shu zi.");
                 else if(!flag1 && flag2) printf("Your password needs zi mu.");
             }
        }
        printf("\n");
    }
    return 0;
}
