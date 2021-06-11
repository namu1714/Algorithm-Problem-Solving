#include <stdio.h>

bool arr[3072][6143] = { 0, };

void star(int N, int row, int col) {
	if (N == 3) {
		arr[row][col + 2] = true;
		arr[row + 1][col + 1] = true; arr[row + 1][col + 3] = true;
		for (int i = 0; i < 5; i++) arr[row + 2][col + i] = true;
		return;
	}
	star(N / 2, row, col + N / 2);
	star(N / 2, row + N / 2, col);
	star(N / 2, row + N / 2, col + N);
}

int main() {
	int N;
	scanf("%d", &N);

	star(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (!arr[i][j])
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}