// https://neetcode.io/problems/max-water-container?list=blind75

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=height.size();
        int l=0, r = height.size() -1;
        int maxA = 0;
        
        while(l<r)
        {
            int a = min(height[r], height[l]) * (r -l);
            if(maxA < a)
              maxA = a;

            if(height[r] < height[l])
                r--;
            else
                l++;

        }

        return maxA;
    }
};
