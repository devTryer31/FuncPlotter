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
		try{ 
			std::cin >> x; 
		}
		catch (const std::exception&){
			std::cout << "Wrong value X" << std::endl;
		}
		std::cin.get();
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
