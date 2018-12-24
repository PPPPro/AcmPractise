#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,k,n,tmp,ans = 0;
	for(i = 0; i <= 100;i++){
        for(j = i; j < 100; j++){
            k = sqrt(1000 - i*i - j*j);
            if(i*i+j*j+k*k == 1000 && i<j &&j < k && i< k)
                cout <<i<< " "<<j<<" "<<k<<endl;
        }
	}
	return 0;
}
