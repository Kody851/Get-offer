题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

class Solution {//常规解法，时间O(n)，空间O(n)
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length<=0) return false;
        unordered_set<int>set;
        for(int i=0;i<length;i++){
            if(set.find(numbers[i])!=set.end()){
                * duplication=numbers[i];
                return true;
            }
            else{
                set.insert(numbers[i]);
            }
        }
        return false;
    }
};

class Solution {//考虑到限制条件：长度为n的数组里的所有数字都在0到n-1的范围内。可做优化，但需要修改原数组。时间O(n)，空间0
public://若没有重复，则数组中的元素就是下标那些值
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==nullptr||length<=0) return false;
        for(int i=0;i<length;i++){
            if(numbers[i]<0||numbers[i]>length-1) return false;
        }
        for(int i=0;i<length;i++){
            if(numbers[i]==i) continue;
            else{
                if(numbers[i]==numbers[numbers[i]]){
                    * duplication=numbers[i];
                    return true;
                }
                else{
                    swap(numbers[i], numbers[numbers[i]]);
                    i--;
                }
            }
        }
        return false;
    }
};
