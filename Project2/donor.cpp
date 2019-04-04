#include <iostream>
#include <string>

std::string getName()
{
	std::string name;

	std::cout << "Donor Name: ";
	std::getline(std::cin, name);

	if(name == "")
	{
		std::cout << "--- You must enter a valid name." << std::endl;
	}
	return name;
}

int getGender()
{
	std::string gender;

	std::cout << "Gender: ";
	std::getline(std::cin, gender);

	if(gender == "Male")
	{
		return 1;
	}
	else if(gender == "Female")
	{
		return 2;
	}
	else if(gender == "Trans Male" || gender == "Trans Female" || gender == "Queer" || gender == "Different")
	{
		return 3;
	} 
	else
	{
		std::cout << "--- You must enter a valid gender." << std::endl;
		return -1;
	}
}

int getAge()
{
	int age;

	std::cout << "Age: ";
	std::cin >> age;
	std::cin.ignore(32767, '\n');

	if(age <= 0)
	{
		std::cout << "--- You must enter a valid age." << std::endl;
		return -1;
	} 
	else
	{
		return age;
	}
}

int getWeight()
{
	int weight;

	std::cout << "Weight: ";
	std::cin >> weight;
	std::cin.ignore(32767, '\n');

	if(weight <= 0)
	{
		std::cout << "--- You must enter a valid weight." << std::endl;
		return -1;
	}
	else
	{
		return weight;
	}
}

int getHeight()
{
	int height;

	std::cout << "Height: ";
	std::cin >> height;
	std::cin.ignore(32767, '\n');

	if(height <= 0)
	{
		std::cout << "--- You must enter a valid height." << std::endl;
		return -1;
	}
	else
	{
		return height;
	}
}

bool checkEligibility(int gender, int age, int weight, int height)
{
	if(weight < 110)
	{
		return false;
	}
	//seperate branch for other gender
	else if(gender == 3)
	{
		if(age <= 22)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if(age < 16)
	{
		return false;
	}
	//big branch for females
	else if(gender == 2)
	{
		if(height < 58)
		{
			return false;
		}
		else if(height == 58)
		{
			if(weight < 146)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if(height == 59)
		{
			if(weight < 142)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		//taller than 60
		else
		{
			return true;
		}
	}
	//final branch: males
	else if(height < 60)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void printEligibility(bool eligible, std::string name)
{
	if(eligible)
	{
		std::cout << "--- Yes, " << name << " you can donate blood." << std::endl;
	}
	else
	{
		std::cout << "--- No, " << name << " you cannot donate blood." << std::endl;
	}
}

int main()
{
	std::string name = getName();
	if(name == "") return -1;

	//1 is male. 2 is female. 3 is other. Do like an enum!
	int gender = getGender();
	if(gender == -1) return -1;

	int age = getAge();
	if(age == -1) return -1;

	int weight = getWeight();
	if(weight == -1) return -1;

	int height = getHeight();
	if(height == -1) return -1;

	printEligibility(checkEligibility(gender, age, weight, height), name);

	return 0;
}