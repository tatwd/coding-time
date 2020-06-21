#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/* 校验身份证号是否有效 */
int validnumber(char *number) 
{
	size_t len = strlen(number);
	if (len != 18) {
		return -1;
	}

	/* 从右向左 最后一位是校验位(0~9,X或x) */
	double sum = 0;
	for (int i = len - 1; i >= 0; i--) {
		int num;
		if ((len - i - 1) == 0 && (number[i] == 'X' || number[i] == 'x')) {
			num = 10;
		} else if (isdigit(number[i])) {
			num = number[i] - '0';
		} else {
			return -1;	
		}
		double w = fmod(pow(2, len - i - 1), 11);
		sum += num * w;
	}
	double r = fmod(sum, 11);
	return r == 1 ? 0 : r;
}

/* 计算校验位 */
int compute_parity(char *number)
{
	size_t len = strlen(number);
	if (len != 18 && len != 17) {
		return -1;
	}

	double sum = 0;
	for (int i = len == 18 ? (len - 2) : (len -1); i >= 0; i--) {
		int num;
		if (i == 0 && (number[i] == 'X' || number[i] == 'x')) {
			num = 10;
		} else if (isdigit(number[i])) {
			num = number[i] - '0';
		} else {
			return -1;	
		}
		double w = fmod(pow(2, len - i - 1), 11);
		sum += num * w;
	}
	double r = fmod(sum, 11);
	return fmod(12 - r, 11);
}

int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		printf("Usage:	%s [18位身份证号]\n", argv[0]);
		return 0;
	}

	int ret = validnumber(argv[1]);
	printf("%d\n", ret);

	return 0;
}
