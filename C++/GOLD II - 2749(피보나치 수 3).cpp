#include <iostream>
#include <vector>

using namespace std;
long long fibo(long long number);
const int pisano=15*100000;
long long dp[pisano];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long number;
    cin>>number;
    dp[0]=0;
    dp[1]=1;
    cout<<fibo(number%pisano);
    return 0;
}

long long fibo(long long number)
{
    for(long long i=2;i<=number;i++) {
        dp[i]=(dp[i-1]+dp[i-2])%1000000;
    }
    return dp[number];
}
