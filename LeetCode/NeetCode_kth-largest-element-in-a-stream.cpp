// https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
    vector<int> heap;
    int hk;
public:
    KthLargest(int k, vector<int>& nums):hk(k) {
        if(nums.size() == 0)
            return;
        auto e = nums.end();
        if(k < nums.size())
        {
            e = nums.begin() + k;
        }

        heap.insert(heap.end(), nums.begin(), e);
        make_heap(heap.begin(), heap.end(),  std::greater<>{});

        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > heap.front())
            {
                pop_heap(heap.begin(), heap.end(),  std::greater<>{});
                heap.pop_back();
                heap.push_back(nums[i]);
                push_heap(heap.begin(), heap.end(),  std::greater<>{});
            }
        }
    }
    
    int add(int val) {
        
        if(heap.size() < hk)
        {
            heap.push_back(val);
            push_heap(heap.begin(), heap.end(), std::greater<>{});
            return heap.front();
        }

        if(heap.size() > 0 && val < heap.front())
        {
            return heap.front();
        }

        if(heap.size() > 0)
        {
            pop_heap(heap.begin(), heap.end(), std::greater<>{});
            heap.pop_back();
        }

        heap.push_back(val);
        push_heap(heap.begin(), heap.end(), std::greater<>{});

        return heap.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
