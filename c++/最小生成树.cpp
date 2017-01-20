#include<iostream>  
#include<fstream>  
using  namespace std;  
  
#define MAX 100
#define MAXCOST 0x7fffffff
  
int graph[MAX][MAX];  
  
int prim(int graph[][MAX], int n)  
{  
    int lowcost[MAX]; // 记录到已经找到的子图的最短距离 0为找到
    int mst[MAX]; // 记录最小距离的终点 0为在子图中
    int i, j, min, minid, sum = 0;  
    mst[1] = 0; 
    lowcost[1] = 0;
    // 初始化到1的距离 此时mst中只有1 
    for (i = 2; i <= n; i++)
    {  
        lowcost[i] = graph[1][i];
        mst[i] = 1;
    }  



    for (i = 2; i <= n; i++)   // 循环n-1次 把所有点加入mst集合中
    {
        min = MAXCOST;
        minid = 0;
        for (j = 2; j <= n; j++)
        {
            if (lowcost[j] < min && lowcost[j] != 0) // 从第二个开始寻找最小权值边 和对应的点
            {
                min = lowcost[j];
                minid = j;
            }
        }
        cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;  
        sum += min;
        lowcost[minid] = 0;
        


        // 更新 lowcase mst
        for (j = 2; j <= n; j++)  
        {  
            if (graph[minid][j] < lowcost[j])  
            {  
                lowcost[j] = graph[minid][j];  
                mst[j] = minid;  
            }  
        }  
        
    }
    return sum;  
}
  
int main()  
{  
    int i, j, k, m, n;  
    int x, y, cost;  
    ifstream in("input.txt");  
    in >> m >> n;//m=顶点的个数，n=边的个数  
    //初始化图G  
    for (i = 1; i <= m; i++)  
    {  
        for (j = 1; j <= m; j++)  
        {  
            graph[i][j] = MAXCOST;  
        }  
    }  
    //构建图G  
    for (k = 1; k <= n; k++)  
    {  
        in >> i >> j >> cost;  
        graph[i][j] = cost;  
        graph[j][i] = cost;  
    }  
    //求解最小生成树  
    cost = prim(graph, m);  
    //输出最小权值和  
    cout << "最小权值和=" << cost << endl;  
    return 0;  
} 