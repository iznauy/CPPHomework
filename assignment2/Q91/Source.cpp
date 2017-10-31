#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 1005;

template <class T>
double ave(T a[], int size)
{
	T s = 0;
	for (int i = 0; i < size; i++) s += a[i];
	return 1.0 * s / size;
}

struct Pair
{
	string id;
	double score;
};

bool cmp(const Pair & p1, const Pair & p2)
{
	return p1.score < p2.score;
}

int scores[MAX][MAX];
double avg[MAX];
map<string, int> sm, cm;
set<string> ids;
Pair pairs[MAX];
int sc, cc;
int n, p, num;


int main()
{
	string s, id, cls;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> s >> id >> cls >> p;
		if (!sm.count(id)) sm[id] = sc++; 
		a = sm[id];
		if (!cm.count(cls)) cm[cls] = cc++;
		b = cm[cls];
		scores[a][b] = p;
		ids.insert(id);
	}
	for (int i = 0; i < sc; i++) avg[i] = ave(scores[i], cc);
	double allAvg = ave(avg, sc);
	for (string id : ids) {
		double po = avg[sm[id]];
		if (po <= allAvg) {
			Pair pair;
			pair.id = id;
			pair.score = po;
			pairs[num++] = pair;
		}
	}
	sort(pairs, pairs + num, cmp);
	for (int i = num - 1; i; i--) cout << pairs[i].id << endl;
	cout << pairs[0].id;
	return 0;
}