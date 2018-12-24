#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int IsC(int a,int b,int c,int d,int e,int f,int g,int h){
    int k[] = {a,b,c,d,e,f,g,h};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i == j)continue;
            if(k[i] == k[j])return 0;
        }
    }
    return 1;
}
int main(){
	int i,j,n,tmp,ans = 0;
	int a,b,c,d,e,f,g,h;
	for(a = 1; a < 10; a++){
        for(b = 0; b < 10; b++){
            for(c = 0; c < 10; c++){
                for(d = 0; d < 10; d++){
                    for(e = 1; e < 10; e++){
                        for(f = 0; f < 10; f++){
                            for(g = 0; g < 10; g++){
                                for(h = 0; h < 10; h++){
                                    tmp = ((a+e)*1000)+((b+f)*100)+((c+g)*10)+d+b;
                                    if(tmp == (e*10000)+(f*1000)+(c*100)+(b*10)+h  && IsC(a,b,c,d,e,f,g,h)){
                                        cout<<a<<b<<c<<d<<e<<f<<g<<h<<endl;
                                    }
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
