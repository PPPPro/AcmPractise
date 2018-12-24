#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0;

	for(i = 0; i < 200 ; i++){
        tmp = 0;
        for(j = i; j < 200 || tmp <= 236; j++){
                tmp += j;
                if(tmp == 236){
                    cout << i;
                    return 0;
                }
        }
	}
	return 0;
}
