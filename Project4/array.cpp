#include <iostream>
#include <string>

int findMinimum(const std::string list[], int n)
{
	int minimum = 0;

	if(n <= 0)
	{
		return -1;
	}

	//loop stops right before max
	for(int i = 0; i < n; i++)
	{
		//compares the string with the next on in array
		if(list[minimum] > list[i])
		{
			minimum = i;
		}
	}

	return minimum;
}

int countAllPunctuation(const std::string list[], int n)
{
	int counter = 0;


	if(n <= 0)
	{
		return -1;
	}

	//run through each string
	for(int i = 0; i < n; i++)
	{
		size_t length = list[i].length();

		//check each string
		for(int j = 0; j < length; j++)
		{
			switch(list[i][j])
			{
				case '.':
				case ',':
				case '!':
				case ';':
				case '-':
				case '/':
				case ':':
				case '?':
				case '\'':
				case '\"':
					counter++;
					break;
			}
		}
	}

	return counter;
}

int countFloatingPointValues(const std::string list[], int n)
{
	int counter = 0;

	if(n <= 0)
	{
		return -1;
	}

	//checking each of the strings
	for(int i = 0; i < n; i++)
	{
		size_t length = list[i].length();
		int decimal = 0;

		bool passing = true;

		for(int j = 0; j < length; j++)
		{
			
			if(list[i][j] == '.' && j != 0 && j != length - 1)
			{
				decimal++;
			}
			else if(list[i][j] < '0' || list[i][j] > '9')
			{
				passing = false;
			}
		}

		if(decimal > 1)
		{
			passing = false;
		}

		if(passing)
		{
			counter++;
		}
	}

	return counter;
}

int removeDuplicatedValues(std::string list[], int n)
{
	int counter = 0;
	std::string placeholder[n];

	if(n <= 0)
	{
		return -1;
	}

	//checks every string
	for(int i = 0; i < n; i++)
	{
		bool different = true;

		//compares each string with those behind it
		for(int j = 0; j < i; j++)
		{
			if(list[i] == list[j])
			{
				different = false;
			}
		}

		//saves only values that are different, thus "removing" duplicate values
		if(different)
		{
			placeholder[i - counter] = list[i];
		}
		else
		{
			counter++;
		}
	}

	//list = placeholder
	for(int i = 0; i < n; i++)
	{
		list[i] = placeholder[i];
	}

	return counter;
}

int replaceAll(std::string list[], int n, char out, char in)
{
	int counter = 0;

	if(n <= 0)
	{
		return -1;
	}

	//checks each string
	for(int i = 0; i < n; i++)
	{
		std::string placeholder = list[i];
		size_t length = placeholder.length();

		//checks and replaces each letter in string
		for(int j = 0; j < length; j++)
		{
			if(placeholder[j] == out)
			{
				placeholder[j] = in;
				counter++;
			}
		}

		list[i] = placeholder;
	}

	return counter;
}

int shiftRight(std::string list[], int n, int amount, std::string replacement)
{
	std::string placeholder[n];

	if(n < 0) 
	{
		return -1;
	}

	//go through each value in string
	for(int i = 0; i < n; i++)
	{	
		if(i < amount)
		{
			placeholder[i] = replacement;
		}
		else
		{
			placeholder[i] = list[i - amount];
		}
	}

	//list = placeholder
	for(int i = 0; i < n; i++)
	{
		list[i] = placeholder[i];
	}

	return amount;
}

int main()
{


	return 0;
}