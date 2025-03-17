#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool inside_check(int width, int length, int box, int x, int y, int z);
void tomato_bfs(int width, int length, int box);

vector<vector<vector<int>>> tomato;
queue<pair<int,pair<int,int>>> tomato_done;

int dx[6] = {0,0,-1,1,0,0}; //좌우
int dy[6] = {-1,1,0,0,0,0}; //위아래
int dz[6] = {0,0,0,0,1,-1}; //높이
//상하좌우위아래
int total_tomato=0;
int answer = 0;
int main()
{
    int width, length, box;
    cin>>width>>length>>box;
    total_tomato = width*length*box;
    for(int i=0;i<box;i++){
        tomato.push_back(vector<vector<int>>());
        for(int j=0;j<length;j++) {
            tomato[i].push_back(vector<int>());
            for(int k=0;k<width;k++) {
                int status;
                cin>>status;
                tomato[i][j].push_back(status);
                if(status==1 || status==-1) total_tomato--;
                if(status==1) tomato_done.push(make_pair(i,make_pair(j,k)));
            }
        }
    }
    if(total_tomato==0) cout<<answer;
    else {
        tomato_bfs(width,length,box);
        if(total_tomato==0) cout<<answer-1;
        else cout<<-1;
    }
    return 0;
}
bool inside_check(int width, int length, int box, int x, int y, int z)
{
    if(z<0 || z>=box) return false;
    if(y<0 || y>=length) return false;
    if(x<0 || x>=width) return false;
    
    return true;
}
void tomato_bfs(int width, int length, int box)
{
    while(!tomato_done.empty()) {
        int x = tomato_done.front().second.second;
        int y = tomato_done.front().second.first;
        int z = tomato_done.front().first;
        tomato_done.pop();
        for(int i=0;i<6;i++) {
            int new_z=z+dz[i];
            int new_y=y+dy[i];
            int new_x=x+dx[i];
            
            if(inside_check(width,length,box,new_x,new_y,new_z)&&tomato[new_z][new_y][new_x]==0) {
                tomato[new_z][new_y][new_x] = tomato[z][y][x] + 1;
                if(answer<tomato[new_z][new_y][new_x]) answer = tomato[new_z][new_y][new_x];
                tomato_done.push(make_pair(new_z,make_pair(new_y,new_x)));
                total_tomato--;
            }
        }
    }
    
}
