#include<iostream>
#include<string>
#include<fstream>

struct DBRow{
  int ID;
  std::string name;
  int price;
};

class DumbDB {
  public:
    DumbDB(){
      std::cout << "Starting database....";
      std::ofstream database("database.txt");
      if(database.is_open()){
        DBRow dr;
        dr.ID = 0;
        dr.name = "test";
        dr.price = 100;
        database << dr.ID << "," << dr.name << "," << dr.price << std::endl; // std::endl adds a newline character
        database.close();
      }

    }
    void write_row(){
                      
    }
    void load(){

    }

};
int main(){
  DumbDB db;
  return 0;
}
