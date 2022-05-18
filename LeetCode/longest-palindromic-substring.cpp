class Solution {
public:
    string longestPalindrome(string s) {
        
        int size = s.length();
        
        int** dp = new int*[size];
        
        for (int i = 0; i < size; i++) {
            dp[i] = new int[size];
        }
        
        for(int i=0; i< size; i++ )
        {
            for(int j=0; j< size; j++ )
            {
                dp[i][j] =0;
            }
        }
        
        for(int i=0; i<size; i++)
        {
            dp[i][i] = 1;
            if(i < (size -1) && s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
            }
        }
        
        
        
         for(int sz=2; sz < size; sz++ )
        {
            for(int si=0; si < size-sz; si++ )
            {
                if(dp[si+1][si+sz-1] == 1 && s[si] == s[si+sz])
                {
                    dp[si][si+sz] =1;
                }
            }
        }
        
        
        int si = 0, e, max = 1;
        for(int i=0; i< size; i++ )
        {
            for(int j=i; j< size; j++ )
            {
                if(dp[i][j] == 1)
                {
                    if(max < (j -i+1))
                    {
                        max = j - i+1;
                        si = i;
                        e = j;
                    }
                }

            }    
        }
        
        return s.substr(si, max);
    }
};
