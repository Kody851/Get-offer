最优解：
本题的特点，只有两个数出现一次，其他都出现偶数次。
利用异或的性质：两个相同数字异或=0，一个数和0异或还是它本身。
知识点：
1、if((x&1)==0)必须加括号，因为==的优先级高于&
2、喂数据时，
int main() {
     vector<int>data={2,4,3,6,3,2,5,5};
     int *num1=0;
     int *num2=0;
     FindNumsAppearOnce(data,num1,num2);
     cout<<num1<<*num1;
     return 0;
最优解法：
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int n=data.size();
        int tmp=0;
        for(int i=0;i<n;i++)
            tmp^=data[i];
        *num1=0,*num2=0;
        for(int i=0;i<n;i++){//FindIndexOf1(tmp)与数组中每个数相与，按照结果是0还是1将数组分成两部分
            if(data[i]&FindIndexOf1(tmp)) *num1^=data[i];
            else *num2^=data[i];
        }
    }
    int FindIndexOf1(int x){//若x右起第2位是1，则返回0x2(0010)
        int t=0x1;
        while((x&t)==0){
            t=t<<1;
        }
        return t;
    }
};
class Solution {//时间O(n) 空间0
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int tmp=0, n=data.size();
        if(n<2) return;
        for(int i=0;i<n;i++){//每个数逐个异或
            tmp^=data[i];
        }
        int bit=Find1FromRight(tmp);//从右边数第一个不是0的数 是右起第几位（从0起）
        int k=1;
        for(int i=0;i<bit;i++){//k仅第bit位为1
            k=k<<1;
        }
        *num1=*num2=0;
        for(int i=0;i<n;i++){
            if((data[i]&k)==0) *num1^=data[i];//第bit位为0
            else *num2^=data[i];////第bit位为0
        }
    }
    int Find1FromRight(int x){
        int num=0;
        while(x){
            if((x&1)==0){
                x=x>>1;
                num++;
            }
            else return num;
        }
        return num;
    }
};
//法2，哈希表
class Solution {//时间O(n) 空间O(n)
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_map<int,int>map(0);
        for(int i=0;i<data.size();i++){
            map[data[i]]++;
        }
        int i=0;
        for(;i<data.size();i++){
            if(map[data[i]]==1){
                *num1=data[i];
                break;
            }
        }
        for(++i;i<data.size();i++){
            if(map[data[i]]==1){
                *num2=data[i];
                break;
            }
        }
    }
};
