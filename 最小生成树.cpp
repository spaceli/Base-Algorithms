/*��ʵ��������ͼ������ʾ           ������ɵ���С���������� 
       v1---2---v2                       v1----2------v2
      /  \     /  \                       \
     4    1   3   10                       1
    /      \ /     \                        \
   v3--2---v4--7---v5              v3---2---v4     v5
    \     /  \     /                          \    /
     5   8   4    6                           4   6
      \ /     \  /                             \ /
      v6---1---v7                     v6---1---v7
����ͼ����С���������ɾ����ʾ*/      

#include "myhead.h"

const int n=7;
int Tree[n][n]={       //����ͼת��Ϊ���� 
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
    cout<<"����ͼ������ʾ"<<endl;
	cout<<"       v1----2----v2 "<<endl;
    cout<<"      / \\        / \\ "<<endl; 
    cout<<"    4     1    3    10"<<endl;
    cout<<"   /       \\  /       \\  "<<endl;
    cout<<" v3----2----v4----7----v5"<<endl;
    cout<<"   \\       /  \\       / "<<endl;
    cout<<"     5   8      4    6 "<<endl;
    cout<<"      \\ /        \\ /  "<<endl;
    cout<<"       v6----1----v7  "<<endl;

	
   	int state[n],okpath=0;//state��Žڵ�i�Ƿ����ӹ�,okpath��¼�����ӵ�·����Ŀ 
    state[0]=1;
	for(int i=1;i<n;i++) state[i]=0;//1Ϊ�����ӣ�0Ϊδ����
	cout<<"Prim�㷨�����ɲ�������"<<endl;
	while(okpath<n-1)  //��Ҫ���n-1��·�� 
	{
		int min=100,mini=0,minj=0;//��¼��СȨ��������
		for(int i=0;i<n;i++)   //ȫ��ɨ��һ��
		{
			if(state[i]==1)    //����ѡ���������·��
			{
    			for(int j=0;j<n;j++)
    			{
    				if(state[j]==0&&Tree[i][j]<min&&i!=j)  //��ѡ��һ��Ϊδѡ
    				{
                        min=Tree[i][j];
                        mini=i;
                        minj=j;
                    }
    			}
            }
		}
		state[minj]=1;
		cout<<"���ӽڵ�v"<<mini+1<<"�ͽڵ�v"<<minj+1<<"��·����Ϊ"<<min<<endl;
        okpath++; 
	}
}

void Kruskal()
{

   	int treenum=0; //��¼�����ĸ���(���1��Ϊ��С��������
	int state[n];//��Ӧ���ڵ��״̬,0Ϊδ���ӣ�i(i>0)��ʾ�����ڵ�i��������

	for(int i=0;i<n;i++) 
	{
		state[i]=0;//��ʼ��Ϊ��δ����
	}
	cout<<"Kruskal�㷨�����ɲ�������"<<endl;
	for(int t=1;t<n;t++)  //���һ���ڵ�Ҳ������С������������ֹ 
	{
		int min=100,mini=0,minj=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				if(Tree[i][j]<min) 
				{
					if((state[i]==0&&state[j]==0)||state[i]!=state[j])
					{//���㲻��ͬʱ��һ������,�����ǵ��ڵ����
						min=Tree[i][j];
						mini=i;
						minj=j;
					}
				}
			}
		
		cout<<"���ӽڵ�v"<<mini+1<<"�ͽڵ�v"<<minj+1<<"��·����Ϊ"<<min<<endl;
		if(t==1)
		{
			 treenum=1;
			 state[mini]=1;  state[minj]=1;//��������С��������
		}
		else
		{
			if(state[mini]==0&&state[minj]==0) //�����ڵ�����һ������
			{
				state[mini]=++treenum;
				state[minj]=treenum;
			}
			if(state[mini]*state[minj]==0)  //���ڵ�������һ�����ϵ����
			{
				if(!state[mini]) state[mini]=state[minj];
				else state[minj]=state[mini];
			}
			else   //�����ڲ�ͬ���ϵ����
			{
				int smalltree,bigtree;// ��¼�����������
				if(state[mini]>state[minj]) { smalltree=state[minj];bigtree=state[mini];}
				else  { smalltree=state[mini];bigtree=state[minj];}
				for(int i=0;i<n;i++)  //����Ŵ�����ϵĵ�ȫ�ӵ����С������
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
	cout<<"Prim�㷨����"<<endl<<endl;
	Kruskal();
    cout<<"Kruskal�㷨����"<<endl<<endl;
    system("pause");
    return 1;
}
