#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(){
	int i,j,n,tmp,ans = 0;
	i = 1234;
	for(i = 1000; i < 10000; i++){
        int d =  i%10;
        int c =  (i%100)/10;
        int b = (i/100)%10;
        int a = i/1000;
        if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d == i)
        cout << a<<b<<c<<d<<endl;
	}
	return 0;
}
