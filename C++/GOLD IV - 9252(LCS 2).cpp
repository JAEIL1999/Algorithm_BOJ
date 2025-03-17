#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int answer=0;
int maximum=0;
vector<char> subsequence;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string first, second;
    cin>>first>>second;
    
    for(int i=0;i<first.length();i++) {
        for(int j=0;j<second.length();j++) {
            if(first[i]==second[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            maximum = max(dp[i+1][j+1], maximum);
        }
    }
    pair<int,int> location=make_pair(first.length(),second.length());
    while(dp[location.first][location.second]!=0) {
        if(dp[location.first][location.second]==dp[location.first-1][location.second]) {
            location.first--;
            continue;
        }
        else if(dp[location.first][location.second]==dp[location.first][location.second-1]) {
            location.second--;
            continue;
        }
        else {
            subsequence.push_back(first[location.first-1]);
            location.first--;
            location.second--;
        }
    }
    reverse(subsequence.begin(),subsequence.end());
    std::cout<<maximum<<'\n';
    for(int i=0;i<subsequence.size();i++) {
        cout<<subsequence[i];
    }

    return 0;
}
