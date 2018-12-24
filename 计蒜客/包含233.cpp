#include<iostream>
using namespace std;
int main(){
	int i,j,cnt = 0,n;
	int a,b,c,d,e,f,g; 
	for(a = 1; a < 10; a++){
		for(b = 0; b < 10; b++){
			for(c = 0; c < 10; c++){	
				for(d = 0; d < 10; d++){		
					for(e = 0; e < 10; e++){
						if(c == 2 && d == 3 && e == 3)cnt++;
						if(b == 2 && c == 3 && d == 3)cnt++;
						if(a == 2 && b == 3 && c == 3)cnt++;
					}
				} 
			}
		}
	}
	cout << cnt;
}
