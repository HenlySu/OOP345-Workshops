/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

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
      carBrand = nullptr;
      carModel = nullptr;
      carYear = 0;
      carStatus = '\0';
      carPromotion = false;
   }
   void Cars::read(std::istream& is) {

      char promotion = '\0';
      char tempBrand[100];
      char tempModel[100];

      if (is.good()){
         is >> carStatus;
         is.ignore();
         is.get(tempBrand, 100, ',');
         is.ignore();
         is.get(tempModel, 100, ',');
         is.ignore();
         is >> carYear;
         is.ignore();
         is >> carPrice;
         is.ignore();
         is >> promotion;
         is.ignore();

         carPromotion = promotion == 'Y' ? true : false;

         delete[] carBrand;
         delete[] carModel;
         carBrand = nullptr;
         carModel = nullptr;
         carBrand = new char[strlen(tempBrand) + 1];
         carModel = new char[strlen(tempModel) + 1];
         strcpy(carBrand, tempBrand);
         strcpy(carModel, tempModel);
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

   //Rule of three
   Cars::Cars(const Cars& car) {
      carBrand = nullptr;
      *this = car;
   }
   Cars& Cars::operator = (const Cars& car) {
      if (this != &car) {
         carPrice = car.carPrice;

         delete[] carBrand;
         carBrand = nullptr;
         carBrand = new char[strlen(car.carBrand) + 1];
         strcpy(carBrand, car.carBrand);

         delete[] carModel;
         carModel = nullptr;
         carModel = new char[strlen(car.carModel) + 1];
         strcpy(carModel, car.carModel);

         carYear = car.carYear;
         carStatus = car.carStatus;
         carPromotion = car.carPromotion;
      }
      return *this;
   }
   Cars::~Cars() {
      delete[] carBrand;
      carBrand = nullptr;

      delete[] carModel;
      carModel = nullptr;
   }

   Cars::operator bool() const {
      return carStatus == 'N' ? true : false;
   }

   void operator >> (const Cars& car, Cars& car1) {
      car1 = car;
   }

   std::istream& operator >> (std::istream& is, Cars& car) {
      car.read(is);
      return is;
   }
}