#include <iostream>
#include <string>
#include <sstream>

//determines if properly formed string...basically solving the problem. I copied and pasted this function into the other functions.
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
		return false;
	}

	//looping through rest of word starting after the L
	for(size_t i = 1; i < stringLength; i++)
	{
		//listmode mode. must be numbers
		if(listmode) 
		{
			if(listingBuild == "")
			{
				if(list[i] >= 49 && list[i] <= 57)
				{
					listingBuild += list[i];
				}
				else
				{
					return false;
				}	
			}	
			else if(list[i] >= 48 && list[i] <= 57)
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
				//if nothing has been added yet. First character must be +
				if(bidBuild == "")
				{
					if(list[i] == '+')
					{
						bidBuild += list[i];
					}
					else
					{
						return false;
					}
				}	
				else if(bidBuild == "+")
				{
					if(list[i] >= 49 && list[i] <= 57)
					{
						bidBuild += list[i];
					}
					else
					{
						return false;
					}	
				}
				else if(list[i] >= 48 && list[i] <= 57)
				{
					bidBuild += list[i];
				}
				else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b' || list[i] == 'U' || list[i] == 'u')
				{
					//substring because we don't want the +
					std::istringstream(bidBuild.substr(1, stringLength - 1)) >> tempBid;
					bidBuild = "";

					if(tempBid == 0)
					{
						return false;
					}

					bidmode = false;
					currentBid += tempBid;
					
					--i;
				}
				else
				{
					return false;;
				}
			}
			else
			{
				if(bidBuild == "")
				{
					if(list[i] >= 49 && list[i] <= 57)
					{
						bidBuild += list[i];
					}
					else
					{
						return false;
					}	
				}
				else if(list[i] >= 48 && list[i] <= 57)
				{
					bidBuild += list[i];
				}
				else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b' || list[i] == 'U' || list[i] == 'u')
				{
					std::istringstream(bidBuild) >> tempBid;
					bidBuild = "";

					if(tempBid == 0)
					{
						return false;
					}

					bidmode = false;
					bidded = true;
					currentBid += tempBid;
					--i;
				}
				else
				{
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
				return false;
			}
		}
		//no other combinations
		else
		{
			return false;
		}

	}

	//build listed price
	std::istringstream(listingBuild) >> listedPrice;
	if(listedPrice == 0) 
	{
		return false;
	}

	//if string ended before enders came. add last thing
	if(bidmode)
	{
		std::istringstream(bidBuild) >> tempBid;
		if(tempBid == 0)
		{	
			return false;
		}
		currentBid += tempBid;
	}

	return true;

}


//processes bids and returns total final bid
int howMuch(std::string list)
{
	if(!isValidEbayListingString(list))
	{
		return -1;
	}
	//determines if string has bidded yet
	bool bidded = false;
	bool watched = false;

	//turns on listmode and bidmode mode. which help extract numbers
	bool listmode = false;
	bool bidmode = false;

	//this counts watchers. do we even need the watcher function?
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
		return -1;
	}

	//looping through rest of word starting after the L
	for(size_t i = 1; i < stringLength; i++)
	{
		//listmode mode. must be numbers
		if(listmode) 
		{
			if(bidBuild == "")
			{
				if(list[i] >= 49 && list[i] <= 57)
				{
					listingBuild += list[i];
				}
				else
				{
					return -1;
				}	
			}
			else if(list[i] >= 48 && list[i] <= 57)
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
				return -1;
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
				//if nothing has been added yet. First character must be +
				if(bidBuild == "")
				{
					if(list[i] == '+')
					{
						bidBuild += list[i];
					}
					else
					{
						return -1;
					}	
				}
				else if(bidBuild == "+")
				{
					if(list[i] >= 49 && list[i] <= 57)
					{
						bidBuild += list[i];
					}
					else
					{
						return -1;
					}	
				}
				else if(list[i] >= 48 && list[i] <= 57)
				{
					bidBuild += list[i];
				}
				else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b' || list[i] == 'U' || list[i] == 'u')
				{
					//substring because we don't want the +
					std::istringstream(bidBuild.substr(1, stringLength - 1)) >> tempBid;
					bidBuild = "";

					if(tempBid == 0)
					{
						return -1;
					}

					bidmode = false;
					currentBid += tempBid;
					
					--i;
				}
				else
				{
					return -1;
				}
			}
			else
			{
				if(bidBuild == "")
				{
					if(list[i] >= 49 && list[i] <= 57)
					{
						bidBuild += list[i];
					}
					else
					{
						return -1;
					}	
				}
				else if(list[i] >= 48 && list[i] <= 57)
				{
					bidBuild += list[i];
				}
				else if(list[i] == 'W' || list[i] == 'w' || list[i] == 'B' || list[i] == 'b' || list[i] == 'U' || list[i] == 'u')
				{
					std::istringstream(bidBuild) >> tempBid;
					bidBuild = "";

					if(tempBid == 0)
					{
						return -1;
					}

					bidmode = false;
					bidded = true;
					currentBid += tempBid;
					--i;
				}
				else
				{
					return -1;
				}
			}
		}
	}

	//build listed price
	std::istringstream(listingBuild) >> listedPrice;
	if(listedPrice == 0) 
	{
		return -1;
	}

	//if string ended before enders came. add last thing

	if(bidmode)
	{
		std::istringstream(bidBuild) >> tempBid;
		if(tempBid == 0)
		{	
			return false;
		}
		currentBid += tempBid;
	}


	if(currentBid < listedPrice)
	{
		return 0;
	} 

	return currentBid;
}

