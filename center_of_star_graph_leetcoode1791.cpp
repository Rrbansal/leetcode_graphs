class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>m;
        int rows=edges.size();
        int col=edges[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                m[edges[i][j]]++;
            }
        }
        int n=m.size();
        for(auto ele:m)
        {
            if(m[ele.first]==n-1) return ele.first;
        }
        return 0;
    }
};
