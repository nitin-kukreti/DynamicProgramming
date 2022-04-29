#include<bits/stdc++.h>
using namespace std;

void printLcs(string s,string p){
    int n=s.length();
    int m=p.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==p[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string ans="";
    while(i>0 && j>0){
        if(s[i-1]==p[j-1]){
          ans+=s[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}


int main()
{
   string s1,s2;
    s1="afnweabcd22";
    s2="abcd2";
    printLcs(s1,s2);
    return 0;
}