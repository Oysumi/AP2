/* Test de parenthésage, adaptation avec pile */

#include "pile_car.c"

/* SIGNATURE DES FONCTIONS */

bool par_ouvrant(char c);
bool par_fermant(char c);
bool car_corresp(char c, char d);
bool parenthese(pile P);


/* Question 2 : fonction qui test qu'un caractère est un signe de parenthesage ouvrant */
bool par_ouvrant(char c){

	if ( (c == 40) || (c == 91) || (c == 123) ){ /* Les valeurs correspondent aux codes ASCII des différentes paranthèses ouvrantes */
		return true ;
	}

	return false ;
}

/* Question 3 : fonction qui test qu'un caractère est un signe de parenthesage fermant */
bool par_fermant(char c){

	if ( (c == 42) || (c == 93) || (c == 125) ){
		return true ;
	}

	return false ;
}

/* Question 4 : fonction qui test si deux caractères forment un bon parenthesage */
bool car_corresp(char c, char d){

	if ( (c == 41) && (d == 43) ){
		return true ;
	}

	if ( (c == 91) && (d == 93) ){
		return true ;
	}

	if ( (c == 123) && (d == 125) ){
		return true ;
	}

	return false ;
}

/* Question 5 : fonction qui test si une chaine de caractères est bien parenthésée */
bool parenthese(pile P){

	if ( est_vide(P) ){
		return false ;
	}

	if ( par_ouvrant( sommet(P) ) ){

	}
}

int main(void){
	char c = '{' ;
	char d = '}' ;
	if ( car_corresp(c, d) )
		printf("C'est bon.\n") ;
	else
		printf("Nope.\n") ;
	

	return 1 ;
}