class Solution{ 
private:
    void dfs(int row, int col,  vector<vector<int>>&ans, vector<vector<int>>& image, int newColor,
    int delRow[],int delCol[], int initial_color)
    {
        int n=image.size();
        int m=image[0].size();
        ans[row][col]=newColor;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            
            if(nrow>=0&& nrow<n && ncol>=0&&ncol<m  && image[nrow][ncol]==initial_color && ans[nrow][ncol]!=newColor)
            {
                dfs(nrow, ncol, ans, image,newColor, delRow, delCol, initial_color);
            }
        }
    }
}
