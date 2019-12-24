#include <boost/python.hpp>
#include "SGP4_cpp_wrapper.h"

//sudo apt-get install libboost-python-dev 
//sudo apt-get install python-dev
//sudo apt-get install libpython3.8-dev

using namespace boost::python;
 
BOOST_PYTHON_MODULE( SGP4_cpp_wrapper )
{
     class_<SGP4_cpp_wrapper>( "SGP4_cpp_wrapper", init<>() )
        .def( "get_version", &SGP4_cpp_wrapper::get_version )	
		.def( "create_object", &SGP4_cpp_wrapper::create_object, args("longstr1", "longstr2") )	
		.def( "get_jday", &SGP4_cpp_wrapper::get_jday, args("year", "month", "day", "hour", "minute", "second") )
		.def( "propagate", &SGP4_cpp_wrapper::propagate, args("satrec", "year", "month", "day", "hour", "minute", "second", "ro", "vo") )
    ;
}
