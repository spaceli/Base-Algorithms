#include "myhead.h"
void end();

int chooseMenu()
{
    int chs=0;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 132);//����������ɫΪ�ҵ׺��� 
    cout<<setw(50)<<"-----�㷨��ʾϵͳ-----"<<setw(30)<<' '<<endl; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//����������ɫΪ����ɫ 
    cout<<"\t1.�����㷨"<<endl;
    cout<<"\t2.�����㷨"<<endl;
    cout<<"\t3.���·���㷨��̰�ķ��Ͷ�̬�滮��)"<<endl;
    cout<<"\t4.���������������(̰�ķ��Ͷ�̬�滮��)"<<endl;
    cout<<"\t5.�������޵���ҵ��������(̰�ķ�)"<<endl; 
    cout<<"\t6.N�ʺ����⣨���ݷ���"<<endl; 
    cout<<"\t7.�Ӽ���������(���ݷ�)"<<endl; 
 
    cout<<"\t8.��ѧ���㣨���ݽṹ--ջ��Ӧ�ã�"<<endl;
    cout<<"\t9.����������ز��������ݽṹ��"<<endl;
    cout<<"\t10.ͼ�ı����㷨"<<endl;
    cout<<"\t11.��С�������㷨"<<endl; 

    cout<<"\t0.�˳�"<<endl<<endl; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����������ɫΪ��ɫ
    cout<<"\t��ѡ��:"; 
    cin>>chs; fflush(stdin);
    return chs;
}

int main()
{
    while(1)  //ִ���㷨 
    {
        switch(chooseMenu())
        {
            case 0:exit(0);
            case 1:searchMain();break;
            case 2:sortMain();break;
            case 3:shortPathMain();break;
            case 4:KNAPMain();break;
            case 5:greedyJobMain();break;
            case 6:nQueenMain();break;
            case 7:sumOfSubMain();break;
            case 8:scientificComputingMain();break;
            case 9:binatTreeMain();break;
            case 10:diagramTraversalMain();break;
            case 11:minimumSpanningTreeMain();break;
        }
    }
    
    system("PAUSE");
    return 1;
}

