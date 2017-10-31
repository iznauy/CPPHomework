#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<string> st;
string xml;

bool validTag(string s)
{
	if (s.size() > 9) return false;
	for (int i = 0; i < s.size(); i++) if (!(s[i] >= 'A' && s[i] <= 'Z')) return false;
	return true;
}

bool valid(string s)
{
	int i = 0;
	while (i < s.size()) {
		if (s[i] == '<') {
			string tag = "";
			if (s[i + 1] == '/') {
				i++;
				while (s[i + 1] != '>') tag += s[++i];
				i += 2;
				if (tag == st.top()) st.pop(); else return false;
				continue;
			}
			if (s[i + 1] == '!' && s[i + 2] == '-' && s[i + 3] == '-') {
				i += 4;
				while (s[i] != '-' || s[i + 1] != '-' || s[i + 2] != '>') {
					if (i + 2 >= s.size()) return false;
					else i++;
				}
				i += 3;
				continue;
			}
			while (s[i + 1] != '>') tag += s[++i];
			i += 2;
			if (validTag(tag)) st.push(tag); else return false;
		}
		else if (s[i] == '(') st.push("("), i++;
		else if (s[i] == ')') if (st.top() == "(") st.pop(), i++; else return false;
		else i++;
	}
	if (st.empty()) return true; else return false;
}

int main()
{
	getline(cin, xml);
	cout << (valid(xml) ? "True" : "False");
}