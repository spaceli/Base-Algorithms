/*查找算法,采用c++模板描述*/
/*包含顺序查找和二分查找算法*/ 
#include "myhead.h"


template<class keyType>
class elemType
{
      public:     
     keyType key;
};
template<class keyType>
class searchList
{
      public:
             searchList()
             {
                  maxSize=30;
                  a=new elemType<keyType>[maxSize+1];

                  for(curSize=0;(cin.peek()!='\n')&&(curSize<maxSize);)
                          cin>>a[++curSize].key;                                        
              }
             ~searchList()
             {
                  delete a;
             };
             int ordinalSearch(keyType target);  //顺序查找 
             int binSearch(keyType target);      //二分查找 
      private:
              elemType<keyType> *a;
              int maxSize,curSize;
};

template<class keyType>
int searchList<keyType>::ordinalSearch(keyType target)
{                                      
    a[0].key=target;
    int i=curSize;
    while(a[i].key!=target)  i--;//从最后一个元素向前一个一个找 
    return i;
}
template<class keyType>
int searchList<keyType>::binSearch(keyType target)
{
    int low=1,high=curSize,mid;
    for(int i=1;i<=curSize;i++) cout<<" "<<a[i].key<<'\t';
    cout<<endl;
    while(low<high)
    {
        mid=(low+high)/2;
        for(int i=1;i<=high;i++) //显示三个标志的变化情况 
        {
                if(i==low) cout<<"low";
                if(i==mid) cout<<"mid";
                if(i==high) cout<<"high";
                else cout<<'\t';
        }
        cout<<endl;
        if(a[mid].key<target) low=mid+1;
        else high=mid;       
    }
    mid=(low+high)/2;
    for(int i=1;i<=high;i++)  //输出最后的情况 
    {
                if(i==low) cout<<"low";
                if(i==mid) cout<<"mid";
                if(i==high) cout<<"high";
                else cout<<'\t';
    }
    cout<<endl;
    if (target==a[mid].key) return mid;
    else return 0;    //0为未找到 
}

int searchMain()
{
    while(1)
    {
    
        int ch=0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//设置字体颜色为蓝绿色
        cout<<"1.顺序查找"<<endl;
        cout<<"2.二分查找"<<endl;
        cout<<"0.Back"<<endl<<"请选择:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//设置字体颜色为白色
        cin>>ch;fflush(stdin);
        switch(ch)
        {
            case 0:return 1;
            case 1:{
                 cout<<"输入一串字符"; 
                 searchList<char> a;
                 char c;
                 cout<<"你想查找的字符是:";
                 cin>>c; 
                 cout<<"顺序查找的结果为"<<a.ordinalSearch(c)<<endl;
                 break;
                 }
            case 2:{
                 cout<<"请按升序输入一串数字:";
                 searchList<int> b;
                 int n;
                 cout<<"你想查找的数字是:";
                 cin>>n;
                 cout<<"二分查找的结果为"<<b.binSearch(n)<<endl;
                 break; 
                 }
            default:return 1;
                              
        } //end switch 
        system("pause"); 
    }//end while
    return 0;
}
