// https://neetcode.io/problems/eating-bananas?list=blind75

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r =piles[0];

        for(int i=0; i< piles.size(); i++)
        {
            r = max(piles[i], r);
        }

        int l=0;
        int sp = INT_MAX;

        while(l<=r)
        {
            int speed = (l+r)/2;
            double timetaken = 0;
            for(auto& p : piles)
            {
                timetaken+= ceil(((double)p) / speed);
            }

            if(timetaken <= h)
            {
                sp = min(sp, speed);
                r = speed - 1;
            }
            else
            {
                l = speed+1;
            }
        }

        return sp;
    }
};

