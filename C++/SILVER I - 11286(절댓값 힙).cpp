#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

void print_max();

struct comp {
    bool operator() (int a, int b) {
        if(abs(a)==abs(b)) return a>b;
        else return abs(a)>abs(b);
        //return a<b;//최대 힙
    }
};
priority_queue<int,vector<int>,comp> max_heap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number;
    cin>>number;
    
    for(int i=0;i<number;i++) {
        int cal;
        cin>>cal;
        if(cal==0) print_max();
        else max_heap.push(cal);
    }

    return 0;
}

void print_max()
{
    if(max_heap.size()==0) cout<<0<<'\n';
    else {
        cout<<max_heap.top()<<'\n';
        max_heap.pop();
    }
}
