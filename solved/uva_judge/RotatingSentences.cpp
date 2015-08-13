#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 490 Rotating Sentences

int main()
{
	string s;
	vector<string> lines;
	int maxSize = 0;

	while( getline(cin, s) )
	{
		lines.push_back(s);

		if (maxSize < s.size()) maxSize = s.size();
	}

	for (int j = 0; j < maxSize; j++)
	{
		stringstream newLine;
		for (int i = lines.size()-1; i >= 0; i--)
		{
			if (j < lines[i].size()) newLine << lines[i][j];
			else newLine << " ";
		}
		cout << newLine.str() << endl;
	}

	return 0;
}
