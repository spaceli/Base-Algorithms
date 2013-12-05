/*�����㷨�����������C++�����������ں�7�������㷨*/
/*Ϊ�˷����������ıȽϣ�ֻ������һ�����ִ������䴢����List�����У�
��ÿ�������㷨�У�����List�ĸ���Ʒa��������*/ 
#include "myhead.h"


void display(int *a,int begin,int end);//��ʾ���� 
void StraiSort(int *a,int i);//ֱ�Ӳ�������
void BinSort(int *a,int i);   //�۰�������� 
void ShellSort(int *a,int size,int gap); //ϣ������ 
void QuickSort(int *a,int left,int right);  //��������
int  partition(int *a,int low,int high);   //�����㷨
void ShiftDown(int *a,int i,int n);    //������������㷨 
void MergeSort(int *a,int *tmp,int left,int right);  //��������
void Merge(int *a,int *tmp,int l,int m,int r);   //��������ĺϲ�����

class SortList
{
	private:
		int *List;
		int maxsize,cursize;
	public:
		SortList()
		{
			maxsize=30;
			List=new int[maxsize+1];
			cout<<"����һ������:";
			for(cursize=0;cursize<=maxsize&&cin.peek()!='\n';)
				cin>>List[++cursize];			
		}
				
		~SortList()
		{
			delete List;
		}
		void swap(int &x,int &y)
		{
			List[0]=x;
			x=y;
			y=List[0];
		}
		void Sort1();   //���ò�������
        void Sort2();   //����ϣ������
        void Sort3();   //ð������ 
        void Sort4();   //���ÿ�������
        void Sort5();   //ѡ������ 
        void Sort6();   //������
        void Sort7();   //���ò������� 
};

