#include <string>
#include <time.h>
#include<sstream>
#include <iomanip>
#include "format.h"

using std::string;


// Reference: https://rstopup.com/convertir-segundos-a-dias-minutos-y-segundos.html
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
  time_t tSeconds(seconds);
  tm *time = gmtime(&tSeconds);
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(2) << time->tm_hour << ":"
     << std::setfill('0') << std::setw(2) << time->tm_min << ":"
     << std::setfill('0') << std::setw(2) << time->tm_sec;
  return ss.str();
}
