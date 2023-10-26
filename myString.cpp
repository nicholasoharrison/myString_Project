//myString.cpp

#include "myString.h"


myString::myString(const std::string& str)
{
	logFile << "\nconstructor called with string value: " << str;
	length = str.length();
	allocateMemory(length + 1);
	copyString(str.c_str());
}



myString::myString(const myString& other)
{
	logFile << "\ncopy constructor called for myString with other string value: " << other.str;
	length = other.length;
	allocateMemory(length + 1);
	copyString(other.str);
}



myString::~myString()
{
	logFile << "\ndestructor called with string value: " << str;
	releaseMemory();
}



int myString::size() const
{
	logFile << "\nsize() function called for string: " << str << ", size is: " << length;
	return length;
}



void myString::addStart(const myString& other)
{
	logFile << "\naddStart() function called adding string: " << other.str << " to: " << str;
	int newLength = length + other.length;
	char* newStr = new char[newLength + 1];
	copyString(other.str, newStr, other.length);
	copyString(str, newStr + other.length, length);
	releaseMemory();
	str = newStr;
	length = newLength;
	logFile << ", getting string: " << str;
}



void myString::addEnd(const myString& other)
{
	logFile << "\naddEnd() function called adding string: " << str << " to: " << other.str;
	int newLength = length + other.length;
	char* newStr = new char[newLength + 1];
	copyString(str, newStr, length);
	copyString(other.str, newStr + length, other.length);
	releaseMemory();
	str = newStr;
	length = newLength;
	logFile << ", getting string: " << str;
}



void myString::allocateMemory(int size)
{
	logFile << "\nallocateMemory() function called with size: " << size;
	str = new char[size];
	if (str == nullptr) {
		status = 1; // Failure
		return;
	}


	status = 0; // Success
}



void myString::releaseMemory()
{
	logFile << "\nreleaseMemory() function called for string: " << str;
	delete[] str;
	str = nullptr;
	length = 0;
}



void myString::copyString(const char* src, char* destination, int length)
{
	logFile << "\ncopyString() function called with length: " << length;
	for (int i = 0; i <= length; i++)
	{
		destination[i] = src[i];
	}


	//destination[length] = '\0'; 
}



void myString::copyString(const char* string)
{
	logFile << "\ncopyString() function called with length: " << length;
	for (int i = 0; i <= length; i++)
	{
		str[i] = string[i];
	}

	str[length] = '\0';
}



void myString::copyString(const std::string string)
{
	logFile << "\ncopyString() function called with length: " << length;
	for (int i = 0; i <= length; i++)
	{
		str[i] = string[i];
	}

	str[length] = '\0';
}



void myString::printStringScreen() const
{
	logFile << "\nprintStringScreen function called for string: " << str;
	for (int i = 0; i < length; i++)
	{
		std::cout << str[i];
	}
}



std::string myString::partString(int startPos, int len) const
{
	while (startPos >= length || length == 0 || startPos + len > length)
	{
		std::cout << "\nOut of bounds. Please enter a new start position: ";
		std::cin >> startPos;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEnter a valid integer: ";
			std::cin >> startPos;
		}
		std::cout << "Enter the new length: ";
		std::cin >> len;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEnter a valid integer: ";
			std::cin >> len;
		}
	}

	std::string output = "";

	for (int i = startPos; i < startPos + len; i++)
	{
		output += str[i];
	}
	logFile << "\npartString() function called giving an output of: " << output;

	return output;


}




void myString::replPartString(const myString& other, int startPos, int len)
{
	while (len > other.length || startPos + len > length)
	{
		std::cout << "\nLength is out of bounds.\nEnter a new length: ";
		std::cin >> len;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEnter a valid integer: ";
			std::cin >> len;
		}
	}
	logFile << "\nreplPartString() function called with string: " << other.str << ", from postion: " << startPos << " and length: " << len;
	copyString(other.str + startPos, str + startPos, len);
}



void myString::replWholeString(const myString& other)
{
	releaseMemory();
	length = other.length;
	allocateMemory(length + 1);
	copyString(other.str);
	logFile << "\nreplWholeString() function called replacing string: "<<str<<" with string: "<<other.str;
}



int myString::compareString(const myString& other) const
{
	for (int i = 0; i < length && i < other.length; i++) {
		if (str[i] < other.str[i]) {
			return -1;
		}
		else if (str[i] > other.str[i]) {
			return 1;
		}
	}
	logFile << "\ncompareString() function called comparing string: " << str << " to string: " << other.str;

	if (length < other.length) {
		return -1;
	}
	else if (length > other.length) {
		return 1;
	}
	else {
		return 0;
	}

}



void myString::initString() {
	releaseMemory();
	length = 0;
	allocateMemory(1);
	str[0] = '\0';
	logFile << "\ninitString() function called";
}



void myString::setString(const std::string string) {
	releaseMemory();

	length = string.length();
	allocateMemory(length + 1);

	copyString(string);
	logFile << "\nsetString() function called setting string: " << str << " to string: " << string;
}



std::string myString::getString() const
{
	logFile << "\ngetString() function called returning: " << str;
	return str;
}



bool myString::numericString() const
{
	logFile << "\nnumericString() function called on string: " << str;
	for (unsigned int i = 0; i < length; i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}

	return true;
}



bool myString::alphabeticString() const
{
	logFile << "\nalphabeticString() function called on string: " << str;
	for (unsigned int i = 0; i < length; i++)
	{
		if (!isalpha(str[i]))
		{
			return false;
		}
	}

	return true;
}