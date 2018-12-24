#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int Max = 1e6 + 5;
const int mod = 10007;
int main(){
	int i,j,n,tmp,ans = 0;
	vector<int>f(Max);
	f.at(1) = 1;
	f.at(2) = 1;
	cin>>n;
	for(i = 3; i <= n; i++){
        f.at(i) = (f.at(i-1) + f.at(i-2))%mod;
	}
	cout<<f[n]<<endl;
	return 0;
}
