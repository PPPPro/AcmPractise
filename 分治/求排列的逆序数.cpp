#include<iostream>
using namespace std;
long long cnt = 0;
void Merge(int a[],int begin,int mid,int end,int tmp[]){
	//将数组a的局部a[s,m]和a[m+1,e]合并到tmp,并保证tmp有序，然后再拷贝回a[s,m]
	//归并操作时间复杂度：O（e-m+1),即O（n)
	int pb = 0;
	int p1 = begin,p2 = mid+1;
	//按照归并排序的方法将两个数组进行比较合并
	while( p1 <= mid && p2 <= end){
		if( a[p1] > a[p2] ){
			cnt += end - p2 + 1;
			tmp[pb++] = a[p1++];
		}
		else
			tmp[pb++] = a[p2++];
	}
	//比较后肯定有一个数组有剩余，将他放入tmp里
	while( p1 <= mid)
		tmp[pb++] = a[p1++];
	while( p2 <= end)
		tmp[pb++] = a[p2++];
	//再把合并的结果放回原数组
	for(int i = 0; i < end-begin+1; i++)
		a[begin+i] = tmp[i];
}
void MergeSort(int a[],int begin,int end,int tmp[]){
	if( begin < end ){
		int mid = begin + (end - begin)/2;
		MergeSort(a,begin,mid,tmp);
		MergeSort(a,mid+1,end,tmp);
		Merge(a,begin,mid,end,tmp);
	}
}

int main(){
	int a[100000];
	int b[100000];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	MergeSort(a,0,n-1,b);

	cout << cnt;
	return 0;
}