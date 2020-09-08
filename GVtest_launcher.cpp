#include"GVtest_launcher.h"

void GVtest::IsRight(bool arg, const std::string& title) {
	CheckEqual(arg, true, title);
}

void GVtest::TestLauncher::StartTest(const std::function<void()> function, const std::string& functionName) {
	try
	{
		function();
		std::cerr << "Function name : " << functionName << " --> OK." << std::endl;
	}
	catch (const std::exception& ex)
	{
		TestsFailedValue++;
		std::cerr << std::endl << "Error: " << ex.what() << ". Function name: " << functionName << "." << std::endl << std::endl;
	}
}


GVtest::TestLauncher::~TestLauncher() {
	if (TestsFailedValue != 0) {
		std::cerr << std::endl << "Some tests are failed. The programme was stopped." << std::endl;
		exit(-505);
	}
}