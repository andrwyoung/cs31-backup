#include <iostream>
#include <string>
#include <cassert>

int findMinimum( const std::string array[ ] , int n );
int countAllPunctuation( const std::string array[ ], int n );
int countFloatingPointValues( const std::string array[ ], int n );
int removeDuplicatedValues( std::string array[ ], int n );
int replaceAll( std::string array[ ], int n, char letterToReplace, char letterToFill );
int shiftRight( std::string array[ ], int n, int amount, std::string placeholder );


void testone(int n)
{
	using namespace std;
    const int N = 6;


    // Act as if  a  were declared:
    //   string a[6] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[6] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "tau", "beta", "epsilon", ""
    };

    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~basic_string();
    a[N].string::~basic_string();

    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);

    string b[N] = {
        "delta", "gamma", "beta", "tau", "epsilon", "alpha"
    };

    string c[N] = {
        "one:", "two/", "three'", "alpha.", "beta", "alpha."
    };


    string d[N] = {
        "one-", "23/", "four:", "56.", "seven,", "89'"
    };

    string e[N] = {
        "4", "23.0a", "four.0", "56.0123", "seven.0,", "89.0.0"
    };    

    string f[N] = {
        "alpha", "beta", "alpha", "gamma", "delta", "beta"
    };

    int answer = 0;
    string s;

    switch (n)

    {    
           case  1:
               assert(findMinimum(z, -1) == -1);
               break; 
           case  2:
               assert(findMinimum(z, 0 ) == -1);
               break;
           case  3:
               assert(findMinimum(a, 6 ) == 0);
               break;
           case  4:
               assert(findMinimum(b, 6 ) == 5);
               break;
           case  5:
               assert(findMinimum(a, 3 ) == 0);
               break; 
           case  6:
               assert(findMinimum(b, 3 ) == 2);
               break; 
           case  7:
               assert(findMinimum(c, 3 ) == 0);
               break; 
           case  8:
               assert(findMinimum(c, 6 ) == 3 || findMinimum( c, 6 ) == 5);
               break; 
           case  9:
               assert(countAllPunctuation(z, -1 ) == -1);
               break; 
           case 10:
               assert(countAllPunctuation(z, 0 ) == -1);
               break; 
           case 11:
               assert(countAllPunctuation(a, 6 ) == 0);
               break; 
           case 12:
               assert(countAllPunctuation(b, 6 ) == 0);
               break; 
           case 13:
               assert(countAllPunctuation(a, 3 ) == 0);
               break; 
           case 14:
               assert(countAllPunctuation(c, 6 ) == 5);
               break; 
           case 15:
               assert(countAllPunctuation(c, 5 ) == 4);
               break; 
           case 16:
               assert(countAllPunctuation(d, 5) == 5);
               break; 
           case 17:
               assert(countAllPunctuation(d, 4 ) == 4);
               break; 
           case 18:
               assert(countFloatingPointValues(z, -1 ) == -1);
               break; 
           case 19:
               assert(countFloatingPointValues(z, 0 ) == -1);
               break; 
           case 20:
               assert(countFloatingPointValues(a, 6 ) == 0); 
               break; 
           case 21:
               assert(countFloatingPointValues(b, 6 ) == 0);

               break; 
           case 22: 
               assert(countFloatingPointValues(d, 6 ) == 1);
               break; 
           case 23:

               assert(countFloatingPointValues(d, 4 ) == 1);
               break; 
           case 24:
               assert(countFloatingPointValues(d, 3 ) == 0);
               break; 
           case 25:
               assert(countFloatingPointValues(e, 6 ) == 2);
               break; 
           case 26:
               assert(countFloatingPointValues(e, 3 ) == 1);
               break; 
           case 27:
               assert(replaceAll(z, -1, 'a', 'z' ) == -1);
               break; 
           case 28:
               assert(replaceAll(z, 0, 'a', 'z' ) == -1);
               break; 
           case 29:
               assert(replaceAll(a, 6, 'z', 'a' ) == 0 );
               break; 
           case 30:
               assert(replaceAll(a, 6, 'g', 'z' ) == 1 );
               assert( a[2] == "zamma" );
               break; 
           case 31:
               assert( replaceAll(a, 3, 'g', 'z' ) == 1 );
               assert( a[2] == "zamma" );
               break; 
           case 32:

               assert( replaceAll(a, 6, 'a', 'z' ) == 7 );
               assert( a[0] == "zlphz" );
               assert( a[1] == "betz" );
               assert( a[2] == "gzmmz" );
               assert( a[3] == "tzu" );
               assert( a[4] == "betz" );
               break; 
           case 33:
               assert( replaceAll(a, 6, 'b', 'z' ) == 2 );
               assert( a[1] == "zeta" );
               assert( a[4] == "zeta" );
               break; 
           case 34:
               assert( replaceAll(a, 4, 'b', 'z' ) == 1 );
               assert( a[1] == "zeta" );
               break; 
           case 35:
               assert(shiftRight(z, -1, 0, "foobar" ) == -1 );
               break; 
           case 36:
               assert(shiftRight(z, 0, 0, "foobar"  ) == -1 );
               break; 
           case 37:
               assert(shiftRight(z, -1, 5, "foobar"  ) == -1 );
               break; 
           case 38:
               assert( shiftRight(z, 0, 5, "foobar" ) == -1 );
               break; 
           case 39:
               assert( shiftRight(c, 6, 0, "foobar"  ) == 0);
               break; 
           case 40:
               answer = shiftRight(c, 6, 1, "foobar" );
               assert( answer == 1 );
               assert( c[0] == "foobar" );
               assert( c[1] == "one:" );
               assert( c[2] == "two/" );
               assert( c[3] == "three'" );
               assert( c[4] == "alpha." );
               assert( c[5] == "beta" );
               break; 
           case 41:
               answer = shiftRight(c, 6, 2, "foo" );
               assert( answer == 2 );
               assert( c[0] == "foo" );
               assert( c[1] == "foo" );
               assert( c[2] == "one:" );
               assert( c[3] == "two/" );
               assert( c[4] == "three'" );
               assert( c[5] == "alpha." );
               break; 
           case 42:

               answer = shiftRight(c, 6, 10, "bar" );
               assert( answer == 6 );
               assert( c[0] == "bar" );
               assert( c[1] == "bar" );
               assert( c[2] == "bar" );
               assert( c[3] == "bar" );
               assert( c[4] == "bar" );
               assert( c[5] == "bar" );
               break; 
           case 43:
               answer = shiftRight(a, 3, 10, "bar" );
               assert( answer == 3 );
               assert( a[0] == "bar" );
               assert( a[1] == "bar" );
               assert( a[2] == "bar" );
               assert( a[3] == "tau" );
               assert( a[4] == "beta" );
               assert( a[5] == "epsilon" );
               break;
           case 44:
               answer = shiftRight(a, 3, 1, "bar" );
               assert( answer == 1 );
               assert( a[0] == "bar" );
               assert( a[1] == "alpha" );
               assert( a[2] == "beta" );
               assert( a[3] == "tau" );
               assert( a[4] == "beta" );
               assert( a[5] == "epsilon" );
               break; 
           case 45:
               assert( removeDuplicatedValues(z, -1 ) == -1 );
               break; 
           case 46:
               assert(removeDuplicatedValues(z, 0  ) == -1 );
               break; 
           case 47: 
               assert(removeDuplicatedValues(z, -1  ) == -1 );
               break; 
           case 48:
               assert( removeDuplicatedValues(z, 0 ) == -1 );
               break; 
           case 49:

               answer = removeDuplicatedValues(c, 6 );
               assert( answer == 1 );
               assert( c[0] == "one:" );
               assert( c[1] == "two/" );
               assert( c[2] == "three'" );
               assert( c[3] == "alpha." );
               assert( c[4] == "beta" );
               assert( c[5] == "" );
               break; 
           case 50:

               answer = removeDuplicatedValues(a, 6 );
               assert( answer == 1 );
               assert( a[0] == "alpha" );
               assert( a[1] == "beta" );
               assert( a[2] == "gamma" );
               assert( a[3] == "tau" );
               assert( a[4] == "epsilon" );
               assert( a[5] == "" );
               break; 
           case 51:
               answer = removeDuplicatedValues(a, 3 );
               assert( answer == 0 );
               break; 
           case 52:

               answer = removeDuplicatedValues(f, 6 );
               assert( answer == 2 );
               assert( f[0] == "alpha" );
               assert( f[1] == "beta" );
               assert( f[2] == "gamma" );
               assert( f[3] == "delta" );
               assert( f[4] == "" );
               assert( f[5] == "" );
               break; 
           case 53:
               answer = removeDuplicatedValues(f, 3 );
               assert( answer == 1 );
               assert( f[0] == "alpha" );
               assert( f[1] == "beta" );
               assert( f[2] == "" );
               break; 
           case 54:
               answer = removeDuplicatedValues(f, 5 );
               assert( answer == 1 );
               assert( f[0] == "alpha" );
               assert( f[1] == "beta" );
               assert( f[2] == "gamma" );
               assert( f[3] == "delta" );
               assert( f[4] == "" );
               break; 



	   default: 
	       cout << "Bad argument" << endl;
               break; 
    }

    new (&a[-1]) string;
    new (&a[N]) string;


}

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
	std::cout << "Enter test number: ";
	int n;
	std::cin >> n;
	testone(n);
	std::cout << "Passed!" << std::endl;
	return 0;
}


//3, 4, 5, 6, 7, 8, 22, 23, 35, 36, 37, 38, 42, 43, 45 And 47