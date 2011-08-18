#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int main() 
{
	int hrs, mins;

	while (1) 
	{
		scanf("%d:%d", &hrs, &mins);

		if (hrs == 0 && mins == 0) break;

		double hourAngle = (hrs*30)+((double)mins/2);
		double minAngle = (mins*6);

		double angle1 = hourAngle - minAngle;
		double angle2 = minAngle - hourAngle;

		if (angle1 < 0) angle1 += 360.00;
		if (angle2 < 0) angle2 += 360.00;

		double res = 0;

		if (angle1 < angle2) res = angle1;
		else res = angle2;

		printf("%.3lf\n", res);
	}
	return 0;
}

