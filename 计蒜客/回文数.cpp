#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp = 0,ans = 0,a,b,c;
	cin >> n;
	for(i = 100; i < 1000; i++){
        c = i%10;
        b = (i/10%10);
        a = i/100;
        if(a+a+b+b+c == n){
            cout<<a<<b<<c<<b<<a<<endl;
            tmp = 1;
        }
	}
	for(i = 100; i < 1000; i++){
        c = i%10;
        b = (i/10%10);
        a = i/100;
        if(a+a+b+b+c+c == n){
            cout<<a<<b<<c<<c<<b<<a<<endl;
            tmp = 1;
        }
	}
    if(!tmp)cout<<"-1";
	return 0;
}
