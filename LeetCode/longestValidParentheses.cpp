class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(s.length() == 0)
        {
            return 0;
        }
        
        stack<int> st;
        st.push(-1);
        int max=0;
        for(int i=0; i< s.length(); i++)
        {
            if( s[i] == ')')
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    auto e = st.top();
                    if(max < (i-e))
                    {
                        max = i-e;
                    }
                }
            }
            if(s[i] == '(')
            {
                st.push(i);
            }
        }
        
        return max;
    }
};
