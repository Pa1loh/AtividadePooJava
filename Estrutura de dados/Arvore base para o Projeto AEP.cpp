#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tipoElemento
{
	int id;
	char senha[20];
	char email[40];
	char nome[20];
}TElemento;


typedef struct tipoN
{
	TElemento elemento;
	struct tipoN *esq, *dir;
}TNo;



void inserirNaoRecursivo (TNo *&raiz, TElemento *elemento)
{
	TNo *novoN;
	novoN = new TNo;
	novoN->elemento.id = elemento->id;
	novoN->esq = NULL;
	novoN->dir = NULL;

	if (raiz == NULL)
	{
		raiz = novoN;
	}
	else
	{
		TNo *aux;
		aux = raiz;
		int inseriu = 0;

		while (inseriu == 0)
		{
			if (novoN->elemento.id < aux->elemento.id)
			{
				if (aux->esq == NULL)
				{
					aux->esq = novoN;
					inseriu = 1;
				}
				else
				{
					aux = aux->esq;
				}
			}
			else
			{
				if (aux->dir == NULL)
				{
					aux->dir = novoN;
					inseriu = 1;
				}
				else
				{
					aux = aux->dir;
				}
			}
		}
	}
}



TNo* inserir (TNo *raiz, TElemento *elemento)
{
	if (raiz == NULL)
	{
		raiz = new TNo;
		raiz->elemento.id = elemento->id;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	else
	{
		if (elemento->id < raiz->elemento.id)
		{
			 raiz->esq = inserir (raiz->esq, elemento);
		}
		else
		{
			raiz->dir = inserir (raiz->dir, elemento);
		}
	}
	return raiz;
}

void lerDados (TElemento *elemento)
{
	printf("\n Informe o novo id para elemento: ");
	scanf("%d", &elemento->id);
}

void preOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		printf("\n Id: %d", raiz->elemento.id);
		preOrdem (raiz->esq);
		preOrdem (raiz->dir);
	}
}

void emOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		emOrdem (raiz->esq);
		printf("\n Id: %d", raiz->elemento.id);
		emOrdem (raiz->dir);
	}
}

void posOrdem (TNo *raiz)
{
	if (raiz != NULL)
	{
		posOrdem (raiz->esq);
		posOrdem (raiz->dir);
		printf("\n Id: %d", raiz->elemento.id);
	}
}


int consultarNaoRecursivo (TNo *auxRaiz, int auxValor)
{
	while ((auxRaiz != NULL) && (auxRaiz->elemento.id != auxValor))
	{
		if (auxValor < auxRaiz->elemento.id)
		{
			auxRaiz = auxRaiz->esq;
		}
		else
		{
			auxRaiz = auxRaiz->dir;
		}
	}
	if (auxRaiz->elemento.id == auxValor)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int consultarRecursivo (TNo *auxRaiz, int auxValor)
{
	if (auxRaiz == NULL)
	{
		return 0;
	}
	else
	{
		if (auxRaiz->elemento.id == auxValor)
		{
			return 1;
		}
		else
		{
			if (auxValor < auxRaiz->elemento.id)
			{
				return consultarRecursivo (auxRaiz->esq, auxValor);
			}
			else
			{
				return consultarRecursivo (auxRaiz->dir, auxValor);
			}
		}
	}
}

int sobeMaiorDireita (TNo *aux)
{
	while (aux->dir != NULL)
	{
		aux = aux->dir;
	}
	return (aux->elemento.id);
}


TNo* remover (TNo *raiz, int auxValor)
{
	if (raiz == NULL)
	{
		printf("\n Elemento nao foi encontrado!");
	}
	else
	{
		if (auxValor < raiz->elemento.id)
		{
			raiz->esq = remover (raiz->esq, auxValor);
		}
		else
		{
			if (auxValor > raiz->elemento.id)
			{
				raiz->dir = remover (raiz->dir, auxValor);
			}
			else
			{
				{
					if (raiz->dir == NULL)
					{
						TNo *aux;
						aux = raiz;
						raiz = raiz->esq;
						free(aux);
					}
					else
					{
						if (raiz->esq == NULL)
						{
							TNo *aux;
							aux = raiz;
							raiz = raiz->dir;
							free(aux);
						}
						else
						{
							raiz->elemento.id = sobeMaiorDireita (raiz->esq);
							raiz->esq = remover (raiz->esq, raiz->elemento.id);
						}
					}
				}
			}
		}
	}
	return raiz;
}


int main()
{
	TNo *raiz;
	raiz = NULL;

	TElemento elemento;

	int opcao;

	do
	{
		printf("\n 01 - Inserir um valor para arvore ");
		printf("\n 03 - Apresentar pre-ordem ");
		printf("\n 04 - Apresentar em-ordem ");
		printf("\n 05 - Apresentar pos-ordem ");
		printf("\n 07 - Consultar um valor - recursivo ");
		printf("\n 08 - Excluir um valor da arvore ");
		printf("\n 0 - Sair agora ");
		printf("\n Escolha uma das  opcoes ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 1:
				{
					lerDados(&elemento);
					raiz = inserir (raiz, &elemento); break;
				}
			case 2:
				{
					lerDados(&elemento);
					inserirNaoRecursivo(raiz, &elemento);
					break;
				}
			case 3: preOrdem (raiz); break;
			case 4: emOrdem (raiz); break;
			case 5: posOrdem (raiz); break;
			case 6:
				{
					int auxValor, encontrou;
					printf("\n Informe valor a ser consultado: ");
					scanf("%d", &auxValor);
					encontrou = consultarNaoRecursivo(raiz, auxValor);
					if (encontrou == 1)
					{
						printf("\n O valor foi Encontrado!");
					}
					else
					{
						printf("\n O valor nao foi encontrado!");
					}
					getch();
					break;
				}
			case 7:
				{
					int auxValor, encontrou;
					printf("\n Informe o valor que deseja ser consultado: ");
					scanf("%d", &auxValor);
					encontrou = consultarRecursivo(raiz, auxValor);
					if (encontrou == 1)
					{
						printf("\n O valor foi Encontrado!");
					}
					else
					{
						printf("\n  O valor nao foi encontrado!");
					}
					getch();
					break;
				}
			case 8:
				{
					int auxValor;
					printf("\n Informe o valor para ser excluido");
					scanf("%d", &auxValor);
					raiz = remover (raiz, auxValor);
				}
		}
	}while (opcao != 0);
}


