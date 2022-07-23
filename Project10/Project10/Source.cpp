#include <iostream>
#include<string>
#include <stack>
#include<cmath>
using namespace std;
stack<int> st1;
stack<char> st2;
stack <int>st3;
stack <char> st4;
string strg;
char op[] = { '+','-','*', '/','%','v','^',' ' };
int pr[] = { 1,1,2,2,3,4,4 };
void split(string strg)
{
	
	int i, z;
	int x = 0;
	string strg1;
	for (i = 0; i <= strg.size(); i++)
	{
		z = 0;
		while (z <= 6 && op[z] != strg[i] )
		{
			z++;
		}
			if (z > 6)
			{
				strg1 =strg1+ strg[i];
			}
			else
			{
				st1.push(stoi(strg1));
				st2.push(strg[i]);
				strg1 = "";
			}
		
	}
	st1.push(stoi(strg1));
}
void calcul()
{
	int a, b;
	a = st3.top();
	st3.pop();
	b = st3.top();
	st3.pop();
	if (st4.top() == '+')
		a = a + b;
	else {
		if (st4.top() == '-')
			a = a - b;
		else {
			if (st4.top() == '*')
				a = a * b;
			else {
				if (st4.top() == '/')
					a = a / b;
				else
				{
					if (st4.top() == '%')
						a = a % b;
					else
					{
						if (st4.top() == 'v')
							a = sqrt(b);
						else
						{
							if (st4.top() == '^')
								a = pow(a, b);
						}
					}
				}
			}
		}
	}
	st3.push(a);
	st4.pop();
}
void calc()
{
	while (!st1.empty())
	{
		st3.push(st1.top());
		st1.pop();
	}
	while (!st2.empty())
	{
		st4.push(st2.top());
		st2.pop();
	}
	int i;
	for (i =5; i >= 1; i--)
	{
		while (!st4.empty())
		{
			int z;
			z = 0;
			while (st4.top() != op[z])
				z++;
			if (pr[z] == i)
			{		
			        calcul();

		    }
			else
			{
				st1.push(st3.top());
				st3.pop();
				st2.push(st4.top());
				st4.pop();
			}
		}
		while (!st1.empty())
		{
			st3.push(st1.top());
			st1.pop();
			st4.push(st2.top());
			st2.pop();
		}
	}
	cout << st3.top() << endl;
	st3.pop();
}
int main()
{
	cout << "enter the equation you wish to solve" << endl;
	cin >> strg;
	split(strg);
	calc();
	system("pause");
	return 0;
}