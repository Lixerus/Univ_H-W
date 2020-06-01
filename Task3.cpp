/*
#include <iostream>
using namespace std;

void PrintTable(int** t, int n, int m)
{
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			cout << t[i][j];
		}
		cout << endl;
	}
};

const char* CheckTable(int** t, int n, int m)
{
	int lol = 0;
	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			cout << t[i][j];
			if (t[i][j] == n / 2) { lol = 1; }
			
		}
		cout << endl;
	}
	if (lol == 1) { return "Yes"; }
	else { return "No"; }
}

int main()
{
	cout << "Input the amount of rocks" << '\n';
	int amount;
	cin >> amount;
	int* mas = new int[amount+1];
	cout << "Enter the values"<<"\n";
	int value;
	int M=0;
	for (int i = 1; i < amount+1; ++i)
	{
		cin >> value;
		mas[i] = value;
		M += value;
	}
	mas[0] = 0;

	if (M % 2 == 1) { cout << "NO"; }
	else
	{
		int** table = new int* [M+1];
		for (int i = 0; i < M+1; ++i)
		{
			table[i] = new int[amount+1];
			table[i][0] = i;
		}

		for (int i = 0; i < amount+1; ++i)
		{
			table[0][i] = mas[i];
		}

		for (int i = 1; i < M + 1; ++i)
		{
			for (int j = 1; j < amount + 1; ++j)
			{
				table[i][j] = 0;
			}
		}
		PrintTable(table , M , amount);
		cout << '\n';
		for (int i = 1; i < amount+1; ++i)
		{
			for (int j = 1; j < M + 1; ++j)
			{
				if (i == 1)
				{
					cout << mas[i] << " zuz " << table[j][i] << " " << j <<'\n';
					if (mas[i] <= table[j][i-1])
						table[j][i] = mas[i];
				}
				else
				{
					if (j - mas[i] <= 0) { table[j][i] = table[j][i - 1]; }
					else {
						table[j][i] = (table[j][i - 1] > (mas[i] + table[j - mas[i]][i - 1])) ? table[j][i - 1] : (mas[i] + table[j - mas[i]][i - 1]);
					}
				}
			}
		}
		cout << CheckTable(table, M, amount) << endl;
	}
}

*/
