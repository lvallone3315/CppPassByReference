#pragma once

#include <string>

class Parser
{

public:
	enum Command { North, South, East, West, Quit, Error };

	struct Message {
		Command userCommand;
		std::string userInputString;
	};
	
	Parser();
	std::string writeOutputGetInputReturnString(std::string);   // function to write string to console, returns user input as a string
	std::string writeOutputGetInputReturnStringValidated(std::string); // writes string to console, returns user input as a string
	Command writeOutputGetInputReturnCommand(std::string);       // writes string to console, returns enum parsing of user input
	Message writeOutputGetInputReturnMessage(std::string);       // writes string to console, returns a message containing both the enum and the user input

private:
	Command parseInput(std::string);      // helper function to parse string into a command
};

