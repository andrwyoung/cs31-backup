#include <iostream>
#include <string>

void printArray(std::string list[], int n)
{
	for(int i = 0; i < n; i++)
	{
		std::cout << list[i] << ", ";
	}

	std::cout << '\n';
}

/*
Return the index of the smallest item found in the array or -1 if n <= 0. 
For example, for the array people[ 5 ] shown above,
findMinimum( people, 5 ) should return the value 3, 
corresponding to the index of "daenerys". 
If there are multiple duplicate minimum values, 
you may return the index of either element that has this smallest value.
*/

int findMinimum(const std::string list[], int n)
{
	int minimum = 0;

	if(n <= 0)
	{
		return -1;
	}

	//loop stops right before max
	for(int i = 0; i < n - 1; i++)
	{
		//compares the string with the next on in array
		if(list[i].compare(list[i + 1]) < 0)
		{
			minimum = i + 1;
		}
	}

	return minimum;
}
/*
Return the total number of punctuation symbols 
found in all the elements of the passed array argument. 
For the purpose of this function, 
the characters '.' , ',', '!', ';', ''', '-', '/', ':', '?', '" 
count as punctuation symbols 
(that is, period, comma, exclamation mark, semicolon, apostrophe, dash, slash, colon, question mark, and double quote). 
Return -1 if n <= 0. For example, 
for the array string data[ 4 ] = { "howard-", "ucla.", "howard", "ucla" }; 
findPunctuation( data, 4 ) should return the value 2 while 
findPunctuation( data, -14 ) should return -1.
*/

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

/*
Return the total number of floating-point values found 
in all the array elements of the passed array argument. 
For the purpose of this function, a floating-point value should have the form #.#, 
where # is one of the digits 0-9. 
The decimal point is optional but should only be found once 
for the element to count as a valid floating-point value. 
Return -1 if n <= 0. For example, 
for the array string data[ 4 ] = { "4.4.3.3", "44", "33.098", "33.098a" }; 
countFloatingPointValues( data, 4 ) should return the value 2 
while countFloatingPointValues( data, -14 ) should return -1.
*/


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


/*
This function should ensure that none of the array elements are the same. 
All the non-duplicated values should be kept together at 
the front of the array and your function should use "" (the empty string) 
to fill out the array as needed. 
Return the number of elements which were removed or -1 if the array has no elements. 
For example, for the array people[ 5 ] shown above, 
removeDuplicatedValues( people, 5 ) should return 0 and the array argument should be unchanged.

However, removeDuplicatedValues( people, -5 ) should return -1. 
And finally, for the array string data[ 4 ] = { "happy", "days", "happy", "days" }; 
removeDuplicatedValues( data, 4 ) should return the value 2 
and the array argument should be changed to: { "happy", "days", "", "" };
*/

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

/*
This function should replace every occurrence of 
the letterToReplace value with the letterToFill value 
found in all the array elements of the passed array argument. 
Return the number of letters that were replaced or -1 if the array has no elements. 
For example, for the array people[ 5 ] shown above, replaceAll( people, 5, 'z', 'a' ) 
should return 0 and the array argument should be unchanged. 
However, replaceAll( people, -5, 'z', 'a' ) should return -1. 
And finally, for the array string data[ 4 ] = { "happy", "days", "are here", "again" }; 
replaceAll( data, 4, 'a', 'z' ) should return the value 5
and the array argument should be changed to: { "hzppy", "dzys", "zre here", "zgzain" };
*/

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

/*
Adjust the items found in the array, 
shifting each value to the right by amount parameter, 
filling the resulting first amount elements of the array with
the placeholder parameter and returning the number of times
the placeholder value was used after all the shifting has been performed 
or -1 if the array has no elements. For example, 
for the array people[ 5 ] shown above, 
shiftRight( people, 5, 3, "foo" ) should return 3 and 
adjust the array to have the values { "foo", "foo", "foo", "samwell", "jon" }; 
However, shiftRight( people, -5, 3, "foo" ) should return -1. 
Finally, shiftRight( people, 5, 25, "foo" ) should return 5 
and adjust the array to have the values { "foo", "foo", "foo", "foo", "foo" };
*/

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
	std::string a[] = {"a", "b", "c", "d", "e"}; //5
	std::string num[] = {"1", "2", "3", "4", "5"}; //5

	std::string ran[] = {"fe??kf'lje", ".3.3.63", "st?aw!re-", ","}; //4

	std::string flo[] = {"1.11", "4444", ".111", "0000", "0.009", "0."}; //6

	std::string one[] = {"one", "two", "one", "four", "five", "five", "five", "one"}; //8

	std::string abc[] = {"feaaakfje", "aaa", "bbb", "ccaac"}; //4



	std::cout << findMinimum(num, 5) << '\n';
	std::cout << findMinimum(a, 5) << '\n';

	std::cout << countAllPunctuation(ran, 4) << '\n';

	std::cout << countFloatingPointValues(flo, 6) << '\n';

	std::cout << removeDuplicatedValues(one, 7) << '\n';
	printArray(one, 8);

	std::cout << replaceAll(abc, 4, 'a', 'z') << '\n';
	printArray(abc, 4);

	std::cout << shiftRight(a, 3, 2, "one") << '\n';
	printArray(a, 5);
	
	return 0;
}