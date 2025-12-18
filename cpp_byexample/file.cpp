#include <fstream>

int main(){
  std::ofstream output("example.txt");
  output << "THis is a test do not be alarmed\n";
  output << "One more test";
}
