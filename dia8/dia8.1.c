#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 10000
#define KPAIRS 1000

typedef struct {
    int x,y,z,id;
} Punto;

typedef struct {
    int u,v;
    double dist;
} Par;

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node *adj[MAXN];
int visited[MAXN];

// --- Distancia ---
double dist(Punto a, Punto b){
    double dx=a.x-b.x, dy=a.y-b.y, dz=a.z-b.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

// --- Comparadores ---
int cmpX(const void *a,const void *b){return ((Punto*)a)->x-((Punto*)b)->x;}
int cmpPar(const void *a,const void *b){
    double d1=((Par*)a)->dist, d2=((Par*)b)->dist;
    return (d1>d2)-(d1<d2);
}

// --- DFS para tamaño de componente ---
int dfs(int u){
    visited[u]=1;
    int size=1;
    for(Node *p=adj[u];p;p=p->next){
        if(!visited[p->v]) size+=dfs(p->v);
    }
    return size;
}

// --- Añadir arista al grafo ---
void add_edge(int u,int v){
    Node *n1=malloc(sizeof(Node));
    n1->v=v; n1->next=adj[u]; adj[u]=n1;
    Node *n2=malloc(sizeof(Node));
    n2->v=u; n2->next=adj[v]; adj[v]=n2;
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

    // Ordenar por X
    qsort(pts,n,sizeof(Punto),cmpX);

    // Generar todos los pares (para simplificar obtener los 1000 más cortos)
    Par *pares=malloc(n*n*sizeof(Par));
    int total=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pares[total].u=pts[i].id;
            pares[total].v=pts[j].id;
            pares[total].dist=dist(pts[i],pts[j]);
            total++;
        }
    }

    // Ordenar pares por distancia
    qsort(pares,total,sizeof(Par),cmpPar);

    // Construir grafo con los KPAIRS pares más cortos
    for(int i=0;i<KPAIRS && i<total;i++){
        add_edge(pares[i].u,pares[i].v);
    }

    // Calcular tamaños de componentes con DFS
    int max1=0,max2=0,max3=0;
    for(int i=0;i<n;i++) visited[i]=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int sz=dfs(i);
            if(sz>max1){max3=max2;max2=max1;max1=sz;}
            else if(sz>max2){max3=max2;max2=sz;}
            else if(sz>max3){max3=sz;}
        }
    }

    printf("Producto de los tres circuitos más grandes: %d\n",max1*max2*max3);

    free(pares);
    return 0;
}

