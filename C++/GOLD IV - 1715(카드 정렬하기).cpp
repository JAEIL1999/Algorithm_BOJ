#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comp {
    bool operator()(int a, int b) {
        return a>b;
    }
};
priority_queue<int,vector<int>,comp>card;
int answer=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number;
    cin>>number;
    for(int i=0;i<number;i++) {
        int card_num;
        cin>>card_num;
        card.push(card_num);
    }
    
    for(int i=0;i<number-1;i++) {
        int num1=card.top();
        card.pop();
        int num2=card.top();
        card.pop();
        card.push(num1+num2);
        answer+=num1+num2;
    }
    
    cout<<answer;
    return 0;
}
