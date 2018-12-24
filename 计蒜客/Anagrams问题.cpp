#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int main(){
	int i,j,ok  = 1;
	map<char,int> dict1,dict2;
	string s1,s2;
	cin >> s1 >> s2;

	for(i = 0; i < s1.length(); i++){
		char tmp = tolower(s1[i]);
		if(dict1.count(tmp)){
			dict1[s1[i]]++;
		}
		dict1.insert(pair<char,int>(tmp,1));
	}
	for(i = 0; i < s2.length(); i++){
		char tmp = tolower(s2[i]);
		if(dict2.count(s2[i])){
			dict2[s2[i]]++;
		}
		dict2.insert(pair<char,int>(tmp,1));
	}
	for(map<char,int>::iterator it = dict1.begin();
	 it != dict1.end(); it++){
	 	if(it->second != dict2[it->first])ok = 0;
	 }
	 if(ok)cout<<'Y';
	 else cout << 'N';
	return 0;
} 
