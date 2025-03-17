#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool inside_check(int now);
void bfs(int start, int goal);
void find_path(int start, int goal);

queue<int> go;
//vector<pair<int,int>>path;
int visit[200001];
int path[200001];
int answer = 0;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int subin, brother;
    cin>>subin>>brother;
    
    go.push(subin);
    visit[subin]=1;
    path[subin]=subin;
    
    bfs(subin, brother);
    cout<<visit[brother]-1<<'\n';
    find_path(subin, brother);
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
            //answer++;
            //cout<<path[goal];
            return ;
        }
        go.pop();
        for(int i=0;i<3;i++) {
            if(!inside_check(new_now[i]) || new_now[i]==now) continue;
            else {
                if(visit[new_now[i]]==0 || visit[new_now[i]]>=visit[now]+1) {
                    visit[new_now[i]] = visit[now]+1;
                    go.push(new_now[i]);
                    path[new_now[i]]=now;
                }
            }
        }
    } 
}

void find_path(int start, int goal)
{
    vector<int> order;
    while(goal!=start) {
        order.push_back(goal);
        goal = path[goal];
    }
    order.push_back(start);
    for(int i=order.size()-1;i>-1;i--) {
        cout<<order[i]<<" ";
    }
}
