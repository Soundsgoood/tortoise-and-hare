//Orion Guan
//February 10th, 2017

#include<stdio.h>
#include<time.h>

int fastPlod();
int slip();
int slowPlod();
int sleep();
int bigHop();
int bigSlip();
int smallHop();
int smallSlip();
void printRace(int tortoisePosition, int harePosition);
void printWinner(int tortoisePosition, int harePosition);
int rand();
void srand(unsigned int seed);

int main()
{
	printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");
	void srand(unsigned int seed);
	srand(time(NULL));

	int tortoisePosition = 1;
	int harePosition = 1;
	unsigned int tortoiseMoveIndex;
	unsigned int hareMoveIndex;
	unsigned int currentTime;

	int (*tortoiseMoveArray[10])() = {fastPlod,
								      fastPlod,
								      fastPlod,
								      fastPlod,
								      fastPlod,
								      slip,
								      slip,
								      slowPlod,
								      slowPlod,
								      slowPlod};
	int (*hareMoveArray[10])() = {sleep,
							      sleep,
							      bigHop,
							      bigHop,
							      bigSlip,
							      smallHop,
							      smallHop,
							      smallHop,
							      smallSlip,
							      smallSlip};

	while (tortoisePosition < 70 && harePosition < 70)
	{
		currentTime = time(0);
		while (time(0) == currentTime);

		tortoiseMoveIndex = (rand(0) % 10);
		tortoisePosition += (*tortoiseMoveArray[tortoiseMoveIndex])();
		if (tortoisePosition < 1) {tortoisePosition = 1;}

		hareMoveIndex = (rand(0) % 10);
		harePosition += (*hareMoveArray[tortoiseMoveIndex])();
		if (harePosition < 1){harePosition = 1;}

		printRace(tortoisePosition, harePosition);
	}

	printWinner(tortoisePosition, harePosition);
}

int fastPlod()
{
	printf("fast plod +3\n");
	return 3;
}
int slip()
{
	printf("slip -6\n");
	return -6;
}
int slowPlod()
{
	printf("slow plod +1\n");
	return 1;
}
int sleep()
{
	printf("sleep 0\n");
	return 0;
}
int bigHop()
{
	printf("big hop +9\n");
	return 9;
}
int bigSlip()
{
	printf("big slip -12\n");
	return -12;
}
int smallHop()
{
	printf("small hop +1\n");
	return 1;
}
int smallSlip()
{
	printf("small slip -2\n");
	return -2;
}

void printRace(int tortoisePosition, int harePosition)
{
	char race[76];
	int i;
	for (i = 0; i < 70; i++)
	{
		race[i] = '-';
	}
	for (i = 70; i < 76; i++)
	{
		race[i] = ' ';
	}

	if (tortoisePosition == harePosition)
	{
		//Better way to do this?
		int j = tortoisePosition;
		race[j] = 'O';
		race[j+1] = 'U';
		race[j+2] = 'C';
		race[j+3] = 'H';
		race[j+4] = '!';
		race[j+5] = '!';
		race[j+6] = '!';
	}
	else
	{
		race[tortoisePosition] = 'T';
		race[harePosition] = 'H';
	}

	for ( i = 0; i < 76; i++)
	{
		printf("%c", race[i]);
	}
	printf("\n");
}

void printWinner(int tortoisePosition, int harePosition)
{
	if (tortoisePosition >= 70)
	{
		if (harePosition >= 70)
		{
			printf("IT'S A TIE!!!\n");
		}
		else
		{
			printf("THE TORTOISE WINS!!!\n");
		}
	}
	else
	{
		printf("THE HARE WINS!!!\n");
	}
}