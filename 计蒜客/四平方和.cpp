#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i = 0,j = 0,k = 0,l = 0,n,ans =0;
	double tmp;
	cin >> n;
	for(i = 0; ;i++){
        for(j = 0;i*i + j*j + k*k  <= n ; j++){
            for(k = 0;i*i + j*j + k*k  <= n ; k++){
                tmp = sqrt(n - (i*i + j*j + k*k));
                if(tmp == int(tmp)){
                cout <<i<<" "<<j<<" "<<k<<" "<<tmp;
                return 0;
               }
            }
            k = 0;
        }
        j = 0;
	}


	return 0;
}
