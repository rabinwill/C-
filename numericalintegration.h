#include <iostream>
#include <limits> 					//for numeric_limits
#include <vector>					//for vectors
#include <numeric> 					//for inner_product
#include <cmath>					//for pow functions

using namespace std; 
class NumericalIntegration 			// class declaration
{
      //private
      int degree, sides;
      vector <double> v1;
      double a, b, x;
      
      
 public:
        void set_degree (int deg); 
        void set_coefficients(vector <double> v);
        void set_integrals (double aa, double bb);
        void set_columns(int n);
        double rectangle_integral();
        double trapeziodal_integral();
        double f(double x);
        double exact_integration();
};


