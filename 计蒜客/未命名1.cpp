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
		//1.�жϸ�ǰ��i-1����û���ظ� 
		for(g=1,k=i-1;k>0;k--){
			if(a[i]==a[k])g=0;
		}
		//2.�жϵ�ǰ״̬�Ƿ����
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
		//3.�Ƿ���� 
		if(i<9&&g){
			i++;continue;
		}
		//4.�Ƿ����
		while(a[i]==9&&i>i)i--; 
		//5.�Ƿ����ѭ��
		if(a[i]==9&&i==1)break;
		else a[i]++;
		
	}
}
