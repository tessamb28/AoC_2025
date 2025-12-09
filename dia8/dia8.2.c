#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 10000

typedef struct {
    int x,y,z,id;
} Punto;

typedef struct {
    int u,v;
    double dist;
} Arista;

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node *adj[MAXN];
int visited[MAXN];

// --- Distancia euclídea ---
double dist(Punto a,Punto b){
    double dx=a.x-b.x, dy=a.y-b.y, dz=a.z-b.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

// --- Comparador de aristas por distancia ---
int cmpArista(const void *a,const void *b){
    double d1=((Arista*)a)->dist;
    double d2=((Arista*)b)->dist;
    return (d1>d2)-(d1<d2);
}

// --- Añadir arista al grafo ---
void add_edge(int u,int v){
    Node *n1=malloc(sizeof(Node));
    n1->v=v; n1->next=adj[u]; adj[u]=n1;
    Node *n2=malloc(sizeof(Node));
    n2->v=u; n2->next=adj[v]; adj[v]=n2;
}

// --- DFS para comprobar conectividad ---
void dfs(int u){
    visited[u]=1;
    for(Node *p=adj[u];p;p=p->next){
        if(!visited[p->v]) dfs(p->v);
    }
}

int main(int argc,char *argv[]){
    if(argc<2){printf("Uso: %s archivo.txt\n",argv[0]);return 1;}
    FILE *f=fopen(argv[1],"r");
    if(!f){perror("No se pudo abrir archivo");return 1;}

    Punto pts[MAXN]; int n=0; char linea[256];
    while(fgets(linea,sizeof(linea),f)){
        int x,y,z;
        if(sscanf(linea,"%d,%d,%d",&x,&y,&z)==3){
            pts[n].x=x; pts[n].y=y; pts[n].z=z; pts[n].id=n; n++;
        }
    }
    fclose(f);
    printf("Leídos %d puntos\n",n);

    // Generar todas las aristas
    Arista *edges=malloc(n*n*sizeof(Arista));
    int total=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges[total].u=i;
            edges[total].v=j;
            edges[total].dist=dist(pts[i],pts[j]);
            total++;
        }
    }

    // Ordenar aristas por distancia
    qsort(edges,total,sizeof(Arista),cmpArista);

    // Añadir aristas hasta que todo esté conectado
    Arista last;
    for(int i=0;i<total;i++){
        add_edge(edges[i].u,edges[i].v);

        // comprobar conectividad
        for(int k=0;k<n;k++) visited[k]=0;
        dfs(0);
        int count=0;
        for(int k=0;k<n;k++) count+=visited[k];

        if(count==n){ // todo conectado
            last=edges[i];
            break;
        }
    }

    printf("Última conexión entre: (%d,%d,%d) y (%d,%d,%d)\n",
           pts[last.u].x,pts[last.u].y,pts[last.u].z,
           pts[last.v].x,pts[last.v].y,pts[last.v].z);

    long long prod=(long long)pts[last.u].x * (long long)pts[last.v].x;
    printf("Producto de coordenadas X: %lld\n",prod);

    free(edges);
    return 0;
}

