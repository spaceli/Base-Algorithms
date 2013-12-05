/*��ʵ������ͨͼ������ʾ
        v1  v7         
       / \ / |
     v2   v3 |
       \ / \ |
       v4   v8
       / \
     v5  v6
���ļ�������ȱ����͹�ȱ������㷨*/ 

#include "myhead.h"

const int n=8;  
static int path[n][n]={   //ͼת��Ϊ���� 
		{0,1,1,0,0,0,0,0},
		{1,0,0,1,0,0,0,0},
		{1,0,0,1,0,0,1,1},
		{0,1,1,0,1,1,0,0},
		{0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0},
		{0,0,1,0,0,0,0,1},
		{0,0,1,0,0,0,1,0}
    };

void depthFirstTraversal(int i,int *visit)//������ȱ���,iΪ��ǰ��ѯ�Ľڵ�
{
	for(int j=1;j<n;j++)
	{
		if(path[i][j]==1&&visit[j]==0)
		{
			visit[j]=1;
			cout<<"---���ʽڵ�v"<<j+1<<endl;
			depthFirstTraversal(j,visit);
		}
	}
}

void breadthFirstTraversal()//������ȱ��� 
{
  
	int visit[n],t=0;//��visit���������У���¼���ʽڵ��˳��,tΪ��ͷ���±�
	for(int i=0;i<n;i++)
		visit[i]=-1;
	visit[0]=0;  //���Ϊv1; 
	cout<<"������ȱ����㷨���ӽڵ�v"<<visit[0]+1<<"��ʼ"<<endl;
	while(visit[n-1]==-1)//���һ���ڵ�����У��㷨���� 
	{
		int i=visit[t];//��ѯ��ͷ�ڵ��·�� 
		for(int j=0;j<n;j++)
		{			
			if(path[i][j]==1)  // i ��� j ����ͨ
			{
                int s=0;
				for(s;visit[s]!=-1;s++) // ��ѯ j ���Ƿ񱻷��ʹ�
					if(visit[s]==j) break; //�����ʹ�������

				if(visit[s]==-1) //û�����ʹ�
				{
					visit[s]=j;  //���뵽�����ʵĶ�����
					cout<<"---���ʽڵ�v"<<j+1<<endl;
				}
			}//end if
		}//end for
		t++;   //��ǰ�ڵ��·����ѯ��ϣ�����һ���ڵ�
	}//end while
	cout<<"������ȱ�������"<<endl; 
}

int diagramTraversalMain()
{
    cout<<"��ͨͼ������ʾ"<<endl; 
    cout<<"        v1  v7  "<<endl;        
    cout<<"       / \\ / |  "<<endl;
    cout<<"     v2   v3 |  "<<endl;
    cout<<"       \\ / \\ |  "<<endl;
    cout<<"       v4   v8  "<<endl;
    cout<<"       / \\      "<<endl;
    cout<<"     v5  v6     "<<endl;
    int depthVisit[n];//������ȱ����м�¼�ڵ��Ƿ񱻷��ʹ�������
	for(int i=1;i<n;i++)  depthVisit[i]=0; //��ʼ��Ϊδ����
	depthVisit[0]=1;//��ǵ�һ���ڵ�Ϊ�ѷ���
    cout<<"������ȱ����㷨���ӽڵ�v1��ʼ"<<endl; 
    depthFirstTraversal(0,depthVisit);//�ӵ�һ���ڵ㿪ʼ���� 
    cout<<"������ȱ�������"<<endl<<endl; 
    
    breadthFirstTraversal(); 
    system("pause");
	return 1;
}
