#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void tomato_bfs(int limit_width, int limit_length);
bool inside_check(int x, int y, int limit_width, int limit_length);

vector<vector<int>> storage;
queue<pair<int,int>> after_tomato;

int check_x[4] = {-1,1,0,0};
int check_y[4] = {0,0,-1,1};

int total_tomato;
int answer_count = 0;
int main()
{
    int width, length;
    cin>>width>>length;
    total_tomato = width*length;
    
    for(int i=0;i<length;i++) {
        storage.push_back(vector<int>());
        for(int j=0;j<width;j++) {
            int tomato;
            cin>>tomato;
            if(tomato ==-1||tomato ==1) total_tomato--;
            if(tomato == 1) after_tomato.push(make_pair(i,j));
            storage[i].push_back(tomato);
        }
    }

    if(total_tomato==0) cout<<0;
    else {
        tomato_bfs(width,length);
        if(total_tomato==0) cout<<answer_count-1;
        else cout<<-1;
    }
    return 0;
}

void tomato_bfs(int limit_width, int limit_length)
{
    while(!after_tomato.empty()) {
        int x=after_tomato.front().first;
        int y=after_tomato.front().second;
        after_tomato.pop();
        for(int i=0;i<4;i++) {
            int new_x = x+check_x[i], new_y = y+check_y[i];
            if(inside_check(new_x,new_y,limit_width,limit_length)&&storage[new_x][new_y]==0) {
                storage[new_x][new_y]= storage[x][y]+1;
                if(answer_count<storage[x][y]+1) answer_count = storage[x][y]+1;
                after_tomato.push(make_pair(new_x,new_y));
                total_tomato--;
            }
        }
        
    }
}

bool inside_check(int x, int y, int limit_width, int limit_length)
{
    if(x>-1 && y>-1 && x<limit_length && y<limit_width) return true;
    else return false;
}
