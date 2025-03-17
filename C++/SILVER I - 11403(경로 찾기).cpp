#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b);

vector<vector<int>> node_edge;
vector<vector<int>> graph_path;

int main()
{
    int node_count;
    cin>>node_count;
    
    for(int i=0;i<node_count;i++) {
        graph_path.push_back(vector<int>());
        for(int j=0;j<node_count;j++) {
            int edge;
            cin>>edge;
            if(edge == 0) graph_path[i].push_back(500);
            else graph_path[i].push_back(edge);
        }
    }
    
    for(int k=0;k<node_count;k++) {
        for(int i=0;i<node_count;i++) {
            for(int j=0;j<node_count;j++) {
                graph_path[i][j] = min(graph_path[i][j],graph_path[i][k]+graph_path[k][j]);
            }
        }
    }
    
    for(int i=0;i<graph_path.size();i++) {
        for(int j=0;j<graph_path[i].size();j++) {
            if(graph_path[i][j]<500) cout<<1<<" ";
            else cout<<0<<" ";
        }
        cout<<'\n';
    }

    return 0;
}


int min(int a, int b)
{
    if(a>b) return b;
    else return a;
}
