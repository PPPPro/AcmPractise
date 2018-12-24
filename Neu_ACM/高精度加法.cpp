#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
 
string a,b;
int x[105],y[105],z[105];

void cul(int size){
	memset(z,0,sizeof(z));
	for(int i = 0; i <= size; i++){
		int tmp = x[i]+y[i];
		z[i] += tmp;
		if(z[i] >= 10){
			z[i] %= 10;
			z[i+1] = 1;
		}
	}
}

int main(){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	cin >> a >> b;
	for(int i = a.size()-1,j = 0; i >= 0;j++ ,i--){
		x[j] = a[i]-'0';
	}
	for(int i = b.size()-1, j = 0; i >= 0;j++, i--){
		y[j] = b[i]-'0';
	}
	
	int tmp = max(a.size(),b.size());
	cul(tmp);
	for(int i = tmp; i >= 0; i--){
		if(z[tmp] == 0 & i == tmp)continue;
		cout << z[i];
	}
}
