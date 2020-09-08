#include <iostream>
#include "GFunction.h"

#include "All_test.h"

int main() {
	GVtest::SpeedTest(TestAll);

	std::cout << "MAIN:" << std::endl;
	std::string expr;
	double x;
	while (true) {
		std::cout << "Enter expression:" << std::endl;
		std::getline(std::cin, expr);
		if (expr == "end") break;
		std::cout << "Enter the x value:" << std::endl;
		while (true) {
			std::regex regular("\\d+\\.*\\d*");
			std::string str;
			std::getline(std::cin, str);
			if (std::regex_match(str.begin(), str.end(), regular)) {
				x = std::stod(str);
				break;
			}
			else {
				std::cout << "Wrong value X. " << "Try again:" << std::endl;
				continue;
			}
		}
		//std::cin.get();
		try {
			std::cout << Func(expr).EvaluateInPoint(x) << std::endl << "=====================\n" <<std::endl;
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl << "=====================\n" <<std::endl;
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////MAIN
