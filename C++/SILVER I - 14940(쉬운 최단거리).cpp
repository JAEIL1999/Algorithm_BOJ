#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
bool inside(int width, int length, int x, int y);
void distance_bfs(int width, int length);

vector<vector<int>> dist;
vector<vector<int>> node;
queue<pair<int,int>> location;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
//상하좌우
int main()
{
    int width, length;
    cin>>width>>length;
    for(int i=0;i<width;i++) {
        dist.push_back(vector<int>());
        node.push_back(vector<int>());
        for(int j=0;j<length;j++) {
            int status;
            cin>>status;
            dist[i].push_back(-1);
            node[i].push_back(status);
            if(status==2) {
                location.push(make_pair(i,j));
                dist[i][j] = 0;
            }
            if(status==0) dist[i][j]=0;
        }
    }

    distance_bfs(width,length);
    
    for(int i=0;i<width;i++) {
        for(int j=0;j<length;j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    

    return 0;
}

bool inside(int width, int length, int x, int y)
{
    if(x<0 || x>=length) return false;
    if(y<0 || y>=width) return false;
    return true;
}

void distance_bfs(int width, int length)
{
    while(!location.empty()) {
        int x=location.front().second;
        int y=location.front().first;
        for(int i=0;i<4;i++) {
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            if(inside(width,length,new_x,new_y) && node[new_y][new_x]==1) {
                location.push(make_pair(new_y,new_x));
                node[new_y][new_x] = 0;
                dist[new_y][new_x] = dist[y][x]+1;
            }
        }
        location.pop();
    }
}
