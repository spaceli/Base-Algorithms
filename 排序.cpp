/*排序算法采用最基本的C++语言描述，内涵7种排序算法*/
/*为了方便各种排序的比较，只需输入一次数字串，将其储存在List数组中，
在每个排序算法中，均用List的复制品a进行排序*/ 
#include "myhead.h"


void display(int *a,int begin,int end);//显示序列 
void StraiSort(int *a,int i);//直接插入排序
void BinSort(int *a,int i);   //折半插入排序 
void ShellSort(int *a,int size,int gap); //希尔排序 
void QuickSort(int *a,int left,int right);  //快速排序
int  partition(int *a,int low,int high);   //划分算法
void ShiftDown(int *a,int i,int n);    //堆排序的下移算法 
void MergeSort(int *a,int *tmp,int left,int right);  //并归排序
void Merge(int *a,int *tmp,int l,int m,int r);   //并归排序的合并操作

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
			cout<<"输入一列数字:";
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
		void Sort1();   //调用插入排序
        void Sort2();   //调用希尔排序
        void Sort3();   //冒泡排序 
        void Sort4();   //调用快速排序
        void Sort5();   //选择排序 
        void Sort6();   //堆排序
        void Sort7();   //调用并归排序 
};

void SortList::Sort1()        //调用插入排序
{  //思想：把后面的依次插入前面一排好的序列 
      int a[cursize+1];
      for(int i=1;i<=cursize;i++)
         a[i]=List[i];
      cout<<endl<<"1.开始插入排序，原始数据如下："<<endl; 
      display(a,1,cursize);
      for(int i=2;i<=cursize;i++)
      {
             BinSort(a,i);//StraiPass(a,i);
        	 for(int j=1;j<=cursize;j++)
        		 cout<<a[j]<<' ';
             printf("----插入第%d个数\n",i);
      }
      cout<<"插入排序结果：";
      display(a,1,cursize); 
}
void SortList::Sort2()      //调用希尔排序
{  //思想：以间隔gap进行直接插入排序，使数列逐渐有序 ，以减小直接插入排序的工作量 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"2.开始希尔排序，原始数据如下："<<endl; 
     display(a,1,cursize);
     int gap=15;
     while(gap!=0)
     {
         if(gap<cursize) 
         {   
             printf("增量为%d,做直接插入排序:",gap);
             display(a,1,cursize);
             ShellSort(a,cursize,gap);
         }
         gap=gap/2;
     }
      cout<<"希尔排序结果：";
      display(a,1,cursize); 
}
void SortList::Sort3()      //冒泡排序 
{  //思想：每一趟把剩余序列中最大的泡泡冒到最后 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"3.开始冒泡排序，原始数据如下："<<endl; 
     display(a,1,cursize);
     for(int i=0;i<cursize;i++)
     {
           for(int j=1;j<cursize-i;j++)
               if(a[j]>a[j+1]) swap(a[j],a[j+1]);
           printf("第%d趟排序后：",i+1); 
           display(a,1,cursize);
     }
      cout<<"冒泡排序结果：";
      display(a,1,cursize);
}
void SortList::Sort4()  //调用快速排序 
{  //思想：分治思想，取第一个数当标兵，比标兵大的放后面，小的放前面；再分为前后两个序列，如法炮制 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"4.开始快速排序，原始数据如下："<<endl; 
     display(a,1,cursize);
     QuickSort(a,1,cursize);  
      cout<<"快速排序结果：";
      display(a,1,cursize);  
}
void SortList::Sort5()      //选择排序
{  //思想:每一趟选出剩余数列中的最小元素，放到剩余数列的最前端，以此减少交换次数 
     int a[cursize+1],k;
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"5.开始选择排序，原始数据如下："<<endl; 
     display(a,1,cursize);
     for(int i=1;i<cursize;i++)
     {
         k=i;  //k记录最小元素下标 
         for(int j=i+1;j<=cursize;j++)
             if(a[j]<a[k]) k=j;
         if (k!=i) swap(a[i],a[k]);
         printf("第%d趟选择后：",i);
         display(a,1,cursize);
     } 
      cout<<"选择排序结果：";
      display(a,1,cursize);        
}
void SortList::Sort6()   //HeapSort堆排序
{  //思想：将现行数列看成堆，建立最大堆，每次把堆顶元素放最后，再调整剩余元素为最大堆，依次进行 
     int a[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"6.开始堆排序，原始数据如下："<<endl; 
     display(a,1,cursize);
     for(int i=cursize/2;i>=1;i--) //从下往上建立最大堆 
         ShiftDown(a,i,cursize); //父亲（下标为i)不如儿子，则降级 
     cout<<"建好最大堆的序列:"<<endl; 
     display(a,1,cursize);
     
     for(int i=cursize;i>=2;i--)
     {
          swap(a[1],a[i]);       //将最大元素移到末尾 
          ShiftDown(a,1,i-1);     //把前面的元素再调整为最大堆 
          display(a,1,cursize);
     }
      cout<<"堆排序结果：";
      display(a,1,cursize);
} 
void SortList::Sort7()  //调用并归排序
{  //思想：分治思想，把一个数作为一小块，每两小块在合并过程中排序，合完再合，最后合成整个有序数列 
     int a[cursize+1],tmp[cursize+1];
     for(int i=1;i<=cursize;i++)
         a[i]=List[i];
     cout<<endl<<"7.开始并归排序，原始数据如下："<<endl; 
     display(a,1,cursize);
     MergeSort(a,tmp,1,cursize);
     
     cout<<"并归排序结果：";
     display(a,1,cursize);       
} 

//------------------------------------------------------------------------------//
void display(int *a,int begin,int end)  //显示序列
{
     for(int i=begin;i<=end;i++)
             cout<<left<<setw(6)<<a[i];
     cout<<endl;
} 
void StraiSort(int *a,int i)   //直接插入排序
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
void BinSort(int *a,int i)   //折半插入排序 
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
void ShellSort(int *a,int size,int gap)  //希尔排序 
{
     for(int i=gap;i<=size;i++)
     {
             a[0]=a[i];
             printf("a[0]保存a[%d]数据:\n",i,a[0]); 
             int j=i;
             while(j>=gap&&a[0]<a[j-gap])
             {
                  printf("  因a[%d]<a[%d],把a[%d]移到a[%d]:\n",j-gap,j,j-gap,j);                  
                  a[j]=a[j-gap];
                  cout<<"                      ";
                  display(a,1,size);
                  j-=gap;
             }
             a[j]=a[0];
             printf("a[%d]取出a[0]数据,Finish!\n",j,a[0]);
     }     
}

void QuickSort(int *a,int left,int right)  //快速排序 
{    
      
     if (left<right)
     {             
             int part=partition(a,left,right);
             QuickSort(a,left,part-1);
             QuickSort(a,part+1,right);
     }   
}

int partition(int *a,int low,int high)   //划分算法
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
void ShiftDown(int *a,int i,int n)    //堆排序的下移算法 
{
     int child;
     for(a[0]=a[i];i<=n/2;i=child)
     {
         child=i*2;
         if((child!=n)&&(a[child+1]>a[child]))  child++;//挑选两个儿子中最大的一个 
         if(a[0]<a[child]) a[i]=a[child]; //子孙比父亲大，都升级 
         else break;         
     }
     a[i]=a[0];  //父亲寻找自己的位置 
}
void MergeSort(int *a,int *tmp,int left,int right)  //并归排序
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
void Merge(int *a,int *tmp,int l,int m,int r)   //合并操作
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//设置字体颜色为蓝绿色
        cout<<"1.插入排序"<<endl; 
        cout<<"2.希尔排序"<<endl;
        cout<<"3.冒泡排序"<<endl;
        cout<<"4.快速排序"<<endl;
        cout<<"5.选择排序"<<endl; 
        cout<<"6.堆排序"<<endl;
        cout<<"7.并归排序"<<endl;
        cout<<"0.Back"<<endl<<endl;
        cout<<"请选择:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//设置字体颜色为白色
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
