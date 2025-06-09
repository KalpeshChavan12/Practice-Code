// https://neetcode.io/problems/kth-largest-element-in-an-array?list=blind75

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(nums.begin(), nums.begin()+k);
        make_heap(heap.begin(), heap.end(), std::greater<>{});

        for(int i=k; i<nums.size(); i++)
        {
            if(heap.front() < nums[i])
            {
                pop_heap(heap.begin(), heap.end(), std::greater<>{});
                heap.pop_back();
                heap.push_back(nums[i]);
                push_heap(heap.begin(), heap.end(), std::greater<>{});
            }
        }

        return heap[0];
    }
};
