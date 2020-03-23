#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int grade(int first, vector<int>& final)
{
	final.push_back(first);
	return first;
}
int main(void)
{
	vector<string> words;
	string s;

	while (cin >> s)
	{
		if (s == "finish")
		{
			break;
		}

		words.push_back(s);
	}

	if (words.size() == 0)
	{
		cout << "단어가 적어도 하나는 있어야 합니다." << endl;

		return 1;
	}

	sort(words.begin(), words.end());

	string temp = words[0];
	int cnt = 1;

	for (int i = 1; i < words.size(); i++)
	{
		if (words[i] == temp)
		{
			cnt++;

			continue;
		}

		cout << temp << " : " << cnt << endl;

		temp = words[i];
		cnt = 1;
	}

	cout << temp << " : " << cnt << endl;

	vector<int> values(1);
	int num;
	num = grade(3, values);
	
	for (int i = 0; i < values.size() - 1; i++)
	{
		cout << values[i] << endl;
	}

	return 0;
}