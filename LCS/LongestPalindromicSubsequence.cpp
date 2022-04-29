/*
  * we have given a string s, and we need to find the longest palindromic subsequence in s.
  * palindromic subsequence is a subsequence which is same in reverse order.
  * for example, "abcdcba" is a palindromic subsequence of "abcdcba"
*/

#include<bits/stdc++.h>
using namespace std;

void print_longest_palindromic_subsequence(string s){
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
    // now we have lcs of s and p which is palindromic subsequence of s
    // now we just need to print the lcs
    
    int i=n,j=n;
    string lcs="";
    while(i>0 && j>0){
        if(s[i-1]==p[j-1]){
            lcs+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<lcs<<endl;
}


int main()
{
    string s="akbcdcbad";
    print_longest_palindromic_subsequence(s);
    return 0;
}