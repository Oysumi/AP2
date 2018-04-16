/* Implantation de la fonction sauf_dernier */

#include "liste_entiers.c"

/* Fonction sauf_dernier*/

/* Fonction récursive */

liste sauf_dernier_R (liste L){

	/* Axiome 2 (comprenant l'axiome 3) */
	/* Le reste d'une liste vide est vide, on test donc uniquement cette condition */

	if ( est_vide ( reste(L) ) ){
		return l_vide() ; /* On peut aussi renvoyer L */
	}

	/* Axiome 1 */

	return cons ( prem (L) , sauf_dernier_R ( reste (L) ) ) ;
}

/* Fonction itérative */

liste sauf_dernier_I (liste L){

	liste M, P ;
	P = l_vide() ;

	M = L ;

	/* On construit la liste dans le sens inversé */
	while ( !est_vide ( reste (M) ) ){
		P = cons ( prem(M) , P ) ;
		M = reste ( M ) ;
	}

	/* On retourne la liste obtenue tout en l'inversant pour avoir le bon ordre */
	return renverser ( P ) ;

}

/* ----------------------------------------------------------------------------------------- */

/* Procédure de test pour la fonction récursive */

liste sauf_dernier_R_param (liste L){
	return sauf_dernier_R (L) ;
}

void sauf_dernier_R_void(void){

	liste L ;
	L = cons ( 5, cons ( 4, cons ( 3, l_vide() ) ) ) ;

	printf("\nFONCTION RECURSIVE : \n") ;
	printf("Liste de départ : ") ;
	afficher_liste ( L ) ;
	printf("\nListe après avoir éliminé le dernier element : ") ;
	afficher_liste ( sauf_dernier_R_param ( L ) ) ;
	printf("\n") ;

}

/* Procédure de test pour la fonction itérative */

liste sauf_dernier_I_param (liste L){
	return sauf_dernier_I (L) ;
}

void sauf_dernier_I_void(void){

	liste M ;
	M = cons ( 8, cons ( 1859, cons ( 487, cons ( 68, l_vide() ) ) ) ) ;

	printf("\nFONCTION ITERATIVE : \n") ;
	printf("Liste de départ : ") ;
	afficher_liste ( M ) ;
	printf("\nListe après avoir éliminé le dernier element : ") ;
	afficher_liste ( sauf_dernier_I_param ( M ) ) ;
	printf("\n\n") ;
}

int main(){

	sauf_dernier_R_void() ;
	sauf_dernier_I_void() ;
	return EXIT_SUCCESS ;

}