#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i = 12345,j,n,a,b,c,d,e,tmp = 0,ans = 0;
	for(i = 10000; i < 100000; i++){
        a =  i%10;
        b = (i%100)/10;
        c = (i%1000)/100;
        d = (i/1000)%10;
        e = i/10000;
 //       cout << e <<" "<< d<<" "<< c << " "<<b<<" "<<a;
        if(a == 4 || b == 4 || c == 4 || d == 4 || e == 4){
           continue;
        }
        tmp++;
        	}
   cout << tmp;
	return 0;
}
