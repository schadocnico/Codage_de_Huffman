struct noeud {
	void* val;
	struct noeud* suivant;
};

typedef struct noeud* nd;

struct heap_liste{
	nd tete;
};

typedef struct heap_liste* heap;

nd creer_noeud(void* _val, void(* _copier(void*, void**)){
	nd n=(nd)malloc(sizeof(struct noeud));
	_copier(_val, &(n->val));
	n->suivant=NULL;
	return n;
}

heap creer_heap(void(* _copier)(void*, void**), void(* _detruire)(void**)){
	heap h = (heap)malloc(sizeof(struct(heap_liste));
	h->tete=NULL;
	h->copier= _copier;
	h->detruire= _detruire;
	return h;
}

void ajouter_heap(void* _val, heap h, int(*_comparer)(void* _val1, void* _val2)){
	nd tete=h->tete;
	nd tmp=h->tete;
	nd prec;

	nd n = creer_noeud(_val,h->copier);
	if(h->tete==NULL){
		h->tete=n;
	}
	else{
		while(_comparer((h->tete)->val,n->val)<1){
			prec=tmp;
			tmp=(h->tete)->suivant;
			h->tete=(h->tete)->suivant;
		}
		h->tete=n;
		(h->tete)->suivant=tmp->suivant;
		prec->suivant=n;
		h->tete=tete;
	}
}

void* extraire_min(heap h,void(* _detruire)(void**)){
	nd tmp=(h->tete)->suivant;	
	detruire_noeud(&(h->tete), h->detruire);
	h->tete=tmp;
	return (h->tete)->val;
}
		
