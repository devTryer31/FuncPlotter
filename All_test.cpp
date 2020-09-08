#include "All_test.h"

void SolveWithPar() {
	GVtest::CheckEqual(Func("(x)").EvaluateInPoint(-12.0), -12.0, "(x)");
	GVtest::CheckEqual(Func("(45.101)").EvaluateInPoint(0), (45.101), "(45.101)");
	GVtest::CheckEqual(Func("14.+(x)+((13-44)*3.)/x+1").EvaluateInPoint(0.5), 14. + (0.5) + ((13. - 44.) * 3.) / 0.5 + 1., "14+(x)+((13-44)*3)/x+1");
	GVtest::CheckEqual(Func("(x/1)+((1.5-1)*(3)/(7*x) +1)").EvaluateInPoint(1.01), (1.01 / 1) + ((1.5 - 1) * (3) / (7 * 1.01) + 1), "(x/1)+((1.5-1)*(3)/(7*x) +1)");
	GVtest::CheckEqual(Func("(x-1)*(x+4)/(5.+x)").EvaluateInPoint(3), (3 - 1.) * (3. + 4) / (5. + 3), "(x-1)*(x+4)/(5+x)");
	GVtest::CheckEqual(Func("(x*(x*(x*(10/(5.05-15)))))+(x)").EvaluateInPoint(111), (111. * (111. * (111. * (10 / (5.05 - 15))))) + (111), "(x*(x*(x*(10/(5+15)))))+(x)");

	GVtest::CheckEqual(Func("7*((1+x)*					x)").EvaluateInPoint(0.11), 7 * ((1 + 0.11) * 0.11), "7*((1+x)*					x)");
	GVtest::CheckEqual(Func("(((1+3* x)   +x*5))").EvaluateInPoint(3), (((1 + 3 * 3) + 3 * 5)), "(((1+3* x)   +x*5))");
	GVtest::CheckEqual(Func("7.1+(3.005-5)").EvaluateInPoint(0.3), 7.1 + (3.005 - 5), "7.1+(3.005-5)");
	GVtest::CheckEqual(Func("(7* x)-   4- (x*x)   *3		   -   654").EvaluateInPoint(0.3), (7 * 0.3) - 4 - (0.3 * 0.3) * 3. - 654., "(7* x)-   4- (x*x)   *3		   -   654");
	GVtest::CheckEqual(Func("13+((x*6)+x)-x-(3*x)*x").EvaluateInPoint(-10), 13 + (((-10.) * 6) + (-10.)) - (-10.) - (3 * (-10.)) * (-10.), "13+((x*6)+x)-x-(3*x)*x");
	GVtest::CheckEqual(Func("((13+4)/(x*16))/(10*3)+1").EvaluateInPoint(12), ((13 + 4.) / (12. * 16)) / (10. * 3) + 1., "((13+4)/(x*16))/(10*3)+1");
	GVtest::CheckEqual(Func("(x/(x/x)/x)").EvaluateInPoint(10), (10. / (10. / 10.) / 10.), "(x/(x/x)/x)");
	GVtest::CheckEqual(Func("-45+(-10)/((-5/2)+45)").EvaluateInPoint(45), -45. + (-10.) / ((-5. / 2.) + 45.), "-45+(-10)/((-5/2)+45)");
	GVtest::CheckEqual(Func("10/(5*10/5*x)").EvaluateInPoint(-20), 10 / (5. * 10 / 5. * (-20)), "10/(5*10/5*x)");
	GVtest::CheckEqual(Func("(-x)-(5/(-5))").EvaluateInPoint(5), (-5) - (5 / (-5)), "(-x)-(5/(-5))");
}

void SolveExprCheck() {
	GVtest::CheckEqual(Func("12-12").EvaluateInPoint(0), 0, "12-12");
	GVtest::CheckEqual(Func("-12.").EvaluateInPoint(0), -12.0, "-12.");
	GVtest::CheckEqual(Func(" 	       45+    45 ").EvaluateInPoint(0), 90, " 	       45+    45 ");
	GVtest::CheckEqual(Func("-7*-1+-x*x").EvaluateInPoint(1.12), (-7.) * (-1.) + (-1.12) * 1.12, "-7*-1+-x*x");
	GVtest::CheckEqual(Func("7*1+x*x").EvaluateInPoint(-1.5), 7 * 1 + (-1.5) * (-1.5), "7*1+x*x");
	GVtest::CheckEqual(Func("-1+3*x+x*5").EvaluateInPoint(0.5), -1 + 3 * 0.5 + 0.5 * 5, "-1+3*x+x*5");
	GVtest::CheckEqual(Func("45.+45").EvaluateInPoint(123), 45. + 45, "45.+45");
	GVtest::CheckEqual(Func("x").EvaluateInPoint(1.105), 1.105, "x");
	GVtest::CheckEqual(Func("13+x*65+75+68+x-x-123*x*x").EvaluateInPoint(-12), 13 + (-12) * 65 + 75 + 68 + (-12) - (-12) - 123 * (-12) * (-12), "13+x*65+75+68+x-x-123*x*x");
	GVtest::CheckEqual(Func("45  .1		 +     x	").EvaluateInPoint(0.7), 45.1 + (0.7), "45  .1		 +     x	");
	GVtest::CheckEqual(Func("45+x   *x").EvaluateInPoint(1.5), 45 + (1.5) * (1.5), "45+x   *x");
	GVtest::CheckEqual(Func("7*1+x*					x").EvaluateInPoint(0), 7 * 1 + 0 * 0, "7*1+x*					x");
	GVtest::CheckEqual(Func("1+3* x   +x*5").EvaluateInPoint(3), 1 + 3 * 3 + 3 * 5, "1+3* x   +x*5");
	GVtest::CheckEqual(Func("7.1+3.005-5").EvaluateInPoint(0.3), 7.1 + 3.005 - 5, "7.1+3.005-5");
	GVtest::CheckEqual(Func("7* x-   4- x*x   *3		   -   654").EvaluateInPoint(0.3), 7 * 0.3 - 4 - 0.3 * 0.3 * 3 - 654, "7* x-   4- x*x   *3		   -   654");
	GVtest::CheckEqual(Func("13+x*6+x-x-3*x*x").EvaluateInPoint(-10), 13 + (-10) * 6 + (-10) - (-10) - 3 * (-10) * (-10), "13+x*6+x-x-3*x*x");
	GVtest::CheckEqual(Func("13+4/x*16/10*3+1").EvaluateInPoint(12), 13 + 4. / 12 * 16. / 10. * 3. + 1., "13+4/x*16/10*3+1");
	GVtest::CheckEqual(Func("x/x/x/x").EvaluateInPoint(1), 1, "x/x/x/x");
	GVtest::CheckEqual(Func("x/x/x/x").EvaluateInPoint(10), 10. / 10. / 10. / 10., "x/x/x/x");
	GVtest::CheckEqual(Func("-45+-10/-5/2+45").EvaluateInPoint(45), -45 + (-10.) / (-5.) / 2. + 45, "-45+-10/-5/2+45");
	GVtest::CheckEqual(Func("10/5*10/5*x").EvaluateInPoint(-20), 10 / 5 * 10 / 5 * (-20), "10/5*10/5*x");
	GVtest::CheckEqual(Func("-x-5/-5").EvaluateInPoint(5), -4, "-x-5/-5");
}

