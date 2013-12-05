/*单源点最短路径算法，动态划归的典型实例*/ 
#include "myhead.h"

void findPass(int v,int i,int *pass)
{   
    if(i==v) cout<<'v'<<v+1<<' '; //如果经过点为起点，输出 
    else 
    {
         findPass(v,pass[i],pass);//否则，查找到此点的经过点 
         cout<<'v'<<i+1<<' ';   //输出此点 
    } 
}

void ShortestPath(int v,int cost[][7],int dist[],const int n)
{    //v是起点，算出v到各点的最短路径 
     int s[n],min,i,j;
     int pass[n];     //起点到点i中间的途径点
     for(i=0;i<=n;i++)
     {
             s[i]=0;    //解集合 
             dist[i]=cost[v][i];   //记录起点到点i间的直接距离
             pass[i]=v;   //初始化不途径任何点 
     }
     s[v]=1;
     dist[v]=0;
     for(i=1;i<=n;i++)  //共需寻找n-1条路径
     {
		  min=-1;
		  for(j=0;j<=n;j++)    //找到起点到未选点中距离最短的一个，用min标记其下标 
		  {
			  if(s[j]==0)
			  {
				  if(min==-1) min=j;
				  else if (dist[j]<dist[min]) min=j;
			  }
		  }
		  s[min]=1;
		  printf("到点v%d的距离为%d，路径为 : ",min+1,dist[min]);
		  findPass(v,pass[min],pass);
          cout<<'v'<<min+1<<endl; 
		  for(j=0;j<=n;j++)  //经过min点是否会使起点到其他未选结点的路径变短？ 
		  {
			  if(s[j]==0&&dist[min]+cost[min][j] <dist[j])
			  {  //比较两段之和与原路径哪个更短 
				  dist[j]=dist[min]+cost[min][j];
				  pass[j]=min;  //记录途经点min 
			  }
		  }		  
     }
     cout<<"起点v"<<v+1<<"到各点的最短距离：";
	 for(j=0;j<=n;j++)  //显示起点到各点的最短距离 
	 cout<<dist[j]<<' ';
	 cout<<endl;
}

void AllPath(int cost[][7],const int n)
{
	int A[n+1][n+1];//记录每对结点间的距离 
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			A[i][j]=cost[i][j];
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				if(A[i][j]>A[i][k]+A[k][j]) //检查经过点k是否会更短 
                    A[i][j]=A[i][k]+A[k][j];
			}
	
	for(int i=0;i<=n;i++)
	{
		cout<<"V"<<i+1<<"到各点的最短距离为:"; 
		for(int j=0;j<=n;j++)
			cout<<setw(5)<<A[i][j];
		cout<<endl;
	}
}

int shortPathMain()
{
	int i,j;
    int cost[][7]={         //将路径图以矩阵形式表示 
        {0,20,50,30,200,200,200},
        {200,0,25,200,200,70,200},
        {200,200,0,40,25,50,200},
        {200,200,200,0,55,200,200},
        {200,200,200,200,0,10,70},
        {200,200,200,200,200,0,50},
        {200,200,200,200,200,200,0}
        };
    cout<<"带权的有向图如下所示:"<<endl; 
    cout<<"     ";
    for(i=0;i<7;i++) cout<<"v"<<i+1<<"   ";
    cout<<endl;
	for(i=0;i<7;i++)
	{
        cout<<"v"<<i+1<<"   ";
		for(j=0;j<7;j++)
			cout<<left<<setw(5)<<cost[i][j];
		cout<<endl;
	}
    int dist[7];
    cout<<"单源点最短路径算法运行结果:"<<endl; 
    ShortestPath(0,cost,dist,6);//单源点最短路径 
    
    cout<<endl<<"每对结点间的最短路径算法运行结果:"<<endl; 
    AllPath(cost,6);//每对结点间的最短路径 
       
    system("pause");
    return 1; 
}

