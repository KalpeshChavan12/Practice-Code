// https://neetcode.io/problems/k-closest-points-to-origin?list=blind75

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> heap;

        for(auto& p: points)
        {
            if(heap.size() < k)
            {
                heap.push_back(p);
                std::push_heap(heap.begin(), heap.end(), hcmp);
            }
            else if(!hcmp(heap[0], p))
            {
                std::pop_heap(heap.begin(), heap.end(), hcmp);
                heap.pop_back();
                heap.push_back(p);
                std::push_heap(heap.begin(), heap.end(), hcmp);
            }
        }

        return heap;
    }
    
    static bool hcmp(vector<int> a, vector<int> b)
    {
        //cout<< "Cmp a "<<a[0]<<","<<a[1]<<" > "<<b[0]<<","<<b[1]<<endl;
        return ((a[0] * a[0]) + (a[1] *a[1])) <
        ((b[0] * b[0]) + (b[1] *b[1]));
    }
};