bool IsExceptClass(const std::string& expr) {
	try
	{
		Func F(expr);
	}
	catch (const std::exception&)
	{
		return true;
	}
	return false;
}

void RegExprCheck() {
	GVtest::IsRight(!IsExceptClass("-12."), "-12.");
	GVtest::IsRight(!IsExceptClass(" 	       45+    45 "), " 	       45+    45 ");
	GVtest::IsRight(!IsExceptClass("45.+45"), "45.+45");
	GVtest::IsRight(!IsExceptClass("x"), "x");
	GVtest::IsRight(!IsExceptClass("-7*-1+-x*x"), "-7*-1+-x*x");
	GVtest::IsRight(!IsExceptClass("7*1+x*x"), "7*1+x*x");
	GVtest::IsRight(!IsExceptClass("-1+3*x+x*5"), "-1+3*x+x*5");
	GVtest::IsRight(!IsExceptClass("7+3-5"), "7+3-5");
	GVtest::IsRight(!IsExceptClass("13+x*65+75+68+x-x-123*x*x"), "13+x*65+75+68+x-x-123*x*x");
	GVtest::IsRight(!IsExceptClass("45  .1		 +     x	"), "45  .1		 +     x	");
	GVtest::IsRight(!IsExceptClass("45+x   *x"), "45+x   *x");
	GVtest::IsRight(!IsExceptClass("7*1+x*					x"), "7*1+x*					x");
	GVtest::IsRight(!IsExceptClass("1+3* x   +x*5"), "1+3* x   +x*5");
	GVtest::IsRight(!IsExceptClass("7.1+3.005-5"), "7.1+3.005-5");
	GVtest::IsRight(!IsExceptClass("7* x-   4- x*x   *3		   -   654"), "7* x-   4- x*x   *3		   -   654");
	GVtest::IsRight(!IsExceptClass("13+x*6+x-x-3*x*x"), "13+x*6+x-x-3*x*x");
	GVtest::IsRight(!IsExceptClass("(-12.)"), "(-12.)");
	GVtest::IsRight(!IsExceptClass("(13+x)*6+(x-x)-3*x*x"), "(13+x)*6+(x-x)-3*x*x");
	GVtest::IsRight(!IsExceptClass("(13+x*(65+(75)+68)+x)-(x-(123)*x*x)"), "(13+x*(65+(75)+68)+x)-(x-(123)*x*x)");

	GVtest::IsRight(IsExceptClass("+12"), "+12");
	GVtest::IsRight(IsExceptClass("+4.5+x-"), "+4.5+x-");
	GVtest::IsRight(IsExceptClass("45++x*x"), "45++x*x");
	GVtest::IsRight(IsExceptClass("7*x-4-x**x*3-654"), "7*x-4-x**x*3-654");
	GVtest::IsRight(IsExceptClass("12-"), "12-");
	GVtest::IsRight(IsExceptClass("145.123.12"), "145.123.12");
	GVtest::IsRight(IsExceptClass("x-"), "x-");
	GVtest::IsRight(IsExceptClass("+x"), "+x");
	GVtest::IsRight(IsExceptClass("(x."), "(x.");
	GVtest::IsRight(IsExceptClass("x.)"), "x.)");
	GVtest::IsRight(IsExceptClass("(x.(+45/5)-13"), "(x.(+45/5)-13");
	GVtest::IsRight(IsExceptClass("(((x/(x/x/1))/1"), "(((x/(x/x/1))/1");
	GVtest::IsRight(IsExceptClass("(x)+((13-44)(*3)/(4+)1)"), "(x)+((13-44)(*3)/(4+)1)");

}

void TestAll() {
	GVtest::TestLauncher tl;
	tl.StartTest(RegExprCheck, "RegExprCheck");
	tl.StartTest(SolveExprCheck, "SolveExprCheck");
	tl.StartTest(SolveWithPar, "SolveWithPar");
}