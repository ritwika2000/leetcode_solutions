class Solution {
public:
    int solve(vector<vector<int>>& adj,vector<bool>& hasapple,int i,int ans,vector<int>& visit,int& found)
    {
        visit[i]=1;
        int step=0;
        int f=0;
        for(auto node:adj[i])
        {
            if(visit[node]==0)
            {
                int f1=false;
                step+=1+solve(adj,hasapple,node,ans,visit,f1);
               if(f1==true)
               {
                   f=1;
                   step++;
               }
               else
               {
                   step--;
               }
            }
        }
        
        if(hasapple[i]==true|| f==1)
        {
            found=true;
        }
        
        return step;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       int ans=0;
       vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visit(n,0);
        int f=0;
        int res=solve(adj,hasApple,0,ans,visit,f);
        return res;
    }
};