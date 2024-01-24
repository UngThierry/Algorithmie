#include <stdio.h>
#include <time.h>
#define INF 99999

int algo1(int k, int V[], int s){
    int i = 0;
    int Cst = 0;
    int x = 0;
    
    if(s < 0){
		return INF;
    }
    else{
	if(s == 0){
	    return 0;
	}
	else{
	    Cst = s;
	    for(i = 0; i<k; i++){ 
			x = algo1(k, V, s-V[i]);
		if(x+1 < Cst){
		    Cst = x+1;
		}
	    }
	}
	return Cst;
    }
    
}

int main(int argc, char **argv){
  
    FILE *fichier;
    fichier = fopen(argv[1], "r"); //on ouvre le fichier
    float temps; 
    clock_t t1, t2; //variables de temps
    int s, k; //vont stocker la quantit� de confiture et la taille du tableau
    int a;

    if(!fichier){ ////traitement du cas d'erreur
	fprintf(stderr, "Fichier vide.\n");
    }

    else{
	fscanf(fichier, "%d %d", &s, &k);
	int V[k]; //on declare un tableau de taille k pour le syst�me de capacite
	for(a = 0; a < k; a++){
	    fscanf(fichier, "%d", &V[a]);
	}
	int nbMinBocaux;
	t1 = clock();
	nbMinBocaux = algo1(k, V, s); ////on r�cup�re la valeur retourn�e par l'algorithme recherche
	printf("Nombre de bocaux minimum : %d.\n", nbMinBocaux); //on affiche ce r�sultat
	t2 = clock();
	temps = (float) (t2-t1)/CLOCKS_PER_SEC; //on calcule le temps d'ex�cution
	printf("Temps d'execution : %f secondes.\n", temps); //on l'affiche

    }
    fclose(fichier);
  
    return 0;
}


	
  
  
