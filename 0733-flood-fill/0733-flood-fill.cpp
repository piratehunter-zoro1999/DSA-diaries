class Solution {
public:
    
    void helper(vector<vector<int>> &image,int sr,int sc,int color,int o){
        int m =image.size();
        int n =image[0].size();

        if(sr>=m || sc>=n || sr<0 || sc<0 || image[sr][sc]!=o) return;
           
        image[sr][sc]=color;

        helper(image,sr+1,sc,color,o);
        helper(image,sr-1,sc,color,o);
        helper(image,sr,sc+1,color,o);
        helper(image,sr,sc-1,color,o);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor= image[sr][sc];

        if(color == originalColor) return image;


       helper(image,sr,sc,color,originalColor);

       return image;
        
    }
};