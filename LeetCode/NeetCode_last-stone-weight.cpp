//  https://neetcode.io/problems/last-stone-weight?list=blind75

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        
        int res = 0;

        while(stones.size() > 1)
        {
            int m1 = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int m2 = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            if(m1 == m2)
                continue;
            
            stones.push_back(abs(m1-m2));
            push_heap(stones.begin(), stones.end());
        }

        return stones.empty() ?  0 : stones[0];
    }
};
