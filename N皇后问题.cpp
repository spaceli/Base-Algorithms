/*N�ʺ����⣬ASCII���3��ʾ�ʺ�111��ʾ��λ 
���ǻ��ݷ��ĵ������� */
#include "myhead.h"


int n;   //N�ʺ������"N" ,ĿǰΪ8�ʺ�����       
int a[20][20];
int beAttack(int m,int i)  //̽���(a,b)�Ƿ񱻹���
{
    if(m==0) return 0;   //�ڵ�һ��϶�û�й��� 
    for(int j=m-1;j>=0;j--)    
    {
         if(a[j][i]==1) return 1;    //̽�����Ϸ��Ƿ��й��� 
         if(i+(m-j) < n) 
             if(a[j][i+m-j]==1) return 1;  //̽�����Ϸ��Ƿ��й��� 
         if(i-(m-j) >= 0) 
             if(a[j][i-m+j]==1) return 1;   //̽�����Ϸ��Ƿ��й���    
    }
    return 0;   //������ˣ���û���� 
} 

int nQueenMain()
{

    cout<<"������ʺ�ĸ���(3<n<20)��n= ";
    cin>>n; 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;    //0Ϊ��ѡ��1Ϊ��ѡ
    cout<<n<<"�ʺ�����Ľ�������ʾ�����δ���ʺ�"<<endl;        
    int m=0,t=0,i=t;
    while(m>=0)
    {
            if(beAttack(m,i)==0)  //���ᱻ���� 
            {
                a[m][i]=1;        //�ʺ���ʱ�������ǣ� 
                //cout<<"1=(m,i)="<<m<<i<<endl;   �˾���Թ۲��ǵ����� 
                m++;            //��Ǻ�ת����һ�� 
                i=0;            //��һ��Ҫ��ͷ��ʼ 
            } 
            else i++;
            while(i==n)
            {                   
                    m--;i=0;     //���ص���һ�� 
                    for(i;a[m][i]!=1;i++);  //�ҵ��ʺ��λ�� 
                    a[m][i]=0;    //����ʺ�ȡ����ǣ� 
                    //cout<<"0=(m,i)="<<m<<i<<endl;  �˾���Թ۲�ȡ����ǵ�����
                    i++;               //���һ��     
                    if(m==0) t++;       //����ڵ�һ�㣬��¼��һ���ʺ��λ�������һ�� 
            }
            if(m==n)  //�Ѿ������һ��������� 
            {       
                    char d1=3,d2=111;//d1Ϊ���Σ�����ʺ󣩵�AScII�룬d2ΪԲ��ASCII�� 
                    cout<<"  ";
                    for(int b=1;b<=n;b++)
                            cout<<setw(3)<<b;
                    cout<<endl;
                    for(int u=0;u<n;u++)
                    {
                       cout<<setw(2)<<u+1;
                       for(int v=0;v<n;v++)  //��ʾ������� 
                       {                         
                          if(a[u][v]==1) 
                          cout<<setw(3)<<d1;
                          else cout<<setw(3)<<d2;
                       }
                       cout<<endl;
                    }
                    cout<<"OK"<<endl;
                    m=0;t++;     //��ͷ��ʼ����һ��������� 
                    for(int u=0;u<n;u++)   //��ʼ������ 
                       for(int v=0;v<n;v++)
                          a[u][v]=0;
                    i=t;
                    system("pause");
            }
            if(t==n) m=-1;   //���������з������˳�ѭ�� 
    }//end while

    system("pause");
    
    return 1;
}
