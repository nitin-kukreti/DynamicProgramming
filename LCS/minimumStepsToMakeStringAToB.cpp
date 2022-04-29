#include<bits/stdc++.h>
using namespace std;

/*
    * we have given a string a and b
    * we have to conert string a into string b in minimum steps
    * steps are:
    * 1. insert a character
    * 2. delete a character
    * at any point we can only do one of the above two operations at string a
*/

int minimumOperationToConvertStringAToStringB(string a,string b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs=dp[n][m];
    int ans=0;
    // now we have common part of string a and b

    // now we need to find how many characters we have to insert
    int insert=m-lcs;
    ans+=insert;
    // now we need to find how many characters we have to delete
    int delete_=n-lcs;
    ans+=delete_;
    return ans;
}


int main()
{
   string a,b;
   a="ABC";
   b="ABD";
   cout<<minimumOperationToConvertStringAToStringB(a,b);
    return 0;
}