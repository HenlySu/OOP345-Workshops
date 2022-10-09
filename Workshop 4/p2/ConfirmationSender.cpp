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
   /*ConfirmationSender::ConfirmationSender() {
      reservation = nullptr;
      resCnt = 0u;
   }*/

   //Rule of three
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj) {
      *this = obj;
   }
   ConfirmationSender& ConfirmationSender::operator = (const ConfirmationSender& obj) {
      if (this != &obj) {
         delete[] reservation;
         resCnt = obj.resCnt;

         *reservation = new Reservation[resCnt];

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
      
   }

   ConfirmationSender& ConfirmationSender::operator -= (const Reservation& res){
      
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
}