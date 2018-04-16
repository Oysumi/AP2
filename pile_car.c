/************************/
/* pile_entiers.h      */
/* auteur : Jean Lieber */
/* version : 2          */
/* date : 11/02/14      */
/************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Pile *pile ;

struct Pile
{
  char premier ;
  pile suivant ;
} ;

/* SIGNATURES DES OPERATIONS PRIMITIVES */
/* issues du type abstrait */
pile pile_vide () ;
pile empiler (char c, pile P) ;
bool est_vide (pile P) ;
char sommet (pile P) ;
pile depiler (pile P) ;
/* autres opérations primitives */
void liberer_pile (pile P) ;
void ecrire_prem (char c, pile P) ;
void ecrire_reste (pile R, pile L) ;

/* IMPLANTATION DES OPERATIONS PRIMITIVES */
/* Constructeurs */
pile pile_vide ()
{
  return NULL ;
}

pile empiler (char c, pile P)
{
  pile M ;
  // Réservation de la place mémoire nécessaire pour une cellule :
  M = malloc (sizeof (*M)) ;
  M->premier = c ; // On peut aussi écrire " M->premier = c ; "
  M->suivant = P ;
  return M ;
}

/* Accès */
bool est_vide (pile P)
{
  return P == NULL ;
}

char sommet (pile P)
{
  if (est_vide (P))
    {
      printf ("Calcul de sommet sur pile vide !\n") ;
      exit (0) ;
    }
  return P->premier ;
}

pile depiler (pile P)
{
  return P->suivant ;
}

/* Autres opérations primitives (hors type-abstrait) */
void liberer_pile (pile P)
{
  if (est_vide (P))
    {
      return ;
    }
  liberer_pile (depiler (P)) ;
  free(P) ;
}

void ecrire_prem (char c, pile P)
{
  P->premier = c ;
}

void ecrire_reste (pile R, pile P)
{
  P->suivant = R ;
}

/* OPERATIONS NON PRIMITIVES */
unsigned int longueurR (pile P)
{
  if (est_vide (P))
    return 0 ;
  return 1 + longueurR (depiler (P)) ;
}

unsigned int longueurI (pile P)
{
  unsigned int lg ;
  lg = 0 ;
  while (!est_vide (P))
    {
      lg = lg + 1 ;
      P = depiler (P) ;
    }
  return lg ;
}

void afficher_pile (pile P)
{
  printf("\n") ;
  printf ("(") ;
  while (!est_vide (P))
    {
      printf ("%c%s",
	      sommet (P),
	      (est_vide (depiler(P)) ? "" : ")\n(")) ;
      P = depiler (P) ;
    }
  printf (")\n\n") ;
}
