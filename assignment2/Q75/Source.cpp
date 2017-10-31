#include <iostream>
#include <string>
#define N 1000
using namespace std;

string nodes[N];

void inorder(int i, int length)
{
	if (2 * i <= length)
		inorder(2 * i, length);
	if (nodes[i] != "null")
		cout << nodes[i] << " ";
	if (2 * i + 1 <= length)
		inorder(2 * i + 1, length);
}

int main()
{
	int length = 1;
	while (cin >> nodes[length])
		length++;
	inorder(1, length - 1);
	return 0;
}