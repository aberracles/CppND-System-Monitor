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
  try {
    time_t tSeconds(seconds);
    tm *time = gmtime(&tSeconds);
    if (time == nullptr) {
      return "00:00:00";
    }
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << time->tm_hour << ":"
       << std::setfill('0') << std::setw(2) << time->tm_min << ":"
       << std::setfill('0') << std::setw(2) << time->tm_sec;
    return ss.str();
  } catch (...) {
    return "00:00:00";
  }
}
