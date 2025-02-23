#include "processor.h"
#include "linux_parser.h"
#include <vector>
#include <string>

using std::vector;
using std::string;


// REFERENCE:https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
float Processor::Utilization() {
  vector<string> utilizations =LinuxParser::CpuUtilization();
  long user = stol(utilizations[0]);
  long nice = stol(utilizations[1]);
  long system = stol(utilizations[2]);
  long idle = stol(utilizations[3]);
  long iowait = stol(utilizations[4]);
  long irq = stol(utilizations[5]);
  long softirq = stol(utilizations[6]);
  long steal = stol(utilizations[7]);


  long PrevIdle = _last_idle + _last_iowait;
  long Idle = idle + iowait;
  long PrevNonIdle = _last_user + _last_nice + _last_system + _last_irq +
                     _last_softirq + _last_steal;
  long NonIdle = user + nice + system + irq + softirq +
                 steal;

  long PrevTotal = PrevIdle + PrevNonIdle ;
  long Total = Idle + NonIdle;

  // differentiate: actual value minus the previous one
  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;

  _last_user = user;
  _last_nice = nice;
  _last_system = system;
  _last_idle = idle;
  _last_iowait = iowait;
  _last_irq = irq;
  _last_softirq = softirq;
  _last_steal = steal;

  return (totald - idled) / totald;
}
