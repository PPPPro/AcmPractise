#include<iostream>
#include<cmath>
using namespace std;
int Pow(int a,int b){
	if(b == 0)
		return 1;
	int tmp = Pow(a,b/2);
	tmp = tmp*tmp;
	 if(b%2== 1)
		 tmp = tmp * a; 
	return tmp;
}
int main(){
	float x,y;
	cin >> x >> y;
	cout<<Pow(x,y)<<endl;
	cout<<pow(x,y); 
	return 0;
} 
