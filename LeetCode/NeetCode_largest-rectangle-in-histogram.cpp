// https://neetcode.io/problems/largest-rectangle-in-histogram?list=blind75



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA=0;
        vector<pair<int, int>> st;

        if(heights.empty())
            return 0;

        for(int i=0; i<heights.size(); i++)
        {
            int start = i;
           while(!st.empty() && st.back().second > heights[i])
           {
                auto tp = st.back();
                st.pop_back();
                auto a = (i - tp.first) * tp.second;
                maxA = max(a, maxA); 
                start = tp.first;
           }
           
           st.push_back({start, heights[i]});
        }

        for(auto& tp: st)
        {
            int t = tp.second * (heights.size() - tp.first);
            maxA = max(maxA, t);
        }

        return maxA;
    }
};
