typedef struct sLista{
    char    nome[30];
    int     freqAB;
    struct  sLista *proximo;
    struct  sLista *anterior;
}Lista;

Lista* insereLista(pNodoA *a, TipoInfo *palavra2);
