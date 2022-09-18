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
   void listArgs(int argc, char* argv[]);

   class Cars {
   private:
      double carPrice;
      char carBrand[10];
      char carModel[15];
      int carYear;
      char carStatus;
      bool carPromotion;
   public:
      Cars();
      void read(std::istream& is);
      void display(bool reset);
      char getStatus();
   };
}
extern double g_taxrate;
extern double g_discount;
#endif // !CARADS_H