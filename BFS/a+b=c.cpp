#include<iostream>
using namespace std;
int main(){
	double a,b,c;
	int n;
	cin >> n;
	int i = 0;
	while(i++ < n){
		cin >> a >> b >> c;
		if(a+b > c){
			cout <<"Case #"<<i<< ": true" << endl;
		}else{
			cout <<"Case #"<<i<< ": false" << endl;
		}
	}
	return 0;
}