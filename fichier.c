#include <stdlib.h>
#include <stdio.h>

void ecrire(char *c) {

	FILE* fichier = NULL;

	fichier = fopen("test2.txt", "r+");

	if (fichier != NULL){
	
	fputs(c,fichier);
	fclose(fichier);

	}

	else {

	printf("Impossible d'ouvrir le fichier");

	}

}

void lire(){
	
	FILE* fichier = NULL;
	int cpt = 0;
	fichier = fopen("fichier.txt","r");

	if (fichier == NULL)
	{
		printf("impossible d'ouvrir le fichier");		
	}
	
	else {
		while(fgetc(fichier) != EOF){
		cpt++;
		}
	printf("%d",cpt);
	}

	char chaine[5];
	
	if(fgets(chaine, 5, fichier) != NULL)
	{ 
		puts(chaine);
	}
		

	fclose(fichier);

	}
	

int main(void) {
	lire();
}
