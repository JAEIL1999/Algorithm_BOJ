#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool inside_check(int now, int goal);
void move(int now, int goal);
void bfs(int start, int goal);

queue<int> go;
int visit[100001];
int main()
{
    int subin, brother;
    cin>>subin>>brother;
    
    go.push(subin);
    visit[subin]=1;
    bfs(subin, brother);
    cout<<visit[brother]-1;
    return 0;
}

bool inside_check(int now, int goal)
{
    if(now<0 || now>100000) return false;
    return true;
}
void move(int now, int goal)
{
    if(inside_check(now*2,goal)&&visit[now*2]==0) {
        visit[now*2] = visit[now];
        go.push(now*2);
    }
    if(inside_check(now-1,goal)&&visit[now-1]==0) {
        visit[now-1] = visit[now]+1;
        go.push(now-1);
    }
    if(inside_check(now+1,goal)&&visit[now+1]==0) {
        visit[now+1] = visit[now]+1;
        go.push(now+1);
    }
}
void bfs(int start, int goal)
{
    while(!go.empty()) {
        int now = go.front();
        if(now==goal) return ;
        go.pop();
        move(now, goal);
    }
}
