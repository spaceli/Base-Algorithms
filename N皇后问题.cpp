/*N皇后问题，ASCII码的3表示皇后，111表示空位 
这是回溯法的典型问题 */
#include "myhead.h"


int n;   //N皇后问题的"N" ,目前为8皇后问题       
int a[20][20];
int beAttack(int m,int i)  //探测点(a,b)是否被攻击
{
    if(m==0) return 0;   //在第一层肯定没有攻击 
    for(int j=m-1;j>=0;j--)    
    {
         if(a[j][i]==1) return 1;    //探测正上方是否有攻击 
         if(i+(m-j) < n) 
             if(a[j][i+m-j]==1) return 1;  //探测右上方是否有攻击 
         if(i-(m-j) >= 0) 
             if(a[j][i-m+j]==1) return 1;   //探测左上方是否有攻击    
    }
    return 0;   //检测完了，则没攻击 
} 

int nQueenMain()
{

    cout<<"请输入皇后的个数(3<n<20)，n= ";
    cin>>n; 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;    //0为可选，1为已选
    cout<<n<<"皇后问题的解如下所示（心形代表皇后）"<<endl;        
    int m=0,t=0,i=t;
    while(m>=0)
    {
            if(beAttack(m,i)==0)  //不会被攻击 
            {
                a[m][i]=1;        //皇后暂时放这里（标记） 
                //cout<<"1=(m,i)="<<m<<i<<endl;   此句可以观察标记的坐标 
                m++;            //标记后转到下一层 
                i=0;            //下一层要从头开始 
            } 
            else i++;
            while(i==n)
            {                   
                    m--;i=0;     //返回到上一层 
                    for(i;a[m][i]!=1;i++);  //找到皇后的位置 
                    a[m][i]=0;    //拿起皇后（取消标记） 
                    //cout<<"0=(m,i)="<<m<<i<<endl;  此句可以观察取消标记的坐标
                    i++;               //向后一格     
                    if(m==0) t++;       //如果在第一层，记录第一个皇后的位置向后移一个 
            }
            if(m==n)  //已经算出了一个解决方案 
            {       
                    char d1=3,d2=111;//d1为心形（代表皇后）的AScII码，d2为圆形ASCII码 
                    cout<<"  ";
                    for(int b=1;b<=n;b++)
                            cout<<setw(3)<<b;
                    cout<<endl;
                    for(int u=0;u<n;u++)
                    {
                       cout<<setw(2)<<u+1;
                       for(int v=0;v<n;v++)  //显示解决方案 
                       {                         
                          if(a[u][v]==1) 
                          cout<<setw(3)<<d1;
                          else cout<<setw(3)<<d2;
                       }
                       cout<<endl;
                    }
                    cout<<"OK"<<endl;
                    m=0;t++;     //从头开始算下一个解决方案 
                    for(int u=0;u<n;u++)   //初始化棋盘 
                       for(int v=0;v<n;v++)
                          a[u][v]=0;
                    i=t;
                    system("pause");
            }
            if(t==n) m=-1;   //算完了所有方案，退出循环 
    }//end while

    system("pause");
    
    return 1;
}
