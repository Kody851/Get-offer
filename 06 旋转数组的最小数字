题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

//从头查找需要O(n)，本题从旋转数组下手进行优化，采用二分法定位两个排序子部分的分界点，复杂度O(logn)，注意特例。
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n=rotateArray.size();
        if(n==0) return 0;
        int p1=0, p2=n-1, mid=0;//mid初始化为0，确保未旋转时输出为第一个
        while(rotateArray[p1]>=rotateArray[p2]){
            if(p2-p1==1){
                mid=p2;
                break;
            }
            mid=(p1+p2)/2;
            if(rotateArray[p1]==rotateArray[p2]==rotateArray[mid]){//特殊情况只能遍历
                int res=rotateArray[p1];
                for(int i=p1;i<p2;i++){
                    res= res<=rotateArray[i] ? res : rotateArray[i];
                }
                return res;
            }
            if(rotateArray[mid]>=rotateArray[p1]) p1=mid;//二分
            else p2=mid;
        }
        return rotateArray[mid];
    }
};
