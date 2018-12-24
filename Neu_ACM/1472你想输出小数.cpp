#include<iostream>
#include<cstring>
using namespace std;
int point;
string s;
int main(){
	cin>>s;
	for(int i = s.size()-1; i >= 0; i--){
		cout << s[i];
	}
	return 0;
}
