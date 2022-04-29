
#include<bits/stdc++.h>
using namespace std;

string solve(string s,string p){
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
                ans+=s[i-1];
                i--;
            }else{
                ans+=p[j-1];
                j--;
            }
        }
    }
    while(i>0){
        ans+=s[i-1];
        i--;
    }
    while (j>0) {
        ans+=p[j-1];
        j--;
    }
    
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return ans;
}

int main(){
    string s1,s2;
    s1="AGGTAB";
    s2="GXTXAYB";
    solve(s1,s2);
    return 0;
}