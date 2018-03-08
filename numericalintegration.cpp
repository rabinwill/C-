#include <iostream>
#include <limits> 					//for numeric_limits
#include <vector>					//for vectors
#include <numeric> 					//for inner_product
#include <cmath>					//for pow functions
#include "numericalintegration.h"    //defined class

using namespace std; 
//Mutator Functions
/* 
 Description: Setting the Degree of the polynomial.
 Parameter: integer degree
*/
void NumericalIntegration::set_degree (int deg) 
{
     degree = deg;
}

/*
 Description: Setting the Vector or coefficients
 Parameter: vector v1
*/
void NumericalIntegration::set_coefficients (vector <double> v) // Set the vector of coefficients
{
     v1 = v;
}

/*
 Description: Setting the Integral Bounds a and b
 Parameter: double a and b
*/
void NumericalIntegration::set_integrals (double aa, double bb) // Set the integral bounds a and b
{
     a = aa;
     b = bb;
}

/*
 Description: Setting the Columns to subdivide the function
 Parameter: integer sides
*/
void NumericalIntegration::set_columns( int n) 	
{
	sides = n;
}

//Accessor Functions
/*
 Description: Integrating f(x) for Trapeziodal rule
*/
double NumericalIntegration::f(double x)
{
	return 1/(1+x*x);
	//return 1/sqrt(2*3.14159)*exp(-pow(x,2)*0.5);
}

/*
 Description: Calculating the Numerical Integration by using the Rectangle Rule
 	Width(dx)=b-a/sides
 	height(xi) =  a + (z×width)
 	area = width(dx)*height(xi)
 	
*/
double NumericalIntegration::rectangle_integral()
{
	double totalsum,xi,dx,area = 0;
	int z = 0;
	dx = (b-a)/sides;
	for (z=0; z<sides; z++) {
		xi = a+z*dx;
		area = xi*dx;
		totalsum += area;
	}
	return totalsum;	
}

/*
 Description: Calculating the Numerical Integration by using Trapeziodal Rule
 Parameters: Vector double trapeCoeffs which holds coefficients *2
 			 Vector double stores values of f(x)
 			 h = a-b/sides to calculate the width of the trapeziode Delta(x)
 			 x_i = b+r*h to evaluate x0..xn and y0...yn
 			 
*/
double NumericalIntegration::trapeziodal_integral()
{
	vector<double> trapeCoeffs(sides+1, 2);
	for (int t = 0; t != trapeCoeffs.size(); ++t)
	{
			if(v1[t]!=0) {
			trapeCoeffs[t] = trapeCoeffs[t]*v1[t];
		}
//		cout << trapeCoeffs[t] << "-----" << endl;
////		//cout << trapeCoeffs.at(t) << "- calling at member" << endl;
	}
	trapeCoeffs[0] = 1;
	trapeCoeffs[trapeCoeffs.size()-1]=1;
	vector<double> storeValues(sides+1);
	
	double h = (a-b)/((double)sides);
	for (int r = 0; r <= sides; r++)
	{
		double x_i= b + r*h;
		storeValues[r] = f(x_i);
	}
	
	double productVal = inner_product(trapeCoeffs.begin(), trapeCoeffs.end(), storeValues.begin(), 0.0);
	double result = 0.5*h*productVal;
	return result;

}

/*
 Description: Calculating the Exact Integral by using Basic Rules
 Parameters: double a_sum holds the sum of Upper Integral bound 'a'
 			 double b_sum holds the sum of Lower Integral bound 'b'
 			 double total_ei holds the final results after adding in the constant C
			 first if to check if x^4 then do not divide
			 	if coefficient is 0 then do not multiply
			 	else coefficient*a^power+1 and coefficient*b^power+1
			 else coefficient*a^power+1/power+1
			 
 			 
*/
double NumericalIntegration::exact_integration()
{
	double a_sum=0.0, b_sum=0.0, total_ei = 0.0;
	int p_a=degree;
//	cout<<"Degree "<<degree;
//	for (int x = 0; x != v1.size(); ++x)
//	{
//		cout << v1[x] << "\n- subscripting" << endl;
//		cout<<"X is: "<<x;
//	}
	for (p_a=degree; p_a>=1; p_a--) {
		if(p_a+1==4){
			if(v1[degree-p_a]==0.0) {
				a_sum = a_sum + (pow(a,p_a+1));
				b_sum = b_sum + (pow(b,p_a+1)); }
			else {
				a_sum = a_sum + (v1[degree-p_a]*pow(a,p_a+1));
				b_sum = b_sum + (v1[degree-p_a]*pow(b,p_a+1)); }
		}
		else if(v1[degree-p_a]==0.0) {
			a_sum = a_sum + (pow(a,p_a+1))/p_a+1;
			b_sum = b_sum + (pow(b,p_a+1))/p_a+1;
		}
		else {
			a_sum = a_sum + ((v1[degree-p_a]*pow(a,p_a+1))/p_a+1);
			b_sum = b_sum + ((v1[degree-p_a]*pow(b,p_a+1))/p_a+1);
		}
	}
	a_sum=a_sum+(v1[degree]*a);
	b_sum=b_sum+(v1[degree]*b);
	total_ei = a_sum + b_sum;	
	return total_ei;
}


