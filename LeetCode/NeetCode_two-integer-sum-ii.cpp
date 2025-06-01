// https://neetcode.io/problems/two-integer-sum-ii?list=blind75

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++)
        {
            int idx = bs(numbers, target - numbers[i]);
            if(idx != i && idx != -1)
            {
                vector<int> r = {i+1, idx+1};
                return r;
            }
        }

        return vector<int>();
    }

    int bs(vector<int>& numbers, int target)
    {
        int l=0, h = numbers.size()-1;

        while(l<=h)
        {
            int mid=(l+h)/2;
            if(numbers[mid] == target)
            {
                return mid;
            }
            if(numbers[mid] < target)
            {
                l = mid +1;
            }
            else
            {
                h = mid -1;
            }
        }
        
        return -1;
    }
};
