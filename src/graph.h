#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

#define NUMTERMINAIS 11
#define INFINITO (1<<30)

enum terminal{Centro, Norte, Sul, Tupy, VilaNova, Iririu, Itaum, NovaBrasilia, Guanabara, Pirabeiraba, Campus};

using namespace std;

typedef pair<int,int> PII;
typedef std::vector<int> VI;
typedef std::vector<PII> VPII;
typedef std::vector<VPII> VVPII;
typedef std::set<PII> SPII;


class Graph
{
    VVPII grafo;
    VI distancia;
    VI pais;
public:
    void iniciar();
    Graph();
    int dijkstra(int inicio, int destino);
    VI getCaminho(int destino);

};

#endif // GRAPH_H
