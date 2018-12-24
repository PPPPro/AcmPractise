#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
// run this program using the console pauser or add your own getch, system("pause") or input loop
long long ans=0,tili = 0;
int hanoi(int n){
    if( n == 1){
        ans++;
        tili+=n;
    }
    else{
        hanoi(n-1);
        ans++;
        tili+=n;
        hanoi(n-1);
    }
}
int main(){
	int i,j,n,tmp;
	cin >> n;
    ans = 0;
	hanoi(n);
	cout << ans <<" "<<tili<<endl;
	return 0;
}
