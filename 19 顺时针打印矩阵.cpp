题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        int m=matrix.size(), n=matrix[0].size();
        if(m==0||n==0) return res;
        int circle=min(m,n)%2==0 ? min(m,n)/2 : min(m,n)/2+1;//(min(m,n)+1)/2
        /*行和列中较小者决定圈数，除最后一圈外，每一圈占2行（列），最后一圈可能占2行（列）或1行（列）.
          故若行是偶数，圈数=行数/2，否则=行数/2+1。*/
        for(int i=0;i<circle;i++){
            for(int j=i;j<=n-1-i;j++)
                res.push_back(matrix[i][j]);//从左到右
            for(int j=i+1;j<=m-1-i;j++)
                res.push_back(matrix[j][n-1-i]);//从上到下
            for(int j=n-2-i;j>=i&&m-1-i!=i;j--)
                res.push_back(matrix[m-1-i][j]);//从右到左，注意判断和从左到右的行应是不同的，否则重复
            for(int j=m-2-i;j>=i+1&&i!=n-1-i;j--)
                res.push_back(matrix[j][i]);//从下到上，注意判断和从上到下的列应是不同的，否则重复
        }
        return res;
    }
};
