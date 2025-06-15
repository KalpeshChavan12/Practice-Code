// https://neetcode.io/problems/course-schedule-ii?list=neetcode150

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        
        vector<int> indegree(numCourses, 0);
        vector<int> visited(numCourses, 0);
        vector<int> res;

        for(auto& p: prerequisites)
        {
            g[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            res.push_back(n);
            
            visited[n] = true;
            for(auto n1 : g[n])
            {
                indegree[n1]--;
                if(indegree[n1] == 0)
                    q.push(n1);
            }
        }

        if(res.size() != numCourses)
            return {};

        return vector<int>(res.rbegin(), res.rend());
    }
};
