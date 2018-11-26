#include <stdio.h>

// 2 1 1 2 特殊数据
// 4 1 4 1 优先左边 
int main() {
    freopen("input.txt", "r", stdin);
	int n, num[10005], i;
	while(~scanf("%d", &n)) {
		num[0] = 21, num[n+1] = 21;
		for(i = 1; i <= n; i++) scanf("%d", &num[i]);
		if(n > 1) {//考虑特殊数据 
		 for(i = 1; i <= n; i++) {
			if(num[i] == 1) {								/*考虑特殊数据*/ 
				if(num[i-1] <= num[i+1] || (num[i-1]==2&&num[i+1]==1)) {
					num[i] += num[i-1];
					num[i-1] = 1;
				} else {
					num[i+1]++;
					i++;//只是为了减少一些不必要的循环 
				}
			}
		 }
	  }
    //   for (i = 0; i <= n+1; i++)
    //     printf("%d ", num[i]);
        for(i = 2; i <= n; i++) num[1] = (num[1]*num[i])%10086;
        printf("%d\n", num[1]);
	}
	return 0;
}