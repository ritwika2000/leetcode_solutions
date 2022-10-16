class Solution {
public:
    int solve(vector<int>& jobDifficulty,vector<vector<int>>& dp,int i,int d)
    {
        if(i==jobDifficulty.size())
        {
           if(d!=0)
               return INT_MAX;
            
            return 0;
        }
        
        if(d==0)
            return INT_MAX;
        
        if(dp[i][d]!=-1)
            return dp[i][d];
        
        int maxi=INT_MIN;
        int minans=INT_MAX;
        for(int idx=i;idx<jobDifficulty.size();idx++)
        {
            maxi=max(maxi,jobDifficulty[idx]);
            int ans=solve(jobDifficulty,dp,idx+1,d-1);
            if(ans!=INT_MAX)
            {
                ans+=maxi;
            }
            minans=min(ans,minans);
        }
        
        return dp[i][d]=minans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)
            return -1;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return solve(jobDifficulty,dp,0,d);
    }
};