#include "acharterminal.h"

acharterminal::acharterminal(VVPIII grafo)
{
    int n = grafo.size();
    distancia = VI(n,INFINITO);
    SPII caminho;
    caminho.insert(make_pair(0,inicio));
    while(caminho.size() > 0){
        PII atual = *caminho.begin();
        caminho.erase(caminho.begin());
        if (atual.first < distancia[atual.second]) {
            distancia[atual.second] = atual.first;
            if (atual.second == destino) {
                break;
            }
            int i;
            for (i = 0; i < grafo[atual.second].size(); ++i) {
                PII d = grafo[atual.second][i];
                int dist = d.second + atual.first;
                caminho.insert(make_pair(dist, d.first));
            }
        }
    }
}

