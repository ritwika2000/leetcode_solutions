class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans=0;
        
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++)
        {
            v.push_back({growTime[i],plantTime[i]});
        }
        
        sort(v.begin(),v.end());
        int  t=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            t+=v[i].second;
            ans=max(ans,t+v[i].first);
        }
        
        return ans;
    }
};