#include <stdio.h>
#include <stdlib.h>
#include "ARBRE.h"
int main()
{
    Tree *arbre = joindre_arbre(joindre_arbre(new_tree(2),new_tree(5),4),new_tree(10),8);
    //-free(arbre);
    affiche_arbre_prefixe(arbre);
    inser_element_ordre_croissant(arbre,1);
    inser_element_ordre_croissant(arbre,14);
    affiche_arbre_prefixe(arbre);
    printf("La taille de l'arbre est de : %d\n",Taille_arbre(arbre));
    recherche_valeur(arbre,1);
    liber_arbre(arbre);//pour supprimer un arbre on empile tous ses elements puis on les dépiles juste
    return 0;
}
