#include <iostream>
#include <string>
#include <cctype>
using namespace std;
const int MAX = 1000050;
int result[MAX], op1[MAX], op2[MAX];
int len1 = 0, len2 = 0;

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	for (int i = s1.length() - 1; i >= 0; i--) if (isdigit(s1[i])) op1[len1++] = s1[i] - '0';
	for (int i = s2.length() - 1; i >= 0; i--) if (isdigit(s2[i])) op2[len2++] = s2[i] - '0';
	int cins = 0;
	int max_len = (len1 > len2) ? len1 : len2;
	for (int i = 0; i < max_len; i++) {
		cins = op1[i] + op2[i] + cins;
		result[i] = cins % 10;
		cins = cins / 10;
	}
	if (cins == 1) result[max_len++] = 1;
	while (result[max_len - 1] == 0) max_len--;
	for (int i = max_len - 1; i >= 0; i--) cout << result[i] << ">";
	cout << "null";
}
