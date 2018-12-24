#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int i,j,n,tmp = 0, ans = 0;
	for(i = 1; i <= 100; i++){
        tmp += i;
        ans += tmp;
	}
	cout<<ans;
	return 0;
}
