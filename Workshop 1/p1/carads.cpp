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

   double g_discount = 0;
   double g_taxrate = 0;

   void listArgs(int argc, char* argv[]) {
      std::cout << "Command Line:\n"
         << "--------------------------\n";
      for (int i = 0; i < argc; i++) {
         std::cout << std::setw(3) << i + 1 << ": " << argv[i] << std::endl;
      }
      std::cout << "--------------------------\n\n";
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

      char promotion = '\0';

      if (is.good()){
         is >> carStatus;
         is.ignore();
         is.get(carBrand, 10, ',');
         is.ignore();
         is.get(carModel, 15, ',');
         is.ignore();
         is >> carYear;
         is.ignore();
         is >> carPrice;
         is.ignore();
         is >> promotion;
         is.ignore();

         carPromotion = promotion == 'Y' ? true : false;
      }
   }
   void Cars::display(bool reset) {

      static int counter = 0;

      reset == true ? counter = 0 : counter;

      std::cout << std::setw(2) << std::left << ++counter << ". ";

      if (carBrand[0]) {
         std::cout << std::setw(10) << std::left << carBrand << "| ";
         std::cout << std::setw(15) << std::left << carModel << "| ";
         std::cout << std::setw(4) << std::right << carYear << " |";
         std::cout << std::setw(12) << std::fixed << std::setprecision(2) << std::right << carPrice * (g_taxrate + 1) << "|";

         if (carPromotion) {
            std::cout << std::setw(12) << std::fixed << std::setprecision(2) << std::right << carPrice * (g_taxrate + 1) * (1 - g_discount);
         }
         std::cout << std::endl;
      }
      else {
         std::cout << "No Car" << std::endl;
      }
   }

   char Cars::getStatus() {
      return carStatus;
   }
}