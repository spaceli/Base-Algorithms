/*�����㷨,����c++ģ������*/
/*����˳����ҺͶ��ֲ����㷨*/ 
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
             int ordinalSearch(keyType target);  //˳����� 
             int binSearch(keyType target);      //���ֲ��� 
      private:
              elemType<keyType> *a;
              int maxSize,curSize;
};

template<class keyType>
int searchList<keyType>::ordinalSearch(keyType target)
{                                      
    a[0].key=target;
    int i=curSize;
    while(a[i].key!=target)  i--;//�����һ��Ԫ����ǰһ��һ���� 
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
        for(int i=1;i<=high;i++) //��ʾ������־�ı仯��� 
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
    for(int i=1;i<=high;i++)  //���������� 
    {
                if(i==low) cout<<"low";
                if(i==mid) cout<<"mid";
                if(i==high) cout<<"high";
                else cout<<'\t';
    }
    cout<<endl;
    if (target==a[mid].key) return mid;
    else return 0;    //0Ϊδ�ҵ� 
}

int searchMain()
{
    while(1)
    {
    
        int ch=0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//����������ɫΪ����ɫ
        cout<<"1.˳�����"<<endl;
        cout<<"2.���ֲ���"<<endl;
        cout<<"0.Back"<<endl<<"��ѡ��:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����������ɫΪ��ɫ
        cin>>ch;fflush(stdin);
        switch(ch)
        {
            case 0:return 1;
            case 1:{
                 cout<<"����һ���ַ�"; 
                 searchList<char> a;
                 char c;
                 cout<<"������ҵ��ַ���:";
                 cin>>c; 
                 cout<<"˳����ҵĽ��Ϊ"<<a.ordinalSearch(c)<<endl;
                 break;
                 }
            case 2:{
                 cout<<"�밴��������һ������:";
                 searchList<int> b;
                 int n;
                 cout<<"������ҵ�������:";
                 cin>>n;
                 cout<<"���ֲ��ҵĽ��Ϊ"<<b.binSearch(n)<<endl;
                 break; 
                 }
            default:return 1;
                              
        } //end switch 
        system("pause"); 
    }//end while
    return 0;
}
