#include <sstream>
#include"Utilities.h"
#include"Car.h"
#include"Van.h"
#include"Racecar.h"
#include"Luxuryvan.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string line{};
		Vehicle* temp_vehicle = nullptr;

		if (std::getline(in, line)) {

			trim(line);

			try {
				std::stringstream temp_stream(line);

				if (line[0] == 'c' || line[0] == 'C') {
					temp_vehicle = new Car(temp_stream);
				}

				else if (line[0] == 'v' || line[0] == 'V') {
					temp_vehicle = new Van(temp_stream);
				}

				else if (line[0] == 'r' || line[0] == 'R') {
					temp_vehicle = new Racecar(temp_stream);
				}

				else if (line[0] == 'l' || line[0] == 'L') {
					temp_vehicle = new Luxuryvan(temp_stream);
				}
				else {
					throw line[0];
				}
			}
			catch (const std::invalid_argument& error) {
				std::cerr << error.what() << std::endl;
			}
		}
		return temp_vehicle;
	}

	//Trims white spaces
	std::string& trim(std::string& str) {
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}

	//Gets data from a string with delimeters
	void getData(std::string& line, std::string& extractTo, char delimeter) {
		size_t found = line.find(delimeter);
		extractTo = line.substr(0, found);
		trim(extractTo);
		line.erase(0, found + 1);
	}

	//Deletes data up to the delimeter
	void delData(std::string& line, char delimeter) {
		size_t found = line.find(delimeter);
		line.erase(0, found + 1);
	}

	//Checks if it is a number, if not throw error
	void isNum(std::string str, double& num) {
		trim(str);

		for (size_t i = 0; i < str.length(); i++) {
			if (!std::isdigit(str[i])) {
				throw std::invalid_argument("Invalid record!");
			}
		}
		num = std::stod(str);
	}
}