//Source.cpp

#include "myString.h"
#include <fstream>

int main()
{
	std::ofstream outFile("output.txt"); 
	outFile << "OUTPUT FILE";

	myString str("test");
	std::cout << "\nTesting print: ";
	str.printStringScreen();
	outFile << "\n\nTesting print: ";
	outFile << str.getString();
	
	std::cout << std::endl;
	myString ing("ing");
	str.addEnd(ing);
	std::cout << "\nTesting addEnd: ";
	str.printStringScreen();
	outFile << "\n\nTesting addEnd: ";
	outFile << str.getString();

	
	std::cout << std::endl;
	str.addStart(ing);
	std::cout << "\nTesting addStart: ";
	str.printStringScreen();
	outFile << "\n\nTesting addStart: ";
	outFile << str.getString();
	
	std::cout << std::endl<<"\nTesting partString with out of bound values: ";
	std::cout << str.partString(3, 11);
	outFile << "\n\nTesting partString with out of bound values (after they are corrected): ";
	outFile << str.getString();

	str.setString("----------");
	std::cout << std::endl;
	myString animal("animal");
	str.replPartString(animal, 3, 2);
	std::cout << "\nTesting replPartString with string animal: ";
	str.printStringScreen();
	outFile << "\n\nTesting replPartString with string animal: ";
	outFile << str.getString();

	std::cout << std::endl;
	myString name("name");
	std::cout << "\nTesting replWholeString (should change str string to name): ";
	str.replWholeString(name);
	str.printStringScreen();

	std::cout << std::endl;
	std::cout << "\nTesting compare string ";
	std::cout<<"\nstr is the same as name (should be 0): "<< str.compareString(name);
	std::cout<<"\nstr is the same as animal (should be 1): " << str.compareString(animal);
	outFile << std::endl;
	outFile << "\nTesting compare string ";
	outFile << "\nstr is the same as name (should be 0): " << str.compareString(name);
	outFile << "\nstr is the same as animal (should be 1): " << str.compareString(animal);

	std::cout << "\n\nAnimal before resetting string: ";
	outFile << "\n\nAnimal before resetting string: ";
	animal.printStringScreen();
	outFile << animal.getString();
	animal.initString();
	std::cout << "\n\nAnimal after resetting string: ";
	animal.printStringScreen();
	outFile << animal.getString();

	//continue outFile HERE ---------------------------

	myString ladder("ladder");
	std::cout << "\n\nTesting setStr on animal, assigning ladder string to it: ";
	std::cout << "\nAnimal before setString (should be empty): ";
	outFile << "\n\nTesting setStr on animal, assigning ladder string to it: ";
	outFile << "\nAnimal before setString (should be empty): ";
	animal.printStringScreen();
	outFile << animal.getString();
	animal.setString(ladder.getString());
	std::cout << "\nAnimal after setString: ";
	outFile << "\nAnimal after setString: ";
	animal.printStringScreen();
	outFile << animal.getString();

	std::cout << "\n\nTesting getString on ladder: ";
	outFile << "\n\nTesting getString on ladder: ";
	std::cout << ladder.getString();
	outFile << ladder.getString();

	std::cout << "\n\nTesting numericString and alphabeticString";
	outFile << "\n\nTesting numericString and alphabeticString";
	myString number1("12345");
	std::cout << "\nIs ladder numeric (should be 0): " << ladder.numericString();
	std::cout << "\nIs number1 numeric (should be 1): " << number1.numericString();
	std::cout << "\nIs ladder alphabetic (should be 1): " << ladder.alphabeticString();
	std::cout << "\nIs number1 alphabetic (should be 0): " << number1.alphabeticString();
	outFile << "\nIs ladder numeric (should be 0): " << ladder.numericString();
	outFile << "\nIs number1 numeric (should be 1): " << number1.numericString();
	outFile << "\nIs ladder alphabetic (should be 1): " << ladder.alphabeticString();
	outFile << "\nIs number1 alphabetic (should be 0): " << number1.alphabeticString();


	outFile.close();
	logFile.close();

	std::cout << "\n\n\n";
	return 0;
}