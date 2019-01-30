题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        int m=array.size();//行
        int n=array[0].size();列
        int i=0,j=n-1;//思路就是从右上角开始，左边的都比它小 右边的都比它大
        while(i<m&&j>=0){
            if(target==array[i][j]) return true;
            else if(target>array[i][j]) i++;
            else j--;
        }
        return false;
    }
};
