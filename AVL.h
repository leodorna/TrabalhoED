#include <stdio.h>

typedef char TipoInfo;

struct TItemA
{
    TipoInfo nome[30];
    struct TItemA *prox;
};

struct TNodoA
{
    TipoInfo info[30];
    int FB;
    int freq;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA* InsereAVL (pNodoA *a, TipoInfo* x, int *ok);
pNodoA* Caso1 (pNodoA *a , int *ok);
pNodoA* Caso2 (pNodoA *a , int *ok);
pNodoA* rotacao_direita(pNodoA* pt);
pNodoA* rotacao_esquerda(pNodoA *pt);
pNodoA* rotacao_dupla_esquerda (pNodoA *pt);
pNodoA* rotacao_dupla_direita (pNodoA* pt);
void imprimeArvore(pNodoA *nude);
void imprimeComDistancia(pNodoA *nude, int cont);

