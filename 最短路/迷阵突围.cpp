#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m; 
struct p{
	int p1;
	int p2;
	p(int a){
		p2 = p1;
		p1 = a;
	}
};
int main(){
	p tmp1(5);
	cout << tmp1.p1<<" " << tmp1.p2;
	return 0;
}
