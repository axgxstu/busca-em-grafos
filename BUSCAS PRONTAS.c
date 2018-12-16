#include <stdio.h>


void imprime_matriz(unsigned int n, unsigned int X[n][n])
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			
			printf("%d\t", X[i][j]);
		}
		printf("\n");
	}
}

void matriz_de_arquivo(unsigned int n, unsigned int adjacencias[n][n], char* caminho)
{
	int i, j;
	
	FILE *f;
  	f = fopen(caminho, "r");
	
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; j++)
		{
			if (!fscanf(f, "%d", &adjacencias[i][j])) 
           		break;
		}	
	}

	fclose(f);

}

void push(unsigned int n, unsigned int* cabeca, unsigned int* cauda, unsigned int fila[n], unsigned int valor)
{
	// caso da fila cheia
	if ( (*cauda - *cabeca) == (n - 1) )
	{
		printf("Fila cheia!\n");
	} else
	{
		// caso da fila vazia
		if (*cabeca > *cauda)
		{
			*cabeca = 0;
			*cauda = 0;
		} else 
		{
			*cauda = *cauda + 1;		
		}
		fila[*cauda % n] = valor;
	}
	
}

int pop(unsigned int n, unsigned int* cabeca, unsigned int* cauda, unsigned int fila[n])
{
	unsigned int retorno;
	
	if (*cabeca > *cauda)
	{
		printf("Fila vazia!\n");
		return -1;
	}
	
	retorno = fila[*cabeca % n];
	*cabeca = *cabeca + 1;
	return retorno;
}

void busca_em_largura(unsigned int n, unsigned int adjacencias[n][n], unsigned int raiz)
{
	
	/* esse vai por camadas, visitando os adjacentes do vértice raiz primeiro, antes de 
	 continuar com os próximos;*/
    	
	unsigned int cabeca = 0;
	unsigned int cauda = -1;
	unsigned int fila[n];
	unsigned int visitado[n];
	unsigned int i, j;
     	
	for (i=0; i< n; i++)
	{
	
	visitado[i] = 0;
	
	}
	
	push(n, &cabeca, &cauda, fila, raiz);
	visitado[raiz] = 1;
	 
    while ((j = pop(n, &cabeca, &cauda, fila)) != -1)
	{
		
    printf("%d", j);
    
    
    	for(i=0;i<n; i++) 
		{
    			if (adjacencias[i][j] > 0 && visitado[i] == 0){
    				push (n, & cabeca, &cauda, fila, i);
    				visitado[i] = 1;
    				
    				
				}
    
		}	
	
	}
}

void busca_em_profundidade(unsigned int n, unsigned int adjacencias[n][n], unsigned int raiz, unsigned visitado[n])
{
		int i;

	printf("%d\t", raiz);
	visitado[raiz] = 1;

	for (i = 0; i < n; i++)
	{
		if (adjacencias[i][raiz] > 0 && visitado[i] == 0)
		{
			busca_em_profundidade(n, adjacencias, i, visitado);
		}
	}
	
}	

unsigned int verifica(
unsigned int n, unsigned int adjacencias[n][n], unsigned int raiz, int j[n])
{
	unsigned int i;

	unsigned int contador= 0;

	for (i = 0; i < n; i++)
	{
		if (adjacencias[i][raiz] > 0)
		{
			if (j[i] == -1)
			{
				j[i] = raiz;
				printf("\n %d", raiz, i);
				contador += verifica(n, adjacencias, i, j);
			}
			else if
			{
				if (j[raiz] != i)
				{
					printf("\n %d ", raiz, i);
					printf("Achei o ciclo, sucesso, Gui!");
					contador += 1;
				}
			}
		}
	}
	return contador;
}

unsigned int conexao(unsigned int n, int j[n])
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		printf("\n %d: %d",j[i]);
		if (j[i] == -1)
			return 0;
	}

	return 1;
}


int main()
{	
	
	int i;
	int j;
	
	unsigned int n = 5;
	unsigned int adjacencias[n][n];
	unsigned int raiz;
	
	
	matriz_de_arquivo(n, adjacencias, "instancia1.txt");
	
	imprime_matriz(n, adjacencias);
	printf("\nBusca em largura: ");
	busca_em_largura(n, adjacencias, raiz);
	busca_em_profundidade(n, adjacencias, 3);
	

		
	
	return 0;
}
