
void makediagonalzero(int mat[][MAX], int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (i == j || (i + j + 1) == n)
				mat[i][j] = 0;
		}
	}

}
