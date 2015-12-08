#include "lista.h"

Lista* insereLista(pNodoA *a, TipoInfo *palavra2)
{
    Lista *paux;
    Lista *pant = NULL;
    Lista *novo;
    paux = a->adj;
	novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome, palavra2);


    if(paux==NULL){
    	novo->freqAB = 1;
        novo->proximo = NULL;
        novo->anterior = NULL;
        paux = novo;
    }
    else{
        while(paux!= NULL && strcmp(paux->nome, novo->nome) != 0){
        	//puts(paux->nome);

            pant = paux;
            paux = paux->proximo;
        }

        if(paux == NULL){
        	if(strcmp(pant->nome, novo->nome)==0){
				printf("aaa");
				(pant->freqAB)++;
			}
			else{
				novo->freqAB = 1;

				if(pant){
		            novo->proximo = paux;
		            novo->anterior = pant;
		            pant->proximo = novo;

		            if(paux){
		                paux->anterior = novo;
		            }
		            paux = a->adj;
		        }
		        else{
		            novo->proximo = paux;
		            novo->anterior = NULL;

		            if(paux){
		                paux->anterior = novo;
		            }
		            paux = novo;
		        }
			}
		}
        else if(strcmp(paux->nome, novo->nome)==0){
        	(paux->freqAB)++;
		}
    }

    return paux;
}
