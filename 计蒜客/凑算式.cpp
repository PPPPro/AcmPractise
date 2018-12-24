#include<iostream>
using namespace std;
bool is(int a,int b,int c,int d,int e,int f,int g,int h,int i){
	int tmp[9] = {a,b,c,d,e,f,g,h,i};
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(i == j)continue;
			if(tmp[i] == tmp[j])return 0;
		}
	}
	return 1;
}
int main(){
	int a,b,c,d,e,f,g,h,i,def,ghi,cnt=0;
	for(a = 1; a <= 9; a++){
		for(b = 1; b <= 9; b++){
			for(c = 1; c <= 9; c++){
				for(d = 1; d <= 9; d++){
					for(e = 1; e <= 9; e++){
						for(f = 1; f <= 9; f++){
							for(g = 1; g <= 9; g++){
								for(h = 1; h <= 9; h++){
									for(i = 1; i <= 9; i++){
										def = d*100+e*10+f;
										ghi = g*100+h*10+i;
									//	cout <<a<<" "<<b<<" "<<c<<" "<<def<<" "<<ghi<<endl;
										if(a*c*ghi+b*ghi+def*c == 10*c*ghi && is(a,b,c,d,e,f,g,h,i)){
											cout <<a<<" "<<b<<" "<<c<<" "<<def<<" "<<ghi<<endl;
											cnt++;	
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << cnt;
}
