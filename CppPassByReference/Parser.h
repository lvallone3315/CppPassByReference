#pragma once

#include <string>

/**
 * Parser using a Singleton design pattern
 */

class Parser
{

public:
	enum Command { ARG_PASSING, SCOPE, PARSING, QUIT, ERROR };

	struct Message {
		Command userCommand;
		std::string userInputString;
	};
	
	static Parser& parserInstance();                            // returns a pointer to the Parser instance
	std::string writeOutputGetInputReturnString(std::string);   // function to write string to console, returns user input as a string
	std::string writeOutputGetInputReturnStringValidated(std::string); // writes string to console, returns user input as a string
	Command writeOutputGetInputReturnCommand(std::string);       // writes string to console, returns enum parsing of user input
	Message writeOutputGetInputReturnMessage(std::string);       // writes string to console, returns a message containing both the enum and the user input

private:
	Parser() = default;  // constructor - private, to ensure only a single copy created
	static Parser singletonInstance;     // singleton instance of Parser
	Command parseInput(std::string);      // helper function to parse string into a command
};

