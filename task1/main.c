/*
利用改进欧拉法实现微分方程{y'+y=0,y(0)=a}各个瞬时值和最终定态。
由改进欧拉法可推导出微分方程的迭代公式为 y(n)=a*[(1-h+h^2/2)]^n。 
其中 h为两自变量之间步长,a为用户输入的y(0)对应值。 
*/
#include<stdio.h>
int main()
{
    double y[100001];        /*给出足够多个瞬时值*/             
    int n;                   /*定义自变量*/
    int count=0;         
    int t=1;
    double h,a,i,j;          /*定义初值、步长以及需要用到的相关变量*/
    h=0.001;                 /*取步长为0.001*/
    i=h*h/2;                 /*优化迭代公式*/
    j=1-h+i;                 /*优化迭代公式*/
        printf("y(0)=2\n");
    a=2;                     /*取初值为2*/
        //scanf("%lf",&a);
        printf("    x         y\n");
    y[0]=a;                
	for(n=1;n>0;n++)     /*遍历赋值*/
	{      
	     count++;
		 for(;t<n;t++)
		 {
		    double k=1-h+i;/*不断累乘求出各个瞬时值*/
		    j*=k;
		 }
		 y[n]=a*j;
		 if(count%100==0) /*每一百个瞬时值打印一个*/
		 {
		    printf("%lf  %lf\n",n*h,y[n]);
	         }
	 if(y[n-1]-y[n]<0.001*h) /*如果相邻两个瞬时值的差小于0.001h，此时认定后值为最终定态，停止运算*/
	 {
	 printf("%lf  %lf\n",n*h,y[n]);
	   break;	                  
	 } 
	}
	printf("lim(x->∞) y=%lf",y[n]);/*打印最终定态*/
return 0;
	}



