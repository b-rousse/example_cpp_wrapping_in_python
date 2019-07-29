#include <iostream>
#include <fstream>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>//to convert eigen data types (and maybe numpy?)
#include <pybind11/stl.h>//to convert standard data types between python and c++11
#include <cstdlib> //to convert command line parameters to double with atof
#include <Eigen/Dense>
#include <vector>
#include "temp.h"


std::vector<double> f_to_c_vector(std::vector<double> f_vec) {
    //convert all elements of f_vec from Fahrenheit to Celcius

    for(auto &it : f_vec) {//: is like in
        it = (it - 32.0) / 1.8;
        }
    return f_vec;
}

Eigen::MatrixXd f_to_c_matrix(Eigen::MatrixXd f_mat) {
    for(int r = 0; r < f_mat.rows(); r++){
        for(int c = 0; c < f_mat.cols(); c++) {
            f_mat(r,c) = (f_mat(r,c) - 32.0) / 1.8;
        }
    }
    return f_mat;
}

bool check_temperature (double my_temp, char temp_type){

    double k_temp;
    if (temp_type == 'K') {
        k_temp = my_temp;
    }
    else if (temp_type == 'C') {
        k_temp = celcius_to_kelvin(my_temp);
    } 
    else if (temp_type == 'F') {
        k_temp = f_to_kelvin(my_temp);
    } 

    if (k_temp > 0.0) {
        return true;
    }
    else if (k_temp == 0.0){
        std::cout << "Temperature is at absolute zero." << std::endl;
        return true;
    }
    else {
        std::cout << "Temperature is below absolute zero." << std::endl;
        return false;
    }
}

double f_to_celcius(double f_temp){
    double c_temp = (f_temp - 32.0)/1.8;
    return(c_temp);
}

double celcius_to_kelvin(double c_temp){
    double k_temp = c_temp + 273.15;
    return(k_temp);
}

double f_to_kelvin(double f_temp){
    double c_temp = f_to_celcius(f_temp);
    double k_temp = celcius_to_kelvin(c_temp);
    return k_temp;
}
