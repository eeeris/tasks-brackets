#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool IsCorrect(string & brack)
{
	stack <char> it;
	for (auto token : brack)
	{
		auto top = it.empty() ? '\0' : it.top();

		switch (token)
		{
		case '(':
		case '[':
		case '{':
			it.push(token);
			break;

		case ')':
		case ']':
		case '}':
			if (!(token == ')' && top == '(' || token == ']' && top == '[' || token == '}' && top == '{'))
				return false;
			it.pop();
			break;

		}
		
	}
	return it.empty();

}

int main (int argc, char* argv[])
{
	string brackets;

	cout << "enter a string" << endl;
	cin >> brackets; 
	
	if (IsCorrect(brackets))
		cout << "correct";
	else
		cout << "not correct" << endl;

	return 0;
}