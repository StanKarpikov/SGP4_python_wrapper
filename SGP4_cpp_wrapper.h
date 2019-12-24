#pragma once
#include <string>
#include <SGP4/SGP4.h>

using std::string;

class SGP4_cpp_wrapper
{
	public:
		SGP4_cpp_wrapper(void);
				
		string get_version(void);
		elsetrec create_object(string longstr1, string longstr2);
		double get_jday(int year, int month, int day, int hour, int minute, double second);
		void propagate(elsetrec &satrec, int year, int month, int day, int hour, int minute, double second, double ro[3], double vo[3]);
};
