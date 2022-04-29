#include<bits/stdc++.h>
using namespace std;




void solve(int index1,int index2,string s1,string s2,int count,int &ans){
    if(index1==0 || index2==0){
        ans=max(ans,count);
        return;
    }
    if(s1[index1-1]==s2[index2-1]){
        solve(index1-1,index2-1,s1,s2,count+1,ans);
    }
    ans=max(ans,count);
    solve(index1-1,index2,s1,s2,0,ans);
    solve(index1,index2-1,s1,s2,0,ans);
}


int longest_common_substring(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    int ans=0;
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0)); 
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    string s1,s2;
    s1="afnweabcd22";
    s2="abcd2";
    cout<<longest_common_substring(s1,s2);
    return 0;
}