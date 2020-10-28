#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,r,ans;
    cin>>s>>r;
    int dp[s.length()+1][r.length()+1],i,j,m=0,x=0;
    for(i=0;i<=s.length();i++)
    for(j=0;j<=r.length();j++)
    if(i==0 || j==0)
    dp[i][j] = 0;
    for(i=1;i<=s.length();i++)
    {
        for(j=1;j<=r.length();j++)
        {
            if(s[i-1] == r[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(dp[i][j] > m)
            m = dp[i][j];
        }
    }
    // cout<<"Resultant Matrix :\n";
    // for(i=0;i<=s.length();i++){
    //     for(j=0;j<=r.length();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<"Length of longest common subsequence :\n";
    cout<<dp[s.length()][r.length()]<<"\n";
    cout<<"The subsequence is :\n";
    i = s.length();
    j = r.length();
    while(i != 0 && j != 0)
    {
        if(dp[i][j] == dp[i-1][j])
        i--;
        else if(dp[i][j] == dp[i][j-1])
        j--;
        else
        {
            // ans = ans + r[j-1];      
            ans = ans + s[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
    return 0;
}


