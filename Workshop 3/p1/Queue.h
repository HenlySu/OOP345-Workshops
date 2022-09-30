/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_QUEUE_H

namespace sdds {

   template <typename T, unsigned int CAPACITY>
   class Queue {
      T client[CAPACITY];
      int numOfObj;
   public:

      //Constructor
      template <typename T, unsigned int CAPACITY>
      Queue<T, CAPACITY>::Queue() : numOfObj = 0;

      template <typename T, unsigned int CAPACITY>
      bool Queue<T, CAPACITY>::push(const T& item) {
         if (numOfObj < CAPACITY) {
            client[numOfObj] = item;
            numOfObj++;
         }
         return (numOfObj < CAPACITY) ? true : false;
      }

      template <typename T, unsigned int CAPACITY>
      T Queue<T, CAPACITY>::pop() {
         T temp{};
         temp = client[0];

         for (int i = 0; i < numOfObj - 1; i++) {
            client[i] = client[i + 1];
         }
         return temp;
      }

      template <typename T, unsigned int CAPACITY>
      int size() {

      }

      template <typename T, unsigned int CAPACITY>
      std::ostream& display(std::ostream& os = std::cout) {

      }

      template <typename T, unsigned int CAPACITY>
      operator [] (int index) {

      }
   };
}
#endif // !SDDS_QUEUE_H
