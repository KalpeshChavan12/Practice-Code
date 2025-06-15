// https://neetcode.io/problems/redundant-connection?list=neetcode150

class DS
{
    vector<int> ds;
    vector<int> ranks;
    public:
        DS(int n):ds(n), ranks(n,0)
        {
            for(int i=0; i<n; i++)
                ds[i] =i;
        }

        int find(int a)
        {
            if(ds[a] != a)
                return find(ds[a]);
            return ds[a];
        }

        void ds_union(int a, int b)
        {
            int a1=find(a);
            int b1= find(b);
            if(a1 != b1)
            {
                if(ranks[a1]<ranks[b1])
                    swap(a1, b1);
                ds[b1] = a1;
                if(ranks[a1] == ranks[b1])
                    ranks[a1]++;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DS ds(100);
        vector<int> res;
        for(auto& e: edges)
        {
            if(ds.find(e[0]) == ds.find(e[1]))
            {
                return e;
            }
            ds.ds_union(e[0], e[1]);
        }

        return {};
    }
};
