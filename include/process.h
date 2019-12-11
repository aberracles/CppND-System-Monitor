#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();
  std::string User();
  std::string Command();
  float CpuUtilization();
  std::string Ram();
  long int UpTime();
  void CpuUtilization(float value);
  void Ram(std::string value);
  void UpTime(long int value);
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  Process(int pid);



  // TODO: Declare any necessary private members
 private:
  int _pid;
  std::string _user;
  std::string _command;
  float _cpuUtilization;
  std::string _ram;
  long int _upTime;
};

#endif
