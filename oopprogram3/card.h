#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;
class Card{
     public :
	enum Suit{U,T,A};
	typedef int Rank;
	Card();
	Card(Suit suit, Rank rank);
	Suit getSuit();
	Rank getRank();
	string card_to_string();
     private :
	
	Suit s;
	Rank r;

};
#endif
