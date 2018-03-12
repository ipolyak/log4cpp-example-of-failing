#ifndef LOG_H_
#define LOG_H_

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/Priority.hh>

class TLogger
{
public:
  typedef log4cpp::Priority EPriority;

  static void Init(std::ostream* outputStream = &std::cout,
    const EPriority::PriorityLevel threshold = log4cpp::Priority::INFO,
    const std::string& pattern = "%d %p : %m%n");

  static log4cpp::Category& GetLogger();
private:
  static log4cpp::Category* logger;

  static log4cpp::Appender* appender;

  static std::stringstream* logStream;
};

#endif /* LOG_H_ */
