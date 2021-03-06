知识点：二分法的start与end在循环条件中包括“=”
1、
class Solution {//二分法 O(logn)
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int first=IndexLeftK(data,k);
        int last=IndexRightK(data,k);
        if(first!=-1&&last!=-1) return last-first+1;
        else return 0;
    }
    int IndexLeftK(vector<int> data ,int k){
        int i=0, j=data.size()-1;
        while(i<=j){//知识点在这里！！！
            int m=(i+j)/2;
            if(data[m]==k){
                if(m==0||m>0&&data[m-1]!=k) return m;
                else j=m-1;
            }
                
            else if(data[m]<k) i=m+1;
            else j=m-1;
        }
        return -1;
    }
    int IndexRightK(vector<int> data ,int k){
        int i=0, j=data.size()-1;
        while(i<=j){
            int m=(i+j)/2;
            if(data[m]==k){
                if(m==data.size()-1||m<data.size()-1&&data[m+1]!=k) return m;
                else i=m+1;
            }
            else if(data[m]<k) i=m+1;
            else j=m-1;
        }
        return -1;
    }
};
2、
class Solution {//哈希表
public:
    int GetNumberOfK(vector<int> data ,int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<data.size();i++){
            mp[data[i]]++;
        }
        return mp[k];
    }
};
3、
//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        return index_insert(data,k+0.5)-index_insert(data,k-0.5);
    }
private:
    int index_insert(vector<int>data ,double x){
        int start=0,end=data.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(data[mid]<x) start=mid+1;
            else if(data[mid]>x) end=mid-1;
        }
        return start;
    }
};
