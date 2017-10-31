#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1005;
int n;
string strings[MAX];

string convert(const string & arg)
{
	string temp = arg;
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] - 'a' >= 0) temp[i] = (temp[i] - 'a') * 2 + 'A';
		else temp[i] = (temp[i] - 'A') * 2 + 1 + 'A';
	return temp;
}

int cmp(const string & s1, const string & s2)
{
	return s1.size() < s2.size() || (s1.size() == s2.size() && convert(s1) < convert(s2));
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> strings[i];
	sort(strings, strings + n, cmp);
	for (int i = 0; i < n - 1; i++) cout << strings[i] << endl;
	cout << strings[n - 1];
	//cin >> n;
}