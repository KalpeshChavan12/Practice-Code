// https://neetcode.io/problems/min-cost-to-connect-points?list=neetcode150

class DS
{
    vector<int> ds;
    vector<int> ranks;
    public:
        DS(int s):ds(s, 0), ranks(s, 0)
        {
            for(int i=0; i<s; i++)
            {
                ds[i] = i;
            }
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int, 3>> edges;

        for(int i=0; i< points.size(); i++)
        {
            for(int j=0; j< points.size(); j++)
            {
                int d = abs(points[i][0] - points[j][0]) + 
                        abs(points[i][1] - points[j][1]);

                edges.push_back({d, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int res=0;
        DS ds(points.size());

        for(auto& item: edges)
        {
            if(ds.find(item[1]) != ds.find(item[2]))
            {
                ds.ds_union(item[1], item[2]);
                res+= item[0];
            }
        }
        return res;
    }
};
