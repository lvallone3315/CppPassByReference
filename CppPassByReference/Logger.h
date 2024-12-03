#pragma once
#include <cstdio>

class Logger
{
private:
	FILE* m_pStream;             // m_ indicates private class member variables
	const char* LOGFILE = "LogFile.txt";
	static Logger m_singletonLoggerInstance;     // singleton instance of Parser
	static int m_numLoggerRefs;              // track # of references, so don't close file until all refs closed

	Logger();    // constructor creates/opens file for writing

public:
	~Logger();   // destructor closes file
	void writeLog(const char* pMessage);   // write string to the log, along with a timestamp
	static Logger& loggerInstance();

	// don't allow external users to create a logger via the copy & assignment commands
	Logger(const Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
};