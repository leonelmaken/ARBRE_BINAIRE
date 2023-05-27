#include <stdio.h>

#include "ARBRE.h"

Tree *new_tree(int x)//au depart on cree une racine
{
    Tree *tr = malloc(sizeof(*tr));//on alloue un espace un memoire de façon dynamique
    int exist = -1;
    if(tr == NULL)
    {
        fprintf(stderr,"Erreur allocation memoire.\n");
        return exist;//si l'espace en memoire n'a pas fonctionnaire ce message nous sera affiche
    }
    tr->value = x;
    tr->tleft = NULL;
    tr->trigth = NULL;
    tr->parent = NULL;

    printf("Creation de la racine %d\n", tr->value);
    return tr;
}
void liber_arbre(Tree *tr)
{
    if(tr == NULL)
    {
        return;
    }
    printf("Suppression de la racine %d\n", tr->value);
    liber_arbre(tr->tleft);
    liber_arbre(tr->trigth);

    free(tr);
}
Tree *joindre_arbre(Tree *left, Tree *rigth, int node)//node represente l'element qui va rattacher les deux noeuds
{
  Tree *tr = new_tree(node);
  tr->tleft = left;
  tr->trigth = rigth;
  if(left != NULL)
      left->parent = tr;
  if(rigth != NULL)
      rigth->parent = tr;

  return tr;
}
void affiche_arbre_prefixe(Tree *tr)
{
    if(tr == NULL)
        return ;
    if(tr->parent != NULL)
        printf("[%d] -> %d\n",tr->parent->value, tr->value);
    else
        printf("[%d]\n",tr->value);
    if(tr->tleft != NULL)
        affiche_arbre_prefixe(tr->tleft);
    if(tr->trigth != NULL)
        affiche_arbre_prefixe(tr->trigth);
}
int Taille_arbre(Tree *tr)
{
    if(tr == NULL)
    {
        return 0;
    }
    return (Taille_arbre(tr->tleft) + Taille_arbre(tr->trigth) + 1);
}
int inser_element_ordre_croissant(Tree *tr, int val)
{
    if(tr == NULL)
    {
        return new_tree(val);
    }
    else
    {
        if(val<tr->value)
        {
            tr->tleft = inser_element_ordre_croissant(tr->tleft, val);
        }
        else
        {
            tr->trigth = inser_element_ordre_croissant(tr->trigth,val);
        }
    }
    return tr;
}
int recherche_valeur(Tree *tr,int val)
{
    if(tr == NULL)
        return 0;
    if(tr->value == val)
        return tr;
    if(val<tr->value)
    {
     return recherche_valeur(tr->tleft,val);
    }
    else
    {
        return recherche_valeur(tr->trigth,val);
    }
}
