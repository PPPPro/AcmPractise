#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1000;
int n;
int a[maxn+10];
int maxlen[maxn+10];
int main(){
	cin >> n;
	//memset(maxlen,1,sizeof(maxlen));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	maxlen[1] = 1;
	for(int i = 2; i <= n; i++){
		int tmp = 0;
		cout << "i: " <<i<<endl;
		for(int j = 1; j < i; j++){
            cout << "j£º"<< j <<"   ";
			if(a[i] > a[j]){
				if(tmp < maxlen[j]){

				tmp = maxlen[j];
				 cout << "tmp:" << tmp <<"   ";
				}

			}
		}
		cout << endl;
		maxlen[i] = tmp+1;
	}
	int max = -1;
	for(int i = 1; i <= n; i++){
		cout << maxlen[i] << " ";
		//if(maxlen[i] > max){
		//	max = maxlen[i];
		//}
	}
	//cout << max;
}
