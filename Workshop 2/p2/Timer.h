/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef TIMER_H
#define TIMER_H

namespace sdds {

   typedef std::chrono::time_point<std::chrono::steady_clock> TIME;
   typedef std::chrono::duration<float> DURATION_FLOAT;

   class Timer {
      TIME startTime;
      TIME endTime;
      DURATION_FLOAT duration;
   public:
      void start();
      long long stop();
   };
}
#endif // !TIMER_H
