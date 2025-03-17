#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool inside_check(int now);
void bfs(int start, int goal);

queue<int> go;
int visit[200001];
int answer = 0;
int main()
{
    int subin, brother;
    cin>>subin>>brother;
    
    go.push(subin);
    visit[subin]=1;
    bfs(subin, brother);
    cout<<visit[brother]-1<<endl;
    cout<<answer;
    return 0;
}

bool inside_check(int now)
{
    if(now<0 || now>200000) return false;
    return true;
}

void bfs(int start, int goal)
{
    while(!go.empty()) {
        int now = go.front();
        int new_now[3] = {now*2,now+1,now-1};
        if(now==goal) {
            answer++;
        }
        go.pop();
        for(int i=0;i<3;i++) {
            if(!inside_check(new_now[i]) || new_now[i]==now) continue;
            else {
                if(visit[new_now[i]]==0 || visit[new_now[i]]>=visit[now]+1) {
                    visit[new_now[i]] = visit[now]+1;
                    go.push(new_now[i]);
                }
            }
        }
    } 
}
