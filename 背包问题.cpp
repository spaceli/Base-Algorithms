/*背包问题和0/1背包问题没有任何联系，绝不可混淆。背包问题是贪心法的经典例子，
相对简单；而0/1背包问题是动态规划的经典应用，其解法很多。这里我用了递归法求
最大效益值，结合回溯法求解向量,与书上使用的算法不同*/ 

#include "myhead.h"

void greedyKnapsack()  //贪心法求解背包问题
{
	const int N=20;
	int p[N],w[N];//p，w分别存放物品的效益值和重量
	int m,n;//m为背包能承受的重量，n为备选物品的数量
	double x[N],h[N];//解集合和效益重量比集合 

	cout<<"请输入物品件数:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"请输入物品"<<i+1<<"的效益值和重量:";
		cin>>p[i]>>w[i];
	}
	cout<<"输入背包能承受的最大重量m=";
    cin>>m; 
	for(int i=0;i<n;i++)
	{
		h[i]=(double)p[i]/(double)w[i];//求各物品的效益重量比 
		x[i]=0;//解集合初始化为0 
    }
	while(m>0)
	{
		int max=0;
		for(int i=1;i<n;i++)
		{
			if(h[i]>h[max]) max=i;//在未选物品中找到h最大的一个 
		}
		if(m>=w[max]) //背包所能容纳的重量是否足够把该物品全部放入 
		{
			x[max]=1;//全部放入 
			m-=w[max];
			h[max]=0;//使其不会再次被选 
		}
		else   //不能放入整个物品的情况 
		{ 
			x[max]=(double)m/w[max];
			m=0;
		}
	}
	double total=0.0;
	cout<<"解向量为(";
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<' ';
		total+=x[i]*p[i];
    }
	cout<<").最大效益值为"<<total<<endl; 
}

int f(int m,int *p,int *w,int n)//容量为m，求物品n是否放入背包获得的最大值 
{//递归法,此法不能求出解向量 
	if(m<0) return -100;
	if(m>=0&&n==0) return 0;
	int unpick=f(m,p,w,n-1);//不取物品n的最大效益值 
	int pick=f(m-w[n-1],p,w,n-1)+p[n-1];//取物品n的最大效益值 
	if(unpick>pick) return unpick;
	else return pick;
}
void sumofsub(int s,int k,int r,int MaxP,int m,int *p,int *w,int *x)
{//子集和数问题算法（回溯法）求解向量，详见“子集和数问题” 
     x[k]=1;
     if(s+p[k]==MaxP) 
     {
         int restm=m; //背包还能承受的总量 
         for(int i=0;i<=k;i++)
             if(x[i]==1) restm-=w[i];
         if(restm>=0) //没有超过背包的承受量 ，是所求解，输出 
         {
             cout<<"解向量为 ("; 
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

void Knapsack()   //动态规划求解0/1背包问题
{
	const int N=20;
	int p[N],w[N];//p，w分别存放物品的效益值和重量
	int m,n;//m为背包能承受的重量，n为备选物品的数量
	int x[N];//解集合 

	cout<<"请输入物品件数:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
        x[i]=0;
		cout<<"请输入物品"<<i+1<<"的效益值和重量:";
		cin>>p[i]>>w[i];
	}
	cout<<"输入背包能承受的最大重量m=";
    cin>>m;
    
    int maxBenefit= f(m,p,w,n);//求最大效益值
   	cout<<"最大的效益值为"<<maxBenefit<<endl;
    
    //用子集和数问题算法求解向量 
    int r;   //所有物品效益值总和 
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
            cout<<"1.背包问题(贪心法求解)"<<endl;
            cout<<"2.0/1背包问题(动态规划法)"<<endl;
            cout<<"0.Back"<<endl;
            cout<<"请选择:";
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
