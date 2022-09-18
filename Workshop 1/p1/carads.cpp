/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <iostream>
#include <iomanip>

#include "carads.h"

namespace sdds {
   void listArgs(int argc, char* argv[]) {
      std::cout << "Commmand Line:\n"
         << "--------------------------";
      for (int i = 0; i < argc; i++) {
         std::cout << i + 1 << ": " << argv[i] << std::endl;
      }
   }

   Cars::Cars() {
      carPrice = 0.0;
      carBrand[0] = '\0';
      carModel[0] = '\0';
      carYear = 0;
      carStatus = '\0';
      carPromotion = false;
   }
   void Cars::read(std::istream& is) {
      if (!is.fail()) {
         is >> carStatus;
         is.get();
         is >> carBrand;
         is.get();
         is >> carModel;
         is.get();
         is >> carYear;
         is.get();
         is >> carPrice;
         is.get();
         is >> carPromotion;
         is.get();
      }
   //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
   }
   void Cars::display(bool reset) {
      static int counter = 0;
      std::cout.width(2);
      std::cout << counter;
      std::cout.width(10);
      std::cout << carBrand;
      std::cout.width(15);
      std::cout << carModel;
      std::cout.width(4);
      std::cout << carYear;
      std::cout.setf(std::ios::fixed);
      std::cout.width(12);
      std::cout.precision(2);
      std::cout << carPrice;
      std::cout.width(12);
      if (carPromotion = true) {
         std::cout << carPrice * 0.9;
      }
   }
   char Cars::getStatus() {
      return carStatus;
   }
}