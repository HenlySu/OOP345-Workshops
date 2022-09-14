/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef CARADS_H
#define CARADS_H

#include <iostream>

namespace sdds {

   void listArgs(int argc, char* argv[], char* env[]);

   extern double g_taxrate = 0.0;
   extern double g_discount = 0.0;

   class Cars {
   private:
      char carBrand[10]{};
      char carModel[15]{};
      int carYear = 0;
      double carPrice = 0.0;
      char carStatus = '\0';
      bool carPromotion = false;
   public:
      Cars();
      void read(std::istream& is); 
      void display(bool reset);
      char getStatus();
   };
}
#endif // !CARADS_H