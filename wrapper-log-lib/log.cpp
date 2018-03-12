#include <cstring>
#include <exception>
#include <iostream>
#include <string>

#include "log.h"
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicConfigurator.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>


log4cpp::Category* TLogger::logger = NULL;
log4cpp::Appender* TLogger::appender = NULL;

std::stringstream* TLogger::logStream = NULL;

void TLogger::Init(std::ostream* outputStream,
  const log4cpp::Priority::PriorityLevel threshold,
  const std::string& pattern)
{
  if (logger == NULL)
  {
    logger = &log4cpp::Category::getRoot();
  }
  if (outputStream == NULL)
  {
    log4cpp::BasicConfigurator::configure();
  }
  else
  {
    if (!*outputStream)
    {
      throw std::runtime_error("Passed stream is not opened for writing.");
    }

    appender = new log4cpp::OstreamAppender("os", outputStream);
    log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
    layout->setConversionPattern(pattern);
    appender->setLayout(layout);

    GetLogger().addAppender(appender);
    GetLogger().setPriority(threshold);
  }
}

log4cpp::Category& TLogger::GetLogger()
{
  if (logger == NULL)
  {
    logger = &log4cpp::Category::getRoot();
    logStream = new std::stringstream;
    Init(logStream, EPriority::DEBUG);
  }
  return *logger;
}
