#include "SGP4_cpp_wrapper.h"

#ifdef TEST_MAIN
int main(void)
{
	SGP4_cpp_wrapper wrapper;

	string longstr1 =  "08195U 75081A   06176.33215444  .00000099  00000-0  11873-3 0   813";
	string longstr2 =  "2 08195  64.1586 279.0717 6877146 264.7651  20.2257  2.00491383225656";

	elsetrec satellite = wrapper.create_object(longstr1, longstr2);

	double ro[3], vo[3];
	wrapper.propagate(satellite, 2019, 12, 11, 27, 10, 25.5, ro, vo);
	
	printf("Result: %16.8f %16.8f %16.8f | %12.9f %12.9f %12.9f\n",
			ro[0], ro[1], ro[2], vo[0], vo[1], vo[2]);
			
	return 0;
}
#endif

string get_version(void)
{
	return SGP4Version;
};

elsetrec create_object(string longstr1, string longstr2)
{
	elsetrec satrec;
	double ro[3], vo[3];/* unused */
	double startmfe, stopmfe, deltamin; /* unused */
		
	//void twoline2rv(
	//	char longstr1[130], char longstr2[130],
	//	char typerun, char typeinput, char opsmode,
	//	gravconsttype whichconst,
	//	double& startmfe, double& stopmfe, double& deltamin,
	//	elsetrec& satrec
	//)
	//opsmode = 'a' best understanding of how afspc code works
	//opsmode = 'i' improved sgp4 resulting in smoother behavior
	SGP4Funcs::twoline2rv(
				(char*)longstr1.c_str(),
				(char*)longstr2.c_str(),
				'c', ' ', 'i',
				wgs84,
				startmfe, stopmfe, deltamin, satrec);
			
	// call the propagator to get the initial state vector value
	// no longer need gravconst since it is assigned in sgp4init	
	SGP4Funcs::sgp4(satrec, 0.0, ro, vo); /* Init propagator */
	
	return satrec;
}

double get_jday(int year, int month, int day, int hour, int minute, double second)
{
	double jd;
	double jdFrac;
	
	//void    jday(
	//	int year, int mon, int day, int hr, int minute, double sec,
	//	double& jd, double& jdFrac
	//);
	SGP4Funcs::jday(year, month, day, hour, minute, second, jd, jdFrac);
	double total = jd + jdFrac;
	return total;
}

position_s propagate(elsetrec &satrec, int year, int month, int day, int hour, int minute, double second)
{
	position_s position;
	double ro[3],vo[3];
	double minutes_per_day = 1440.0;

	double j = get_jday(year, month, day, hour, minute, second);	
    double m = (j - (satrec.jdsatepoch+satrec.jdsatepochF)) * minutes_per_day;
    
    //printf("jdep=%.12f\n",satrec.jdsatepoch);
    //printf("jdepF=%.12f\n",satrec.jdsatepochF);

    //printf("j=%.12f m=%.6f\n",j, m);
    SGP4Funcs::sgp4(satrec, m, ro, vo);
    position.ro_x = ro[0];
    position.ro_y = ro[1];
    position.ro_z = ro[2];
        
    position.vo_x = vo[0];
    position.vo_y = vo[1];
    position.vo_z = vo[2];
    return position;
}






