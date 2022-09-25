/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <iostream>
#include <chrono>

#include "Timer.h"

namespace sdds {
   void Timer::start(){
      startTime = std::chrono::steady_clock::now();
   }

   long long Timer::stop() {
      endTime = std::chrono::steady_clock::now();
      duration = endTime - startTime;

      auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
      long long int ns = nanoseconds.count();
      return ns;
   }
}