#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
    int ans = 0;
    for (int i = 0; i < (1<<14); ++i) {
        int tot_1 = 0;
        int tot_0 = 0;
        int num = 2;
        for (int j = 0; j < 14; ++j) {
            if (i&(1 << j)) { // �����ж϶����� i �������� j + 1 λ�Ƿ�Ϊ 1
                tot_1++;
                num = num * 2;
            } else {
                tot_0++;
                num = num - 1;
            }
        }
        if (tot_1 == 5 && tot_0 == 9 && num == 1) {
            ++ans; // ��¼�Ϸ�������
        }
    }
    cout << ans;
	return 0;
}
