#include "myhead.h"

void greedyJob(int *p,int *d,int *x,int n)
{
	int maxd=0;//�������ֵ
	for(int i=0;i<n;i++)  //�ҵ��������
	{
		if(d[i]>maxd) maxd=d[i];
	}
	int num=maxd;   //��ѡ����ҵ����
	for(int i=0;i<n&&num>0;i++)
	{
		int maxp=0;
		for(int j=1;j<n;j++)
			if((p[j]>=p[maxp]||maxp==0)&&d[j]!=0)
				maxp=j;  //�ҵ���ǰʣ������Ч��ֵ����ҵ

		int endtime=d[maxp];//���ʱ�価���ܿ�����������
		d[maxp]=0;  //����ҵ������Ϊ0����ֹ�´α�ѡ
		while(x[endtime]!=0) //��ʼʱ���������ѡ��ҵ��ͻ
			endtime--;  //������ǰ��

		if(endtime>0)
		{
			x[endtime]=maxp+1; //��endtime����ɵ���ҵ��maxp;
			num--;  //��ѡ��ҵ������һ
		}			
	}
	int psum=0;//���Ž��õ���Ч��ֵ 
	for(int i=1;i<=maxd;i++)
    if(x[i]!=0)
    { 
         cout<<"ʱ��"<<i<<"�����ҵ"<<x[i]<<endl;
         psum+=p[x[i]-1];
    }
    cout<<"���Ž��õ���Ч��ֵ "<<psum<<endl; 
}

int greedyJobMain()
{
	int n;//��ѡ��ҵ����
	int p[20],d[20];//����ҵ��Ч��ֵ������
	int x[20];//��Ӧ����ҵ��ʼ����ţ�0��ʾ��ѡ����ҵ
	cout<<"�����뱸ѡ��ҵ������";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"�����"<<i+1<<"����ҵ��Ч��ֵ�����ڣ�";
		cin>>p[i]>>d[i];
		x[i]=0;
	}

	greedyJob(p,d,x,n);
	

    system("pause");
	return 1;
}
