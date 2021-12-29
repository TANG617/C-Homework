#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
	char temp[10];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);

}
//int num[101];


// BKDR Hash Function
// unsigned int BKDRHash(char *str) {
// 	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
// 	unsigned int hash = 0;

// 	while (*str) {
// 		hash = hash * seed + (*str++);
// 	}

// 	return hash % 10000;
// }
int num[10000];

int main() {
	// freopen("test.txt", "r", stdin);
	int n, k = 1;
	char a[101][9];//strcmp()前大返回1，否则返回0；
	scanf("%d", &n);
//	a[0] = &"00000559", a[1] = &"00000935";
//	printf("%d\n", strcmp(a[0], a[1]));
//	swap(a[0], a[1]);
//	printf("%s %s\n", a[0], a[1]);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++) {
		int p = i + 1;
		while (p < n) {

			// num[BKDRHash(a[i])] = 1;
			if (strcmp(a[i], a[p]) > 0) {
				swap(a[i], a[p]);
//				printf("swap %d and %d\n", i + 1, p + 1);
			}
			// num[BKDRHash(a[i])] = 1;
//			printf("%s---%d\n", a[i], BKDRHash(a[i]));
//			if (strcmp(a[i], a[p]) == 0) {
//				k++;
//				num[BKDRHash(a[i])]
////				printf("%d\n", k);
////				printf("swap %d and %d\n", i + 1, p + 1);
//			}
			p++;

		}

	}
	// for (int i = 0; i < 10000; i++) {
	// 	k += num[i];
	// }
	
	for (int i = 1; i < n; i++) {
		if (strcmp(a[i], a[i - 1]) != 0) {
			// printf("%s", a[i]);
			k++;
		}
	}
	printf("%d\n", k);
	printf("%s\n", a[0]);

//			printf("%s--%d\n", a[i], BKDRHash(a[i]));
	
	for (int i = 1; i < n; i++) {
		if (strcmp(a[i], a[i - 1]) != 0) {
			printf("%s", a[i]);
			if (i != (n - 1))
				printf("\n");
		}

//			printf("%s--%d\n", a[i], BKDRHash(a[i]));
	}
}