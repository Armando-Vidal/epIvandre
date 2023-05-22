//--------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: Armando Augusto Marchini Vidal
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int grupo() {
    int grupo = 18;
  return grupo;
}

// 13673072 e 11892556
int nroUSP1() {
    int nroUSP1 = 13673072;
    return nroUSP1 ;
}

int nroUSP2() {
    int nroUSP2 = 11892556;
    return nroUSP2;
}

// elemento das listas de adjacência e de resposta - NAO ALTERE ESTA DEFINICAO
typedef struct estr 
{
      int adj; // elemento
	  int peso; // custo (não precisa ser usado na resposta)
      struct estr *prox;
} NO; //ARESTA ou ADJACENCIA

// vertices do grafo (salas) - use este tipo ao criar o grafo  - NAO ALTERE ESTA DEFINICAO
typedef struct {
       int flag; // para uso na busca em largura e profundidade, se necessario
       bool aberto; // vale true se a sala em questao esta aberta
       int via; // use este campo se precisar computar algum caminho etc.
       //índice do vértice anterior 
	   int dist; // use este campo se precisar computar alguma distância etc.
       //soma dos pesos das areas
       NO* inicio;
} VERTICE;

typedef struct{
    int chave;
} REGISTRO;

typedef struct{
    REGISTRO A[1000];
    int inicio;
    int nroElem;
} FILA;
////////////////////////////{ }
typedef struct grafo{
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;


//grafo criado 
GRAFO *criaGrafo (int v){
  GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO));
  g->vertices = v;
  g->arestas = 0,
  g->adj = (VERTICE*)malloc(v*sizeof(VERTICE));
  int i;
  for (i=0, i<v; i++);
    g->adj[i].inicio = NULL;
    return (g);
}
//adiciona arestas { }
NO *criaNo (int v, int peso){
  NO *temp = (NO *)malloc(sizeof(NO));
  temp-> vertice = v;
  temp->peso = peso;
  temp->prox = NULL;
  return (temp);
}

bool criaAresta (GRAFO *gr, int vi, int vf, int p){
  if(!gr) return(false);
  if((vf<0)||(vf>= gr->vertices))
    return (false);
  if((vi<0)||(vi>= gr->vertices))
    return (false);
  NO *novo = criaNo(vf,p);
  novo->prox = gr->adj[vi].inicio;
  gr->adj[vi].inicio = novo;
  gr->arestas++;
  return (true);
}

////// IMPRIMIR O GRAFO
void imprime(GRAFO *gr){ 
printf("Vertices %d. Arestas %d. \n", gr->vertices, gr->arestas);
  int i;
  for (i=0; i<gr->vertices ; i++){ 
  printf("v%d: ", i);
  NO *No = gr->adj[i].inicio;
  while(No){ 
    printf("v%d(%d)", ad->peso),
      No=No->prox;
  }
    printf("\n");  
  }
}
/* funcao principal
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave);



// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar*/

//Função que cria grapho



/*void criaMatriz (int *ijpeso,int N, int A, int m ){
        
        int tam = 3*A + 1;
        
        printf("%i\n",tam);
        for(int a = 0; a<=N; a++){
            for(int b = 0; b<=N; b++){
                m[a][b] = -1; //matriz de adjacencia inicializada
            }
        } 
        
        int i=0;
        while(i<= tam){
            m[ijpeso[i]][ijpeso[i+1]]=ijpeso[i+2];
            i=i+3;
       }
       
    }
    



Criar laço que percore ijpeso.
    //1. IF VERIFICA SE INDICE+1%3=0
        //SE for, CRIA ARESTA QUE CRIA INDICE-2 com INDICE-1
    //Verifica se Vertice do indice x existe
        //Se existe continue;
        //Else Cria Verticice ijpeso[indice];*/




/*//funções para mexer com a estrutura de Fila
void inicializaFila(FILA * f){
    f->inicio = 0;
    f->nroElem = 0;
}

void entrarFila(FILA * f, int reg){
    if(f->nroElem >= MAX) return;
    int posicao = (f->inicio + f->nroElem) % MAX;
    f->A[posicao].chave = reg;
}

int sairFila(FILA * f){
    if(f->nroElem == 0) return 0;
    int i = f->inicio;
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem--;
    return i;
}

int tamanhoFila(FILA * f){
    return f->nroElem;
}

void zerarFlags(VERTICE * g, int V){
    for(int i = 0; i < V; i++) g[i].flag = 0;
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave)
{
    NO* resp;
	resp = NULL;

//algoritmo de djkstra
    int valor = N+1;
    int m[valor][valor];
    criaMatriz(ijpeso,N,A,m);

    /*FILA * f = (FILA *) malloc(sizeof(FILA));
    inicializaFila(f);
    entrarFila(f, i);*/

for(int a = 0; a<=N; a++){
            for(int b = 0; b<=N; b++){
                printf("%i\n",m[a][b]);
            }
        } 

    /*while(tamanhoFila(f) > 0){
        i = sairFila(f);
        flags[i] = 1;

        for(int j=0; j<V; j++){
            if(m[i][j] == 1 && flags[j] == 0){
                entrarFila(f, j);
                //flags[j] = 1;
            }
        }
        flags[i] = 2;
    }
}*/

    
}

//...

	//return resp;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {


	// aqui vc pode incluir codigo de teste

	// exemplo de teste trivial
    int A = 3;
	int N=3; // grafo de 3 vértices numerados de 1..3
	int aberto[] = {1,1,1}; // todos abertos
	int inicio=1;
	int fim=3;
	int chave=2;
	int ijpeso[]={1,2,10, 2,3,20, 3,1,10};
    

   caminho(N,A,ijpeso,aberto,inicio,fim,chave);

	// o EP sera testado com uma serie de chamadas como esta
	//NO* teste = null;
	//teste = caminho(N, ijpeso, aberto, inicio, fim, chave);
	//return teste;


//como usaro main do grafo do norton
  GRAFO *gr = criaGrafo(5);
  criaAresta(gr,0,1,2);
  criaAresta(gr,1,2,4);
  //
  //
  //
  //

  imprime(gr);




  
}

// por favor nao inclua nenhum código abaixo da função main()
