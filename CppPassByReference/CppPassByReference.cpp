// CppPassByReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Scope.h"
#include "Parser.h"

class TwoInts {
public:
    int a;
    int b;
}; 

void swap(int, int);
void swapC(TwoInts);
void swapByReference(int&, int&);
void swapCByReference(TwoInts&);
TwoInts swapByNewInstance(TwoInts);
void demoArgumentPassing();
void demoScope();
void demoParsingUserInput();



int main()
{
    // Playing with singleton design pattern - only a single parser
    Parser& parser = Parser::parserInstance();  // correct access to singleton

    // Compiler won't let you do this, constructor is private
    //  Parser parserIncorrectSingletonCreation;

    // Let's create a 2nd version and verify the addresses are the same
    std::cout << "\t\tDemo Singleton Object\n\n";
    std::cout << "parser address is: " << &parser << std::endl;
    Parser& parserSecondInstance = Parser::parserInstance();
    std::cout << "second instance of parser address is: " << &parser << std::endl << std::endl;

    // back to the rest of the demo
    std::string userMessage = "\n\nEnter type of example to demo - Arguments, Scope, Parsing, or Quit to exit: ";
    Parser::Message messageObject;

    // created a parser - might as well use it :)

    do
    {
        messageObject = parser.writeOutputGetInputReturnMessage(userMessage);
        switch (messageObject.userCommand) {
        case Parser::SCOPE:
            std::cout << "\n\t\t*** Demo'ing Variable Scope ***\n\n";
            demoScope();
            break;
        case Parser::ARG_PASSING:
            std::cout << "\n\t\t*** Demo'ing Argument passing by value & reference ***\n\n";
            demoArgumentPassing();
            break;
        case Parser::PARSING:
            std::cout << "\n\t\t*** Demo'ing Parsing user input ***\n\n";
            demoParsingUserInput();
            break;
        default:
            std::cout << "\t invalid command entered: " << messageObject.userInputString << "try again or type Quit to exit\n\n";
        }
    } while (messageObject.userCommand != Parser::QUIT);
}


// Argument passing by value & reference
void demoArgumentPassing() {

    std::cout << "\t\tSwap Program Demonstrating C++ Pass by Value & Pass by Reference!\n\n";

    std::cout << "\n\t First two scenarios: pass integer vars by value, then by reference\n";
    std::cout << "\t Second two scenarios: pass an object of type TwoInts by value, then by reference\n\n\n";
    std::cout << "\tC++ swap by reference, in called function/method add & between type and param name\n";
    std::cout << "\t\tfor example: swap(int a, int b) vs. swap (int& a, int& a)\n\n";

    int a2 = 1;
    int b3 = 99;

    std::cout << "\tSwap\t\t\t\ta2 = " << a2 << "\t\tb3 = " << b3 << "\n";
    std::cout << "\tMemory addresses: \t\ta2 = " << &a2 << "\tb3 = " << &b3 << "\n\n";
    std::cout << "\t\t\t       Correct Result \t\t\t       Wrong Result\n";
    std::cout << "\t\t\t   a = " << b3 << "\tb = " << a2;
    std::cout << "\t\t\t   a = " << a2 << "\tb = " << b3 << "\n\n";
    system("pause");


    swap(a2, b3);
    std::cout << "\tPass by value result: \t\t\ta = " << a2 << "\tb = " << b3 << "\n\n";
    system("pause");

    a2 = 1;
    b3 = 99;

    swapByReference(a2, b3);
    std::cout << "\tPass by reference result: \t\ta = " << a2 << "\tb = " << b3 << "\n";
    system("pause");



    // Same concept - but passing an object (ie TwoInts) instead of discrete variables

    TwoInts ab;
    ab.a = 1;
    ab.b = 99;

    std::cout << "\n\n*** Same concept - but pass object instead of discrete variables ***\n";
    std::cout << "\tSwap object\t\t\tab.a = " << ab.a << "\t\tab.b = " << ab.b << "\n";
    std::cout << "\tMemory addresses: \t\tab.a = " << &ab.a << "\t\tab.b = " << &ab.b << "\n\n";

    swapC(ab);
    std::cout << "\tMain TwoInts swap result: \t\ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");


    ab.a = 1;
    ab.b = 99;
    swapCByReference(ab);
    std::cout << "\tMain TwoInts Ref swap result: \t\ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");

    ab.a = 1;
    ab.b = 99;
    ab = swapByNewInstance(ab);
    std::cout << "\tPost assign - Struct ab mem addresses: \t\tab = " << &ab << "\t .a = " << &ab.a << "\t.b = " << &ab.b << "\n\n";
    std::cout << "\tMain TwoInts Instance swap result: \ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");
}


// Scope section

