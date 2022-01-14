#ifndef C___TP2_PRODUIT_H
#define C___TP2_PRODUIT_H

#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Produit {

public:

    // CONSTRUCTEUR
    Produit(string nomproduit, string description, int nombre, float prix);
    Produit();

    // GETTERS
    string nomproduit() const;
    string description() const;
    int nombre() const;
    float prix() const;

    // SETTERS
    void setNomproduit(const string &nomproduit);

    void setDescription(const string &description);

    void setPrix(float prix);

    //METHODE CHMT QUANTITÉ
    void chgmtquantite(int nvl_quantite);

    //AFFICH PRODUIT
    void affichproduit();

    //SETTER
    void setNombre(int stock);

    // SURCHARGE OPERATOR <<
    void afficher(std::ostream &flux) const;

private:
    string _nomproduit;
    string _description;
    int _nombre;
    float _prix;

};

#endif //C___TP2_PRODUIT_H
