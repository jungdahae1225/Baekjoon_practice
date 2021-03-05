// 222-Ǯ�� Ǯ��
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>


int pul(int arr[][10], int size) {
	int sort[4];
	int n; // �ι�° �� ����

	for (int i = 0; i < size; i += 2) {
		for (int j = 0; j < size; j += 2) {

			sort[0] = arr[i][j];
			sort[1] = arr[i + 1][j];
			sort[2] = arr[i][j + 1];
			sort[3] = arr[i + 1][j + 1];

			n = selectionSort(sort, 4);//4�� �� �ι�°�� ���� �� ���ϱ� ����

			arr[i / 2][j / 2] = sort[2];

			size /= 2;
		}
	}

	return arr;
}

int selectionSort(int arr[], int size) {
	int minIndex;
	int i, j;
	for (i = 0; i < size - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(&arr[i], &arr[minIndex]);
	}
	 
	return arr[1];
}
int main() {
	int num;
	int arr[10][10];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d", arr[i][j]);
		}
	}

	pul(arr, num);

}