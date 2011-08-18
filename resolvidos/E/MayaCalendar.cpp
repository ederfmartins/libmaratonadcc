/*
300 - Maya Calendar

3
10. zac 0
0. pop 0
10. zac 1995
*/

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	scanf("%i", &n);
	printf("%i\n", n);

	int Number;
	char NameOfTheDay[100];
	int Year;

	map<string, int> days;

	days["pop"] = 0;
	days["no"] = 20;
	days["zip"] = 40;
	days["zotz"] = 60;
	days["tzec"] = 80;
	days["xul"] = 100;
	days["yoxkin"] = 120;
	days["mol"] = 140;
	days["chen"] = 160;
	days["yax"] = 180;
	days["zac"] = 200;
	days["ceh"] = 220;
	days["mac"] = 240;
	days["kankin"] = 260;
	days["muan"] = 280;
	days["pax"] = 300;
	days["koyab"] = 320;
	days["cumhu"] = 340;
	days["uayet"] = 360;

	const char* nameOfDays[20] = {
							"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
	};

	for (int i = 0; i < n; i++)
	{
		/*cin >> Number;
		cin >> NameOfTheDay;
		cin >> Year;*/

		scanf("%i. %s %i", &Number, NameOfTheDay, &Year);
		string name(NameOfTheDay);

		int numDays = Year*365 + days[name] + Number;
		Year = numDays/260;
		Number = numDays%13 + 1;

		printf("%i %s %i\n", Number, nameOfDays[numDays%20], Year);
		
	}
	return 0;
}
