/*
���øĽ�ŷ����ʵ��΢�ַ���{y'+y=0,y(0)=a}����˲ʱֵ�����ն�̬��
�ɸĽ�ŷ�������Ƶ���΢�ַ��̵ĵ�����ʽΪ y(n)=a*[(1-h+h^2/2)]^n�� 
���� hΪ���Ա���֮�䲽��,aΪ�û������y(0)��Ӧֵ�� 
*/
#include<stdio.h>
int main(){
    double y[100001];        /*�����㹻���˲ʱֵ*/             
	int n;
	int count=0;
	int t=1;
	double h,a,i,j;
	h=0.001;                /*ȡ����Ϊ0.001*/
	i=h*h/2;                /*�Ż�������ʽ*/
	j=1-h+i;                /*�Ż�������ʽ*/
	printf("y(0)=1\n");
	a=1; 
	//scanf("%lf",&a);
	printf("    x         y\n");
	y[0]=a;
	for(n=1;n>0;n++){      /*������ֵ*/
	     count++;
		 for(;t<n;t++){
		 double k=1-h+i;
		 	j*=k;
		 }
		 y[n]=a*j;
		 if(count%100==0){
		 printf("%lf  %lf\n",n*h,y[n]);
	}
	 if(y[n-1]-y[n]<0.001*h){/*�����������˲ʱֵ�Ĳ�С��0.001����ʱ�϶���ֵΪ���ն�̬ */
	 printf("%lf  %lf\n",n*h,y[n]);
	   break;	                  
	 } 
	}
	printf("lim(x->��) y=%lf",y[n]);
return 0;
	}



