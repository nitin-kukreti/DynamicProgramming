/*

there are 100 diffrent type of cap available each have unique id from 1 to 100
there are n people each having collection of cap
and they have decided to visit a party and nobody should have same cap
so there are how many ways they can visit the party

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

vector<int> capPerson[100];
int solve(int cap,int n,int &caped){
    // if all people have caped then return 1
    if(caped==(1<<n)-1) return 1;
    // we have no cap left
    if(cap==0) return 0;

    // if we have already calculated this cap
    if(memo[cap][caped]!=-1) return memo[cap][caped];

    // if we don't use current cap
    int withoutCap=solve(cap-1,n,caped);

    // if we use current cap 
    int withCap=0;
    for(auto person : capPerson[cap-1]){
        int mask=(1<<person);

        // if we already assigned cap to this person
        if(caped&mask) continue;
        
        caped|=mask;
        withCap+=solve(cap-1,n,caped);
        caped^=mask;
    }
   return memo[cap][caped]=withCap+withoutCap;
}
  
int main()
{
    int n=0;
    int people=3;
    // capPerson[0].push_back(0);
    capPerson[99].push_back(0);
    // capPerson[4].push_back(0);
    // capPerson[1].push_back(1);
    // capPerson[4].push_back(2); 
    capPerson[99].push_back(2);
    capPerson[99].push_back(1);    

    memo.resize(101,vector<int>(1<<people,-1));
    cout<<solve(100,people,n);   
    return 0;
}