#include "myhead.h"

void sumOfSub(int s,int k,int r,int M,int *w,int *x)
{
	x[k]=1;

	if(s+w[k]==M) //求得一解，输出 
	{
        cout<<"解集合为{"; 
		for(int i=0;i<=k;i++)
			if(x[i]==1) cout<<w[i]<<' ';
		cout<<"}"<<endl;
    }
	else if(s+w[k]+w[k+1]<=M) //取w[k]的情况 
		sumOfSub(s+w[k],k+1,r-w[k],M,w,x);

	if(s+r-w[k]>=M&&s+w[k+1]<=M) //若上一个条件不满足，则此处隐含了一个条件 
	{// 探测不取的情况           //s+w[k]+w[k+1]>M 
		x[k]=0;
		sumOfSub(s,k+1,r-w[k],M,w,x);
	}
}

int sumOfSubMain()
{
	const int N=20;
	int w[N];//存放正数的集合 
	int x[N],n=0,M=0;//解向量，正数的个数，和数 
	int r=0; //未探测元素的和 
    cout<<"输入一些正数：";

	for(int i=0;cin.peek()!='\n';i++)
	{
        cin>>w[i];
		x[i]=0;
        n++;
    }

	for(int i=0;i<n;i++)
		r+=w[i];  
	do    //输入一个合适的和数 
	{
        cout<<"请输入您想求的和数:";
        cin>>M;
        if(M>r) cout<<"所有元素加起来都比你要求的和小！"<<endl; 
    }while(M>r);

	sumOfSub(0,0,r,M,w,x);
    system("pause");
	return 1;
}
