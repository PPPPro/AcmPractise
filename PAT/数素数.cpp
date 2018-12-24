#include<iostream>
#include<cstring>
using namespace std;
bool prime[10010];
void is_prime(){
	memset(prime,true,sizeof(prime));
	for(int i = 2; i < 10000; i++){
		if(prime[i])
		for(int j = i*2; j <= 10010; j += i){
			prime[j] = false;
		}
	}
}
int main(){
	int M,N;
	cin >> M >> N;
	is_prime();
	int cnt = 0;
	for(int i = 2; i < 10010; i++){

		if(cnt == N)break;
	    else if(prime[i]){
			cnt++;
			if(cnt >= M){
				cout << i;

				if((cnt-M) % 10 == 0 && cnt!=N &&(cnt-M)!=0)cout << endl;
				else if(cnt != N )cout<<" ";
			}
			
		}
	}
}