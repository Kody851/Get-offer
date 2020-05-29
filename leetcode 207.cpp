现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

@知识点1：pair
声明vector：
vector<pair<int,int> >vec
往vector中插入数据，需要用到make_pair:
vec.push_back(make_pair<int,int>(10,50));
vec.push_back(make_pair(20,30));
定义迭代器：
vector<pair<int,int> > ::iterator iter;
for(iter=vec.begin();iter!=vec.end();iter++);
数据读取：
第一个数据:(*iter).first
第二个数据:(*iter).second
原文：https://blog.csdn.net/linxihe123/article/details/70173476 
--------------------- 
@知识点2：图的BFS
void BFS(int num, vector<pair<int, int>>&edge, vector<int>vexs){//给了节点数组
    vector<vector<int>> graph(num, vector<int>(0));//邻接表
    for(auto i:edge) graph[i.first].push_back(i.second);
    queue<int>q;
    bool *visited[num];
    memset(visited,false,num);
    for(int i=0;i<num;i++){
        if(!visited[i]){
            visited[i]=true;
            cout<<vexs[i];
            q.push(i);
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(auto j : graph[temp]){
                    if(!visited[j]){
                        visited[j]=true;
                        cout<<vexs[j];
                        q.push(j);
                    }
                }
            }
        }
    }
}
void BFS(int num, vector<vector<int>>& edge, vector<int>vexs){//给了节点数组
    vector<vector<int>>mat(num, vector<int>(num))={0};//邻接矩阵
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            mat[edge[i][0]][edge[i][1]]=1;
        }
    }
    queue<int>q;
    bool *visited[num];
    memset(visited,false,num);
    for(int i=0;i<num;i++){
        if(!visited[i]){
            visited[i]=true;
            cout<<vexs[i];
            q.push(i);
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(int j=0;j<num;j++){
                    if(!visited[j]&&mat[i][j]==1){
                        visited[j]=true;
                        cout<<vexs[j];
                        q.push(j);
                    }
                }
            }
        }
    }
}
--------------------- 
@知识点2：图的DFS
void DFS(int num, vector<vector<int>>& edge, vector<int>vexs){//给了节点数组
    vector<vector<int>>mat(num, vector<int>(num))={0};//邻接矩阵
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            mat[edge[i][0]][edge[i][1]]=1;
        }
    }
    bool *visited[num];
    int i;
    for(i=0;i<num;i++) visited[i]=false;
    for(i=0;i<num;i++) {
        if(!visited[i]) DFScore(mat,vexs,i);
    }
}
void DFScore(vector<vector<int>>mat, vector<int>vexs,int i){
    visited[i]=true;
    cout<<vexs[i];
    for(int j=0;j<num;j++){
        if(mat[i][j]==1&&!visited[j]) DFScore(mat,vexs,j);
    }
    
}
--------------------- 
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));//由于定义是pair<int,int>，图采用邻接表
        vector<int> inDegree(numCourses, 0);//记录入度。pair<int<-int>方向是第二个指向第一个
        for(auto i : prerequisites){
            graph[i.second].push_back(i.first);
            inDegree[i.first]++;
        }//构建图和入度数组
        queue<int> q;

        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto j : graph[temp]){//寻找tmp指向的顶点
                inDegree[j]--;//该顶点的入度减一
                if(inDegree[j] == 0){//若入度为0则加入队列
                    q.push(j);
                }
            }
        }
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] != 0){//最终，若有入度不为0的顶点，则说明存在环
                return false;
            }
        }
        return true;
    }
};
若本题是无向图，则统计“度”，从度为1的顶点开始BFS，访问之后度减一，最终若有度大于1的顶点，则说明存在环.
无向图算法https://www.cnblogs.com/toulanboy/p/8017499.html
通过广度遍历（BFS）访问图的所有点，对于每个点，都检测和已访问过的点是否有边（除了和它连接的上层节点）。
适用范围：#
（1）判断图添加一条无向边后是否有回路。只要从这条新边的一个点出发执行操作（1）即可。
（2）判断一个图是否有回路。需要从任意点都执行一次操作（1），只有所有操作（1）均说明无回路，才表明没有回路。
