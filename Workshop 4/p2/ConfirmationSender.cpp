/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
   //Constructor
   ConfirmationSender::ConfirmationSender() {
      reservation = nullptr;
      resCnt = 0u;
   }

   //Rule of three
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj) {
      *this = obj;
   }
   ConfirmationSender& ConfirmationSender::operator = (const ConfirmationSender& obj) {
      if (this != &obj) {
         delete[] reservation;
         resCnt = obj.resCnt;

         reservation = new Reservation*[resCnt];

         for (size_t i = 0; i < resCnt; i++) {
            reservation[i] = obj.reservation[i];
         }
      }
   }
   ConfirmationSender::~ConfirmationSender() {
      delete[] reservation;
      reservation = nullptr;
   }

   //Rule of five
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj) noexcept {
      *this = std::move(obj);
   }
   ConfirmationSender& ConfirmationSender::operator = (ConfirmationSender&& obj) noexcept {
      if (this != &obj) {
         delete[] reservation;
         resCnt = obj.resCnt;

         reservation = obj.reservation;

         obj.reservation = nullptr;
         obj.resCnt = 0u;
      }
      return *this;
   }


   ConfirmationSender& ConfirmationSender::operator += (const Reservation& res){
      if (!inArray(res)) {
         const Reservation** temp;
         temp = new const Reservation*[resCnt++];

         for (size_t i = 0; i < resCnt; i++) {
            temp[i] = reservation[i];
         }

         temp[resCnt] = &res;

         delete[] reservation;
         reservation = nullptr;
         
         reservation = temp;
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator -= (const Reservation& res){
      
      size_t index = 0;

      if (inArray(res, index)) {
         for (size_t i = 0; i < resCnt; i++) {
            if (reservation[i] == &res) {
               reservation[i] = nullptr;
            }
         }

         //Challenge to resize the array
         const Reservation** temp;
         temp = new const Reservation *[resCnt - 1];

         for (size_t i = 0; i < index - 1; i++) {
            temp[i] = reservation[i];
         }

         for (size_t i = index + 1; i < resCnt; i++) {
            temp[i] = reservation[i];
         }

         delete[] reservation;
         reservation = nullptr;

         reservation = temp;
      }
      return *this;
   }

   std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirmationSender){
      
      os << "--------------------------\n"
         "Confirmations to Send\n"
         "--------------------------\n";
      
      if (confirmationSender.resCnt == 0) {
         os << "There are no confirmation to send!\n";
      }
      else {
         for (size_t i = 0; i < confirmationSender.resCnt; i++) {
            os << confirmationSender.reservation[i];
         }
      }
      return os;
   }

   bool ConfirmationSender::inArray(const Reservation& obj) {
      bool inTheArray = false;

      for (int i = 0; i < resCnt && !inTheArray; i++) {
         if (reservation[i] == &obj) {
            inTheArray = true;
         }
      }
      return inTheArray;
   }

   bool ConfirmationSender::inArray(const Reservation& obj, size_t& index) {
      bool inTheArray = false;

      for (int i = 0; i < resCnt && !inTheArray; i++) {
         if (reservation[i] == &obj) {
            inTheArray = true;
            index = i;
         }
      }
      return inTheArray;
   }
}