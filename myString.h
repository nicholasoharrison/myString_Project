//myString.h

#pragma once
#include <iostream>
#include <string>
#include <fstream>

static std::ofstream logFile("logFile.txt");

class myString
{

	private:
		// Attributes
		char* str;
		int length;
		int status;

		// Private methods
		void allocateMemory(int size);
		void releaseMemory();
		void copyString(const char* str, char* destination, int length);
		void copyString(const char* string);
		void copyString(const std::string str);

	public:
		// Constructors
		myString(const std::string& str);
		myString(const myString& other);

		// Destructor
		~myString();

		// Methods
		int size() const;
		void addStart(const myString& other);
		void addEnd(const myString& other);
		std::string partString(int startPos, int length) const;
		void replPartString(const myString& other, int startPos, int length);
		void replWholeString(const myString& other);
		int compareString(const myString& other) const;
		void initString();
		void setString(const std::string str);
		std::string getString() const;
		void printStringScreen() const;
		bool numericString() const;
		bool alphabeticString() const;


};

