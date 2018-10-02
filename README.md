# Codage_de_Huffman

Structures utilisé : 
	- Arbre (creer par Nicolas) : 
	- Noeud_arbre (creer par Nicolas) : c'est une structure utilisé
	- Noeud_generic (recuperé du TD) : est utilisé que par Heap_list, on pourrais creer un package Heap_list avec les fichiers noeud_generic et heap_list et mettre que heap_list en public.
	- Heap_list (creer par Arnaud) : (ou file de priorité) : 
		On peut la retrouver en Python sous la forme 'heapq' ('priority_queue' en C++), c'est un type abstrait ou l'on peut effectuer trois opération : 
			(1) insérer un élément
			(2) extraire l'élément le plus grand (ou petit) - Nous utiliserons le deuxieme cas
			(3) tester si la file est vide
      
  Implementation : comme la structure n'existe pas en C, nous allons l'implementer de maniere simple en liste chainée, chaque ajout a la liste se fera de facon trier, la liste restera donc trier. La complexité de l'insertion sera de l'ordre de O(n) ou n le nombre d'element de la liste et l'extraction du plus petit element en O(1).
		
  Pourquoi utiliser cette structure? Pour creer l'arbre de Huffman : "Tant que la liste d’arbres contient au moins deux arbres, deux des arbres de plus petite fréquence en sont extraits pour être fusionnés", le but etant de creer une heap_list, mettre 
