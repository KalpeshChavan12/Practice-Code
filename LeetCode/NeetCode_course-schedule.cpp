// https://neetcode.io/problems/course-schedule?list=blind75



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        for(auto& p : prerequisites)
        {
            g[p[0]].push_back(p[1]);
        }

        for(int i=0; i<numCourses; i++)
        {
            set<int> v;
            if(detectCycle(i, g, v))
                return false;
        }        

        return true;
    }

    bool detectCycle(int s, vector<vector<int>>& g, set<int>& visited)
    {
        
        if(g[s].empty())
            return false;
        if(visited.find(s) != visited.end())
            return true;
        
        visited.insert(s);
        for(auto n: g[s])
        {
            if(detectCycle(n, g, visited))
                return true;
        }
        visited.erase(s);
        g[s].clear();
        return false;
    }
};
