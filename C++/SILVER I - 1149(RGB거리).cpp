#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[1001][3];
int number;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>number;
    int R,G,B;
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=0;i<number;i++) {
        cin>>R>>G>>B;
        dp[i+1][0]=R;
        dp[i+1][1]=G;
        dp[i+1][2]=B;
    }
    for(int i=1;i<=number;i++) {
        dp[i][0]+=min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]+=min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]+=min(dp[i-1][0],dp[i-1][1]);
    }
    cout<<min({dp[number][0],dp[number][1],dp[number][2]});
    return 0;
}
