#include<stdio.h>

int main()
{
	
	int i,k,n,g;
	int a[10];
	int b,c,ghi,def;
	int sum=0;
	i=1;
	a[i]=1;
	
	
	while(1){
		//1.判断跟前面i-1个数没有重复 
		for(g=1,k=i-1;k>0;k--){
			if(a[i]==a[k])g=0;
		}
		//2.判断当前状态是否成立
		if(g&&i==9){
			b=a[2];
			c=a[3];
			def=a[4]*100+a[5]*10+a[6];
			ghi=a[7]*100+a[8]*10+a[9];
			if(a[1]*c*ghi+b*ghi+def*c==10*c*ghi){
				printf("%d\n",sum);
				sum++;
			}
		} 
		//3.是否继续 
		if(i<9&&g){
			i++;continue;
		}
		//4.是否回溯
		while(a[i]==9&&i>i)i--; 
		//5.是否结束循环
		if(a[i]==9&&i==1)break;
		else a[i]++;
		
	}
}
