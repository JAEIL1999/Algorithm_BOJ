#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
long long recursive_math(int A, int B, int C);
map<long long,long long> power;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B, C;
    cin>>A>>B>>C;
    power.insert({0,1});
    power.insert({1,A%C});
    cout<<recursive_math(A%C,B,C);

    return 0;
}

long long recursive_math(int A, int B, int C)
{
    if(A==0) return 0;
    if(A==1) return 1;
    
    //if(B==0 || B==1) return int(pow(A,B))%C;
    
    if(power.find(B) != power.end()) return power[B];
    else power.insert({B,( recursive_math(A,B/2,C)%C * recursive_math(A,B-B/2,C)%C ) %C});
    return power[B];
}
