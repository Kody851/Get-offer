网络延迟时间 - 力扣 (LeetCode) https://leetcode-cn.com/problems/network-delay-time/
有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们向当前的节点 K 发送了一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。

注意:

N 的范围在 [1, 100] 之间。
K 的范围在 [1, N] 之间。
times 的长度在 [1, 6000] 之间。
所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //构造邻接矩阵
        vector<vector<int>> mat(N+1,vector<int>(N+1));
        for(int i = 1;i <= N;i++){//题目要求是顶点1到N
            for(int j = 1;j <= N;j++){
                if(i == j) mat[i][j] = 0;
                else mat[i][j] = 0x3f3f3f3f;
            }
        }
        for(int i = 0;i < times.size();i++){
            mat[times[i][0]][times[i][1]] = times[i][2];//赋权值
        }
        
        //距离、标志位的初始化
        vector<int> dist(N+1);//K点到任一点i的距离
        vector<int> flag(N+1);//到i点最短距离已求好，赋1
        for(int i = 1;i <= N;i++){
            dist[i] = mat[K][i];//初始化为邻接矩阵中边的权值
        }
        flag[K] = 1;//点K无需计算自身距离
        int delay = 0;
        //
        for(int i = 0;i < N - 1;i++){
            int u = K,min = 0x3f3f3f3f;
            for(int j = 1;j <= N;j++){
                if(!flag[j] && dist[j] < 0x3f3f3f3f && dist[j] < min){
                    u = j;//记录节点，它的最短距离已求得
                    min = dist[j];
                }
            }
            flag[u] = 1;
            if(u == K) return -1;//k点没有出度
            if(mind > delay) delay = min;//到每个节点的最短路径最大的那个
            for(int j = 1;j <= N;j++){
                if(!flag[j] && map[u][j] < 0x3f3f3f3f && map[u][j] + dist[u] < dist[j])//若先到u再到j的路径比直接到j短，需更新
                    dist[j] = map[u][j] + dist[u];
            }
        }
        return delay;
    }
};
--------------------- 
作者：tzyshiwolaogongya 
来源：CSDN 
原文：https://blog.csdn.net/tzyshiwolaogongya/article/details/79652670 
版权声明：本文为博主原创文章，转载请附上博文链接！

从A地坐地铁到B地,小于3站收费2元，大于等于3站，每2站加收1元。问怎么坐车收费最少。
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int A, int B) {
        //构造邻接矩阵
        vector<vector<int>> matrix(N,vector<int>(N));
        for(int i = 0;i < times.size();i++){
            matrix[times[i][0]][times[i][1]] = 1;//赋权值
        }
        
        //距离、标志位的初始化
        vector<int> dist(N);//K点到任一点i的距离
        vector<int> flag(N,0);//到i点最短距离已求好，赋1
        for(int i = 0;i <N;i++){
            dist[i] = matrix[A][i];//初始化为邻接矩阵中边的权值
        }
        flag[A] = 1;//点A无需计算自身距离
        //
        int k=A;
        for(int i = 0;i < N - 1;i++){//每一次循环，求出距离A最近的顶点，若有多个，随机选一个，下次循环会接着选出来
            int min = INT_MAX;
            for(int j = 0;j < N;j++){
                if(!flag[j] && dist[j]!=0 && dist[j] < min){
                    k = j;//记录节点，它的最短距离已求得
                    min = dist[j];
                }
            }
            flag[k] = 1;
            if(k == A) return -1;//A点没有出度
            for(int j = 0;j < N;j++){//已知到k点的最短路径，修正A到其他点的最短路径
                if(!flag[j] && matrix[k][j] !=0 && matrix[k][j] + min < dist[j])//若先到k再到j的路径比直接到j短，需更新到j的最短路径
                    dist[j] = matrix[k][j] + min;
            }
        }
        if(dist[B]<3) return 2;
        else return 2+(dist[B]-1)/2;
    }
};
