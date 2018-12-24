#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,s = 0;
	const int MOD = 1000000;
	cin >> n;
	for(i = 1; i <= n; i++){
        int factorial = 1;
        for(j = 1; j <= i; j++)
            factorial = (factorial*j%MOD);
        s = (s + factorial) % MOD;
        cout << s <<endl;
        cout <<"time used = "<<(double)clock() / CLOCKS_PER_SEC;
    }
	return 0;
}
