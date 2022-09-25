/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef TENNISLOG_H
#define TENNISLOG_H

namespace sdds {
   class TennisMatch { 
   public:
      std::string tournamentID = {};
      std::string tournamentName = {};
      size_t matchID = {};
      std::string matchWinner = {};
      std::string matchLoser = {};
   };

   class TennisLog {
      TennisMatch* tennisMatches;
      size_t numMatches;
   public:
      //Constructors
      TennisLog();
      TennisLog(const char* filename);

      //Rule of 3
      TennisLog(const TennisLog& obj);
      TennisLog& operator = (const TennisLog& obj);
      ~TennisLog();

      //Rule of 5
      TennisLog(TennisLog&& obj);
      TennisLog& operator = (TennisLog&& obj);

      void addMatch(TennisMatch& tennisMatch);
      TennisLog findMatches(const char* playername);
      TennisMatch operator [] (size_t index);
      operator size_t();
   };

   std::ostream& operator << (std::ostream& os, TennisMatch tennisMatch);
}
#endif // !TENNISLOG_H