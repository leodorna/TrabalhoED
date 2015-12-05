#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "AVL.h"

/* Exemplo de abertura e tokeniza??o de um arquivo texto*/

void lowerString(char *palavra)
{
	int i = 0;

	while(palavra[i] != '\0')
	{
		palavra[i] = tolower(palavra[i]);
		printf("a");
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

	//memes

    entrada = fopen (argv[1], "r"); // abre o arquivo para leitura
    if (entrada == NULL){ //se n?o conseguiu abrir o arquivo
        printf ("Erro ao abrir o arquivo %s",argv[1]);
        return 1;
    }
    else // arquivo OK
    {
        start=clock(); //inicia a contagem do tempo;

        //percorre todo o arquivo lendo linha por linha
        while (fgets(linha,1000,entrada)){
            palavra1 = strtok (linha, separador); //considera qquer caractere n?o alfab?tico como separador

            do{
				//palavra2 = strtok (NULL, separador); 			//considera qquer caractere nao alfabetico como separador
                arvore = InsereAVL(arvore, palavra1, &altura); 	//<-- colocar q a palavra 2 ta do lado da 1

				//arvore = InsereAVL(arvore, palavra, &altura);

                palavra1 = strtok (NULL, separador); // printf(" %s", gordaco)
            }while (palavra1 != NULL /*&& palavra2 != NULL*/);

			fflush(entrada);
        }
        end=clock(); //le o tempo final
        elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC); //calcula o tempo decorrido em milissegundos
        printf("\nO tempo gasto na tokenizacao do arquivo foi de %ld ms\n",elapsed);
    }
    fclose (entrada); //fecha o arquivo
    imprimeComDistancia(arvore, 0);
    return 0;
}
