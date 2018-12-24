#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool Is_r(int a,int b,int c,int d,int e,int f,int g){
	int juge[7] = {a,b,c,d,e,f,g};
	int i,j;
	for(i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){
			if(i == j)continue;
			if(juge[i] == juge[j])return 0;
		}
	}
	return 1;
}

int main(){
	int i,j,n,tmp,ans = 0;
	int a,b,c,d,e,f,g;
	for(a = 1; a <= 9; a++){
        for(b = 0; b <= 9; b++){
            for(c = 0; c <= 9; c++){
                for(d = 0; d <= 9; d++){
                    for(e = 1; e <= 9; e++){
                        for(f = 0; f <= 9; f++){
                            for(g = 0; g <= 9; g++){
                                if(a*1000+b*100+c*10+d + e*100+f*10+g == e*1000+g*100+a*10+b  && Is_r(a,b,c,d,e,f,g)){
                                    cout << a << b<<c<<d<<endl;
                                    cout << e << f<<g<<endl;
                                    cout <<e<<g<<a<<b<<endl<<endl;
                                }

                            }
                        }
                    }
                }
            }
        }
	}
	return 0;
}
