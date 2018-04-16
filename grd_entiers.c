/* Implantation des fonctions pour les grands entiers */

#include "liste_entiers.c"
#define base 10

/* SIGNATURES DES FONCTIONS */
void affiche_grd_entiers(void);
liste succ(liste L);
liste int_to_bigint(unsigned int N, liste L); /* L sera le grand entier retourné, on appelera cette fonction avec une liste vide */
unsigned int bigint_to_int(liste L, unsigned int i); /* i sert à la puissance, on appelera cette fonction avec i = 0 */
liste somme_grd_entiers(liste L, liste M, liste SUM); /* SUM sera la somme, on appelera cette fonction avec une liste vide */
liste diff_grd_entiers(liste L, liste M, liste DIF); /* DIF sera la différence, on appelera cette fonction avec une liste vide */
liste prod_grd_entiers(liste L, liste M, liste P);
liste facto_grd_entier(liste L);

/* Question 2 : procédure permettant d'afficher un grand entier */
/* Pour cette question, nous utiliserons la fonction de la question 5 */
void affiche_grd_entiers(void){

	liste L ;

	L = cons (5, cons (9, cons( 6, cons (8, cons (0, cons (0, l_vide() ) ) ) ) ) ) ;
	printf("Grand entier : ") ;
	afficher_liste(L) ;
	printf("\nAffichage de ce grand entier : %u", bigint_to_int(L, 0) ) ;
	printf("\n") ;

}

/* Question 3 : fonction qui donne le successeur d'un grand eniter */
liste succ(liste L){

	if ( est_vide( L) ){
		return cons( 1, l_vide() ) ; /* Une liste vide représente l'entier 0 */
	}

	if ( prem(L) == 9 ){
		return cons( 0, succ( reste(L) ) ) ;
	}

	return cons ( prem(L) + 1, reste(L) ) ;
}

/* Question 4 : fonction qui à un entier naturel associe le grand entier correspond */
liste int_to_bigint(unsigned int N, liste L){

	if ( N == 0 ){
		return L ; /* Comme une liste vide représente 0, le grand entier associé à 0 est la liste vide */
	}

	return cons ( N%base, int_to_bigint( N / base, L) ) ;
}

/* Question 5 : fonction qui à un grand entier associe l'entier naturel correspondant */
unsigned int bigint_to_int(liste L, unsigned int i){

	if ( est_vide( L ) ){
		return 0 ;
	}

	return prem (L) * pow (base, i) + bigint_to_int( reste(L), i+1 ) ;
}	

/* Question 6 : fonction qui calcule la somme de deux grands entiers */
liste somme_grd_entiers(liste L, liste M, liste SUM){

	if ( longueurI(L) < longueurI(M) ){     /* On met le plus grand entier en premier pour régler le problème de la retenue */
		return somme_grd_entiers(M, L, SUM) ;
	}

	if ( est_vide(L) ){
		return M ;
	}

	if ( est_vide(M) ){
		return L ;
	}

	/* On s'assure de ne pas oublier une éventuelle retenue */
	if ( prem(M) + prem(L) / base != 0){             
		L = cons( prem(L), succ( reste(L) ) ) ;
	}

	return ( cons( ( prem(M) + prem(L) ) % base , somme_grd_entiers( reste(L), reste(M), SUM) ) ) ;
}

/* Question 7 : fonction qui calcule la différence de deux grands entiers */
liste diff_grd_entiers(liste L, liste M, liste DIF){

	if ( longueurI(L) < longueurI(M) ){     /* On met le plus grand entier en premier pour régler le problème de la retenue */
		return diff_grd_entiers(M, L, DIF) ;
	}

	if ( est_vide(L) ){
		return M ;
	}

	if ( est_vide(M) ){
		return L ;
	}

	/* On s'assure de ne pas oublier une éventuelle retenue */
	if ( prem(L) < prem(M) ){             
		L = cons ( prem(L) + base, reste(L) ) ;
		L = cons ( prem(L), succ( reste(L) ) ) ;
	}

	return ( cons( abs( prem(M) - prem(L) )%base , diff_grd_entiers( reste(L), reste(M), DIF) ) ) ;
}

/* Question 8 : fonction qui calcule le produit de deux grands entiers */
liste prod_grd_entiers(liste L, liste M, liste P){

	if ( longueurI(L) > longueurI(M) ){
		return prod_grd_entiers(M, L, M) ;
	}

	if ( est_vide(M) ){
		return l_vide() ;
	}

	if ( est_vide(L) ){
		return prod_grd_entiers(P, M, P) ;
	}

}

int main(){

	liste L = cons( 9, cons( 3, cons( 6, cons( 8, l_vide() ) ) ) ) ;
	liste M = cons( 9, cons( 7, cons( 4, l_vide() ) ) ) ;
	affiche_grd_entiers() ;
	printf("\nPRODUIT DES DEUX ENTIERS : ");
	afficher_liste(prod_grd_entiers(L, M, L) ) ;
	printf("\n") ;

	return EXIT_SUCCESS ;

}