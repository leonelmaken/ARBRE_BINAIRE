#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct Tree//cree un abre de la racine a ses sous arbres
{
    int value;//racine de l'arbre
    struct Tree *tleft;//sous arbre gauche
    struct Tree *trigth;//sous arbre droit
    struct Tree *parent;//le parent ou racine d'un sous arbre
}Tree;//on ne met pas d'étoile pour cacher les pointeurs

Tree *new_tree(int x);
void liber_arbre(Tree *tr);
Tree *joindre_arbre(Tree *left, Tree *rigth, int node);
void affiche_arbre_prefixe(Tree *tr);
int Taille_arbre(Tree *tr);
int inser_element_ordre_croissant(Tree *tr, int val);
int recherche_valeur(Tree *tr,int val);
#endif // ARBRE_H_INCLUDED
