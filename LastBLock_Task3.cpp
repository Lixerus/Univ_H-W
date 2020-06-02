#include <iostream>
#include <algorithm>

using namespace std;

void dihotomy(int* mas, int size, int* ptr)
{
	if (size < 2)
		return;

	else
	{
		for (int i =0 ; i<size ; ++i)
			dihotomy(mas, size / 2, (ptr - size / 2));
	}
}

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