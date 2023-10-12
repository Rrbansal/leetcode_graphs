class Solution {
public:
int c,r,col,val;
void f(vector<vector<int>>&image, int sr, int sc)
{
    if(sr>=r || sc>=col || sr<0 || sc<0 || image[sr][sc]!=val) return;
    image[sr][sc]=c;
    f(image,sr+1,sc);
    f(image,sr-1,sc);
    f(image,sr,sc+1);
    f(image,sr,sc-1);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        c=color;
        r=image.size();
        col=image[0].size();
        val=image[sr][sc];
        if(val==c) return image;
        f(image,sr,sc);
        return image;   
    }
};
