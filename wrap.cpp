#include <boost/python.hpp>
#include "SGP4_cpp_wrapper.h"
#include "SGP4/SGP4.h"

//sudo apt-get install libboost-python-dev 
//sudo apt-get install python-dev
//sudo apt-get install libpython3.7-dev

using namespace boost::python;
 
BOOST_PYTHON_MODULE( libSGP4_cpp_wrapper )
{
	class_<elsetrec>("elsetrec");
	class_<position_s>("position_s")
	.def_readwrite("ro_x", &position_s::ro_x)
	.def_readwrite("ro_y", &position_s::ro_y)
	.def_readwrite("ro_z", &position_s::ro_z)
	.def_readwrite("vo_x", &position_s::vo_x)
	.def_readwrite("vo_y", &position_s::vo_y)
	.def_readwrite("vo_z", &position_s::vo_z);
	
    def( "get_version", &get_version );
	def( "create_object", &create_object, args("longstr1", "longstr2") );
	def( "get_jday", &get_jday, args("year", "month", "day", "hour", "minute", "second") );
	def( "propagate", &propagate, args("satrec", "year", "month", "day", "hour", "minute", "second") );
}
