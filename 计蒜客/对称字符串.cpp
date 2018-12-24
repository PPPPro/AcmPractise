#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char s[10000];
int main(){
	int i,j,n,len,tmp,ans = 0;
	cin >> n;
	len = 0;
	for(i = 0; i < n; i++){
      strcpy(s+len+1,s);
      s[len] = 'A' + i ;
      len = strlen(s);
	}
	for(i = 0; i < len+2; i++){
        cout << s[i];
	}
	return 0;

}
