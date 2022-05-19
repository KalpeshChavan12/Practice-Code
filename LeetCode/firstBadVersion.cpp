// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       
        int l =0, h = n;
        int mid=0;
        while(l<h)
        {
            mid= l + (h-l)/2;
            
            if(mid == 0)
                break;
            
            auto b1 = isBadVersion(mid+1);
            auto b2 = isBadVersion(mid);
            
            if(b1 && !b2)
            {
                return mid+1;
            }
            else if (!b1 && !b2) 
            {
                l = mid+1;
            }
            else if (b1 && b2) 
            {
                h = mid;
            }
        }
        
        return 1;
        
    }
    
    
};
