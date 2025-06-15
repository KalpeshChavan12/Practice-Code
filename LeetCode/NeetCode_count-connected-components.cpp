// https://neetcode.io/problems/count-connected-components?list=neetcode150

class DS
{
    vector<int> ds;
    vector<int> ranks;
    public:
        DS(int s): ds(s), ranks(s, 0)
        {
            for(int i=0; i<s; i++)
                ds[i] = i;
        }

        int find(int a)
        {
            if(ds[a] != a)
                return find(ds[a]);
            return ds[a];
        }

        void ds_union(int a, int b)
        {
            int a1 = find(a);
            int b1 = find(b);
            if(a1 != b1)
            {
                if(ranks[a1] < ranks[b1])
                    swap(a1, b1);
                ds[b1] = a1;
                if(ranks[a1] == ranks[b1])
                    ranks[a1]++;
            }
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DS ds(n);

        for(auto& e: edges)
        {
            ds.ds_union(e[0], e[1]);
        }

        set<int> p;
        for(int i=0; i<n; i++)
        {
            int tmp = ds.find(i);
            p.insert(tmp);
        }

        return p.size();
    }
};
