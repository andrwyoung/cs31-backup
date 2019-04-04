#include <iostream>
#include <string>
#include <sstream>

//determines if properly formed string...basically solving the problem, making the other functions extra
bool isValidEbayListingString(std::string list)
{
	//determines if string has bidded yet
	bool bidded = false;
	bool watched = false;

	//turns on listmode and bidmode mode. which help extract numbers
	bool listmode = false;
	bool bidmode = false;

	//this counts watchers. do we even need the watcher function?
	int watchers = 0;
	int listedPrice = 0;
	int currentBid = 0;
	int tempBid = 0;

	//because we can't see the future. these strings help build the numbers
	std::string bidBuild = "";
	std::string listingBuild = "";

	size_t stringLength = list.length();

	//first letter must be L
	if(list[0] == 'L' || list[0] == 'l')
	{
		listmode = true;
	}
	else
	{
		std::cout << "not L\n";
		return false;
	}

	//looping through rest of word starting after the L
	for(size_t i = 1; i < stringLength; i++)
	{
		//listmode mode. must be numbers
		if(listmode) 
		{
			if(list[i] >= 48 && list[i] <= 57)
			{
				listingBuild += list[i];
			}
			else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b')
			{
				listmode = false;
				--i;
			}
			else
			{
				std::cout << "listmode: not number or enders\n";
				return false;
			}
		}






		//start bid (turns on bidmode mode)
		else if(list[i] == 'B' || list[i] == 'b')
		{
			bidmode = true;
		}
		//bidmode mode
		else if(bidmode)
		{
			//if first bid has already been placed
			if(bidded)
			{
				if(bidBuild == "")
				{
					if(list[i] == '+')
					{
						bidBuild += list[i];
					}
					else
					{
						std::cout << "already bidded, but no +\n";
						return false;
					}	
				}
				else if(list[i] >= 48 && list[i] <= 57)
				{
					bidBuild += list[i];
				}
				else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b' || list[i] == 'U' || list[i] == 'u')
				{
					if(bidBuild == "" || bidBuild == "+")
					{
						std::cout << "no bid\n";
						return false;
					}

					bidmode = false;

					//clear bidBuild
					std::istringstream(bidBuild.substr(1, stringLength - 1)) >> tempBid;
					currentBid += tempBid;
					bidBuild = "";
					--i;
				}
				else
				{
					std::cout << "bidmode: already bid: not number or enders\n";
					return false;
				}
			}
			else
			{
				if(list[i] >= 48 && list[i] <= 57)
				{
					bidBuild += list[i];
				}
				else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b' || list[i] == 'U' || list[i] == 'u')
				{
					if(bidBuild == "")
					{
						std::cout << "no initial bid\n";
						return false;
					}

					bidmode = false;
					bidded = true;
					//clear bidBuild
					std::istringstream(bidBuild) >> currentBid;
					bidBuild = "";
					--i;
				}
				else
				{
					std::cout << "bidmode: first bid: not number or enders\n";
					return false;
				}
			}
		}






		//watchers
		else if(list[i] == 'W' || list[i] == 'w')
		{
			if(watched == false)
			{
				watched = true;
			}
			watchers++;
		}

		//unwatchers. must have watchers
		else if (list[i] == 'U' || list[i] == 'u')
		{
			if(watched && watchers - 1 >= 0)
			{
				watchers--;
			}
			else
			{
				std::cout << "unwatching\n";
				return false;
			}
		}
		//no other combinations
		else
		{
			std::cout << "don't know man\n";
			return false;
		}

	}

	//build listed price
	if(listingBuild == "") 
	{
		std::cout << "no listed price\n";
		return false;
	} 
	else
	{
		std::istringstream(listingBuild) >> listedPrice;
	}

	//if string ended before enders came. add last thing
	if(bidBuild != "")
	{
		std::istringstream(bidBuild) >> tempBid;
		currentBid += tempBid;
	}

	std::cout << listedPrice << ", ";
	std::cout << watchers << ", ";
	std::cout << currentBid << ", ";

	std::cout << "success!\n";
	return true;

}
bool listingSold(std::string list); //process bids to determine if totla bid exceeds list price (given good string)

int howMuch(std::string list); //processes bids and returns total final bid

int watchers(std::string list); //processes watchers


int main()
{
	isValidEbayListingString("L99B50WB+10UWB+40W");
	isValidEbayListingString("l99b50wb+10uwb+40w");
	isValidEbayListingString("L100B99");
	isValidEbayListingString("L100B50WWWWWWW");
	isValidEbayListingString("L100B50WUWUWUWWWWW");
	isValidEbayListingString("L100B50WWUUB+10WWUU");
	isValidEbayListingString("L100W");
	isValidEbayListingString("L100WU");
	isValidEbayListingString("L100B50WU");

	std::cout << isValidEbayListingString("L100 B50 W B+10 U W B+40 W");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100.50B50");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100B50UW");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100BW50");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100B50WBU+50");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100B50UUUUUUUUU");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100B50WWUUUUUUUUU");
	std::cout << '\n';
	std::cout << isValidEbayListingString("WUL100");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100L50");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100B+50");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L100B50B+50B20");
	std::cout << '\n';
	*/
	std::cout << isValidEbayListingString("LB");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L0BW");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L001");
	std::cout << '\n';
	std::cout << isValidEbayListingString("L00000B00");
	std::cout << '\n';


	return 0;
}