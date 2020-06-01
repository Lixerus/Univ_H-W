/*#include <iostream>
#include <initializer_list>
#include <ctime>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Chip
{
public:
    Chip() {};
    Chip(initializer_list<int> list) {
        auto begin = list.begin();
        auto end = list.end();
        for (auto it = begin; it != end; ++it)
        {
            if (it == begin) amount = *it;
            else cost = *it;
        }
        lool = 0;
        okay = 0;
        sum = 0;
    }

    bool has() { return lool > okay; }
    void place() {
        ++okay;
        sum += cost;
    }
    bool pick() {
        if (lool < amount)
        {
            ++lool;
            return true;
        }
        return false;
    }
    bool used() { return (okay > 0); }
    void refresh() {
        okay = 0;
        sum = 0;
    }
    static int get_sum() { return sum; }

    int amount;
    int cost;
private:
    int lool;
    int okay;
    static int sum;
};
int Chip::sum = 0;

map<char, Chip> letter = { {'�',{10,1}}, {'�',{3,3}}, {'�',{5,2}}, {'�',{3,3}}, {'�',{5,2}},
{'�',{9,1}}, {'�',{2,5}}, {'�',{2,5}}, {'�',{8,1}}, {'�',{4,2}}, {'�',{6,2}}, {'�',{4,2}},
{'�',{5,2}}, {'�',{8,1}}, {'�',{10,1}}, {'�',{6,2}}, {'�',{6,2}}, {'�',{6,2}}, {'�',{5,2}},
{'�',{3,3}}, {'�',{1,10}}, {'�',{2,5}}, {'�',{1,10}}, {'�',{2,5}}, {'�',{1,10}}, {'�',{1,10}},
{'�',{1,10}}, {'�',{2,5}}, {'�',{2,5}}, {'�',{1,10}}, {'�',{1,10}}, {'�',{3,3}}, {'*',{3,0}} };

void omega()
{
    for (auto& Chip : letter)
        Chip.second.refresh();
}

char pikt(int range)
{
    bool can_pick = false;
    char c;
    while (!can_pick)
    {
        int x = rand() % range;
        if (x == 32) c = '*';
        else c = '�' + x;
        can_pick = letter[c].pick();
    }
    return c;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "russian");

    ifstream dict;
    dict.open("dictionary.txt");
    if (!dict.is_open())
    {
        cout << "Can't open dictionary!" << endl;
        return -1;
    }

    cout << "������ �����: ";
    for (size_t i = 0; i < 7; ++i)
        cout << pikt(33) << " ";
    char main_letter = pikt(32);
    cout << main_letter << endl;
    cout << "������� �����: " << main_letter << endl;
    Chip& main_Chip = letter[main_letter];

    Chip& asterisk_Chip = letter['*'];
    int max_sum = 0;
    string maxword = "lul";
    while (!dict.eof())
    {
        omega();
        bool good_word = true;
        string word;
        dict >> word;
        for (size_t i = 0; i < word.size(); ++i)
        {
            Chip& current_Chip = letter[word[i]];

            if (current_Chip.has()) current_Chip.place();
            else if (asterisk_Chip.has()) asterisk_Chip.place();
            else {
                good_word = false;
                break;
            }
        }

        if (!good_word || !main_Chip.used()) continue;
        int sum = Chip::get_sum();
        if (sum > max_sum) {
            max_sum = sum;
            maxword = word;
        }
    }
    dict.close();
    cout << endl;

    if (max_sum == 0)
    {
        cout << "���� ���!" << endl;
        return 1;
    }

    cout << "������������ �����: " << maxword << " (���� = " << max_sum << ")" << endl;

    return 0;
}*/