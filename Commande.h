#ifndef C___TP2_COMMANDE_H
#define C___TP2_COMMANDE_H

#include <ostream>
#include <string>
#include <vector>
#include "Produit.h"
#include "Client.h"
#include "Commande.h"
using namespace std;

class Commande {

public:

    // CONSTRUCTEUR
    Commande(const Client &client, const vector<Produit> &produit, bool livree);
    Commande();

    // GETTERS
    const Client &client() const;
    const vector<Produit> &l_produit() const;
    bool livree() const;

    // SETTER
    void setLivree(bool livree);
    void setClient(const Client &client);
    void setLProduit(const vector<Produit> &lProduit);

    // SURCHARGE OPERATOR <<
    void afficher(std::ostream &flux) const;

    //affichage d'une commande
    void affichcommande();

private:
    Client _client;
    vector<Produit> _l_produit;
    bool _livree;

};

#endif //C___TP2_COMMANDE_H
