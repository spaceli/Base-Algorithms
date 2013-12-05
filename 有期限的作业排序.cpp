#include "myhead.h"

void greedyJob(int *p,int *d,int *x,int n)
{
	int maxd=0;//最大期限值
	for(int i=0;i<n;i++)  //找到最大期限
	{
		if(d[i]>maxd) maxd=d[i];
	}
	int num=maxd;   //可选的作业数量
	for(int i=0;i<n&&num>0;i++)
	{
		int maxp=0;
		for(int j=1;j<n;j++)
			if((p[j]>=p[maxp]||maxp==0)&&d[j]!=0)
				maxp=j;  //找到当前剩余的最大效益值的作业

		int endtime=d[maxp];//完成时间尽可能靠近它的期限
		d[maxp]=0;  //该作业期限置为0，防止下次被选
		while(x[endtime]!=0) //开始时间和其他已选作业冲突
			endtime--;  //让它提前做

		if(endtime>0)
		{
			x[endtime]=maxp+1; //第endtime个完成的作业是maxp;
			num--;  //可选作业数量减一
		}			
	}
	int psum=0;//最优解获得的总效益值 
	for(int i=1;i<=maxd;i++)
    if(x[i]!=0)
    { 
         cout<<"时间"<<i<<"完成作业"<<x[i]<<endl;
         psum+=p[x[i]-1];
    }
    cout<<"最优解获得的总效益值 "<<psum<<endl; 
}

int greedyJobMain()
{
	int n;//备选作业数量
	int p[20],d[20];//各作业的效益值及限期
	int x[20];//对应各作业开始的序号，0表示不选该作业
	cout<<"请输入备选作业数量：";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"输入第"<<i+1<<"项作业的效益值和限期：";
		cin>>p[i]>>d[i];
		x[i]=0;
	}

	greedyJob(p,d,x,n);
	

    system("pause");
	return 1;
}
