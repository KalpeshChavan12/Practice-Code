// https://neetcode.io/problems/daily-temperatures?list=blind75

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++)
        {
            while(!st.empty() && st.top().first < temperatures[i] )
            {
                auto si =st.top().second;
                st.pop();
                res[si] = i - si; 
            }

            st.push({temperatures[i], i });
        }

        return res;
    }
};
