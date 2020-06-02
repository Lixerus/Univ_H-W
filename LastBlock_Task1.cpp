#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Input array length" << endl;
	int s;
	cin >> s;
	int* mas = new int[s];
	cout << "Input array values" << endl;
	for (int i = 0; i < s; ++i)
	{
		cin >> mas[i];
	}
	cout << "Unsorted array: " << endl;
	for (int i = 0; i < s; ++i)
	{
		cout << mas[i];
	}
	cout << endl;

	sort(mas,(mas+s));

	cout << "Sorted array: " << endl;
	for (int i = 0; i < s; ++i)
	{
		cout << mas[i];
	}
	cout << endl;
}