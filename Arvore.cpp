#include  <stdio.h>
#include  <stdlib.h>

typedef struct  node Node;

 struct node {
    int valor;
    Node *esquerda;
    Node *direita;
    Node *maior;
 };

Node *alocarNovoNode ( int valor);

Node *inserirItem (Node *raiz, int valor);
Node *buscarItem (Node *raiz, int valor);

void  imprimirEmOrdem (Node *raiz);
void  imprimirEmOrdemInversa (Node *raiz);
void  imprimirPreOrdem (Node *raiz);
void  imprimirPosOrdem (Node *raiz);
void imprimirMaiorElemento (Node *raiz);
void imprimirMenorElemento (Node *raiz);
int imprimirAltura (Node *raiz);


void  printNode (Node *node);

int  main ()
{
    Node *arvore = NULL ;

    printf ( "\n Arvores \n \n " );

    arvore = inserirItem (arvore, 30 );
    arvore = inserirItem (arvore, 18 );
    arvore = inserirItem (arvore, 44 );
    arvore = inserirItem (arvore, 23 );
    arvore = inserirItem (arvore, 10 );
    arvore = inserirItem (arvore, 39 );

    Node *busca = arvore;

	printf ( " \n \n \n EM ORDEM CRESCENTE \n " );

	imprimirEmOrdem (arvore);

	printf ( " \n \n \n EM ORDEM DECRESCENTE \n " );

	imprimirEmOrdemInversa (arvore);

	printf ( " \n \n \n PRE ORDEM \n " );

	imprimirPreOrdem (arvore);


	printf ( " \n \n \n POS ORDEM \n " );

	imprimirPosOrdem (arvore);
	
	printf(" \n \n \n MAIOR ELEMENTO \n ");
	
	imprimirMaiorElemento (arvore);
	
	printf(" \n \n \n MENOR ELEMENTO \n ");
	
	imprimirMenorElemento (arvore);
	
	printf(" \n \n \n ALTURA DA ARVORE \n ");
	
	printf("%d", imprimirAltura (arvore));
}

Node *alocarNovoNode ( int valor )
{
    Node *novo = (Node *) malloc ( sizeof (Node));
    novo->valor = valor;
    novo->esquerda = NULL ;
    novo->direita = NULL ;

    
    return novo;
}

Node *inserirItem (Node *raiz, int valor)
{

    if (raiz == NULL )
    {
        // printf ("Inserindo% d \ n", valor);
        Node *novo = (Node *) malloc ( sizeof (Node));
        novo->valor = valor;
        novo->esquerda = NULL ;
        novo->direita = NULL ;
    

        return novo;
    }
    else
    {
        if (valor <raiz->valor )
        {
            // printf ("Esquerda \ n");
            raiz-> esquerda = inserirItem (raiz->esquerda , valor);
        }
        else if (valor> raiz->valor )
        {
            // printf ("Direita \ n");
            raiz->direita = inserirItem (raiz->direita , valor);
        }
        else
        {

            printf ( " Valor ja inserido! \n \n " );
        }
    }
    // system ("PAUSE");
    return raiz;
}

Node* buscarItem (Node *raiz, int valor) {


    if (raiz == NULL ) {
       	printf ( " Valor : %d não encontrado \n " , valor);
       	return  NULL ;

    }
    else if (valor == raiz->valor ) {
    	printf ( " Valor : %d \n " , valor);
        return raiz;
    } 
    else if (valor <raiz->valor ) {
        return  buscarItem (raiz->esquerda , valor);
    } 
    else if  (valor> raiz->valor ) {
        return  buscarItem (raiz->direita , valor);
    }
    else if  (valor> raiz->valor ) {
        return  buscarItem (raiz->maior, valor);
    }
}

void  imprimirEmOrdem (Node *raiz)
{
	if (raiz!= NULL ) {
		imprimirEmOrdem (raiz->esquerda );
		printNode (raiz);
		imprimirEmOrdem (raiz->direita );
	}
}

void  imprimirEmOrdemInversa (Node *raiz)
{
	if (raiz!= NULL ) {
		imprimirEmOrdemInversa (raiz->direita );
		printNode (raiz);
		imprimirEmOrdemInversa (raiz->esquerda );
	}
}

void  imprimirPreOrdem (Node *raiz) {
	if (raiz!= NULL ) {
		printNode (raiz);
		imprimirPreOrdem (raiz->esquerda );
		imprimirPreOrdem (raiz->direita );
	}
}

void  imprimirPosOrdem (Node *raiz) {
	if (raiz!= NULL ) {
		imprimirPosOrdem (raiz->esquerda );
		imprimirPosOrdem (raiz->direita );
		printNode (raiz);
	}
}

void imprimirMaiorElemento(Node *raiz) {
    node *aux = new node;
    aux = raiz;
    if (aux != NULL) {
        int numero = aux->valor;

        while (aux != NULL) {
            if (aux->valor >= numero) {
                numero = aux->valor;
                aux = aux->direita;
                if (aux == NULL) {
                    printf("%d", numero);
                }
            }
        }
    } else {
        printf("Arvore vazia.");
    }
}

void imprimirMenorElemento(Node *raiz) {
    node *aux = new node;
    aux = raiz;
    if (aux != NULL) {
        int numero = aux->valor;

        while (aux != NULL) {
            if (aux->valor <= numero) {
                numero = aux->valor;
                aux = aux->esquerda;
                if (aux == NULL) {
                    printf("%d", numero);
                }
            }
        }
    } else {
        printf("Arvore vazia.");
    }
}

int imprimirAltura(Node *raiz) {
    int alturaEsquerda, alturaDireita;

    if (raiz == NULL) {
        return 0;
    }

    alturaEsquerda = imprimirAltura(raiz->esquerda);
    alturaDireita = imprimirAltura(raiz->direita);

    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}



void  printNode (Node *node)
{
    printf ( " %d \n " , node->valor );
}
