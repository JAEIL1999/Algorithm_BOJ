#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
 
using namespace std;
 
typedef pair<int, int> pii;
 
vector<pair<pii, pii> > vc;
 
map<pii, int, greater<> > st;
 
map<int, int> mp;
 
int main()
{
    int n;
    scanf("%d", &n);
 
    // vector에는 현재 점, 높이, 반대편점, 상태를 받는다.
    // 0 :: 현재 점이 사각형 시작 1 :: 현재 점이 사각형 끝
    for (int i = 0; i < n; i++)
    {
        int s, e, height;
        scanf("%d %d %d", &s, &height, &e);
 
        vc.push_back({ {s,height }, { e, 0 } });
        vc.push_back({ {e,height }, { s, 1 } });
    }
 
    // x좌표에 대해 정렬
    sort(vc.begin(), vc.end());
 
    // 이전의 최고 높이
    int prev = -1;
    st[{0, 0}] = 0;
 
    for (int i = 0; i < vc.size(); i++)
    {
        int here = vc[i].first.first;
        int other = vc[i].second.first;
        int height = vc[i].first.second;
        int pos = vc[i].second.second;
 
        // 만약 현재 점이 시작이라면 맵에 그대로 넣는다.
        if (pos == 0)
            st[{height, here}] = other;
 
        // 시작점이 아닌 끝점이라면 시작점을 찾아 삭제한다.
        else {
            auto it = st.find({ height, other });
            st.erase(it);
        }
 
        // 지금 맵에 남아있는 높이 최대를 찾는다.
        auto it = st.begin();
        int maxH = it->first.first;
 
        // 내가 알고있던 이전 최대 높이와 다르다면
        if (maxH != prev)
        {
            // 최대 높이 갱신
            prev = maxH;
 
            // 만약 시작점이라면 최대 갱신
            if (pos == 0)
                mp[here] = max(mp[here], maxH);
 
            // 만약 끝점이라면
            else {
                // 아직 표시된 적이없다면 최대값으로 갱신
                if (mp.count(here) == 0)
                    mp[here] = maxH;
                // 표시된 적이 있다면 최솟값으로 갱신
                else
                    mp[here] = min(mp[here], maxH);
            }
        }
    }
 
    prev = -1;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second != prev)
            printf("%d %d ", it->first, it->second);
        prev = it->second;
    }
    return 0;
}
