#include <iostream>
#include <string>
#include <regex> //Included this library to remove white spaces

using namespace std;

int main()
{
   std::string tempString = ("1234: John    ,  john@email.com  ,           2,   3,    5");
   std::regex removingWhiteSpaces("\\s+"); //Regex to remove whitespaces

   tempString = std::regex_replace(tempString, removingWhiteSpaces, "");

   std::string reservationID{};
   std::string reservationName{};
   std::string reservationEmail{};
   int numPartyPeople{};
   int reservationDay{};
   int reservationHour{};

   int starting = 0;
   char semiColon = ':';
   char comma = ',';

   //Reservation ID
   size_t found = tempString.find(semiColon);
   reservationID = tempString.substr(starting, found);
   tempString.erase(starting, found + 1);

   //Reservation Name
   found = tempString.find(comma);
   reservationName = tempString.substr(starting, found);
   tempString.erase(starting, found + 1);

   //Reservation Email
   found = tempString.find(comma);
   reservationEmail = tempString.substr(starting, found);
   tempString.erase(starting, found + 1);

   //Number of Part People
   found = tempString.find(comma);
   numPartyPeople = stoi(tempString.substr(starting, found));
   tempString.erase(starting, found + 1);

   //Reservation Day
   found = tempString.find(comma);
   reservationDay = stoi(tempString.substr(starting, found));
   tempString.erase(starting, found + 1);

   //Reservation Hour
   found = tempString.find(comma);
   reservationHour = stoi(tempString.substr(starting, found));
   tempString.erase(starting, found + 1);

   cout << "Reservation ID: " << reservationID << endl;
   cout << "Reservation Name: " << reservationName << endl;
   cout << "Reservation Email: " << reservationEmail << endl;
   cout << "Number of Party People: " << numPartyPeople << endl;
   cout << "Reservation Day: " << reservationDay << endl;
   cout << "Reservation Hour: " << reservationHour << endl;

   return 0;
}
