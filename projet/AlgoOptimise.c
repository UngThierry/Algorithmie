#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define INF -10

int min(int a, int b){
  if(a < 0) return b;
  if(b < 0) return a;
  if(a < b) return a;
  return b; //on d�finit une fonction min 
}

void affBocal(int al, int B[],int k){ //fonction d'affichage du bocal simplement
  int i;
  printf("%d, |", al) ;
  for(i = 0; i < k; i++){
    printf(" %d |", B[i]);
  }
  printf("\n");		
}

int AlgoOptimise(int k, int V[], int s, int Bocaux[]){
  int i, j; //indices de parcours du tableau doublement indic�
  int M[s][k];
  //tableau doublement indic�
  for(i = 1; i <= s; i++){
    for(j = 1; j <= k; j++){
      int v1 = 0;
      int v2 = 0;
      int v3 = 0; //trois valeurs qui vont servir � stocker les r�sultats temporaires
      if(j-1 == 0){ 
	v1 = INF; //on suit la relation de l'�nonc� pour mettre les bonnes cases � l'infini et � 0
      } 
      else{
	v1 = M[i-1][j-2]; //on stocke cette valeur
      }
      int quantite = i - V[j-1]; //on met � jour la quantit�
      if(quantite <= 0){
	if(quantite == 0){
	  v3 = 0; 
	}
	else{
	  v3 = INF; 
	}
      }            
      else{
	v3 = M[quantite-1][j-1];
      }           	            
      v2 = v3 + 1; 
      M[i-1][j-1] = min(v1,v2); //on r�cup�re le minimum entre les deux valeurs qui correspondent � la relation de l'�nonc�
    }
  }
  for(i = 0; i < k; i++){ //on met � 0 toutes les cases du tableau qui vont servir � compter les bocaux
    Bocaux[i] = 0;
  }
  i = k;
  j = s;
  int cpt = 1;

  while(j > 0){ //tant qu'il reste de la confiture
    if(j == 1){ //on regarde si j = 1
      j = 0;
      Bocaux[0]++; //si oui c'est qu'on ne peut mettre qu'un seul bocal de 1, c'est fini
    }
    else if(j == V[i-1]){
      j = 0;
      Bocaux[i-1]++; //si j est exactement la derni�re case du tableau de m�me on ne remplit qu'un seul bocal et c'est fini
    }
    else if(j - V[i-1] >= 0 && M[j-1][i-1] == (1 + M[j - V[i-1]-1][i-1])){ //sinon d'apr�s la relation de l'�nonc� on remonte dans la matrice progressivement
      j = j - V[i-1]; //on d�cr�mente la quantit�
      Bocaux[i-1] = cpt++; //on met � jour la quantit� de bocaux;
    }
    else{
      i = i-1; //sinon on passe au bocal suivant c'est a dire la case pr�c�dente dans la matrice
      cpt = 1;      // on remet cpt 1
    }
  }
  return M[s-1][k-1]; //enfin on renvoie la derni�re case de la matrice qui contient la solution optimale
}


int main(int argc, char **argv){
  FILE *fichier;
  fichier = fopen(argv[1], "r");
  float temps;
  clock_t t1, t2; //variables de temps
  int s, k; //vont stocker la quantit� de confiture et la taille du tableau
  int a;
  if(!fichier){ //traitement du cas d'erreur
    fprintf(stderr, "Fichier vide.\n");
  }

  else{
    //on recupere s et k 
    fscanf(fichier, "%d %d", &s, &k);
    int V[k]; //on declare un tableau de taille k pour stocker la taille des bocaux
    //on recupere le tableau sur le reste du fichier
    for(a = 0; a < k; a++){
      fscanf(fichier, "%d", &V[a]);
    }
    int Bocaux[k]; //on declare un tableau qui va compter les bocaux
    t1 = clock();		
    int nbMinBocaux = AlgoOptimise(k, V, s, Bocaux); //on r�cup�re la valeur retourn�e par l'algorithme optimise
    affBocal(nbMinBocaux, Bocaux, k); //on affiche le tableau final
    printf("Quantite = %d\nNombre de bocaux minimum : %d.\n", s, nbMinBocaux); //on affiche la solution optimale
    t2 = clock();
    temps = (float) (t2-t1)/CLOCKS_PER_SEC; //on calcule le temps d'ex�cution
    printf("Temps d'execution : %f secondes.\n", temps); //on affiche le temps d'ex�cution
  }
  

  fclose(fichier);

  return 0;
}
