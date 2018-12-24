#include<algorithm>
#include<cstring>
#include<iostream>
#include<cctype>
using namespace std;
int main(){
	int i,j,k,n;
	string s;
	while(getline(cin ,s)){
		for(i = s.length()-1;i >= 0; i--){
            cout<<s[i];
		}
    cout <<endl;
	}
	return 0;
}
