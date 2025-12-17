#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

const char* cmd = "ls -l";

int main() {


  pid_t c_pid = fork();
  
  if(c_pid == -1){
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (c_pid > 0) {
    std::cout << "printed from process  " << getpid() << std::endl;
  } else {
    
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

    if(!pipe){
      throw std::runtime_error("popen failed");
    }
    std::cout << "Call ls from child process" << std::endl;
    while(fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr){
      result += buffer.data();
    }
    std::cout << "printed from child process   " << getpid() << std::endl;
    std::cout << "Result from cmd    " << result;
  }
  return 0;
}
