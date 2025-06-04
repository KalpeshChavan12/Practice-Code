// https://neetcode.io/problems/car-fleet?list=blind75


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        vector<float> st;
        for(int i=0; i<position.size(); i++)
        {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end(), [] (const pair<int, int>& a, const pair<int, int>&  b) {
            return a.first < b.first;
        });

        for(int i=ps.size()-1; i>=0; i--)
        {
            float t = ((float)(target - ps[i].first)) / ps[i].second;
            st.push_back(t);
            if(st.size() > 0 && st[st.size() -1] <= st[st.size() -2])
                st.pop_back();
        }

        return st.size();
    }

    static bool pcmp(pair<int,int> a, pair<int,int> b)
    {
        return a.first < b.first;
    }
};
