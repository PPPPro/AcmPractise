#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a[5];
    for(int i = 0; i < 5; i++){
        cin>>a[i];
    }
    cout<<&(find(a,a+4,3));
    return 0;
}
