/*��Դ�����·���㷨����̬����ĵ���ʵ��*/ 
#include "myhead.h"

void findPass(int v,int i,int *pass)
{   
    if(i==v) cout<<'v'<<v+1<<' '; //���������Ϊ��㣬��� 
    else 
    {
         findPass(v,pass[i],pass);//���򣬲��ҵ��˵�ľ����� 
         cout<<'v'<<i+1<<' ';   //����˵� 
    } 
}

void ShortestPath(int v,int cost[][7],int dist[],const int n)
{    //v����㣬���v����������·�� 
     int s[n],min,i,j;
     int pass[n];     //��㵽��i�м��;����
     for(i=0;i<=n;i++)
     {
             s[i]=0;    //�⼯�� 
             dist[i]=cost[v][i];   //��¼��㵽��i���ֱ�Ӿ���
             pass[i]=v;   //��ʼ����;���κε� 
     }
     s[v]=1;
     dist[v]=0;
     for(i=1;i<=n;i++)  //����Ѱ��n-1��·��
     {
		  min=-1;
		  for(j=0;j<=n;j++)    //�ҵ���㵽δѡ���о�����̵�һ������min������±� 
		  {
			  if(s[j]==0)
			  {
				  if(min==-1) min=j;
				  else if (dist[j]<dist[min]) min=j;
			  }
		  }
		  s[min]=1;
		  printf("����v%d�ľ���Ϊ%d��·��Ϊ : ",min+1,dist[min]);
		  findPass(v,pass[min],pass);
          cout<<'v'<<min+1<<endl; 
		  for(j=0;j<=n;j++)  //����min���Ƿ��ʹ��㵽����δѡ����·����̣� 
		  {
			  if(s[j]==0&&dist[min]+cost[min][j] <dist[j])
			  {  //�Ƚ�����֮����ԭ·���ĸ����� 
				  dist[j]=dist[min]+cost[min][j];
				  pass[j]=min;  //��¼;����min 
			  }
		  }		  
     }
     cout<<"���v"<<v+1<<"���������̾��룺";
	 for(j=0;j<=n;j++)  //��ʾ��㵽�������̾��� 
	 cout<<dist[j]<<' ';
	 cout<<endl;
}

void AllPath(int cost[][7],const int n)
{
	int A[n+1][n+1];//��¼ÿ�Խ���ľ��� 
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			A[i][j]=cost[i][j];
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				if(A[i][j]>A[i][k]+A[k][j]) //��龭����k�Ƿ����� 
                    A[i][j]=A[i][k]+A[k][j];
			}
	
	for(int i=0;i<=n;i++)
	{
		cout<<"V"<<i+1<<"���������̾���Ϊ:"; 
		for(int j=0;j<=n;j++)
			cout<<setw(5)<<A[i][j];
		cout<<endl;
	}
}

int shortPathMain()
{
	int i,j;
    int cost[][7]={         //��·��ͼ�Ծ�����ʽ��ʾ 
        {0,20,50,30,200,200,200},
        {200,0,25,200,200,70,200},
        {200,200,0,40,25,50,200},
        {200,200,200,0,55,200,200},
        {200,200,200,200,0,10,70},
        {200,200,200,200,200,0,50},
        {200,200,200,200,200,200,0}
        };
    cout<<"��Ȩ������ͼ������ʾ:"<<endl; 
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
    cout<<"��Դ�����·���㷨���н��:"<<endl; 
    ShortestPath(0,cost,dist,6);//��Դ�����·�� 
    
    cout<<endl<<"ÿ�Խ�������·���㷨���н��:"<<endl; 
    AllPath(cost,6);//ÿ�Խ�������·�� 
       
    system("pause");
    return 1; 
}

