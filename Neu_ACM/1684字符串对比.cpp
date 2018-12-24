#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string a,b;
bool one(){
	if(a.size() != b.size()) return 1;
	return 0;
}
bool two(){
	if(a == b) return 1;	
	return 0;
}
bool three(){
	string ta,tb;
	ta = a;
	tb = b;
	for(int i = 0; i < ta.size(); i++){
		ta[i] = toupper(ta[i]);
	}
	for(int i = 0; i < tb.size(); i++){
		tb[i] = toupper(tb[i]);
	}
	if(ta == tb)return 1;
	return 0;
	
}
bool four(){
	if(a != b) return 1;
	return 0;
}

int main(){
	cin >> a >> b;
	if(one())cout <<"1" ;
	else if(two())cout << "2" ;
	else if(three())cout << "3";
	else if(four())cout << "4"; 
} 
