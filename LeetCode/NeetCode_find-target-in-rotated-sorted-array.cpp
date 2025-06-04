// https://neetcode.io/problems/find-target-in-rotated-sorted-array?list=blind75

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r = nums.size() -1;

        while(l<r)
        {
            int mid = (l+r)/2;
            if(nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }

        int pivot = l;

        int res = bs(nums, target, 0, l-1);
        if(res == -1)
            res = bs(nums, target, l, nums.size()-1);

        return res;
    }

    int bs(vector<int>& nums,int target, int l, int r)
    {
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                 r = mid -1;
        }

        return -1;
    }
};
