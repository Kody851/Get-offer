/*
题目描述P205
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

//1、哈希表，时间O(n) 空间O(n)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n=numbers.size();
        if(n==0) return 0;
        unordered_map<int,int>map;//或unordered_map<int,int>map(0);
        for(int i=0;i<n;i++){
            map[numbers[i]]++;
            if(map[numbers[i]]>n/2) return numbers[i];
        }
        return 0;
    }
};
//2、数组  时间O(n) 空间无 （最优解！）
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int n=numbers.size();
        int val=numbers[0],count=1;
        for(int i=1;i<n;i++){
            if(numbers[i]==val) count++;
            else count--;
            if(count==0){
                val=numbers[i];//最后一个把count设为1的数就是所求，它存在val中
                count=1;
            }
        }
        //验证val的次数
        count=0;
        for(int i=0;i<n;i++){
            if(numbers[i]==val) count++;
        }
        return count>n/2 ? val : 0;
    }
};
//3、Partition函数（找第K大的数）。会修改原数组
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int n=numbers.size();
        int start=0,end=n-1;
        int index=Partition(numbers,start,end);
        int mid=n>>1;
        while(index!=mid){//寻找中位数
            if(index<mid) {
                start=index+1;
                index=Partition(numbers,start,end);
            }
            if(index>mid){
                end=index-1;
                index=Partition(numbers,start,end);
            }
        }
        int res=numbers[index],times=0;
        for(int i=0;i<n;i++){
            if(numbers[i]==res) times++;//计算中位数出现次数
        }
        if(times<=mid) return 0;
        return res;
    }
    int Partition(vector<int>&numbers,int start,int end){
        int small=start-1;
        for(int i=start;i<end;i++){
            if(numbers[i]<numbers[end]){//取numbers[end]为中枢数
                small++;
                if(small!=i) swap(numbers[small],numbers[i]);
            }
        }
        small++;
        swap(numbers[small],numbers[end]);//numbers[end]左边的比它小，右边的比它大
        return small;//比中枢数小的数字个数
    }
};
