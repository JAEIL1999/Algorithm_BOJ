#include <iostream>
#include <vector>

using namespace std;
int prefix_sum(int x1, int y1, int x2, int y2);

vector<vector<int>> graph;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Q;
    int x1,y1,x2,y2;
    cin>>N>>Q;
    for(int i=0;i<N;i++) {
        graph.push_back(vector<int>());
        int number_input;
        cin>>number_input;
        graph[i].push_back(number_input);
        for(int j=1;j<N;j++) {
            cin>>number_input;
            graph[i].push_back(number_input+graph[i][j-1]);
        }
    }

    for(int i=0;i<Q;i++) {
        cin>>x1>>y1>>x2>>y2;
        int answer = prefix_sum(x1-1,y1-1,x2-1,y2-1);
        cout<<answer<<'\n';
    }

    return 0;
}
int prefix_sum(int x1, int y1, int x2, int y2)
{
    int sum=0;
    if(y1==0) {
        for(int i=x1;i<=x2;i++) {
            sum+=graph[i][y2];
        }
    }
    else {
        for(int i=x1;i<=x2;i++) {
            sum+=graph[i][y2]-graph[i][y1-1];
        }
    }
    return sum;
}
