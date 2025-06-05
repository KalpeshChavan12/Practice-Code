// https://neetcode.io/problems/sliding-window-maximum?list=blind75

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;
        vector<int> res(nums.size() -k +1);
        int last = 0;

        for(int i=0; i< nums.size(); i++)
        {

            while(!q.empty() && nums[q.back()] < nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);

            if(last > q.front())
                q.pop_front();

            if(i-k+1 >= 0)
            {
                res[last]=(nums[q.front()]);
                last++;
            }
        }
        
        return res;
    }
};
