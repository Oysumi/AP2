/* Test de parenthésage, adaptation avec pile */

#include "pile_car.c"

/* SIGNATURE DES FONCTIONS */

bool par_ouvrant(char c);
bool par_fermant(char c);
bool car_corresp(char c, char d);
bool bien_parenthesee(pile P);
int cas_parenthesage(pile P);
pile chaine_finale(pile P);


/* Question 2 : fonction qui test qu'un caractère est un signe de parenthesage ouvrant */
bool par_ouvrant(char c){

	if ( (c == '{') || (c == '[') || (c == '(') ){ 
		return true ;
	}

	return false ;
}

/* Question 3 : fonction qui test qu'un caractère est un signe de parenthesage fermant */
bool par_fermant(char c){

	if ( (c == '}') || (c == ']') || (c == ')') ){
		return true ;
	}

	return false ;
}

/* Question 4 : fonction qui test si deux caractères forment un bon parenthesage */
bool car_corresp(char c, char d){

	if ( (c == '(') && (d == ')') ){
		return true ;
	}

	if ( (c == '[') && (d == ']') ){
		return true ;
	}

	if ( (c == '{') && (d == '}') ){
		return true ;
	}

	return false ;
}

/* Question 5 : fonction qui test si une chaine de caractères est bien parenthésée */
bool bien_parenthesee(pile P){

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

	if ( !est_vide(M) ){
		return false ;
	}

	return true ;
}

/* Question 6 : fonction qui distingue les différents cas de parenthésage */

/* Valeurs de retour : */
/* (1) = chaîne de caractères bien parenthésée */
/* (-1) = chaîne de caractères avec parenthèses fermantes manquantes */
/* (-2) = chaîne de caractères mal parenthésée */

int cas_parenthesage(pile P){

	pile M ;
	M = pile_vide();

	if ( !bien_parenthesee(P) ){

		while ( !est_vide(P) ){

			if ( par_ouvrant ( sommet(P) )){
				M = empiler ( sommet(P) , M ) ;
			}

			if ( par_fermant ( sommet(P) )){
				if ( !car_corresp( sommet(M), sommet(P) ) ) {
					return -2 ;
				}
				else{
					M = depiler (M) ;
				}
			}

			P = depiler( P );

		}
	}

	if ( !est_vide(M) ){
		return -1 ;
	}

	return 1 ;
}

/* Question 7 : fonction qui à une chaine (-1) associe une chaine de caractères bien parenthésée */
pile chaine_finale(pile P){

	pile M ;
	pile S ;

	M = pile_vide() ;
	S = P ; /* Sera la pile renvoyée */

	if ( cas_parenthesage( P ) == -1 ){

		while ( !est_vide(P) ){
			if ( par_ouvrant ( sommet(P) )){
				M = empiler ( sommet(P) , M ) ;
			}

			if ( par_fermant ( sommet(P) )){
				M = depiler (M) ;
			}

			P = depiler( P );
		}

		while ( !est_vide(M) ){
			if ( car_corresp( sommet(M), '}' ) ){
				S = empiler('}', S) ;
				M = depiler( M ) ;
				continue ;
			}
			if ( car_corresp( sommet(M), ')' ) ){
				S = empiler(')', S) ;
				M = depiler( M ) ;
				continue ;
			}
			if ( car_corresp( sommet(M), ']' ) ){
				S = empiler(']', S) ;
				M = depiler( M ) ;
				continue ;
			}
		}
	}

	return S ;
}


int main(void){
	
	pile P ;

	P = empiler( '{', empiler( 'a', empiler( 'b', empiler( 'm', empiler( '[', (empiler ( 'a', pile_vide() ) ) ) ) ) ) ) ;

	printf("Pile avant : ") ;
	afficher_pile(P) ;

	if ( cas_parenthesage(P) == -2 ){
		printf("Votre chaine de caractères est mal parenthésée. Nous ne pouvons rien faire.\n") ;
	}
	if ( cas_parenthesage(P) == 1 ){
		printf("Votre chaine de caractères est bien parenthésée. Félicitations.\n") ;
	}
	if ( cas_parenthesage(P) == -1 ){
		printf("Votre chaine de caractères manque de parenthèses fermantes. Nous allons arranger ça.\n");
		P = chaine_finale(P) ;
		printf("Votre chaine de caractères a été traitée. La voici ( à lire de bas en haut ) : \n") ;
		afficher_pile(P) ;
	}

	return 1 ;
}


