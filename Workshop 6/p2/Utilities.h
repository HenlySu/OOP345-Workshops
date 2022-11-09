#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include"Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string& trim(std::string& str);

	void getData(std::string& line, std::string& extractTo, char delimeter);
	void delData(std::string& line, char delimeter);
	void isNum(std::string str, double& num);
}

#endif // !SDDS_UTILS_H