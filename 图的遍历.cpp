/*此实例的连通图如下所示
        v1  v7         
       / \ / |
     v2   v3 |
       \ / \ |
       v4   v8
       / \
     v5  v6
此文件包含深度遍历和广度遍历两算法*/ 

#include "myhead.h"

const int n=8;  
static int path[n][n]={   //图转化为矩阵 
		{0,1,1,0,0,0,0,0},
		{1,0,0,1,0,0,0,0},
		{1,0,0,1,0,0,1,1},
		{0,1,1,0,1,1,0,0},
		{0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0},
		{0,0,1,0,0,0,0,1},
		{0,0,1,0,0,0,1,0}
    };

void depthFirstTraversal(int i,int *visit)//深度优先遍历,i为当前查询的节点
{
	for(int j=1;j<n;j++)
	{
		if(path[i][j]==1&&visit[j]==0)
		{
			visit[j]=1;
			cout<<"---访问节点v"<<j+1<<endl;
			depthFirstTraversal(j,visit);
		}
	}
}

void breadthFirstTraversal()//广度优先遍历 
{
  
	int visit[n],t=0;//用visit数组代替队列，记录访问节点的顺序,t为队头的下标
	for(int i=0;i<n;i++)
		visit[i]=-1;
	visit[0]=0;  //起点为v1; 
	cout<<"广度优先遍历算法，从节点v"<<visit[0]+1<<"开始"<<endl;
	while(visit[n-1]==-1)//最后一个节点进队列，算法结束 
	{
		int i=visit[t];//查询队头节点的路径 
		for(int j=0;j<n;j++)
		{			
			if(path[i][j]==1)  // i 点和 j 点连通
			{
                int s=0;
				for(s;visit[s]!=-1;s++) // 查询 j 点是否被访问过
					if(visit[s]==j) break; //被访问过，放弃

				if(visit[s]==-1) //没被访问过
				{
					visit[s]=j;  //插入到被访问的队列中
					cout<<"---访问节点v"<<j+1<<endl;
				}
			}//end if
		}//end for
		t++;   //当前节点的路径查询完毕，换下一个节点
	}//end while
	cout<<"广度优先遍历结束"<<endl; 
}

int diagramTraversalMain()
{
    cout<<"连通图如下所示"<<endl; 
    cout<<"        v1  v7  "<<endl;        
    cout<<"       / \\ / |  "<<endl;
    cout<<"     v2   v3 |  "<<endl;
    cout<<"       \\ / \\ |  "<<endl;
    cout<<"       v4   v8  "<<endl;
    cout<<"       / \\      "<<endl;
    cout<<"     v5  v6     "<<endl;
    int depthVisit[n];//深度优先遍历中记录节点是否被访问过的数组
	for(int i=1;i<n;i++)  depthVisit[i]=0; //初始化为未访问
	depthVisit[0]=1;//标记第一个节点为已访问
    cout<<"深度优先遍历算法，从节点v1开始"<<endl; 
    depthFirstTraversal(0,depthVisit);//从第一个节点开始查找 
    cout<<"深度优先遍历结束"<<endl<<endl; 
    
    breadthFirstTraversal(); 
    system("pause");
	return 1;
}
