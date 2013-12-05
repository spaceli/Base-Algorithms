/*此实例的无向图如下所示           最后生成的最小生成树如下 
       v1---2---v2                       v1----2------v2
      /  \     /  \                       \
     4    1   3   10                       1
    /      \ /     \                        \
   v3--2---v4--7---v5              v3---2---v4     v5
    \     /  \     /                          \    /
     5   8   4    6                           4   6
      \ /     \  /                             \ /
      v6---1---v7                     v6---1---v7
无向图和最小生成树均由矩阵表示*/      

#include "myhead.h"

const int n=7;
int Tree[n][n]={       //无向图转化为矩阵 
    {0  ,2  ,4  ,1  ,100,100,100},
    {2  ,0  ,100,3  ,10 ,100,100},
    {4  ,100,0  ,2  ,100,5  ,100},
    {1  ,3  ,2  ,0  ,7  ,8  ,4  },
    {100,10 ,100,7  ,0  ,100,6  },
    {100,100,5  ,8  ,100,0  ,1  },
    {100,100,100,4  ,6  ,1  ,0  }
};

void prim() 
{
    cout<<"无向图如下所示"<<endl;
	cout<<"       v1----2----v2 "<<endl;
    cout<<"      / \\        / \\ "<<endl; 
    cout<<"    4     1    3    10"<<endl;
    cout<<"   /       \\  /       \\  "<<endl;
    cout<<" v3----2----v4----7----v5"<<endl;
    cout<<"   \\       /  \\       / "<<endl;
    cout<<"     5   8      4    6 "<<endl;
    cout<<"      \\ /        \\ /  "<<endl;
    cout<<"       v6----1----v7  "<<endl;

	
   	int state[n],okpath=0;//state存放节点i是否被连接过,okpath记录已连接的路径数目 
    state[0]=1;
	for(int i=1;i<n;i++) state[i]=0;//1为已连接，0为未连接
	cout<<"Prim算法的生成步骤如下"<<endl;
	while(okpath<n-1)  //需要算出n-1条路径 
	{
		int min=100,mini=0,minj=0;//记录最小权及其坐标
		for(int i=0;i<n;i++)   //全部扫描一遍
		{
			if(state[i]==1)    //从已选点中延伸出路径
			{
    			for(int j=0;j<n;j++)
    			{
    				if(state[j]==0&&Tree[i][j]<min&&i!=j)  //备选点一定为未选
    				{
                        min=Tree[i][j];
                        mini=i;
                        minj=j;
                    }
    			}
            }
		}
		state[minj]=1;
		cout<<"连接节点v"<<mini+1<<"和节点v"<<minj+1<<"，路径长为"<<min<<endl;
        okpath++; 
	}
}

void Kruskal()
{

   	int treenum=0; //记录子树的个数(设第1棵为最小生成树）
	int state[n];//对应各节点的状态,0为未连接，i(i>0)表示连接在第i棵子树上

	for(int i=0;i<n;i++) 
	{
		state[i]=0;//初始化为均未连接
	}
	cout<<"Kruskal算法的生成步骤如下"<<endl;
	for(int t=1;t<n;t++)  //最后一个节点也连在最小生成树上则终止 
	{
		int min=100,mini=0,minj=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				if(Tree[i][j]<min) 
				{
					if((state[i]==0&&state[j]==0)||state[i]!=state[j])
					{//两点不能同时在一棵树上,但都是单节点可以
						min=Tree[i][j];
						mini=i;
						minj=j;
					}
				}
			}
		
		cout<<"连接节点v"<<mini+1<<"和节点v"<<minj+1<<"，路径长为"<<min<<endl;
		if(t==1)
		{
			 treenum=1;
			 state[mini]=1;  state[minj]=1;//连接在最小生成树上
		}
		else
		{
			if(state[mini]==0&&state[minj]==0) //俩单节点连成一棵新树
			{
				state[mini]=++treenum;
				state[minj]=treenum;
			}
			if(state[mini]*state[minj]==0)  //单节点连接在一棵树上的情况
			{
				if(!state[mini]) state[mini]=state[minj];
				else state[minj]=state[mini];
			}
			else   //两点在不同树上的情况
			{
				int smalltree,bigtree;// 记录两棵树的序号
				if(state[mini]>state[minj]) { smalltree=state[minj];bigtree=state[mini];}
				else  { smalltree=state[mini];bigtree=state[minj];}
				for(int i=0;i<n;i++)  //把序号大的树上的点全接到序号小的树上
				{
					if(state[i]==bigtree) state[i]=smalltree;
				}
			}//end else
		}//end else
	}//end for
	
}

int minimumSpanningTreeMain()
{
	prim();
	cout<<"Prim算法结束"<<endl<<endl;
	Kruskal();
    cout<<"Kruskal算法结束"<<endl<<endl;
    system("pause");
    return 1;
}
