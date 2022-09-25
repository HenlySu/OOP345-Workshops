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

         std::getline(fp, line);

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
         numMatches = obj.numMatches;
         delete[] tennisMatches;
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
   TennisLog::TennisLog(TennisLog&& obj) noexcept {
      *this = std::move(obj);
   }
   TennisLog& TennisLog::operator = (TennisLog&& obj) noexcept {
      if (this != &obj) {
         delete[] tennisMatches;
         tennisMatches = obj.tennisMatches;
         obj.tennisMatches = nullptr;

         numMatches = obj.numMatches;
         obj.numMatches = 0;
      }
      return *this;
   }

   void TennisLog::addMatch(TennisMatch& tennisMatch) {
      numMatches++;
      TennisMatch* temp = new TennisMatch[numMatches];
      
      if (tennisMatches != nullptr) {
         for (size_t i = 0; i < (numMatches - 1); i++) {
            temp[i] = tennisMatches[i];
         }
         temp[numMatches - 1] = tennisMatch;
      }
      else {
         temp[0] = tennisMatch;
      }

      delete[] tennisMatches;
      tennisMatches = nullptr;

      tennisMatches = temp;
   }
   TennisLog TennisLog::findMatches(const char* playername) {
      TennisLog temp{};

      for (size_t i = 0; i < numMatches; i++) {
         if (!strcmp(playername, tennisMatches[i].matchWinner.c_str()) || !strcmp(playername, tennisMatches[i].matchLoser.c_str())) {
            temp.addMatch(tennisMatches[i]);
         }
      }
      return temp;
   }
   TennisMatch TennisLog::operator [] (size_t index) {
      TennisMatch emptyMatch{};
      return (!(tennisMatches == nullptr)) ? emptyMatch = tennisMatches[index] : emptyMatch;
   }
   TennisLog::operator size_t() {
      return numMatches;
   }

   std::ostream& operator << (std::ostream& os, TennisMatch tennisMatch) {
      if (tennisMatch.matchID) {
         os << std::setfill('.') << std::setw(23) << std::right << "Tourney ID : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.tournamentID << '\n';
         os << std::setfill('.') << std::setw(23) << std::right << "Match ID : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.matchID << '\n';
         os << std::setfill('.') << std::setw(23) << std::right << "Tourney : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.tournamentName << '\n';
         os << std::setfill('.') << std::setw(23) << std::right << "Winner : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.matchWinner << '\n';
         os << std::setfill('.') << std::setw(23) << std::right << "Loser : " << std::setw(30) << std::setfill('.') << std::left << tennisMatch.matchLoser << '\n';
         
         os << std::setfill(' ');
      }
      else {
         os << "Empty Match";
      }
      return os;
   }
}