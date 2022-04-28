#include<bits/stdc++.h>
using namespace std;

// recursive solution time complexity O(2^n) space complexity O(max(n,m)) 
int recursive_lcs(int ithcharS1,int ithcharS2,string s1,string s2){
    // if any string is empty then common subsequence is empty
    if(ithcharS1==0 || ithcharS2==0) return 0;

    // not taking the current character
    int not_taken_s1=recursive_lcs(ithcharS1-1,ithcharS2,s1,s2);
    int not_taken_s2=recursive_lcs(ithcharS1,ithcharS2-1,s1,s2);
    int not_taken=max(not_taken_s1,not_taken_s2);

    // taking the current character
    int taken=0;
    if(s1[ithcharS1-1]==s2[ithcharS2-1]){
        taken=1+recursive_lcs(ithcharS1-1,ithcharS2-1,s1,s2);
    }
    return max(taken,not_taken);
} 

// recursive memoization time complexity O(n*m) space complexity O(n*m) + O(max(n,m))
int memo_lcs(int ithcharS1,int ithcharS2,string s1,string s2,vector<vector<int>> &memo){
    // if any string is empty then common subsequence is empty
    if(ithcharS1==0 || ithcharS2==0) return 0;
    if(memo[ithcharS1][ithcharS2]!=-1) return memo[ithcharS1][ithcharS2];

    // not taking the current character
    int not_taken_s1=memo_lcs(ithcharS1-1,ithcharS2,s1,s2,memo);
    int not_taken_s2=memo_lcs(ithcharS1,ithcharS2-1,s1,s2,memo);
    int not_taken=max(not_taken_s1,not_taken_s2);

    // taking the current character
    int taken=0;
    if(s1[ithcharS1-1]==s2[ithcharS2-1]){
        taken=1+memo_lcs(ithcharS1-1,ithcharS2-1,s1,s2,memo);
    }
    return memo[ithcharS1][ithcharS2]=max(taken,not_taken);
}

// tabular time complexity O(n*m) space complexity O(n*m)
int tab_lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> T(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int taken=0;
            if(s1[i-1]==s2[j-1]){
                taken=1+T[i-1][j-1];
            }
            int nottaken=max(T[i-1][j],T[i][j-1]);

            T[i][j]=max(taken,nottaken);
        }
    }
    return T[n][m];
}

int main()
{
    string s1="AGGTAB";
    string s2="GXTXAYB";
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
    cout<<tab_lcs(s1,s2)<<endl;
    return 0;
}