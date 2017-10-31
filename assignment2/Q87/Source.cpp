#include <iostream>
using namespace std;
const int MAX = 1005;
int nums[MAX][MAX], n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) cin >> nums[i][j];
	for (int i = n - 2; i >= 0; i--) for (int j = 0; j <= i; j++) nums[i][j] += (nums[i + 1][j] < nums[i + 1][j + 1]) ? nums[i + 1][j] : nums[i + 1][j + 1];
	cout << nums[0][0];
	return 0;
}