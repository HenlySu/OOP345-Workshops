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
#include <fstream>
#include <cstring>
#include <string>

#include "TennisLog.h"

namespace sdds {
   //Constructors
   TennisLog::TennisLog() {
      tennisMatches = nullptr;
      numMatches = 0;
   }
   TennisLog::TennisLog(const char* filename) {
      numMatches = 0;
      std::string line;
      std::ifstream fp(filename);

      if (fp.is_open()) {
         while (std::getline(fp, line)) { numMatches++; }
         numMatches--;

         tennisMatches = new TennisMatch[numMatches];
         fp.clear();
         fp.seekg(0);

         std::getline(fp, line); // Skip first line

         for (size_t i = 0; i < numMatches; i++) {
            TennisMatch tempMatch{};
            std::getline(fp, tempMatch.tournamentID, ',');
            std::getline(fp, tempMatch.tournamentName, ',');
            fp >> tempMatch.matchID;
            fp.ignore();
            std::getline(fp, tempMatch.matchWinner, ',');
            std::getline(fp, tempMatch.matchLoser, '\n');
            tennisMatches[i] = tempMatch;
         }
      }
      fp.close();
   }

   //Rule of 3
   TennisLog::TennisLog(const TennisLog& obj) {
      *this = obj;
   }
   TennisLog& TennisLog::operator = (const TennisLog& obj) {
      if (this != &obj) {
         delete[] tennisMatches;
         tennisMatches = nullptr;

         numMatches = obj.numMatches;
         tennisMatches = new TennisMatch[numMatches];

         for (size_t i = 0; i < numMatches; i++) {
            tennisMatches[i] = obj.tennisMatches[i];
         }
      }
      return *this;
   }
   TennisLog::~TennisLog() {
      delete[] tennisMatches;
      tennisMatches = nullptr;
   }

   //Rule of 5 for part 2
   //TennisLog(TennisLog&& obj);
   //TennisLog& operator = (TennisLog&& obj);

   void TennisLog::addMatch(TennisMatch& tennisMatch) {
      numMatches++;
      TennisMatch* temp = new TennisMatch[numMatches];

      for (size_t i = 0; i < (numMatches - 1); i++) {
         temp[i] = tennisMatches[i];
      }
      temp[numMatches - 1] = tennisMatch;

      delete[] tennisMatches;
      tennisMatches = nullptr;

      tennisMatches = temp;
      //not sure if I'm supposed to delete temp too
   }
   TennisLog TennisLog::findMatches(const char* playername) {
      TennisLog temp{};
      
      for (size_t i = 0; i < numMatches; i++) {
         if (!strcmp(playername, tennisMatches[i].matchWinner.c_str()) || !strcmp(playername, tennisMatches[i].matchLoser.c_str())){
            temp.addMatch(tennisMatches[i]);
         }
      }
      return temp;
   }
   TennisMatch TennisLog::operator [] (size_t index) {
      TennisMatch emptyMatch{};
      
      if (!(tennisMatches == nullptr)) {
         emptyMatch = tennisMatches[index];
      }
      return emptyMatch;
   }
   TennisLog::operator size_t() {
      return numMatches;
   }

   std::ostream& operator << (std::ostream& os, TennisMatch tennisMatch) {
      if (tennisMatch.matchID) {
         os << std::setfill('.') << std::setw(23) << std::right << "Tourney ID : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.tournamentID << std::endl;
         os << std::setfill('.') << std::setw(23) << std::right << "Match ID : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.matchID << std::endl;
         os << std::setfill('.') << std::setw(23) << std::right << "Tourney : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.tournamentName << std::endl;
         os << std::setfill('.') << std::setw(23) << std::right << "Winner : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.matchWinner << std::endl;
         os << std::setfill('.') << std::setw(23) << std::right << "Loser : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.matchLoser << std::endl;
      }
      else {
         os << "Empty Match";
      }
      return os;
   }
}