#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct meet {
    int start;
    int end;
};

struct cmp {
    bool operator()(meet a, meet b) {
        if(a.end == b.end) return a.start>b.start;
        return a.end>b.end;
    }
};

priority_queue<meet,std::vector<meet>,cmp> find_meet;
int answer = 0;
int main()
{
    int meeting;
    meet meets;
    cin>>meeting;
    for(int i=0;i<meeting;i++) {
        int start, end;
        cin>>start>>end;
        meets.start = start;
        meets.end = end;
        find_meet.push(meets);
    }
    
    int end=0;
    
    while(!find_meet.empty()) {
        meet temp = find_meet.top();
        if(end<=temp.start) {
            answer++;
            end = temp.end;
        }
        find_meet.pop();
    }
    cout<<answer;

    return 0;
}
