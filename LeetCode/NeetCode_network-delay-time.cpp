// https://neetcode.io/problems/network-delay-time?list=neetcode150

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1, vector<pair<int, int>>());

        for(auto& e: times)
        {
            g[e[0]].push_back({e[2], e[1]});
        }

        vector<int> dist(n+1, INT_MAX);
        vector<bool> v(n+1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;

        //pq.push()
        //queue<pair<int, int>> q;
        pq.push({0, k});
        int res =0;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            if( v[p.second])
                continue;
            v[p.second] = true;
            res = p.first;

            for(auto& e: g[p.second])
            {
                if(v[e.second])
                    continue;
                pq.push({e.first + p.first, e.second});
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(!v[i])
                return -1;
        }
        
        return res;


    }
};
