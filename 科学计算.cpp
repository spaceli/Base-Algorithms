/*科学计算算法，参照《数据结构》堆栈的应用实例*/ 

#include   "myhead.h"   
#include   "string.h"   
#include   "memory.h"
#define   stack_init_size   20   
#define   stackincrement   5    
  

typedef   struct     
{   
  double   *base;   
  double   *top;   
  int   stacksize;   
}Nstack;   
    
typedef   struct     
{   
  char   *base;   
  char   *top;   
  int   stacksize;   
}Cstack;   

Nstack   numstack;   
Cstack   opstack;   
//构造一个空栈numstack  
int   Initstack(Nstack   &numstack)   
{   
  numstack.base = (double*)malloc(stack_init_size*sizeof(double));   
  if(!numstack.base)  return   -1;   
  numstack.top = numstack.base;   
  numstack.stacksize=stack_init_size;   
  return   0;   
}   
//构造一个空栈opstack   
int   Initstack(Cstack   &opstack)   
{   
  opstack.base = (char*)malloc(stack_init_size*sizeof(char));   
  if(!opstack.base)  return   -1;   
  opstack.top = opstack.base;   
  opstack.stacksize=stack_init_size;   
  return   0;   
}   
//把数字e压入栈numstack   
int Push(Nstack &numstack,double e)   
{   
  if((numstack.top-numstack.base) >= numstack.stacksize)   
  {   
      numstack.base=(double*)realloc(numstack.base,(numstack.stacksize+stackincrement)*sizeof(double));   
      if(!numstack.base)   return -1;   
      numstack.top = numstack.base+numstack.stacksize;   
      numstack.stacksize += stackincrement;   
  }   
  *numstack.top++ = e;   
  return   1;   
}   
//把运算符e压入栈opstack   
int Push(Cstack &opstack,char e)   
{   
  if((opstack.top-opstack.base)>=opstack.stacksize)   
  {   
      opstack.base=(char*)realloc(opstack.base,(opstack.stacksize+stackincrement)*sizeof(char));   
      if(!opstack.base)   return -1;   
      opstack.top = opstack.base+opstack.stacksize;   
      opstack.stacksize += stackincrement;   
  }   
  *opstack.top++ = e;   
  return  1;   
}   
//把数字e从栈numstack弹出   
double Pop(Nstack &numstack,double &e)   
{   
  if(numstack.top == numstack.base)return   -1;   
  e = *--numstack.top;   
  return e;   
}   
//把运算符e从栈opstack弹出   
char Pop(Cstack &opstack,char &e)   
{   
  if(opstack.top == opstack.base)return -1;   
  e = *--opstack.top;   
  return e;   
}   
//用e返回numstack栈顶元素的值   
double  Gettop(Nstack numstack,   double   &e)   
{   
  if(numstack.top == numstack.base) return -1;   
  e = *(numstack.top-1);   
  return e;   
}   
//用e返回opstack栈顶元素的值   
char Gettop(Cstack opstack,char &e)   
{   
  if(opstack.top == opstack.base) return -1;   
  e = *(opstack.top-1);   
  return e;   
}   
//判断读入的是不是运算符符,是返回1,否返回0   
int is_op(char op)   
{   
  switch(op)   
  {   
      case   '+':   
      case   '-':   
      case   '*':   
      case   '/':   
      case   '(':   
      case   ')':   
      case   '=':return 1;break;   
      default:return 0;   
  }   
}   
//对运算符栈中的元素进行赋值，并将值返回   
int opFront(char op)   //前一个运算符
{   
  switch(op)   
  {   
      case   '=':return 0;break;   
      case   '(':return 1;break;   
      case   '+':   
      case   '-':return 3;break;   
      case   '*':   
      case   '/':return 5;break;   
      case   ')':return 6;break;   
      default:return -1;   
  }   
}   
//对将要读入的运算符进行赋值，并将值返回   
int opBehind(char op)   //后一个运算符
{   
  switch(op)   
  {   
      case   '=':return 0;break;   
      case   ')':return 1;break;   
      case   '+':   
      case   '-':return 2;break;   
      case   '*': 
      case   '/':return 4;break;   
      case   '(':return 6;break;   
      default:return -1;   
  }   
}   
//弹出两个运算数和一个运算符进行二元运算，并将值再次压入运算数栈   
double Operate(double a,char op,double b)   
{ 
       cout<<"计算 "<<a<<op<<b<<endl;  
  switch(op)   
  {   
      case   '+':return(a+b);break;   
      case   '-':return(a-b);break;   
      case   '*':return(a*b);break;   
      case   '/':return(a/b);break;   
  }   
  return 0;   
}   
//运算符的优先级比较   
char Precede(int e1,int e2)   
{   
  if(e1-e2<0)  return '<';   
  else  if(e1-e2==0)   
  return  '=';   
  else  return '>';   
}   

int scientificComputingMain()   
{     
  char   express[30],num[10],theta,tp,d='y';  //express[30]用来读入一个表达式   
  double   a,b,result,tps;   //num[10]用来存放表达式中连接着的数字字符   
  int   t,i,j;   
  int   position=0;//表达式读到的当前字符的下标   
  Initstack(numstack);     
  Initstack(opstack);   
  Push(opstack,'=');   

  while(d=='y'||d=='Y')   
  {   
      printf("请输入混和运算表达式（可用加减乘除和括号）,以\"=\"结尾：\n");   
      gets(express);   
      while(express[position]!= '=' || Gettop(opstack,tp) != '=')   
      {   
        if(!is_op(express[position]))  //用两个计数器t和j实现浮点数的读取    
        {     
            t = position;j=0;   
            while(!is_op(express[position]))   
            {   
                position++; 
            }   
            for(i = t;i<position;i++)   //把表达式中第t到position-1个字符赋给num[10]   
            {
               num[j] = express[i];   
               //j++;   
            }   
            Push(numstack,atof(num));   //将获取的数压入数字栈 
            memset(num,0,sizeof(num));//将num[10]清空   
         }   
         else   
         {   
                  switch(Precede(opFront(Gettop(opstack,tp)),opBehind(express[position])))  
                  {   //比较两个运算符的优先级 
                      case '<':Push(opstack,express[position]);
                               position++;
                               break;   
                      case '=':Pop(opstack,tp);
                               position++;
                               break;     
     				  case '>':Pop(opstack,theta);   
   							   Pop(numstack,b);     
   							   Pop(numstack,a);     
       						   result = Operate(a,theta,b);   
       						   Push(numstack,result);
                               break;       
                   }   
         }//end   else   
      }//end   while   
        
      printf("%s%8.4f\n",express,Pop(numstack,tps));          
      memset(express,0,sizeof(express));   
      position = 0;   
      printf("继续计算？(Y/N):");   
      scanf("%c",&d);   
      getchar();   
  }//end   while   
}   
