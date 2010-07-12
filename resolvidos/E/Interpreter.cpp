#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>


/** 10033 - Interpreter */

using namespace std;

#define MAX_REG 10
#define MAX_RAM 1000

int pointer;
int regArray[MAX_REG];
int ram[MAX_RAM];

bool decode() 
{
	int command, a1, a2;
	command = ram[pointer] / 100;
	a1 = (ram[pointer] % 100) / 10;
	a2 = ram[pointer] % 10;
	
	switch (command) {
		/* halt */
		case 1 :		
			return false;
			break;
			
		/* set register a1 to a2 */
		case 2 :
			regArray[a1] = a2;
			pointer++;
			break;
			
		/* add a2 to register a1 */
		case 3 :
			regArray[a1] = (regArray[a1] + a2) % 1000;
			pointer++;
			break;
			
		/* multiply register a1 by a2 */
		case 4 :
			regArray[a1] = (regArray[a1] * a2) % 1000;
			pointer++;
			break;
			
		/* set register a1 to the value of register a2 */
		case 5 : 
			regArray[a1] = regArray[a2];
			pointer++;
			break;
			
		/* add the value of register a2 to register a1 */
		case 6 : 
			regArray[a1] = (regArray[a1] + regArray[a2]) % 1000;
			pointer++;
			break;
			
		/* multiply register a1 by the value of register a2 */
		case 7 :
			regArray[a1] = (regArray[a1] * regArray[a2]) % 1000;
			pointer++;
			break;
			
		/* set register a1 to the value in RAM whose address is in register a2 */
		case 8 :
			regArray[a1] = ram[regArray[a2]];
			pointer++;
			break;			
			
		/* set the value in RAM whose address in in register a2 to that of register a1 */
		case 9 :
			ram[regArray[a2]] = regArray[a1];
			pointer++;
			break;			
			
		/* goto */		
		case 0 :
			if (regArray[a2] != 0) pointer = regArray[a1];
			else pointer++;
			break;			
			
		default: 
			break;
	}
	return true;	
}

int init()
{
	for (int i = 0; i < MAX_REG; i++) regArray[i] = 0;

	for (int i = 0; i < MAX_RAM; i++) ram[i] = 0;
}

int main (int argc, const char * argv[])
{
	int cases, num_instr;
	char instr[10];

	scanf("%i", &cases);

	fgets(instr, sizeof(instr), stdin);
	fgets(instr, sizeof(instr), stdin);

	num_instr = 0;

	for (int i = 0; i < cases; i++) 
	{
		init();
		
		pointer = 0;
		
		if (i != 0) printf("\n");
		
		while(fgets(instr, sizeof(instr), stdin) != NULL)
		{
			if (instr[0] == '\n') break;

			ram[pointer] = (instr[0] - '0') * 100 + (instr[1] - '0') * 10 + (instr[2] - '0');
			pointer++;
		}

		num_instr = 1;
		pointer = 0;

		while (decode()) num_instr++;

		printf("%i\n",num_instr);
	}
	
	return 0;
}

