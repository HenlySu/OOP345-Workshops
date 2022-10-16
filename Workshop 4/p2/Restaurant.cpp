/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Restaurant.h"

namespace sdds {
   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
      if (reservations) {
         resCnt = cnt;
         reservation = new Reservation * [resCnt];

         for (size_t i = 0; i < resCnt; i++) {
            reservation[i] = new Reservation(*reservations[i]);
         }
      }
   }

   size_t Restaurant::size() const{
      return resCnt;
   }

   //Rule of three
   Restaurant::Restaurant(const Restaurant& obj){
      *this = obj;
   }

   Restaurant& Restaurant::operator = (const Restaurant& obj){
      if (this != &obj) {
         delete[] reservation;
         reservation = nullptr;
         
         resCnt = obj.resCnt;
         reservation = new Reservation * [resCnt];

         for (size_t i = 0u; i < resCnt; i++) {
            reservation[i] = obj.reservation[i];
         }
      }
      return *this;
   }

   Restaurant::~Restaurant(){
      /*for (size_t i = 0; i < resCnt; i++) {         //Program crashes
         delete reservation[i];
      }*/

      delete[] reservation;
   }

   //Rule of five
   Restaurant::Restaurant(Restaurant&& obj) noexcept {
      *this = std::move(obj);
   }

   Restaurant& Restaurant::operator = (Restaurant&& obj) noexcept {
      if (this != &obj) {
         delete[] reservation;
         reservation = nullptr;
         
         reservation = obj.reservation;
         resCnt = obj.resCnt;
         
         obj.reservation = nullptr;
         obj.resCnt = 0u;
      }
      return *this;
   }

   std::ostream& operator << (std::ostream& os, const Restaurant& res) {
      static size_t counter = 0u;

      os << "--------------------------\n"
         << "Fancy Restaurant (" << ++counter
         << ")\n--------------------------\n";

      if (res.resCnt == 0){
         os << "This restaurant is empty!\n";
      }
      else {
         for (size_t i = 0; i < res.resCnt; ++i) {
            os << *res.reservation[i];
         }
      }

      os << "--------------------------\n";
      return os;
   }
}