/*
利用改进欧拉法实现微分方程{y'+y=0,y(0)=a}各个瞬时值和最终定态。
由改进欧拉法可推导出微分方程的迭代公式为 y(n)=a*[(1-h+h^2/2)]^n。 
其中 h为两自变量之间步长,a为用户输入的y(0)对应值。 
*/
#include<stdio.h>
int main(){
    double y[100001];        /*给出足够多个瞬时值*/             
	int n;
	int count=0;
	int t=1;
	double h,a,i,j;
	h=0.001;                /*取步长为0.001*/
	i=h*h/2;                /*优化迭代公式*/
	j=1-h+i;                /*优化迭代公式*/
	printf("y(0)=1\n");
	a=1; 
	//scanf("%lf",&a);
	printf("    x         y\n");
	y[0]=a;
	for(n=1;n>0;n++){      /*遍历赋值*/
	     count++;
		 for(;t<n;t++){
		 double k=1-h+i;
		 	j*=k;
		 }
		 y[n]=a*j;
		 if(count%100==0){
		 printf("%lf  %lf\n",n*h,y[n]);
	}
	 if(y[n-1]-y[n]<0.001*h){/*如果相邻两个瞬时值的差小于0.001，此时认定后值为最终定态 */
	 printf("%lf  %lf\n",n*h,y[n]);
	   break;	                  
	 } 
	}
	printf("lim(x->∞) y=%lf",y[n]);
return 0;
	}



