struct noeud{
    void *val;
    struct noeud *droit;
    struct noeud *gauche;
};

typedef struct noeud *noeud;