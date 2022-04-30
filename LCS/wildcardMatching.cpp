/*
 we are given two strings, A and B.
 if string A machtes string B, then return true, otherwise return false.
 string A contain some special characters, which are: '?' and '*'.
    '?' means that the character can mach 1 character.
    '*' means that the character is be machted zero or more characters.

*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
bool isMatch(int index1,int index2,string A,string B){
    if(index1==0 && index2==0)
        return true;
    if(index2==0) {
        if(A[index1-1]=='*')
            return isMatch(index1-1,index2,A,B);
        else
            return false;
    }
     bool result=false;   
     if(memo[index1][index2]!=-1)
        return memo[index1][index2];
    if(A[index1-1]==B[index2-1] || A[index2-1]=='?')
        result=isMatch(index1-1,index2-1,A,B);
    if(A[index1-1]=='*'){

        result=isMatch(index1,index2-1,A,B) || isMatch(index1-1,index2-1,A,B) || isMatch(index1-1,index2,A,B);
    }
   return  memo[index1][index2]=result;
}

bool iterative_isMatch(string A,string B){
    int n=A.size();
    int m=B.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    //  initialize the first row and first column
    dp[0][0]=true;
    for(int index1=1;index1<=n;index1++){
        if(A[index1-1]=='*') dp[index1][0] =dp[index1-1][0];
    }

   for(int index1=1;index1<=n;index1++){
        for(int index2=1;index2<=m;index2++){
         
        if(A[index1-1]==B[index2-1] || A[index1-1]=='?'){
            dp[index1][index2]=dp[index1-1][index2-1];
           continue;    
        }
        if(A[index1-1]=='*'){
            dp[index1][index2]=dp[index1-1][index2] || dp[index1][index2-1] || dp[index1-1][index2];
        }
   }

   }
    
    return dp[n][m];
}

int main(){
    string A,B;
    A="*RA*";
    B="RAY";
    memo.resize(A.size()+1,vector<int>(B.size()+1,-1));
    cout<<iterative_isMatch(A,B)<<endl;
    return 0;
}

