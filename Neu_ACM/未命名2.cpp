#include<iostream>
using namespace std;
const int Max = 2005;
int fa[Max];
int n;


int find(int x){
	int count=0;  
    while(x!=fa[x])  
    {  
        x=fa[x];  
        count++;  
    }  
    return count;  
}
int main(){
	while(cin >> n){
		cout << n << endl;
		for(int i = 0; i <= Max; i++){
			fa[i] = i;
		}
		cout << n << endl;
		int u,v;
		for(int i = 0; i < n; i++){
			cout << n <<endl; 
			cin >> u >> v;
			fa[u] = v;
		}
		int ra = find(1);
		int rb = find(2);
		if(ra==rb)cout<<"You are my brother\n";  
        else if(ra>rb)cout<<"You are my elder\n";  
        else if(ra<rb)cout<<"You are my younger\n"; 
	}
	return 0;
} 
