#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int dp[1001][1001];
int maxi=0;
int main()
{
    string a, b;
    cin>>a>>b;
    //cout<<a<<endl;
    //cout<<b<<endl;
    //std::cout<<"Hello World";
    for(int i=0;i<a.length();i++) {
        for(int j=0;j<b.length()+1;j++) {
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            
            if(dp[i+1][j+1]>maxi) maxi=dp[i+1][j+1];
        }
    }
    /*
    cout<<endl;
    for(int i=0;i<=a.length();i++) {
        for(int j=0;j<=b.length()+1;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<maxi;
    return 0;
}
