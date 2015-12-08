#include "AVL.h"

pNodoA* InsereAVL (pNodoA *a, TipoInfo* x, int *ok)
{
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
    x, a chave a ser inserida e h a altura da árvore */

    /*
    if(x[0] < 97){
        lowerString(x);
    }
    */

    puts(x);

    if(palavra !=NULL){
		if (a == NULL){
            if(palavra[0] < 97){
				lowerString(palavra);
			}
			a = (pNodoA*) malloc(sizeof(pNodoA));

			strcpy(a->info, palavra);

	        a->esq = NULL;
	        a->dir = NULL;
	        a->FB = 0;
	        a->adj = NULL;

	        if(palavra2){
                a->adj = insereLista(a, palavra2);
            }
            a->freq = 1;

	        *ok = 1;
	    }
	    else if (strcmp(palavra, a->info) < 0){ //as comparações devem ser feitas utilizando STRCMP
	        a->esq = InsereAVL(a->esq,palavra,palavra2, ok);

	        if (*ok){
	            switch (a->FB){
	                case -1: a->FB = 0; *ok = 0; break;
	                case 0: a->FB = 1; break;
	                case 1: a=Caso1(a,ok); *ok = 0; break;
	            }
	        }
	    }
	    else if(strcmp(palavra, a->info) > 0){
	        a->dir = InsereAVL(a->dir,palavra,palavra2, ok);

	        if (*ok){
	            switch (a->FB){
	                case 1: a->FB = 0; break;
	                case 0: a->FB = -1; break;
	                case -1: a = Caso2(a,ok); break;
	            }
	        }
	    }
	    else{
			(a->freq)++;

			if(palavra2){
			a->adj = insereLista(a, palavra2);
            }
		}
	}

    return a;
}

pNodoA* Caso1 (pNodoA *a , int *ok)
{
    pNodoA *ptu;
    ptu = a->esq;

    if (ptu->FB == 1){
        a = rotacao_direita(a);
    }
    else{
        a = rotacao_dupla_direita(a);
    }

    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoA* Caso2 (pNodoA *a , int *ok)
{
    pNodoA *ptu;

    ptu = a->dir;
    if (ptu->FB == -1){
        a=rotacao_esquerda(a);
    }
    else {
        a=rotacao_dupla_esquerda(a);
    }

    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoA* rotacao_direita(pNodoA* pt)
{
    pNodoA *ptu;

    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->FB = 0;
    pt = ptu;

    return pt;
}

pNodoA* rotacao_esquerda(pNodoA *pt)
{
    pNodoA *ptu;

    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->FB = 0;
    pt = ptu;

    return pt;
}

pNodoA* rotacao_dupla_esquerda (pNodoA *pt)
{
    pNodoA *ptu, *ptv;

    ptu = pt->dir;
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    pt->dir = ptv->esq;
    ptv->esq = pt;

    if (ptv->FB == -1) pt->FB = 1;
    else pt->FB = 0;

    if (ptv->FB == 1) ptu->FB = -1;
    else ptu->FB = 0;

    pt = ptv;
    return pt;
}

pNodoA* rotacao_dupla_direita (pNodoA* pt)
{
    pNodoA *ptu, *ptv;

    ptu = pt->esq;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    pt->esq = ptv->dir;
    ptv->dir = pt;

    if (ptv->FB == 1) pt->FB = -1;
    else pt->FB = 0;

    if (ptv->FB == -1) ptu->FB = 1;
    else ptu->FB = 0;

    pt = ptv;
    return pt;
}

void imprimeArvore(pNodoA *nude)
{
    if(nude!=NULL){
        printf("%s\n", nude->info);
        imprimeArvore(nude->esq);
        imprimeArvore(nude->dir);
    }
    return;
}

void imprimeComDistancia(pNodoA *nude, int cont)
{
    int j;
    cont++;
    if(nude==NULL) return;
    for(j=0; j < cont; j++){
        printf("=", cont);
    }

    printf("%s; frequencia = %d\n", nude->info, nude->freq);

    imprimeComDistancia(nude->esq, cont);
    imprimeComDistancia(nude->dir, cont);
}

int contaNodos(pNodoA *nude)
{
    int d, l;

    if(nude==NULL) return 0;

    d= contaNodos(nude->dir);
    l= contaNodos(nude->esq);

    return d+l+1;
}

float buscaFreq(pNodoA* a, TipoInfo *nome)
{
	puts(a->info);
	puts(nome);

	if(strcmp(a->info, nome) == 0){
		return a->freq;
	}

	if(strcmp(a->info, nome) < 0) return buscaFreq(a->dir, nome);
	if(strcmp(a->info, nome) > 0) return buscaFreq(a->esq, nome);
}

void calculaAdj(pNodoA* a, pNodoA* inicioA)
{
	Lista *paux;
	float auxiliar;
	if(a== NULL)
	return;

	if(a->adj==NULL){
        puts("LISTA VAZIA\n");
    }
    else{
        for(paux=a->adj; paux!=NULL; paux=paux->proximo){
        	printf("aaaa");
        	puts(a->info);
            paux->freqAB = (paux->freqAB)/sqrt((a->freq) * buscaFreq(inicioA, paux->nome));
            printf("bbbb");
        }
    }
    printf("ccccc");

    calculaAdj(a->dir, inicioA);
    calculaAdj(a->esq, inicioA);

	return;
}
