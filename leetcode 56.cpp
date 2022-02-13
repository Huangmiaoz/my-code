class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int st=-2e9,ed=-2e9;
        vector<vector<int>> ans;
        for(auto interval : intervals) {
            if(ed < interval[0]) {
                if(ed != -2e9) {
                    ans.push_back({st,ed});
                }
// 如果此时的区间终点小于遍历到的起点，说明已经到了一个新的区间，应该将之前的区间加入答案数组中
                    st=interval[0];
                    ed=interval[1];
                    // 更新起点终点
                } else {
                    ed=max(ed,interval[1]);
                }
            }
        if(ed!=-2e9) {
            ans.push_back({st,ed});
            // 最后一个区间
        }
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;
pair<int,int>PII;
vector<pair<int,int>> segs;
void merge(vector<pair<int,int>> &segs) {
    vector <pair<int,int>>ans;
    sort(segs.begin(),segs.end());

    int st=-2e9,ed=-2e9;

    for(auto seg:segs) {
        if(ed < seg.first) {
            if(st != -2e9) ans.push_back({st,ed});
            st =seg.first;
            ed =seg.second;
        }
        else {
            ed=max(ed,seg.second);
            // 不断更新区间结束的位置
        }
    }

    if(st !=-2e9) ans.push_back({st,ed});
    segs=ans;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        segs.push_back({a,b});
    }

    merge(segs);

    cout<<segs.size()<<endl;

    return 0;
}
