#pragma warning(disable : 4996)
#include "Logger.h"
#include <ctime>
#include <iostream>

/**
 * Logger.
 * 
 * Logger() - constructor opens file for writing, creating it if not present, appending to end of file (ie not erased)
 * ~Logger() - destructor closes file
 * writeLog() - writes the passed message (pointer to char) to the file, prepended with the current time
 * 
 * Notes:
 *    file open uses the Microsoft specific version
 *    ctime uses the legacy version, flagged as unsafe by Microsoft, hence the #pragma warning to suppress
 * 
 * Singleton pattern notes:
 *    Singleton pattern class - creating multiple instances that open the same file for writing would not work well
 *    approach - Eager instantiation - object created & stream opened as soon as program is started
 *      alternative approach: lazy instanciation - uses pointers instead, but has a different drawback on the destructor
 *    note "= delete" for copy & assignment constructors in header, ensures external callers MUST assign to a pointer object
 * 
 */

Logger Logger::m_singletonLoggerInstance;   // create the logger object, there will only be one
int Logger::m_numLoggerRefs = 0;    // initialize # of external references to zero

Logger::Logger()
{
	// fopen_s() is a microsoft specific function (ie not portable)
	//   note - Microsoft compiler considers fopen() as unsafe & throws a compile error
	//     error can be suppressed, or we can use the Microsoft specific function
	std::cout << __FUNCSIG__ << std::endl;
	fopen_s(&m_pStream, LOGFILE, "a");

}

//  Destructor - only close the stream once there are no more external references to the logger
Logger::~Logger()
{
	std::cout << __FUNCSIG__ << std::endl; 
	m_numLoggerRefs--;
	if (m_numLoggerRefs == 0) {
		fclose(m_pStream);
	}
}

//  returns a handle to the object, callers cannot create the object directly
Logger& Logger::loggerInstance()
{
	// assume each call will be a separate reference, track # open references
	m_numLoggerRefs++;
	return m_singletonLoggerInstance;
}


// write message into the file & flush to ensure message isn't lost on a crash
void Logger::writeLog(const char* pMessage)
{
	// create timestamp
	//    get the current time & convert to local time - then print to the file
	//    note: formatting uses '02' to always print two places with leading zeros if a single digit
	std::time_t now = std::time(nullptr);
	std::tm* local_tm = std::localtime(&now);
	fprintf(m_pStream, "%d-%d-%02d %d:%02d", 1900 + local_tm->tm_year, 1 + local_tm->tm_mon, local_tm->tm_mday,
		local_tm->tm_hour, local_tm->tm_min);

	// print the message to the file and flush
	fprintf(m_pStream, "  %s\n", pMessage);
	fflush(m_pStream);
}
