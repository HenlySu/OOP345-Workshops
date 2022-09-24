/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "TennisLog.h"

using namespace std;

namespace sdds {
   //Constructors
   TennisLog::TennisLog() {
      tennisMatches = nullptr;
      numMatches = 0;
   }
   TennisLog::TennisLog(const char* filename) {
      std::string line;
      std::ifstream fp(filename);

      if (fp.is_open()) {
         while (fp.peek() != EOF) {
            getline(fp, line);
            numMatches++;
         }
         numMatches--;

         
         tennisMatches = new TennisMatch[numMatches];
         
      }
      fp.close();
   }

   //Rule of 3
   //TennisLog(const TennisLog& obj);
   //TennisLog& operator = (const TennisLog& obj);
   //~TennisLog();

   //Rule of 5 for part 2
   //TennisLog(TennisLog&& obj);
   //TennisLog& operator = (TennisLog&& obj);

   void TennisLog::addMatch(TennisMatch& tennisMatch) {

   }
   TennisLog TennisLog::findMatches(const char* playername) {

   }
   TennisMatch TennisLog::operator [] (size_t index) {
      if (index < numMatches) {
         return tennisMatches[index];
      }
      else {
         TennisMatch emptyMatch;
            return emptyMatch;
      }
   }
   TennisLog::operator size_t() {
      return numMatches;
   }
}