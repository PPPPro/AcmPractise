#include<iostream>
#include<cstring>
using namespace std;
int Next[100];
void get_next(char *p){
	int m = strlen(p);
	Next[0] = Next[1] = 0;
	for(int i = 1; i < m; i++){
		int j = Next[i];
		while(j && p[i] != p[j]){
			j = Next[j];
		}
		Next[i+1] = p[i] == p[j] ? j+1 : 0;
	}
}
int KMP(char *T,char *s){
	int n = strlen(T),m = strlen(s);
	get_next(s);
	int j = 0;
	for(int i = 0; i < n; i++){
		while(j && T[i] != s[j]){
			j = Next[j];
		}
		if(T[i] == s[j]){
			j++;
		}
		if(j == m){
			return i - m + 1;
		}
	}
	return -1;

}
int main(){
	char T[100],s[100];
	cin >> T >> s;
	cout << KMP(T,s);
	return 0;
}