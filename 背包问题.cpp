/*���������0/1��������û���κ���ϵ�������ɻ���������������̰�ķ��ľ������ӣ�
��Լ򵥣���0/1���������Ƕ�̬�滮�ľ���Ӧ�ã���ⷨ�ܶࡣ���������˵ݹ鷨��
���Ч��ֵ����ϻ��ݷ��������,������ʹ�õ��㷨��ͬ*/ 

#include "myhead.h"

void greedyKnapsack()  //̰�ķ���ⱳ������
{
	const int N=20;
	int p[N],w[N];//p��w�ֱ�����Ʒ��Ч��ֵ������
	int m,n;//mΪ�����ܳ��ܵ�������nΪ��ѡ��Ʒ������
	double x[N],h[N];//�⼯�Ϻ�Ч�������ȼ��� 

	cout<<"��������Ʒ����:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"��������Ʒ"<<i+1<<"��Ч��ֵ������:";
		cin>>p[i]>>w[i];
	}
	cout<<"���뱳���ܳ��ܵ��������m=";
    cin>>m; 
	for(int i=0;i<n;i++)
	{
		h[i]=(double)p[i]/(double)w[i];//�����Ʒ��Ч�������� 
		x[i]=0;//�⼯�ϳ�ʼ��Ϊ0 
    }
	while(m>0)
	{
		int max=0;
		for(int i=1;i<n;i++)
		{
			if(h[i]>h[max]) max=i;//��δѡ��Ʒ���ҵ�h����һ�� 
		}
		if(m>=w[max]) //�����������ɵ������Ƿ��㹻�Ѹ���Ʒȫ������ 
		{
			x[max]=1;//ȫ������ 
			m-=w[max];
			h[max]=0;//ʹ�䲻���ٴα�ѡ 
		}
		else   //���ܷ���������Ʒ����� 
		{ 
			x[max]=(double)m/w[max];
			m=0;
		}
	}
	double total=0.0;
	cout<<"������Ϊ(";
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<' ';
		total+=x[i]*p[i];
    }
	cout<<").���Ч��ֵΪ"<<total<<endl; 
}

int f(int m,int *p,int *w,int n)//����Ϊm������Ʒn�Ƿ���뱳����õ����ֵ 
{//�ݹ鷨,�˷�������������� 
	if(m<0) return -100;
	if(m>=0&&n==0) return 0;
	int unpick=f(m,p,w,n-1);//��ȡ��Ʒn�����Ч��ֵ 
	int pick=f(m-w[n-1],p,w,n-1)+p[n-1];//ȡ��Ʒn�����Ч��ֵ 
	if(unpick>pick) return unpick;
	else return pick;
}
void sumofsub(int s,int k,int r,int MaxP,int m,int *p,int *w,int *x)
{//�Ӽ����������㷨�����ݷ������������������Ӽ��������⡱ 
     x[k]=1;
     if(s+p[k]==MaxP) 
     {
         int restm=m; //�������ܳ��ܵ����� 
         for(int i=0;i<=k;i++)
             if(x[i]==1) restm-=w[i];
         if(restm>=0) //û�г��������ĳ����� ��������⣬��� 
         {
             cout<<"������Ϊ ("; 
             for(int i=0;i<=k;i++)
                cout<<x[i]<<' ';
             cout<<")"<<endl;
         }
     }
     else if(s+p[k]+p[k+1]<=MaxP)
         sumofsub(s+p[k],k+1,r-p[k],MaxP,m,p,w,x);
         
     if(s+r-p[k]>=MaxP&&s+p[k+1]<=MaxP)
     {
         x[k]=0;
         sumofsub(s,k+1,r-p[k],MaxP,m,p,w,x);
     }
              
}

void Knapsack()   //��̬�滮���0/1��������
{
	const int N=20;
	int p[N],w[N];//p��w�ֱ�����Ʒ��Ч��ֵ������
	int m,n;//mΪ�����ܳ��ܵ�������nΪ��ѡ��Ʒ������
	int x[N];//�⼯�� 

	cout<<"��������Ʒ����:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
        x[i]=0;
		cout<<"��������Ʒ"<<i+1<<"��Ч��ֵ������:";
		cin>>p[i]>>w[i];
	}
	cout<<"���뱳���ܳ��ܵ��������m=";
    cin>>m;
    
    int maxBenefit= f(m,p,w,n);//�����Ч��ֵ
   	cout<<"����Ч��ֵΪ"<<maxBenefit<<endl;
    
    //���Ӽ����������㷨������� 
    int r;   //������ƷЧ��ֵ�ܺ� 
    for(int i=0;i<n;i++)
           r+=p[i];
    sumofsub(0,0,r,maxBenefit,m,p,w,x);		

}

int KNAPMain()
{
    int c;
    while(1)
    {
            cout<<endl<<endl;
            cout<<"1.��������(̰�ķ����)"<<endl;
            cout<<"2.0/1��������(��̬�滮��)"<<endl;
            cout<<"0.Back"<<endl;
            cout<<"��ѡ��:";
            cin>>c;
            switch(c)
            {
                case 1:greedyKnapsack();break;
                case 2:Knapsack();break;
                default:return 1;
            }
            system("pause");
    }           
   
	return 1;
}
