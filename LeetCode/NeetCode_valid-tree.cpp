// https://neetcode.io/problems/valid-tree?list=blind75

class DS
{
    vector<int> ds;
    vector<int> ranks;
    public:
        DS(int s):ds(s), ranks(s)
        {
            for(int i=0; i<s;i++)
                ds[i] = i;
        }
    
    int find(int s)
    {
        if(ds[s] != s)
            return find(ds[s]);
        return ds[s];
    }

    void union_set(int a, int b)
    {
        int a1 = find(a);
        int b1 = find(b);
        if(a1 != b1)
        {
            if(ranks[a1] < ranks[b1])
                swap(a1, b1);
            ds[b1]=a1;
            if(ranks[a1] == ranks[b1])
                ranks[a1]++;
        }
    }

};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> v(n, false);
        
        DS ds(n);

        for(auto& e: edges)
        {
            if(ds.find(e[0]) == ds.find(e[1]))
                return false; //loop

            ds.union_set(e[0], e[1]);
        }
        
        int prev = ds.find(0);
        for(int i=1; i<n; i++)
        {
            if(ds.find(i) != prev)
                return false;
        }

        return true;
    }
};

