题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

若没有最后一句话（书上是这种情况）：
class Solution {//前后指针法，i指向偶数，j指向奇数
public:
    void reOrderArray(vector<int> &array) {
        int n=array.size();
        if(n==0) return;
        int i=0, j=n-1;
        while(i<j){
            while(i<j&&(array[i]&0x1)==1) i++;//判断i<j是为了防止死循环
            while(i<j&&(array[j]&0x1)==0) j--;
            if(i<j) swap(array[i],array[j]);//判断i<j是为了防止错误交换
        }
    }
}; 
要求相对位置不变：
class Solution {//后指针需要从与i相邻开始
public:
    void reOrderArray(vector<int> &array) {
        int n=array.size();
        if(n==0) return;
        int i=0, j=1;
        while(j<n){
            while(i<n&&(array[i]&0x1)==1) i++;//i指偶数,防止全奇数时i溢出
            j=i+1;
            while(j<n&&(array[j]&0x1)==0) j++;//j指i后的奇数
            if(j>=n) break;//说明找到最后也没找到奇数，循环结束
            while(j!=i){//array[j]依次与前面的偶数交换
                swap(array[j],array[j-1]);
                j--;
            }
            i++;
        }
    }
}; 
法2
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty()) return;
        int i=1;
        while(i<array.size()){
            if(array[i]%2!=0&&array[i-1]%2==0){
                swap(array[i],array[i-1]);
                if(i!=1) i--;//交换之后还要继续，以防奇数前面有好几个偶数
            }
            else i++;
        }
    }
};
