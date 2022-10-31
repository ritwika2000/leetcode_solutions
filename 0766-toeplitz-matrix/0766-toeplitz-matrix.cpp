class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      for(int i=0;i<matrix[0].size();i++)
      {
          int val=matrix[0][i];
          int r=0;
          int c=i;
          
          while(r<matrix.size() && c<matrix[0].size())
          {
              if(val != matrix[r][c])
              {
                  return false;
              }
              
              r++;
              c++;
          }
      }
        
        for(int i=0;i<matrix.size();i++)
        {
            int val=matrix[i][0];
            int r=i;
            int c=0;
            
            while(r<matrix.size() && c<matrix[0].size())
            {
                if(val !=matrix[r][c]) return false;
                
                r++;
                c++;
            }
            
        }
        
        return true;
    }
};