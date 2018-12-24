#include<iostream>
#include<cstring>
using namespace std;
string s1[1010],s2[1010],s3[1010];
bool t[1010];
int main(){

	int a,b,c;
	while(cin >> a >> b >> c){
		memset(t,0,sizeof(t));
		for(int i = 0; i < a; i++){
			cin >> s1[i]; 
		}
		for(int i = 0; i < b; i++){
			cin >> s2[i];
			for(int j = 0; j < a; j++){
				if(s2[i] == s1[j])t[j] = 1;
			}
		}
		for(int i = 0; i < c; i++){
			cin >> s3[i];
			for(int j = 0; j < a; j++){
				if(s3[i] == s1[j])t[j] = 0;
			}
		}
		bool key = 0;
		for(int i = 0; i < a; i++){
			if(t[i]){
				cout << s1[i] << " ";
				key = 1;
			}
		}
		if(!key)cout << "No enemy spy";
		cout << endl;
	}
} 
