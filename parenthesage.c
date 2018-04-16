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

	if ( (c == 41) || (c == 93) || (c == 125) ){
		return true ;
	}

	return false ;
}

/* Question 4 : fonction qui test si deux caractères forment un bon parenthesage */
bool car_corresp(char c, char d){

	if ( (c == 40) && (d == 41) ){
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

	pile M ;
	M = pile_vide() ;

	while ( !est_vide(P) ){

		if ( par_ouvrant ( sommet(P) )){
			M = empiler ( sommet(P) , M ) ;
		}

		if ( par_fermant ( sommet(P) )){
			if ( !car_corresp( sommet(M), sommet(P) ) ) {
				return false ;
			}
			else{
				M = depiler (M) ;
			}
		}

		P = depiler( P );

	}

	return true ;
}

int main(void){
	
	pile P ;

	P = empiler( '{', empiler( 'a', empiler( 'b', empiler( ')', pile_vide() ) ) ) ) ;
	afficher_pile(P) ;

	if ( parenthese(P) ){
		printf("C'est bon.\n");
	}
	else{
		printf("C'est pas bon.\n") ;
	}

	return 1 ;

}