void demoScope() {
    std::cout << "\n\nDemonstrate some fundamental variable scope behaviors\n";
    std::cout << "\t\tCreate TWO scope objects\n\t\t\t1st: default global VaR = 100\n\t\t\t2nd: global Var = 200\n\n";
    system("pause");

    Scope scope;
    Scope scope2(200);

    std::cout << "\t*** Display details of 1st scope object (" << &scope << ") ***/n";
    scope.showScope();
    std::cout << "\n\t*** Display details of 2nd scope object (" << &scope2 << ") ***/n";
    scope2.showScope();

    system("pause");
    scope.showGlobalScope();

    extern void showFileScope();  // not part of class, hence not in Scope.h, could declare in Scope.h - but that would be misleading
    showFileScope();
}


    /**
     * this next section demonstrates a rudimentary parser (singleton instance)
     * 
     * start with
     *    using strings to input directions without validation, then
     *    using strings with basic validation, then
     *    parsing the input string into a command (enum) and finally,
     *    returning a message (structure) including both the raw input and the command
     */
    // start with just using strings to input directions
    //    uses a singleton parser
void demoParsingUserInput() {
    Parser &parser = Parser::parserInstance();
    std::string userMessage = "Enter type of example to demo - Arguments, Scope, Parsing, or Quit to exit: ";
    std::string userInput;

    std::cout << "\n\n*** Write output, ask user to input a string ***\n";
    while ((userInput = parser.writeOutputGetInputReturnString(userMessage)) != "Quit") {
        std::cout << "\tYou entered: *" << userInput << "*\n";
    }

    // validated
    std::cout << "\n\n*** Write output, ask user to input a string, but validate - case sensitive ***\n";
    while ((userInput = parser.writeOutputGetInputReturnStringValidated(userMessage)) != "Quit") {
        std::cout << "\tYou entered: " << userInput << "\n";
    }

    // enum
    Parser::Command command;
    std::cout << "\n\n*** Write output, ask user to input a string, but parse into a command (enum) ***\n";
    while ((command = parser.writeOutputGetInputReturnCommand(userMessage)) != Parser::QUIT) {
        switch (command) {
            case Parser::SCOPE:
                std::cout << "\tYou entered: Scope\n";
                break;
            default:
                std::cout << "\tsomething else was entered\n";

        }
    }

    // message object
    Parser::Message messageObject;
    std::cout << "\n\n*** Write output, ask user to input a string, but parse into a message object ***\n";
    do 
    {
        messageObject = parser.writeOutputGetInputReturnMessage(userMessage);
        switch (messageObject.userCommand) {
        case Parser::SCOPE:
            std::cout << "\tYou entered: " << messageObject.userInputString << "\n";
            std::cout << "\t\t command is Scope\n\n";
            break;
        default:
            std::cout << "\t something other than Scope was entered: " << messageObject.userInputString << "\n";
        }
    } while (messageObject.userCommand != Parser::QUIT);
}



// helper functions for swapping demo

void swap(int a, int b) {
    int temp;
    std::cout << "*** Swap two variables - by value:";
    std::cout << "\n\tPass by value Memory: \ta = " << &a << "\tb = " << &b << "\n";
    temp = a;
    a = b;
    b = temp;
}

void swapByReference(int& a, int& b) {
    int temp;

    std::cout << "\n*** Swap two variables - by Reference:";
    std::cout << "\n\tPass by ref Memory: \ta = " << &a << "\tb = " << &b << "\n";
    temp = a;
    a = b;
    b = temp;
}

void swapC(TwoInts numbersToSwap) {
    int temp;
    std::cout << "\n*** Swap twoInts object - by Value*\n";
    std::cout << "\n\tPass an instance by value memory addresses: \ta = " << &numbersToSwap.a << "\tb = " << &numbersToSwap.b << "\n";
    temp = numbersToSwap.a;
    numbersToSwap.a = numbersToSwap.b;
    numbersToSwap.b = temp;

    //

}



void swapCByReference(TwoInts& numbersToSwap) {
    int temp;
    std::cout << "\n*** Swap twoInts object - by Reference*\n";
    std::cout << "\n\tPass an instance by reference memory addresses: \ta = " << &numbersToSwap.a << "\tb = " << &numbersToSwap.b << "\n";
    temp = numbersToSwap.a;
    numbersToSwap.a = numbersToSwap.b;
    numbersToSwap.b = temp;
}


// Create a new instance of TwoInts and return to calling routine
// Note: new instance is created on the stack, 
//    but compiler will copy into the calling structure before nuking the temporary instance
TwoInts swapByNewInstance(TwoInts numbersToSwap) {
    TwoInts tempTwoInts;

    std::cout << "\n*** Create a new instance of TwoInts and return to calling routine\n";
    tempTwoInts.b = numbersToSwap.a;
    tempTwoInts.a = numbersToSwap.b;
    std::cout << "\n\tStruct temp object mem addresses: \ttempTwoInts = " << &tempTwoInts << "\t .a = " << &tempTwoInts.a << "\t .b = " << &tempTwoInts.b << "\n";
    return tempTwoInts;
}