void SortList::Sort1()        //���ò�������
{  //˼�룺�Ѻ�������β���ǰ��һ�źõ����� 
      int a[cursize+1];
      for(int i=1;i<=cursize;i++)
         a[i]=List[i];
      cout<<endl<<"1.��ʼ��������ԭʼ�������£�"<<endl; 
      display(a,1,cursize);
      for(int i=2;i<=cursize;i++)
      {
             BinSort(a,i);//StraiPass(a,i);
        	 for(int j=1;j<=cursize;j++)
        		 cout<<a[j]<<' ';
             printf("----�����%d����\n",i);
      }
      cout<<"������������";
      display(a,1,cursize); 
}
void SortList::Sort2()      //����ϣ������
{  //˼�룺�Լ��gap����ֱ�Ӳ�������ʹ���������� ���Լ�Сֱ�Ӳ�������Ĺ����� 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"2.��ʼϣ������ԭʼ�������£�"<<endl; 
     display(a,1,cursize);
     int gap=15;
     while(gap!=0)
     {
         if(gap<cursize) 
         {   
             printf("����Ϊ%d,��ֱ�Ӳ�������:",gap);
             display(a,1,cursize);
             ShellSort(a,cursize,gap);
         }
         gap=gap/2;
     }
      cout<<"ϣ����������";
      display(a,1,cursize); 
}
void SortList::Sort3()      //ð������ 
{  //˼�룺ÿһ�˰�ʣ����������������ð����� 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"3.��ʼð������ԭʼ�������£�"<<endl; 
     display(a,1,cursize);
     for(int i=0;i<cursize;i++)
     {
           for(int j=1;j<cursize-i;j++)
               if(a[j]>a[j+1]) swap(a[j],a[j+1]);
           printf("��%d�������",i+1); 
           display(a,1,cursize);
     }
      cout<<"ð����������";
      display(a,1,cursize);
}
void SortList::Sort4()  //���ÿ������� 
{  //˼�룺����˼�룬ȡ��һ������������ȱ����ķź��棬С�ķ�ǰ�棻�ٷ�Ϊǰ���������У��編���� 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"4.��ʼ��������ԭʼ�������£�"<<endl; 
     display(a,1,cursize);
     QuickSort(a,1,cursize);  
      cout<<"������������";
      display(a,1,cursize);  
}
void SortList::Sort5()      //ѡ������
{  //˼��:ÿһ��ѡ��ʣ�������е���СԪ�أ��ŵ�ʣ�����е���ǰ�ˣ��Դ˼��ٽ������� 
     int a[cursize+1],k;
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"5.��ʼѡ������ԭʼ�������£�"<<endl; 
     display(a,1,cursize);
     for(int i=1;i<cursize;i++)
     {
         k=i;  //k��¼��СԪ���±� 
         for(int j=i+1;j<=cursize;j++)
             if(a[j]<a[k]) k=j;
         if (k!=i) swap(a[i],a[k]);
         printf("��%d��ѡ���",i);
         display(a,1,cursize);
     } 
      cout<<"ѡ����������";
      display(a,1,cursize);        
}
void SortList::Sort6()   //HeapSort������
{  //˼�룺���������п��ɶѣ��������ѣ�ÿ�ΰѶѶ�Ԫ�ط�����ٵ���ʣ��Ԫ��Ϊ���ѣ����ν��� 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"6.��ʼ������ԭʼ�������£�"<<endl; 
     display(a,1,cursize);
     for(int i=cursize/2;i>=1;i--) //�������Ͻ������� 
         ShiftDown(a,i,cursize); //���ף��±�Ϊi)������ӣ��򽵼� 
     cout<<"�������ѵ�����:"<<endl; 
     display(a,1,cursize);
     
     for(int i=cursize;i>=2;i--)
     {
          swap(a[1],a[i]);       //�����Ԫ���Ƶ�ĩβ 
          ShiftDown(a,1,i-1);     //��ǰ���Ԫ���ٵ���Ϊ���� 
          display(a,1,cursize);
     }
      cout<<"����������";
      display(a,1,cursize);
} 
void SortList::Sort7()  //���ò�������
{  //˼�룺����˼�룬��һ������ΪһС�飬ÿ��С���ںϲ����������򣬺����ٺϣ����ϳ������������� 
     int a[cursize+1],tmp[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"7.��ʼ��������ԭʼ�������£�"<<endl; 
     display(a,1,cursize);
     MergeSort(a,tmp,1,cursize);
     
     cout<<"������������";
     display(a,1,cursize);       
} 

//------------------------------------------------------------------------------//
void display(int *a,int begin,int end)  //��ʾ����
{
     for(int i=begin;i<=end;i++)
             cout<<left<<setw(6)<<a[i];
     cout<<endl;
} 
void StraiSort(int *a,int i)   //ֱ�Ӳ�������
{
  	a[0]=a[i];
  	int j=i-1;
  	while(a[0]<a[j])
  	{
  		a[j+1]=a[j];
  		j--;
  	}
  	a[j+1]=a[0];
}
void BinSort(int *a,int i)   //�۰�������� 
{
     int low=1,high=i-1,middle;
     a[0]=a[i];
     while(low<=high)
     {
         middle=(low+high)/2;
         if(a[0]<a[middle])  high=middle-1;
         else low=middle+1;
     } 
   
     for(int j=i-1;j>high;j--)
         a[j+1]=a[j];
     a[high+1]=a[0];      
}
void ShellSort(int *a,int size,int gap)  //ϣ������ 
{
     for(int i=gap;i<=size;i++)
     {
             a[0]=a[i];
             printf("a[0]����a[%d]����:\n",i,a[0]); 
             int j=i;
             while(j>=gap&&a[0]<a[j-gap])
             {
                  printf("  ��a[%d]<a[%d],��a[%d]�Ƶ�a[%d]:\n",j-gap,j,j-gap,j);                  
                  a[j]=a[j-gap];
                  cout<<"                      ";
                  display(a,1,size);
                  j-=gap;
             }
             a[j]=a[0];
             printf("a[%d]ȡ��a[0]����,Finish!\n",j,a[0]);
     }     
}

void QuickSort(int *a,int left,int right)  //�������� 
{    
      
     if (left<right)
     {             
             int part=partition(a,left,right);
             QuickSort(a,left,part-1);
             QuickSort(a,part+1,right);
     }   
}

int partition(int *a,int low,int high)   //�����㷨
{
     int x=a[low];
     int l=low,h=high;

     while(l<h)
     {
          while(a[l]<=x&&l<high) l++;
          while(a[h]>=x&&h>low) h--;
          if(l<h) swap(a[l],a[h]);          
          else break;
     }
     a[low]=a[h];
     a[h]=x;
     
     for(int i=1;i<low;i++) cout<<"      "; 
     display(a,low,high);
     return h;
} 
void ShiftDown(int *a,int i,int n)    //������������㷨 
{
     int child;
     for(a[0]=a[i];i<=n/2;i=child)
     {
         child=i*2;
         if((child!=n)&&(a[child+1]>a[child]))  child++;//��ѡ��������������һ�� 
         if(a[0]<a[child]) a[i]=a[child]; //����ȸ��״󣬶����� 
         else break;         
     }
     a[i]=a[0];  //����Ѱ���Լ���λ�� 
}
void MergeSort(int *a,int *tmp,int left,int right)  //��������
{
     int center;
     if(left==right) tmp[left]=a[left];
     else
     {
         center=(left+right)/2;
         MergeSort(a,tmp,left,center);
         MergeSort(a,tmp,center+1,right);
         Merge(a,tmp,left,center,right);
     }
} 
void Merge(int *a,int *tmp,int l,int m,int r)   //�ϲ�����
{
     int i=l,j=m+1,k=l-1;
     while(i<=m&&j<=r)
     {
         if(a[i]<=a[j])  tmp[++k]=a[i++];
         else  tmp[++k]=a[j++];
     }
     if(i<=m)  
               for(int t=i;t<=m;t++)
                       tmp[++k]=a[t];
     if(j<=r)  
               for(int t=j;t<=r;t++)
                       tmp[++k]=a[t];
     for(i=l;i<=r;i++)
          a[i]=tmp[i];   
     for(int i=1;i<l;i++) cout<<"      ";
     display(a,l,r);
                         
} 

//-----------------------------------------------------------------------------//
int sortMain()
{
    SortList list;
    while(1)
    {
        cout<<endl;
        int ch=0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//����������ɫΪ����ɫ
        cout<<"1.��������"<<endl; 
        cout<<"2.ϣ������"<<endl;
        cout<<"3.ð������"<<endl;
        cout<<"4.��������"<<endl;
        cout<<"5.ѡ������"<<endl; 
        cout<<"6.������"<<endl;
        cout<<"7.��������"<<endl;
        cout<<"0.Back"<<endl<<endl;
        cout<<"��ѡ��:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����������ɫΪ��ɫ
        cin>>ch;fflush(stdin);
        switch(ch)
        {
            case 0:return 1;
            case 1:list.Sort1();break;
            case 2:list.Sort2();break;
            case 3:list.Sort3();break;
            case 4:list.Sort4();break;
            case 5:list.Sort5();break;
            case 6:list.Sort6();break;
            case 7:list.Sort7();break;
            default:return 1;
        } 
        system("pause");   
    }
	return 1;
}
