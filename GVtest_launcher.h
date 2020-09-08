#pragma once

#ifndef GVTEST_LAUNCER_H
#define GVTEST_LAUNCER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <functional>
#include <ctime>

namespace GVtest {

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T> vec) {
		os << "{";
		bool IsFirstElement = true;
		for (const T& l : vec) {
			if (IsFirstElement) {
				os << l;
				IsFirstElement = false;
			}
			os << " ," << l;
		}
		os << "}";
		return os;
	}

	template<typename FirstT, typename SecondT>
	std::ostream& operator<<(std::ostream& os, const std::map<FirstT, SecondT> mp) {
		os << "{";
		bool IsFirstElement;
		for (const std::pair<FirstT, SecondT>& l : mp) {
			if (IsFirstElement) {
				os << "{" << l.first << ", " << l.second << "}";
				IsFirstElement = false;
			}
			os << " ," << l;
		}
		os << "}";
		return os;
	}

	template<typename T>
	std::ostream& operator<< (std::ostream& os, const std::set<T> st) {
		os << "{";
		bool IsFirstElement = true;
		for (const T& l : st) {
			if (IsFirstElement) {
				os << l;
				IsFirstElement = false;
			}
			os << " ," << l;
		}
		os << "}";
		return os;
	}

	/// <summary>
	/// Checks if the arg was true.
	/// </summary>
	void IsRight(bool arg, const std::string& title = {});

	/// <summary>
	/// If the arguments Left and Right are not equal then throws exception. 
	/// </summary>
	template <typename FirstT, typename SecondT>
	void CheckEqual(const FirstT& Left, const SecondT& Right, const std::string& title = "") {
		if (Left != Right) {
			std::ostringstream oss;
			oss << "Verification failed [ " << Left << " != " << Right <<" ].";
			if (!title.empty()) {
				oss << "\nTitle: " << title;
			}
			throw std::invalid_argument(oss.str());
		}
	}

	/// <param name="func">Your oun function for testing.</param>
	template<typename Func>
	void SpeedTest(Func func) {
		uint32_t start = clock();
		func();
		uint32_t stop = clock();
		std::cout << (stop - start) / 1000.0 << std::endl;
	}

	class TestLauncher final{
	public:
		/// <param name="function">Your oun function for testing.</param>
		/// <param name="functionName">Test title.</param>
		void StartTest(const std::function<void()> function, const std::string& functionName);
		~TestLauncher();

	private:
		int TestsFailedValue = 0;
	};

}

#endif // !GVTEST_LAUNCER_H
