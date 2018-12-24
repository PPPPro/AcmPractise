#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0,Size,Sizeb,Sizea;
	string a,b;
	cin >> a >> b;
	if(a.size()>b.size()){
        Size = a.size();
	}
	else{
        Size = b.size();
	}
	int res[Size+1];
	memset(res,0,sizeof(res));
	Size = sizeof(res);
	Sizea = a.size();
	Sizeb = b.size();
    while(1){
        if(Sizea==0 && Sizeb == 0)break;
        else if(Sizea == 0)a[Sizea] = 0;
        else if(Sizeb == 0)b[Sizeb] = 0;
        res[Size] = int(a[Sizea] - '0') + int(b[Sizeb] - '0');
        if(res[Size] >= 10){
            res[Size-1]++;
            res[Size] = 0;
        }
        Size--;
        Sizea--;
        Sizeb--;
    }
    for(i = 0; i < Size; i++){
        cout<<res[i]<<" ";
    }
	return 0;
}
