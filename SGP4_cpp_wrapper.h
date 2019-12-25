#pragma once
#include <string>
#include <SGP4/SGP4.h>

using std::string;

typedef struct position_s{
	 double ro_x;
	 double ro_y;
	 double ro_z;
	 double vo_x;
	 double vo_y;
	 double vo_z;
}position_s;

string get_version(void);
elsetrec create_object(string longstr1, string longstr2);
double get_jday(int year, int month, int day, int hour, int minute, double second);
position_s propagate(elsetrec &satrec, int year, int month, int day, int hour, int minute, double second);

