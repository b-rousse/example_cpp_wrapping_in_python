#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include "temp.h"

PYBIND11_MODULE(sss_cpp, m)//sss_cpp or whatever you put for name MUST BE THE SAME NAME YOU USE AT COMPILETIME AFTER g++ -o sss_cpp
{
    m.doc() = "This is example C++ module called from python.";
    m.def("f_to_celcius",f_to_celcius,"convert Fahrenheit to celcius");
    m.def("celcius_to_kelvin",celcius_to_kelvin,"convert celcius to kelvin");
    m.def("f_to_kelvin", f_to_kelvin, "convert Fahrenheit to kelvin");
    m.def("f_to_c_vector", f_to_c_vector, "convert vector of Fahrenheits to Celcius");
    m.def("f_to_c_matrix", f_to_c_matrix, "convert matrix of Fahrenheit to Celcius");
}

