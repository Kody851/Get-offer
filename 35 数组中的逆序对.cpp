知识点：
归并排序：参考 归并排序 - 如果天空不死 - 博客园 https://www.cnblogs.com/skywang12345/p/3602369.html ； 《大话》
class Solution {
public:
void mergeSort(vector<int>&a){
   mergeSortUp2Down(a, 0, a.size()-1);
}
void mergeSortUp2Down(vector<int>&a, int start, int end)
{
     if(a.empty() || start >= end) return;
     int mid = (end + start)/2;
     mergeSortUp2Down(a, start, mid); // 递归排序a[start...mid]
     mergeSortUp2Down(a, mid+1, end); // 递归排序a[mid+1...end]
     // a[start...mid] 和 a[mid...end]是两个有序空间，
     // 将它们排序成一个有序空间a[start...end]
     merge(a, start, mid, end);
 }
void merge(vector<int>&a, int start, int mid, int end) {
    vector<int>tmp(end - start + 1);// tmp是汇总2个有序区的临时区域
    int i = start;            // 第1个有序区的索引
    int j = mid + 1;        // 第2个有序区的索引
    int k = 0;                // 临时区域的索引
    while (i <= mid && j <= end) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= end)
        tmp[k++] = a[j++];
    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];
    tmp.clear();
}
};





#include <iostream>
using namespace std;

void merge(int* a, int start, int mid, int end) {
    int *tmp = new int[end - start + 1];    // tmp是汇总2个有序区的临时区域
    int i = start;            // 第1个有序区的索引
    int j = mid + 1;        // 第2个有序区的索引
    int k = 0;                // 临时区域的索引

    while (i <= mid && j <= end) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i <= mid)
        tmp[k++] = a[i++];

    while (j <= end)
        tmp[k++] = a[j++];

    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    delete[] tmp;
}
void mergeSortUp2Down(int* a, int start, int end)
{
     if(a==NULL || start >= end)
        return;

     int mid = (end + start)/2;
     mergeSortUp2Down(a, start, mid); // 递归排序a[start...mid]
     mergeSortUp2Down(a, mid+1, end); // 递归排序a[mid+1...end]

     // a[start...mid] 和 a[mid...end]是两个有序空间，
     // 将它们排序成一个有序空间a[start...end]
     merge(a, start, mid, end);
 }

int main() {
     int i;
     int a[] = {80,30,60,40,20,10,50,70};
     int ilen = (sizeof(a)) / (sizeof(a[0]));

     cout << "before sort:";
     for (i=0; i<ilen; i++)
             cout << a[i] << " ";
     cout << endl;

     mergeSortUp2Down(a, 0, ilen-1);        // 归并排序(从上往下)
     //mergeSortDown2Up(a, ilen);            // 归并排序(从下往上)

     cout << "after  sort:";
     for (i=0; i<ilen; i++)
             cout << a[i] << " ";
     cout << endl;

     return 0;
}

题目解答：
class Solution {//本题就在归并排序里加一句话，记录P的变化即可！
public:
    int InversePairs(vector<int> data) {
        int P=0;
        mergeSort(data, 0, data.size()-1,P);
        return P;
    }
    void mergeSort(vector<int>&data, int start, int end, int &P){
        if(data.empty() || start >= end) return;
        int mid = (end + start)/2;
        mergeSort(data, start, mid, P); // 递归排序a[start...mid]
        mergeSort(data, mid+1, end, P); // 递归排序a[mid+1...end]
         // a[start...mid] 和 a[mid...end]是两个有序空间，
         // 将它们排序成一个有序空间a[start...end]
        merge(data, start, mid, end, P);
    }
    void merge(vector<int>&data, int start, int mid, int end, int &P){
        vector<int>tmp(end - start + 1);// tmp是汇总2个有序区的临时区域
        int i = start;            // 第1个有序区的索引
        int j = mid + 1;        // 第2个有序区的索引
        int k = 0;                // 临时区域的索引
        while (i <= mid && j <= end) {
            if (data[i] <= data[j])
                tmp[k++] = data[i++];
            else{
                tmp[k++] = data[j++];
                P=(P+mid-i+1)%1000000007;//i到mid之间的(mid-i+1)个数都比j处大，故P增加mid-i+1
            }
        }
        while (i <= mid)
            tmp[k++] = data[i++];
        while (j <= end)
            tmp[k++] = data[j++];
        // 将排序后的元素，全部都整合到数组a中。
        for (i = 0; i < k; i++)
            data[start + i] = tmp[i];
        tmp.clear();
    }
};
