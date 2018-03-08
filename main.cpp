#include <iostream>
#include <limits> 					//for numeric_limits
#include <vector>					//for vectors
#include <numeric> 					//for inner_product
#include <cmath>					//for pow functions
#include "numericalintegration.h"    //defined class

using namespace std; 

int main (void)
{
	
    int degree, opt, columns, i;
    double a0, b0, rectMethod, trapeMethod=0.0, exactMethod = 0.0;
    double vin;
    vector <double> coef;
    vector <double> testVector;
    char moreinput = 'y';
    
    NumericalIntegration integration1;    		//instance of class
    
	while ((moreinput == 'y'|| moreinput=='Y'))		//While loop to keep looping until user wishes to exit
        { //While to validate input for the degree of the polynomial.
        while (cout<<"Enter Degree of the polynomial (Must be between 1 - 10) : " && (!(cin>>degree) || degree<1 || degree>10))	{
        	cout<<"Invalid Entry! Please Enter a valid value between 1 - 10:";
        	cin.clear();
        	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 	} //end of while loop
        // Set the degree from the user to class
		integration1.set_degree(degree);
		
		i=0;
		//for loop to let the user input coefficients based on the degree of the polynomial
		for (i=1; i<=degree+1; i++) {
			//While loop to validate the input for coefficients 
			while (cout<<"Enter the coefficient of the polynomial at position " <<i <<" : " && !(cin>>vin)) {
				cout<<"Invalid Entry! Please enter a number: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	} //end of while loop
			// Set the coefficients from the user to temp vector in main
			coef.push_back(vin);
		} //end of foor loop
		
		//set the coefficient vector of the class
		integration1.set_coefficients(coef);
		
		while (cout<<"Enter the Upper Integral bound 'a':" && !(cin>>a0)) {
			cout<<"Invalid Entry! Please enter a number: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 	}
			
		while (cout<<"Enter the Lower Integral bound 'b' :" && !(cin>>b0)) {
			cout<<"Invalid Entry! Please enter a number: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 	}
			
		//Set the integral bounds a and b from the user to the class
		integration1.set_integrals(a0, b0);
		
		cout<<"Select an option (1-3) to Calculate the Numerical Integration:";
		while (cout<<"\n 1. Rectangle Method \n 2. Trapezoidal Method \n 3. Exact Numerical Method.\n" && !(cin>>opt) || opt<1 || opt>3) {
			cout<<"Invalid Option Selected! Please select a valid option from 1-3: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 		}
			
		bool switch_condition = true; 
		while(switch_condition) {
			switch (opt) {
				case 1: 
					cout<<"\nRectangle Method!";
					while (cout<<"How many columns? " && !(cin>>columns)) {
						cout<<"Invalid Entry! Please enter a valid number: ";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }	
					integration1.set_columns(columns);
					rectMethod = integration1.rectangle_integral();
					cout<<"The Numerical Integral by using the Rectable Method is: "<<rectMethod;
					switch_condition = false;
					break;
					
				case 2:
					cout<<"\nTrapezoidal Method!";	
					while (cout<<"How many columns? " && !(cin>>columns)) {
						cout<<"Invalid Entry! Please enter a valid number: ";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
					integration1.set_columns(columns);
					trapeMethod = integration1.trapeziodal_integral();
					cout<<"The Numerical Integral by using the Trapezoidal Method is: "<<trapeMethod;
					switch_condition = false;	
					break;
				
				case 3:
					cout<<"\n Exact Numerical Method!\n";
					exactMethod = integration1.exact_integration();
					cout<<"The Numerical Integral by performing the symbolic integration of the polynomial is: "<<exactMethod;
					switch_condition = false;
					break;
					
				default:
					cout<<"Wrong Selection! Try Again!";
					switch_condition = false;
					break;
			
		}					//end switch
		} 					//end while switch condition
		cout<<"\nDo you want to exit program? (Y/N)? ";
		char exit_status;
		cin>>exit_status;
		if(exit_status=='y' || exit_status == 'Y'){
			cout<<"Exit ";
			moreinput = 'N'; 	//Setting While condition to not loop through again
		}
		else{
				//Validating input from user
			while(exit_status!= 'n'&& exit_status != 'N'){
				cout<<"Invalid Input";
				cout<<"\nDo you want to exit program? (Y/N)? ";
				cin>>exit_status;
				cout<<exit_status<<endl;
				if(exit_status=='y' || (exit_status == 'Y')){
					cout<<"Exit ";
					moreinput = 'N';
					return 0;
				}
			} 		//end of while loop
			moreinput = 'Y';
		}
		
 	}  //loop for another new test
	return 0;
}


