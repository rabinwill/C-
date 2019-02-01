#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

int main(){

	cout<<"Enter String: ";
	string s;
	getline(cin, s);

	//cout<<"Entered String: "<<s<<"\n";

	string::size_type max_sz=0;
	string max_wrd;
	string word;

	istringstream stream(s);

	while (stream >> word){

		if(max_sz < word.size()){
			max_sz = word.size();
			max_wrd = word;
		}
		else if(max_sz == word.size()){

			max_wrd += ", "+word;
		}
	}

	cout<<"Max Word(s) is: "<<max_wrd<<"\n";
}