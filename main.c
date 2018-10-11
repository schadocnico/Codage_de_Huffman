#include "utils.h"
#include "huffman.h"
#include "arbre.h"
#include "heapq.h"
#include "couple.h"

void _afficher_couple_intchar(void *_val){
    couple* c = (couple*)_val;
    printf("(%d,", *((int*)c->val1));
    if(c->val2 != NULL)
        printf("%c", *((char*)c->val2));
    printf(")");
}

int couple_to_int(void* _couple){
    couple* cp = (couple*)_couple;
    char c = (char)(*(char*)cp->val2);

    return (int)c;
}

//MAIN -------------------

int main(int argc, char *argv[]) {

    printf("%s", argv[0]);

    if(argc != 4){
        return 1;
    }else{
        if (strcmp(argv[1], "-c") == 0){
            int *occurrences  = calloc(256, sizeof(int) );


            FILE* fichier = NULL;
            char chaine[100] = ""; // Chaîne vide de taille TAILLE_MAX

            fichier = fopen("test.txt", "r");

            if (fichier != NULL) {
                fgets(chaine, 100,
                      fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"

                occurrences_ASCII(chaine, occurrences);

                fclose(fichier);
            }

            for (int i = 0; i < 256; ++i) {
                if(occurrences[i] != 0)
                    printf("%c(%d)\n", (char)i, occurrences[i]);

            }


            arb* fin = arbre_huffman(occurrences);



            _afficher_noeud_tout((*fin)->racine, &_afficher_couple_intchar);

            char **tab = chemin_tout_element(*fin, &couple_to_int);



            //--------------------LIRE CARACTERE PAR CARACTERE----------------------------

            FILE* fichier_lecture = NULL;
            int caractereActuel = 0;

            fichier_lecture = fopen("test.txt", "r");

            FILE* fichier_ecrire = NULL;
            fichier_ecrire = fopen("test_bin.txt", "w");

            if (fichier_lecture != NULL)
            {

                while ((caractereActuel = fgetc(fichier_lecture)) != EOF)
                {
                    fprintf(fichier_ecrire, "%s", tab[caractereActuel]);
                }

                fclose(fichier_lecture);
                fclose(fichier_ecrire);
            }
            for (int i = 0; i < 256; ++i) {
                free(tab[i]);

            }
            free(tab);
            detruire_arbre(fin);
            free(fin);





        }
    }



    /*arb* fin = arbre_huffman("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Duis suscipit bibendum urna sit amet pellentesque. Nulla ullamcorper libero luctus pharetra gravida. Vestibulum vulputate elementum justo. Vivamus quis justo ante. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cras lobortis arcu sit amet erat rhoncus, eget faucibus ligula placerat. Fusce sed nibh id felis sagittis placerat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec consequat augue id dolor ultricies euismod. Nullam imperdiet ut mi eu iaculis. Vestibulum molestie lorem nunc, ac auctor dolor vulputate nec. Curabitur vel facilisis justo.\n");


    _afficher_noeud_tout((*fin)->racine, &_afficher_couple_intchar);

    bit *tab = chemin_tout_element(*fin, &couple_to_int);

    for (int i = 0; i < 256; ++i) {
        if(tab[i].taille != 0)
            printf("%hhx(%x)\n", (unsigned char) i, tab[i].valeur);

    }

    detruire_arbre(fin);
    free(fin);
    free(tab);*/

    return 0;
}
