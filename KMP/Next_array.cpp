#include<iostream>
#include<cstring>
using namespace std;

char a[100];
int Next[100];
int search(int end,int begin){
	cout << "e b: " << end << " " << begin << endl;
	if(a[end] == a[begin]){
		Next[end] = Next[begin] + 1;
		return begin;
	}
	if(begin == 0){
		Next[end] = 0;
		return begin;
	}
	begin = Next[begin-1];
	begin = search(end,begin);

}
int main(){
	int n;
	cin >> n;
	memset(Next,0,sizeof(Next));
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	Next[0] = 0;
	for(int j = 0, i = 1; i < n; i++){
		cout << "i : " << i << endl;
		if(a[i] == a[j]){
			Next[i] = Next[i-1] + 1;
			j++;
		}
		else{
			j = search(i,j);

		}
	}
	for(int i = 0; i < n; i++){
		cout << Next[i] << " ";
	}
}