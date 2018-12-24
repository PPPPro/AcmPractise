#include<iostream>
using namespace std;
int main(){
long long n,f,a,b;
cin >> n;
b = 1;
a = 1;
if(n < 3){
    cout << "1" << endl;
    return 0;;
}

for(int i = 3; i <= n; i++){


    f = a + b;
    b = a;
    a = f;
}
cout << f%1000000007 << endl;
return 0;
}
