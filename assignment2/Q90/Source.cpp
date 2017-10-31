#include <iostream>
#include <string>
using namespace std;

struct Node
{
	Node * pre;
	Node * next;
	int data;
};

Node * head;
Node * tail;

void init()
{
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->pre = head;
}

void reverse()
{
	Node * temp;
	Node * current = head->next;
	while (current != tail) {
		temp = current->pre;
		current->pre = current->next;
		current->next = temp;
		current = current->pre;
	}
	head->pre = head->next;
	tail->next = tail->pre;
	temp = head;
	head = tail;
	tail = temp;
}

void add(int data)
{
	Node * node = new Node();
	node->data = data;
	tail->pre->next = node;
	node->pre = tail->pre;
	tail->pre = node;
	node->next = tail;
}

int getsize()
{
	int size = 0;
	Node * current = head;
	while (current->next != tail) current = current->next, size++;
	return size;
}

void print()
{
	int size = getsize();
	Node * current = head;
	if (size == 0) { cout << "NULL"; return; }
	for (int i = 0; i < size - 1; i++) {
		current = current->next;
		cout << current->data << " ";
	}
	cout << current->next->data;
}

void remove(Node * node)
{
	Node * pre = node->pre;
	Node * next = node->next;
	pre->next = next;
	next->pre = pre;
	delete node;
}

void removeRepeat(int i)
{
	Node * current = tail->pre;
	bool mf = false;
	while (current != head) 
		if (current->data == i) 
			if (mf) current = current->pre, remove(current->next);
			else mf = true, current = current->pre;
		else current = current->pre;
}

void deleteAll(int i)
{
	Node * node = new Node();
	node->pre = tail;
	tail->next = node;
	tail->data = i;
	tail = node;
	removeRepeat(i);
	tail = tail->pre;
	delete tail->next;
	tail->next = NULL;
}

int main()
{
	init();
	bool hasOut = false;
	int n, op;
	string cmd;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "ADD") {
			cin >> op;
			add(op);
		}
		else if (cmd == "SIZE") {
			if (hasOut) cout << endl;
			else hasOut = true;
			cout << getsize();
		}
		else if (cmd == "PRINT") {
			if (hasOut) cout << endl;
			else hasOut = true;
			print();
		}
		else if (cmd == "REMOVEREPEAT") {
			cin >> op; 
			removeRepeat(op);
		}
		else if (cmd == "DEL") {
			cin >> op;
			deleteAll(op);
		}
		else if (cmd == "REVERSE") {
			reverse();
		}
	}
}