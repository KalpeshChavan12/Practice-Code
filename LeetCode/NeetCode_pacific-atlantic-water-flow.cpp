// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
    int ROW, COL;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW  = heights.size();
        COL  = heights[0].size();
        vector<vector<int>> pac(ROW, vector<int>(COL, -1));
        vector<vector<int>> at(ROW, vector<int>(COL, -1));
        queue<pair<int, int>> q;

        for(int i=0; i< ROW; i++)
        {
            q.push({i, 0});
            pac[i][0] = 1;
        }
        for(int i=0; i< COL; i++)
        {
            q.push({0, i});
            pac[0][i] = 1;
        }
        cout<<"qsize = "<<q.size()<<endl;
        bsf(heights, pac, q);
        //q.clear();

        for(int i=0; i< ROW; i++)
        {
            q.push({i, COL-1});
            at[i][COL-1] = 1;
        }
        for(int i=0; i< COL; i++)
        {
            q.push({ROW-1, i});
            at[ROW-1][i] = 1;
        }

        bsf(heights, at, q);

        vector<vector<int>> res;//(ROW, vector<int>(COL, -1));
        for(int i=0; i< ROW; i++)
        {
            for(int j=0; j< COL; j++)
            {
                if(pac[i][j] != -1 && at[i][j] != -1)
                {
                    vector<int> v ={i, j};
                    res.push_back(v);
                }
            }
        }

        return res;
    }

    void bsf(vector<vector<int>>& heights, vector<vector<int>>& res, queue<pair<int, int>>& q)
    {
        vector<pair<int, int>> dirs = {{1,0},{-1, 0},{0, 1},{0, -1}};

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            for(auto& d: dirs)
            {
                int r1 = p.first + d.first;
                int c1 = p.second + d.second;

                if(c1 <0 || r1<0 || c1>=COL || r1>=ROW)
                    continue;
                
                if(res[r1][c1] != -1 || heights[r1][c1] < heights[p.first][p.second] )
                    continue;
                
                res[r1][c1] = 1;
                q.push({r1, c1});
            }
        }
    }


};
