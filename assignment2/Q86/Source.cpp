#include <iostream>
using namespace std;
const int MAX = 1020;

int m, n;
int num;
int list[MAX][MAX], land[MAX][MAX];

void mark(int a, int b, int c, int d, int startCount)
{
	if (a > c || b > d) return;
	for (int i = b; i <= d; i++) land[a][i] = startCount++;
	for (int j = a + 1; j <= c; j++) land[j][d] = startCount++;
	for (int l = d - 1; l >= b && a != c; l--) land[c][l] = startCount++;
	for (int k = c - 1; k >= a + 1 && b != d; k--) land[k][a] = startCount++;
	mark(a + 1, b + 1, c - 1, d - 1, startCount);
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> list[i][j];
	cin >> num;
	mark(0, 0, m - 1, n - 1, 0);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (land[i][j] == num) cout << list[i][j];
	return 0;
}