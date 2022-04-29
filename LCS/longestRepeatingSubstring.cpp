/*
 * we have given a string s and we need to find the longest repeating subsequence in s.
 */

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;

int solve(int index1,int index2,string s,string p){
    if(index1 == 0 || index2 == 0){
        return 0;
    }
    if(memo[index1][index2] != -1){
        return memo[index1][index2];
    }
    if(s[index1-1] == p[index2-1] and index1!=index2){
        return memo[index1][index2]=1+solve(index1-1,index2-1,s,p);
    }
    else{
        return memo[index1][index2]=max(solve(index1-1,index2,s,p),solve(index1,index2-1,s,p));
    }
}

int iterative_solve(string s){
    int n=s.length();
    string p=s;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[j-1] and i!=j){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

//    print longest repeating subsequence
    int i=n,j=n;
    string lcs="";
    while(i>0 && j>0){
        if(s[i-1]==p[j-1] and i!=j){
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
    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<endl;

    return dp[n][n];
}

int main()
{
   string s="abcdabecde";
   memo.resize(s.length()+1,vector<int>(s.length()+1,-1));
   cout<<iterative_solve(s)<<endl;
    return 0;
}