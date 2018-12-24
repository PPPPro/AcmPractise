#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0;
	while(cin >> n){
        for(i = 2; i <= n; i++){
                int tmp = 1;
            for(j = 2; j < i; j++){
                if(i%j == 0){
                    tmp = 0;
                }
            }
        if(tmp)cout << i << endl;
        }
	}
	return 0;
}

