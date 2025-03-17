#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool uni_compare(int start, int com, int planet_num);
void compression(int uni, int planet_num);

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second<b.second;
}

int universe[100][10000];
vector<pair<int,int>> temp;
int answer=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int uni_num, planet_num;
    cin>>uni_num>>planet_num;
    
    for(int i=0;i<uni_num;i++) {
        for(int j=0;j<planet_num;j++) {
            int planet_size;
            cin>>planet_size;
            temp.push_back(make_pair(j,planet_size));
        }
        sort(temp.begin(),temp.end(),compare);
        compression(i,planet_num);
        temp.clear();
    }
    
    for(int i=0;i<uni_num-1;i++) {
        for(int j=i+1;j<uni_num;j++) {
            uni_compare(i,j, planet_num);
        }
    }
    cout<<answer;
    return 0;
}

void compression(int uni, int planet_num)
{
    int previous, count=0;
    previous=temp[0].second;
    universe[uni][temp[0].first]=0;
    
    for(int i=1;i<planet_num;i++) {
        if(temp[i].second==previous) universe[uni][temp[i].first]=count;
        else {
            count++;
            universe[uni][temp[i].first]=count;
            previous=temp[i].second;
        }
    }
}

bool uni_compare(int start, int com, int planet_num)
{
    for(int i=0;i<planet_num;i++) {
        if(universe[start][i]!=universe[com][i]) return false;
    }
    answer++;
    return true;
}
