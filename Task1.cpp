#include <iostream>
#include <vector>
using namespace std;
bool is_divided(int a, int b);
int ae(int x)
{
	if (x == 1) return 1;
	int k = 2;
	for (int i = 2; i <= sqrt(x); ++i)
		if (is_divided(x, i))
		{
			++k;
			if (i != sqrt(x)) ++k;
		}

	return k;
}

int main()
{
	int m, n;
	vector<int> vec;

	cout << "Enter M, N: ";
	cin >> m >> n;

	int kmax = 1;
	for (int i = m; i <= n; ++i)
	{
		int k = ae(i);
		if (k == kmax) vec.push_back(i);
		else if (k > kmax)
		{
			kmax = k;
			vec.clear();
			vec.push_back(i);
		}
	}

	cout << endl << "Max dividers: ";
	for (auto x : vec)
		cout << x << " ";
	cout << endl;
}

bool is_divided(int a, int b)
{
	if (a % b == 0) return true;
	return false;
}
