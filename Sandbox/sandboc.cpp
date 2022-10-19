#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
   std::ifstream file("books.txt");
   std::string line{};

   std::string bad[6];
   std::string good[6];

      if (file) {

         size_t i = 0;

         for(size_t i =0; i < 6; i++){
            getline(file, bad[i], ' ');
            bad[i].erase(0, bad[i].find_first_not_of(' '));
            bad[i].erase(bad[i].find_last_not_of(' ') + 1);

            getline(file, good[i], '\n');
            good[i].erase(0, good[i].find_first_not_of(' '));
            good[i].erase(good[i].find_last_not_of(' ') + 1);
         }
         file.close();
      }

   for (int i = 0; i < 6; i++) {
      std::cout << setw(10) << left << bad[i] << setw(10) << right << good[i] << std::endl;
   }

   return 0;
}
