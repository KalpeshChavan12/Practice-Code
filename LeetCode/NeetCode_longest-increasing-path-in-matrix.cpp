// https://neetcode.io/problems/longest-increasing-path-in-matrix?list=blind75

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        auto m = matrix.size();
        if(m ==0 )
        {
            return 0;
        }
        
        auto n = matrix[0].size();
        
        vector<vector<int>> dist( m , vector<int> (n, 1)); 
        vector<vector<bool>> vis( m , vector<bool> (n, false)); 
        
        for(int i=0; i < m; i++)
        {
            for(int j=0; j< n; j++)
            {
                GetDist(dist, vis, matrix, m,n, i,j);
            }
        }
        
        int mx =1;
        
        for(int i=0; i < m; i++)
        {
            for(int j=0; j< n; j++)
            {
                mx = std::max(mx, dist[i][j]);
            }
        }
        
        return mx;
    }
    
    int GetDist(vector<vector<int>> &dist, vector<vector<bool>> &vis, vector<vector<int>>& matrix, int m, int n, int i, int j)
    {
        //cout<<" "<<i<<" "<<j<<" "<<endl;
        if(i >= m || j >= n)
        {
            return 0;
        }
        
        if(vis[i][j])
        {
            return dist[i][j];
        }
        
        vis[i][j] = true;
        
        int max1=0,max2=0,max3=0,max4=0 ;
        
        if(i != 0 && matrix[i][j] > matrix[i-1][j])
        {
            max1 = GetDist(dist, vis, matrix, m, n, i-1, j);
        }
        
        if(j != 0 && matrix[i][j] > matrix[i][j-1])
        {
            max2 = GetDist(dist, vis, matrix, m, n, i, j-1);
        }
        
        if(i < (m-1) && matrix[i][j] > matrix[i+1][j])
        {
            max3 = GetDist(dist, vis, matrix, m, n, i+1, j);
        }
        
        if(j < (n - 1) && matrix[i][j] > matrix[i][j+1])
        {
            max4 = GetDist(dist, vis, matrix, m, n, i, j+1);
        }
    
        //cout<<"Max "<<max1<<","<<max2<<","<<max3<<","<<max4<<","<<endl;
        
        auto m1=std::max(max1, max2);
        auto m2=std::max(max3, max4);
        
        dist[i][j] = dist[i][j] + std::max(m1,m2);
        
        return dist[i][j];
    }
};
