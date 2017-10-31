#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX = 10005;

string tree[MAX], obj1, obj2;
map<string, int> dict;
int num, ct;

int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++) cin >> tree[i], dict[tree[i]] = i;
	cin >> obj1 >> obj2;
	int o1 = dict[obj1], o2 = dict[obj2], l, s;
	if (o1 > o2) l = o1, s = o2; else l = o2, s = o1;
	while (l > s) l /= 2, ct++;
	if (l == s) cout << ct; else cout << -1;
}