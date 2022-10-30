class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ans=0;
        queue<vector<int>> q;
        
        q.push({0,0,k});
        int n=grid.size();
        int m= grid[0].size();
        
        vector<vector<vector<int>>> visit(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                vector<int> temp=q.front();
                q.pop();
                
                if(temp[0] == n-1 && temp[1]== m-1 && temp[2]-grid[temp[0]][temp[1]] >=0) return ans;
                
                if(temp[2]<0 || visit[temp[0]][temp[1]][temp[2]]!=0) continue;
                
                visit[temp[0]][temp[1]][temp[2]]=1;
                
                if(temp[0]-1 >= 0 ) q.push({temp[0]-1,temp[1],temp[2]-grid[temp[0]][temp[1]]});
                if(temp[0]+1< grid.size()) q.push({temp[0]+1,temp[1],temp[2]-grid[temp[0]][temp[1]]});
                if(temp[1]-1 >= 0) q.push({temp[0],temp[1]-1,temp[2]-grid[temp[0]][temp[1]]});
                
                if(temp[1]+1 < grid[0].size()) q.push({temp[0],temp[1]+1,temp[2]-grid[temp[0]][temp[1]]});
            }
            
            ans++;
        }
        
        return -1;
        
    }
};