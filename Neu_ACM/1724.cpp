#include<iostream>
#include<cstring>
using namespace std;
char key[5] = {'a','e','i','o','u'};
int f(char s){
	for(int i = 0; i < 5; i++){
		if(s == key[i])return 1;
	}
	return 0;
}
int main(){
	string s;
	char d;
	if( getline(cin,s)!=NULL)  
    { 
		for(int i = 0; i < s.size(); i++){
			if(f(s[i])){
				cout << i+1;
				return 0;
			}
		}cout<<"0" << endl;
    }  
	
	return 0;
} 
