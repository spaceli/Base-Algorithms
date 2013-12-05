/*��ѧ�����㷨�����ա����ݽṹ����ջ��Ӧ��ʵ��*/ 

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
//����һ����ջnumstack  
int   Initstack(Nstack   &numstack)   
{   
  numstack.base = (double*)malloc(stack_init_size*sizeof(double));   
  if(!numstack.base)  return   -1;   
  numstack.top = numstack.base;   
  numstack.stacksize=stack_init_size;   
  return   0;   
}   
//����һ����ջopstack   
int   Initstack(Cstack   &opstack)   
{   
  opstack.base = (char*)malloc(stack_init_size*sizeof(char));   
  if(!opstack.base)  return   -1;   
  opstack.top = opstack.base;   
  opstack.stacksize=stack_init_size;   
  return   0;   
}   
//������eѹ��ջnumstack   
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
//�������eѹ��ջopstack   
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
//������e��ջnumstack����   
double Pop(Nstack &numstack,double &e)   
{   
  if(numstack.top == numstack.base)return   -1;   
  e = *--numstack.top;   
  return e;   
}   
//�������e��ջopstack����   
char Pop(Cstack &opstack,char &e)   
{   
  if(opstack.top == opstack.base)return -1;   
  e = *--opstack.top;   
  return e;   
}   
//��e����numstackջ��Ԫ�ص�ֵ   
double  Gettop(Nstack numstack,   double   &e)   
{   
  if(numstack.top == numstack.base) return -1;   
  e = *(numstack.top-1);   
  return e;   
}   
//��e����opstackջ��Ԫ�ص�ֵ   
char Gettop(Cstack opstack,char &e)   
{   
  if(opstack.top == opstack.base) return -1;   
  e = *(opstack.top-1);   
  return e;   
}   
//�ж϶�����ǲ����������,�Ƿ���1,�񷵻�0   
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
//�������ջ�е�Ԫ�ؽ��и�ֵ������ֵ����   
int opFront(char op)   //ǰһ�������
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
//�Խ�Ҫ�������������и�ֵ������ֵ����   
int opBehind(char op)   //��һ�������
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
//����������������һ����������ж�Ԫ���㣬����ֵ�ٴ�ѹ��������ջ   
double Operate(double a,char op,double b)   
{ 
       cout<<"���� "<<a<<op<<b<<endl;  
  switch(op)   
  {   
      case   '+':return(a+b);break;   
      case   '-':return(a-b);break;   
      case   '*':return(a*b);break;   
      case   '/':return(a/b);break;   
  }   
  return 0;   
}   
//����������ȼ��Ƚ�   
char Precede(int e1,int e2)   
{   
  if(e1-e2<0)  return '<';   
  else  if(e1-e2==0)   
  return  '=';   
  else  return '>';   
}   

int scientificComputingMain()   
{     
  char   express[30],num[10],theta,tp,d='y';  //express[30]��������һ�����ʽ   
  double   a,b,result,tps;   //num[10]������ű��ʽ�������ŵ������ַ�   
  int   t,i,j;   
  int   position=0;//���ʽ�����ĵ�ǰ�ַ����±�   
  Initstack(numstack);     
  Initstack(opstack);   
  Push(opstack,'=');   

  while(d=='y'||d=='Y')   
  {   
      printf("��������������ʽ�����üӼ��˳������ţ�,��\"=\"��β��\n");   
      gets(express);   
      while(express[position]!= '=' || Gettop(opstack,tp) != '=')   
      {   
        if(!is_op(express[position]))  //������������t��jʵ�ָ������Ķ�ȡ    
        {     
            t = position;j=0;   
            while(!is_op(express[position]))   
            {   
                position++; 
            }   
            for(i = t;i<position;i++)   //�ѱ��ʽ�е�t��position-1���ַ�����num[10]   
            {
               num[j] = express[i];   
               //j++;   
            }   
            Push(numstack,atof(num));   //����ȡ����ѹ������ջ 
            memset(num,0,sizeof(num));//��num[10]���   
         }   
         else   
         {   
                  switch(Precede(opFront(Gettop(opstack,tp)),opBehind(express[position])))  
                  {   //�Ƚ���������������ȼ� 
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
      printf("�������㣿(Y/N):");   
      scanf("%c",&d);   
      getchar();   
  }//end   while   
}   
