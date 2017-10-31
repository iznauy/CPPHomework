#include <iostream>
#include <string>
using namespace std;
const int N = 105;

int nums[N], len, op_count;

void replace(int a, int b)
{
	for (int i = 0; i < len; i++) if (nums[i] == a) nums[i] = b;
}

void print()
{
	for (int i = 0; i < len - 1; i++) cout << nums[i] << " ";
	cout << nums[len - 1] << endl;
}

void move(string op, int n)
{
	if (op == "tail") {
		int current = 0;
		for (int i = 0; i < len; i++) if (nums[i] != n) nums[current++] = nums[i];
		for (int i = current; i < len; i++) nums[i] = n;
	}
	else if (op == "head") {
		int current = len - 1;
		for (int i = len - 1; i >= 0; i--) if (nums[i] != n) nums[current--] = nums[i];
		for (int i = current; i >= 0; i--) nums[i] = n;
	}
}

void translate(string op, int n)
{
	if (op == "head") {
		int temp[N];
		for (int i = 0; i < len; i++) temp[(len - n + i) % len] = nums[i];
		for (int i = 0; i < len; i++) nums[i] = temp[i];
	}
	else if (op == "tail") {
		int temp[N];
		for (int i = 0; i < len; i++) temp[(len + n + i) % len] = nums[i];
		for (int i = 0; i < len; i++) nums[i] = temp[i];
	}
}


int main()
{
	cin >> len;
	for (int i = 0; i < len; i++) cin >> nums[i];
	cin >> op_count;
	string law, op;
	int op1, op2;
	for (int i = 0; i < op_count; i++) {
		cin >> law;
		if (law == "print") print();
		else if (law == "replace") cin >> op1 >> op2, replace(op1, op2);
		else if (law == "move") cin >> op >> op1, move(op, op1);
		else if (law == "translate") cin >> op >> op1, translate(op, op1);
	}
	return 0;
}