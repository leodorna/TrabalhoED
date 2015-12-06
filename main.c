#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "AVL.h"

void lowerString(char *palavra)
{
	int i = 0;

	while(palavra[i] != '\0')
	{
		palavra[i] = tolower(palavra[i]);
		i++;
	}

}


int main(int argc, char *argv[])
{
	pNodoA*	arvore = NULL;
	int altura;

    setlocale(LC_ALL,""); //para imprimir corretamente na tela os caracteres acentuados
    clock_t start, end, elapsed;
    int lineno=0;

    //char nome_arq[]=argv[1];
    FILE * entrada;

    char *palavra1, linha[1000]; // linhas a serem lidas do arquivo
	char *palavra2; // linhas a serem lidas do arquivo
    char separador[]= {" 0123456789,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};

    entrada = fopen (argv[1], "r");
    if (entrada == NULL){
        printf ("Erro ao abrir o arquivo %s",argv[1]);
        return 1;
    }
    else{
        start=clock(); //inicia a contagem do tempo;

		fgets(linha,1000,entrada);
		//pega primeira linha, eh um caso especial
		palavra = NULL;
		// a primeira palavra vai ser representada como NULL, pois a funcao eh a msm pra todas insercoes
		palavra2 = strtok(linha, separador);
		//e a alocacao de memoria para FREQUENCIA eh feita pela palavra 2
		arvore = InsereAVL(arvore, palavra, palavra2, aux, &altura);
		//nao vai criar nodo algum, soh vai alocar um espaco para frequencia da primeira palavra
		strcpy(palavra, palavra2);

        while(palavra2!=NULL){ //essa condicao soh sera verdade se chegou no final do arquivo(eu espero) TEM QUE VER SE EH MESMO ISSO
			if((palavra2=strtok(NULL,separador))==NULL){
				//palavra2 vai receber a palavra da mesma linha se nao chegou ao final da mesma
            	if(fgets(linha,1000,entrada)){
					//mas se chegou ao final da linha, pega a proxima linha e salve salve gurizada!!!
            		palavra2 = strtok(linha,separador);
					//se a LINHA nao era NULA palavra2 vai receber a palavra, else a palavra2 continuara NULA
					fflush(entrada);
				}
			}

			arvore = InsereAVL(arvore, palavra, palavra2, aux, &altura);

			strcpy(palavra, palavra2);	//palavra1 = palavra2
        }

        end=clock(); //le o tempo final
        elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC); //calcula o tempo decorrido em milissegundos
        printf("\nO tempo gasto na tokenizacao do arquivo foi de %ld ms\n",elapsed);
    }
    fclose (entrada); //fecha o arquivo
    imprimeComDistancia(arvore, 0);
    return 0;
}