bool listingSold(std::string list) //process bids to determine if totla bid exceeds list price (given good string)
{
	if(howMuch(list) > 0)
	{
		return true;;
	}
	return false;
}

//counts watchers
int watchers(std::string list)
{
	if(!isValidEbayListingString(list))
	{
		return -1;
	}

	int watchers = 0;

	size_t stringLength = list.length();
	for(size_t i = 0; i < stringLength; i++)
	{
		//watchers
		if(list[i] == 'W' || list[i] == 'w')
		{
			watchers++;
		}

		//unwatchers. must have watchers
		if (list[i] == 'U' || list[i] == 'u')
		{
			if(watchers - 1 >= 0)
			{
				watchers--;
			}
			else
			{
				return -1;;
			}
		}

	}

	return watchers;
}


int main()
{
	std::cout << isValidEbayListingString("L99B50WB+10UWB+40W") << std::endl;
	std::cout << isValidEbayListingString("l99b50wb+10uwb+40w") << std::endl;
	std::cout << isValidEbayListingString("L100B99") << std::endl;
	std::cout << isValidEbayListingString("L100B50WWWWWWW") << std::endl;
	std::cout << isValidEbayListingString("L100B50WUWUWUWWWWW") << std::endl;
	std::cout << isValidEbayListingString("L100B50WWUUB+10WWUU") << std::endl;
	std::cout << isValidEbayListingString("L100W") << std::endl;
	std::cout << isValidEbayListingString("L100WU") << std::endl;
	std::cout << isValidEbayListingString("L100B50WU") << std::endl;

	std::cout << '\n';

	std::cout << isValidEbayListingString("L100 B50 W B+10 U W B+40 W") << std::endl;
	std::cout << isValidEbayListingString("L100.50B50") << std::endl;
	std::cout << isValidEbayListingString("L100B50UW") << std::endl;
	std::cout << isValidEbayListingString("L100BW50") << std::endl;
	std::cout << isValidEbayListingString("L100B50WBU+50") << std::endl;
	std::cout << isValidEbayListingString("L100B50UUUUUUUUU") << std::endl;
	std::cout << isValidEbayListingString("L100B50WWUUUUUUUUU") << std::endl;
	std::cout << isValidEbayListingString("WUL100") << std::endl;
	std::cout << isValidEbayListingString("L100L50") << std::endl;
	std::cout << isValidEbayListingString("L100B+50") << std::endl;
	std::cout << isValidEbayListingString("L100B50B+50B20") << std::endl;
	std::cout << isValidEbayListingString("LB") << std::endl;
	std::cout << isValidEbayListingString("L0BW") << std::endl;
	std::cout << isValidEbayListingString("L001") << std::endl;
	std::cout << isValidEbayListingString("L00000B00") << std::endl;

	return 0;
}