#include "Parser.h"
#include <iostream>

/**
 * Parser - demonstrating rudimentary parser, especially contrast between using literals and using Enums
 * 
 * Four different variations - from dumb get input & return it, to creating a messaging structure to pass between objects
 * 
 *   writeOutputGetInputReturnString(string) - prints message & returns the user input literal (no validation)
 *   writeOutputGetInputReturnStringValidated(string) - prints message, but validates the user input before returning it
 *   writeOutputGetInputReturnCommand(string) - prints message & returns an enum with a fixed number of values based on user input
 *   writeOutputGetInputReturnMessage(string) - prints message, but returns a structure with the command enum as well as the user input
 * 
 */

Parser::Parser() {
	// empty constructor
}

// function to do a write to console & return everything the user entered
std::string Parser::writeOutputGetInputReturnString(std::string messageToOutput) {
	std::string userInput;

	std::cout << messageToOutput;
	std::cin >> userInput;
	return userInput;
}


// print message & returns the user input if valid, otherwise return "Error"
std::string Parser::writeOutputGetInputReturnStringValidated(std::string messageToOutput) {
	std::string userInput;

	userInput = writeOutputGetInputReturnString(messageToOutput);
	if (userInput == "East" || userInput == "West" || userInput == "South" || userInput == "North" || userInput == "Quit")
		return userInput;
	else
		return "Error";
}



// print message & return an enum with a fixed number of values based on user input
Parser::Command Parser::writeOutputGetInputReturnCommand(std::string messageToOutput) {
	std::string userInput;
	Command inputCommand;

	// only execute if there is something to write to console, otherwise being called as a helper function
	userInput = writeOutputGetInputReturnString(messageToOutput);

	inputCommand = parseInput(userInput);
	return inputCommand;
}

// return a message that includes both the string the user typed & an enum identifying the parsed command
Parser::Message Parser::writeOutputGetInputReturnMessage(std::string messageToOutput) {
	std::string userInput;
	Command inputCommand;
	Message interObjectMessage;

	interObjectMessage.userInputString = writeOutputGetInputReturnString(messageToOutput);
	interObjectMessage.userCommand = parseInput(interObjectMessage.userInputString);
	return interObjectMessage;
}

// helper function to parse the input into a command (enum)

Parser::Command Parser::parseInput(std::string inputString) {
	Command inputCommand;

	if (inputString == "East") inputCommand = East;
	else if (inputString == "West") inputCommand = West;
	else if (inputString == "North") inputCommand = North;
	else if (inputString == "South") inputCommand = South;
	else if (inputString == "Quit") inputCommand = Quit;
	else inputCommand = Error;
	return inputCommand;
}






