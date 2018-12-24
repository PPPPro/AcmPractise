#include<stdio.h>
int main()
{
	int m, n;
	int i, j;
	int mat[200][200];
	scanf("%d", &m);
    scanf("%d", &n);
		for(i = 0; i < m; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &mat[i][j]);
			}
		}
		for(i = 0; i < m; ++i){
			for(j = n - 1; j >= 0; --j){
				printf("%d", mat[j][i]);
				if(j == 0) printf("\n");
				else printf(" ");
			}
		}
	return 0;
}

