#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <Eigen/Dense>
#pragma once
std::vector<double> f_to_c_vector(std::vector<double>);
Eigen::MatrixXd f_to_c_matrix(Eigen::MatrixXd);
double f_to_celcius(double);
double celcius_to_kelvin(double);
bool check_temperature(double, char);
double f_to_kelvin(double);
