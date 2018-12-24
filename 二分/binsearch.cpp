#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
//54 98 32 15 89 65 12 48 47 99

int BinSearch(int a[],int size,int p){//查找
	int L = 0;
	int R = size - 1;
	while(L <= R){
		int mid =  L+(R-L)/2;
		if(a[mid] == p)
			return mid;
		else if(a[mid] > p)
			R = mid - 1;
		else L = mid + 1; 
	}
	return -1;
}
int Lowbound(int a[],int size,int p){//查找比给定整数p小的，下标最大的元素
	int L = 0;
	int R = size - 1;
	int LastPos = -1;//到目前为止找到的最优解
	while(L <= R){
		int mid =  L+(R-L)/2;
		if(a[mid] >= p)
			R = mid - 1;
		else{
			L = mid + 1;
			LastPos = mid;
		}
	}	 
	return a[LastPos];
}

int main(int argc, char * argv[]) 
{

    /* code */

    nt a[10];
    int key;
    
    for(int i = 0; i < 10; i++){
    	cin >> a[i];
    }

	sort(a,a+10);

    std::cin >> key;
    
    std::cout << "BinSearch :" << BinSearch(a,10,key) << endl;
    std::cout << "Lowbound :"<< Lowbound(a,10,key);

    return 0;
}