/**
The Josephus problem (or Josephus permutation) is a theoretical problem related to a certain counting-out game. There are people standing in a circle waiting to be executed. After the first man is executed, certain number of people are skipped and one man is executed. Then again, people are skipped and a man is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last man remains, who is given freedom. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
 */

using namespace std;

int josephus(int n, int m)
{
	int res = 0;
	vector <int> people;
	int loc = 0;

	for (int i = 0; i < n; i++) people.push_back(i+1);

	while (people.size() > 1)
	{
		if (loc >= people.size())
			loc %= people.size();

		people.erase(people.begin()+loc);
		loc += (m-1);
	}

	return people[0];
}
