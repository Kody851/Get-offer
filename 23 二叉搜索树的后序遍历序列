题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n=sequence.size();
        if(n==0) return false;//空数组不是后序遍历的结果，但递归时，递归到空数组应该返回true，因此下面设置flag
        int i=0;
        for(;i<n-1;i++){
            if(sequence[i]>sequence[n-1]) break;//i是第一个比sequence[n-1]大的数
        }
        for(int j=i+1;j<n-1;j++){
            if(sequence[j]<sequence[n-1]) return false;//i后都是右子树，若存在比sequence[n-1]小的，则错误
        }
        bool flag_left=true, flag_right=true;
        vector<int>sequence_left(sequence.begin(),sequence.begin()+i);
        vector<int>sequence_right(sequence.begin()+i,sequence.end()-1);
        if(!sequence_left.empty()) flag_left=VerifySquenceOfBST(sequence_left);//数组不为空才判断，为空时默认是true
        if(!sequence_right.empty()) flag_right=VerifySquenceOfBST(sequence_right);
        return flag_left&&flag_right;
    }
};
