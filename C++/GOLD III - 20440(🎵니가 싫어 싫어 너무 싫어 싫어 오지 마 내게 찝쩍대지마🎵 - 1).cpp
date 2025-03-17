#include <iostream>
#include <unordered_map>
#include <set>
#include <vector> 
#include <algorithm>
#include <utility>

using namespace std;

unordered_map<int,int> record;
vector<int>access;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number;
    int start, end;
    cin>>number;
    
    for(int i=0;i<number;i++) {
        cin>>start>>end;
        
        if(record.count(start)==0) record.insert(make_pair(start,1));
        else record[start]+=1;
        
        if(record.count(end)==0) record.insert(make_pair(end,-1));
        else record[end]-=1;
        
        access.push_back(start);
        access.push_back(end);
    }
    sort(access.begin(), access.end());
	access.erase(unique(access.begin(), access.end()), access.end());
    
    int now_number=0;
    int max=-1;
    pair<int,int> max_time=make_pair(-1,-1);
    for(int iter=0;iter<access.size();iter++) {
        now_number+=record[access[iter]];
        if(max<now_number) {
            max=now_number;
            max_time.first=access[iter];
            max_time.second=-1;
        }
        if(max>now_number&&max_time.second==-1) max_time.second=access[iter]; 
    }
    cout<<max<<'\n';
    cout<<max_time.first<<" "<<max_time.second;

    return 0;
}
