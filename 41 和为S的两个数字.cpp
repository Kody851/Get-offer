输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
本题很简单，复杂度O(n)
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>res;
        if(array.empty()) return res;
        int i=0,j=array.size()-1;
        while(i<j){
            if(array[i]+array[j]==sum){
                res.push_back(array[i]);
                res.push_back(array[j]);
                return res;
            }
            else if(array[i]+array[j]<sum) i++;
            else j--;
        }
        return res;
    }
};
