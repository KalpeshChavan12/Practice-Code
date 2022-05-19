class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     
        int h=nums.size()-1 ,l = 0;
        int mid =0;
        while(l<=h)
        {
            mid = l + (h-l)/2;
            //cout<<mid<<endl;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        //cout<<">>>>>>>> l="<<l<<" h="<<h<<endl;
        return l;
        
    }
};
