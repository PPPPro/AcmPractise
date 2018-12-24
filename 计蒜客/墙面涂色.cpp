#include<iostream>
using namespace std;
int main(){
	int i,n,tmp = 3;
	cin >> n;
	for(i = 2; i < n; i++){
		tmp *= 2;
	}
	int temp = tmp/2;
	tmp += temp;
	cout << tmp;
	return 0;
}
