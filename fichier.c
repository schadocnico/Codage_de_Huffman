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
	

	int cpt = 0;
	FILE* fichier = NULL;
	
	fichier = fopen("test.txt","r");

	if (fichier != NULL)
	{
		while(fgetc(fichier) != EOF)
		cpt ++;
		
	char chaine[cpt];	
	while (fgets(chaine, cpt, fichier) != NULL)
	{
	printf("%s",chaine);	
	}
	
	fclose(fichier);

	} else {
	
	printf("Impossible d'ouvrir le fichier");

	}
	
}

