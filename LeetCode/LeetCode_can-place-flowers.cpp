// https://leetcode.com/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       vector<int> ff;
       ff.push_back(0);
       ff.insert(ff.end(), flowerbed.begin(), flowerbed.end());
       ff.push_back(0);

        int res=0;
       for(int i=1; i< ff.size()-1; i++)
       {
            if(ff[i] == 0 && ff[i-1] == 0 && ff[i+1] == 0)
            {
                res++;
                ff[i] = 1;
            }
       }
       
       return res >= n;
    }
};
