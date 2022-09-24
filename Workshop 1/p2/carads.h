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
   class Cars {
   private:
      double carPrice;
      char* carBrand;
      char* carModel;
      int carYear;
      char carStatus;
      bool carPromotion;
   public:
      Cars();
      void read(std::istream& is);
      void display(bool reset);
      char getStatus();

      //Rule of three
      Cars(const Cars& car);
      Cars& operator = (const Cars& car);
      ~Cars();

      operator bool() const;
   };
   void listArgs(int argc, char* argv[]);
   void operator >> (const Cars& car, Cars& car1);
   std::istream& operator >> (std::istream& is, Cars& car);

   extern double g_taxrate;
   extern double g_discount;
}
#endif // !CARADS_H