/*
 * we have given a string s and we need to make it palindromic by deleting some characters.
 * deletion of characters has to be minimum. 
*/

#include<bits/stdc++.h>
using namespace std;


int minDeletionToMakePalendromic(string s){
    int n=s.length();
    string p=s;
    reverse(p.begin(),p.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // now we have length of longest palindromic subsecuence in string s
    // now we just need to remove extra characters
    return n-dp[n][n];
}

int main()
{
    
  string s="abcdcbaa";
    cout<<minDeletionToMakePalendromic(s)<<endl;
    return 0;
}