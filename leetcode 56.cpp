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
// �����ʱ�������յ�С�ڱ���������㣬˵���Ѿ�����һ���µ����䣬Ӧ�ý�֮ǰ����������������
                    st=interval[0];
                    ed=interval[1];
                    // ��������յ�
                } else {
                    ed=max(ed,interval[1]);
                }
            }
        if(ed!=-2e9) {
            ans.push_back({st,ed});
            // ���һ������
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
            // ���ϸ������������λ��
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
