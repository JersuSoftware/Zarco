#ifndef ACHARTERMINAL_H
#define ACHARTERMINAL_H

using namespace std;

typedef pair<int,int> PII;
typedef std::vector<int> VI;
typedef std::vector<PII> VPII;
typedef std::vector<VPII> VVPII;
typedef std::set<PII> SPII;

class acharterminal
{
public:
    VI distancia;
    acharterminal(VVPII grafo);
};

#endif // ACHARTERMINAL_H
