#include <iostream>
#include <cmath>

using namespace std;
void hanoi(int number, int start, int end, int sub);
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number;
    cin>>number;
    cout<<int(pow(2,number))-1<<'\n';
    hanoi(number,1,3,2);

    return 0;
}

void hanoi(int number, int start, int end, int sub)
{
    if(number==1) {
        cout<<start<<" "<<end<<'\n';
        return ;
    }
    hanoi(number-1,start,sub,end);
    cout<<start<<" "<<end<<'\n';
    hanoi(number-1,sub,end,start);
}
