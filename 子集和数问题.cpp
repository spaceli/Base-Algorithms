#include "myhead.h"

void sumOfSub(int s,int k,int r,int M,int *w,int *x)
{
	x[k]=1;

	if(s+w[k]==M) //���һ�⣬��� 
	{
        cout<<"�⼯��Ϊ{"; 
		for(int i=0;i<=k;i++)
			if(x[i]==1) cout<<w[i]<<' ';
		cout<<"}"<<endl;
    }
	else if(s+w[k]+w[k+1]<=M) //ȡw[k]����� 
		sumOfSub(s+w[k],k+1,r-w[k],M,w,x);

	if(s+r-w[k]>=M&&s+w[k+1]<=M) //����һ�����������㣬��˴�������һ������ 
	{// ̽�ⲻȡ�����           //s+w[k]+w[k+1]>M 
		x[k]=0;
		sumOfSub(s,k+1,r-w[k],M,w,x);
	}
}

int sumOfSubMain()
{
	const int N=20;
	int w[N];//��������ļ��� 
	int x[N],n=0,M=0;//�������������ĸ��������� 
	int r=0; //δ̽��Ԫ�صĺ� 
    cout<<"����һЩ������";

	for(int i=0;cin.peek()!='\n';i++)
	{
        cin>>w[i];
		x[i]=0;
        n++;
    }

	for(int i=0;i<n;i++)
		r+=w[i];  
	do    //����һ�����ʵĺ��� 
	{
        cout<<"������������ĺ���:";
        cin>>M;
        if(M>r) cout<<"����Ԫ�ؼ�����������Ҫ��ĺ�С��"<<endl; 
    }while(M>r);

	sumOfSub(0,0,r,M,w,x);
    system("pause");
	return 1;
}
