#include <iostream>
#include <string>
#include "card.h"
#include <exception>
using namespace std;

int main(){

	cout << "part 1" << endl;
	//first part
	for(int i = 0; i < 20 ; i ++){
		Card test;
		cout << test.card_to_string() << endl;

	}
	
	

	//second part
	cout << "part 2" << endl;
	try{
		int num = 3;
		Card U3((Card::Suit)'U', (Card::Rank) num);
		if((Card::Suit) U3.getSuit() != 'U'){
			throw 99;	
		}
		if((Card::Rank) U3.getRank() != 3){
			throw 99;
		}
		cout <<" The character in ASCII U = 85 T = 84 A =65" << endl;
		cout << "The character in ASCII "<<U3.getSuit() << endl << U3.getRank() << endl;
	
	} 
	catch(...){
		cout << "ERROR wrong enter with U or 3" << endl;
	}
	

	//thrid part
	cout << "part 3" << endl;
	try{
		Card test3((Card::Suit)3, 0);
		cerr << "Error with suit" << endl;
	
	} catch (runtime_error& e){
	
	}

	//fourth part
	cout << "part 4" << endl;
	try{
		Card test4((Card::Suit)'U', (Card::Rank)3);
		cerr << "Error with rank" << endl;
	} catch(runtime_error& e){
	}
}
