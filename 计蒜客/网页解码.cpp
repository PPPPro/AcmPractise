#include <iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int IsPrime(int n)
{
    for(int i=2; i<=sqrt(1.0*n); ++i)
        if(n%i == 0)
            return 0;
    return 1;
}
const long long Max = 999999943999999559;
int main(){
	int i,j,n,tmp,ans = 0;
	vector<int>a;
	vector<int>b;
	cout<<sqrt(Max);
    for(i = sqrt(sqrt(Max)); i > 0; i--){
            for(j = sqrt(sqrt(Max)); j > 0; j--){
                if((j*i == Max) && IsPrime(i) && IsPrime(j))
                    cout << i << " " << j;
            }
    }
    cout<<"1";
	return 0;
}
