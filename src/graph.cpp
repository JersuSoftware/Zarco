#include "graph.h"

void Graph::iniciar(){
    grafo = VVPII(NUMTERMINAIS,VPII());
    grafo[Centro].push_back(make_pair(Norte,4100));
    grafo[Centro].push_back(make_pair(Sul,6100));
    grafo[Centro].push_back(make_pair(Tupy,5900));
    grafo[Centro].push_back(make_pair(VilaNova,7600));
    grafo[Centro].push_back(make_pair(Iririu,4600));
    grafo[Centro].push_back(make_pair(Itaum,6200));
    grafo[Centro].push_back(make_pair(NovaBrasilia,6900));
    grafo[Centro].push_back(make_pair(Guanabara,4800));
    grafo[Centro].push_back(make_pair(Campus,7800));
    grafo[Sul].push_back(make_pair(Norte,8800));
    grafo[Sul].push_back(make_pair(Centro,6000));
    grafo[Sul].push_back(make_pair(Itaum,4300));
    grafo[Sul].push_back(make_pair(Campus,11900));
    grafo[Norte].push_back(make_pair(Centro,4100));
    grafo[Norte].push_back(make_pair(Iririu,2900));
    grafo[Norte].push_back(make_pair(VilaNova,7500));
    grafo[Norte].push_back(make_pair(Pirabeiraba,10100));
    grafo[Norte].push_back(make_pair(Sul,8800));
    grafo[Norte].push_back(make_pair(Campus,4400));
    grafo[Tupy].push_back(make_pair(Centro,5900));
    grafo[Tupy].push_back(make_pair(Guanabara,7800));
    grafo[Tupy].push_back(make_pair(Iririu,3700));
    grafo[Itaum].push_back(make_pair(Campus,12800));
    grafo[Itaum].push_back(make_pair(Centro,6200));
    grafo[Itaum].push_back(make_pair(Campus,12800));
    grafo[Itaum].push_back(make_pair(Sul,3900));
    grafo[NovaBrasilia].push_back(make_pair(Centro,6900));
    grafo[Iririu].push_back(make_pair(Centro,4600));
    grafo[Iririu].push_back(make_pair(Campus,4600));
    grafo[Iririu].push_back(make_pair(Norte,2900));
    grafo[Iririu].push_back(make_pair(Campus,4600));
    grafo[Guanabara].push_back(make_pair(Centro,4800));
    grafo[Guanabara].push_back(make_pair(Tupy,7800));
    grafo[Pirabeiraba].push_back(make_pair(Norte,10100));
    grafo[Pirabeiraba].push_back(make_pair(VilaNova,13300));
    grafo[Campus].push_back(make_pair(Norte,4400));
    grafo[Campus].push_back(make_pair(Centro,7800));
    grafo[Campus].push_back(make_pair(Iririu,4600));
    grafo[Campus].push_back(make_pair(Itaum,12800));
    grafo[Campus].push_back(make_pair(Sul,11900));
    grafo[VilaNova].push_back(make_pair(Centro,7600));
    grafo[VilaNova].push_back(make_pair(Pirabeiraba,13300));
    grafo[VilaNova].push_back(make_pair(Norte,7500));
}

int Graph::dijkstra(int inicio, int destino){
    int n = grafo.size();
    distancia = VI(n,INFINITO);
    pais = VI(n,-1);
    SPII caminho;
    caminho.insert(make_pair(0,inicio));
    while(caminho.size() > 0){
        PII atual = *caminho.begin();
        caminho.erase(caminho.begin());
        if (atual.second == destino) {
            break;
        }
        distancia[atual.second] = atual.first;
        unsigned int i;
        for (i = 0; i < grafo[atual.second].size(); ++i) {
            PII d = grafo[atual.second][i];
            int dist = d.second + atual.first;
            if (dist < distancia[d.first]) {
                distancia[d.first] = dist;
                pais[d.first] = atual.second;
                caminho.insert(make_pair(dist,d.first));
            }
        }
    }
    return distancia[destino];
}

VI Graph::getCaminho(int destino){
    VI caminho;
    caminho.push_back(destino);
    for(;;){
        int ultimo = caminho[caminho.size()-1];
        if( pais[ultimo] == -1 ) break;
        caminho.push_back( pais[ultimo] );
    }
    reverse( caminho.begin(), caminho.end() );
    return caminho;
}

Graph::Graph()
{
    iniciar();
}

