#include "myhead.h"
void end();

int chooseMenu()
{
    int chs=0;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 132);//设置字体颜色为灰底红字 
    cout<<setw(50)<<"-----算法演示系统-----"<<setw(30)<<' '<<endl; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//设置字体颜色为蓝绿色 
    cout<<"\t1.查找算法"<<endl;
    cout<<"\t2.排序算法"<<endl;
    cout<<"\t3.最短路径算法（贪心法和动态规划法)"<<endl;
    cout<<"\t4.两个背包问题求解(贪心法和动态规划法)"<<endl;
    cout<<"\t5.带有期限的作业排序问题(贪心法)"<<endl; 
    cout<<"\t6.N皇后问题（回溯法）"<<endl; 
    cout<<"\t7.子集和数问题(回溯法)"<<endl; 
 
    cout<<"\t8.科学计算（数据结构--栈的应用）"<<endl;
    cout<<"\t9.二叉树的相关操作（数据结构）"<<endl;
    cout<<"\t10.图的遍历算法"<<endl;
    cout<<"\t11.最小生成树算法"<<endl; 

    cout<<"\t0.退出"<<endl<<endl; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//设置字体颜色为白色
    cout<<"\t请选择:"; 
    cin>>chs; fflush(stdin);
    return chs;
}

int main()
{
    while(1)  //执行算法 
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

