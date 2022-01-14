#include "Magasin.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// SURCHARGE DE L'OPERATEUR << AVEC LES 3 CLASSES____________________________
// (PRODUIT)
ostream& operator<<( ostream &flux, Produit const & produit) {
    produit.afficher(flux);
    return flux;
}
// (CLIENT)
ostream& operator<<( ostream &flux, Client const & client) {
    client.afficher(flux);
    return flux;
}
// (COMMANDE)
ostream& operator<<( ostream &flux, Commande const & commande) {
    commande.afficher(flux);
    return flux;
}
//____________________________________________________________________________

// CONSTRUCTEUR
Magasin::Magasin() {}

// GETTER
const vector<Produit> &Magasin::getProduit() const {
    return _produit;
}

//METHODE ADD PRODUIT (BASE SUR LE TP 1)
    void Magasin::addproduit() {
        int i = 0;  // Pour compter le nombre de création
        Produit Produit;
        string nom;
        char choice = '0';
        int b=0;
        int b1 = 0;
        // Forçage de la valeur b pour revenir au menu (et y pour continuer)
        while (b == 0) {
            std::cout << "Continuer ?" << std::endl << "Yes (y) / No (n)" << std::endl;
            std::cin >> choice;
            // Choix entre : continuer à créer et retourner au menu
            switch(choice){
                case 'y' : case 'Y':
                    b1=0;
                    // PROGRAMME DE CREATION DE Produit
                    // Boucle While avec b1 pour refaire la création de Produit en cas de "non-confirmation"
                    while (b1 == 0) {
                        std::cout << " " << std::endl << "____Creation de nouveau Produit (" << i+1 <<")____" << std::endl;
                        // GESTION NOM PRODUIT
                        std::cout << "NOM :";
                        // GESTION DE LA DUPLICATION DE Produit AVEC MEME NOM
                        // on saute la vérif' si la liste des Produits est vide
                        if (_produit.empty()){
                            getline(cin, nom);
                            getline(cin, nom);
                        }
                        // si la liste des Produits n'est pas vide
                        else{
                            int test_nom =0;
                            // notre variable test s'incremente de 1 jusqu'a la taille de la liste 'Produit'
                            getline(cin, nom);
                            while (test_nom != _produit.size()){
                                getline(cin, nom);
                                test_nom = 0;
                                // la variable test va augmenter de 1 chaque fois que nom sera different du nom du Produit
                                for (auto j = _produit.begin(); j != _produit.end(); ++j) {
                                    if (nom == (*j).nomproduit()){
                                        std::cout << std::endl << "(" << nom << ") ALREADY USED ! TAKE ANOTHER :" << std::endl << std::endl;
                                    }
                                    else
                                        test_nom++;
                                }
                            }
                        }
                        Produit.setNomproduit(nom);
                        string description;
                        int nombre;
                        float prix;
                        cout << "Description du nouveau produit :" << endl;
                        getline(cin, description);
                        Produit.setDescription(description);
                        cout << "Stock :" ;
                        cin >> nombre;
                        Produit.setNombre(nombre);
                        cout << "Prix du nouveau produit :" ;
                        cin >> prix;
                        Produit.setPrix(prix);
                        std::cout << "___________________________________" << std::endl;
                        b1 = 1;
                        // CONFIRMATION
                        int b2 = 0;
                        // Forçage de la valeur y et n pour b2
                        while (b2 == 0) {
                            char c;
                            // AFFICHAGE DES VARIABLES DU Produit
                            Produit.affichproduit();
                            std::cout << " " << std::endl;
                            std::cout << "Confirmer ?" << std::endl << "Yes (y) / No (n)" << std::endl;
                            std::cin >> c;
                            switch (c) {
                                case 'y' :
                                case 'Y':
                                    // INTEGRATION DU Produit DANS LA LISTE DES Produits
                                    i = i+1;
                                    std::cout << " " << std::endl << "Nouveau Produit (" << nom << ") ajoute !" << std::endl;
                                    _produit.push_back(Produit);
                                    b2 = 1;
                                    break;
                                case 'n' :
                                case 'N' :
                                    // CHANGEMENT DES VARIABLES DU Produit| b1 = 0 -> refaire la création
                                    b1 = 0;
                                    b2 = 1;
                                    break;
                                default:
                                    std::cout << "Vous devez : 'Y' ou 'N', svp !" << std::endl;
                            }
                        }
                    }
                    break;
                case 'n' : case 'N':
                    b=1;
                    break;
                default:
                    std::cout << "Vous devez : 'Y' ou 'N', svp !" << std::endl;
            }
        }
        std::cout << "Creation de Produit(s) : termine" << std::endl << "Retour au menu" << std::endl << " " << std::endl;
    }

//PUSH BACK PRODUIT
    void Magasin::ajout_produit_mag_ext(Produit nv_produit) {
        _produit.push_back(nv_produit);
    }

//PUSH BACK CLIENT
    void Magasin::ajout_client_mag_ext(Client nv_client) {
        _client.push_back(nv_client);
    }

//PUSH BACK COMMANDE
void Magasin::ajout_commande_mag_ext(Commande nvl_commande) {
    _commande.push_back(nvl_commande);
}

//METHODE AFFICHAGE DE TOUS LES PRODUTIS
    void Magasin::displayproduits() {
        cout << endl << "AFFICHAGE DE TOUS LES PRODUITS DANS LE MAGASIN" << endl << endl;
        if (_produit.empty())
            cout << "Bahh en faite.. y a pas de produit.." << endl;
        else {
        for (auto i = _produit.begin(); i != _produit.end(); ++i)
            (*i).affichproduit();
        cout << endl;
        }
    }

//METHODE DEMANDE DU NOM
    void Magasin::demande_nom_produit() {
        string nomproduit;
        cout << endl << "quel produit cherchez vous ? On va l'afficher !" << endl;
        getline(cin, nomproduit); //getline fainéant
        getline(cin, nomproduit); //getline qui veut fonctionner
        for (auto i = _produit.begin(); i != _produit.end(); ++i)
            if (nomproduit == (*i).nomproduit())
                (*i).affichproduit();
    }

//METHODE CHGMT SUIVANT NOM
    void Magasin::changement_quantite() {
    bool test_nom = false; // TEST POUR SAVOIR SI LE PRODUIT EXISTE
        displayproduits();
        string nomproduit;
        cout << endl << "quel produit cherchez vous ? On va changer la quantite !" << endl;
        getline(cin, nomproduit);
        getline(cin, nomproduit);
        for (auto i = _produit.begin(); i != _produit.end(); ++i)
            if (nomproduit == (*i).nomproduit()){
                test_nom = true;
                cout << "Quelle est la nouvelle quantite ?" << endl;
                int nv_quantite;
                cin >> nv_quantite;
                (*i).chgmtquantite(nv_quantite);
            }
        // SI LE NOM DE CORRESPOND PAS
    if (!test_nom)
        cout << "Le produit n'existe pas, retour au menu" << endl;
    }

//METHODE SUPPRESSION PRODUIT SUIVANT NOM
void Magasin::supprimer_produit() {
    string nomproduit;
    bool b = false; // VARIABLE DE TEST POUR CONFIRMATION DE CHOIX
    bool test_nom = false; // TEST SI LE PRODUIT EXISTE
    string confirm;
    displayproduits();
    cout << endl << "quel produit cherchez vous ? Il va etre supprimer.. a tout jamais.." << endl;
    getline(cin, nomproduit); // LE PREMIER NE MARCHE PAS
    getline(cin, nomproduit); // LE DEUXIEME OUI, MAIS.. pourquoi ?
    for (auto i = _produit.begin(); i != _produit.end(); ++i)
        if (nomproduit == (*i).nomproduit()){
            test_nom = true;
            (*i).affichproduit();
            // CONFIRMATION
            cout << endl << "Confirmer la suppression du produit et en prendre la responsabilite ? [Yes (y) / No (n)]" << endl;
            while (!b) {
                cin >> confirm;
                if (confirm == "Y" || confirm == "y" || confirm == "N" || confirm == "n"){
                    b = true;
                }
                else {
                cout << "Y OU N ! PAS AUTRE CHOSE, c'est pas possible ca...." << endl;
                cout << "Allez... on reessaye : " << endl;
                }
            }
            if (confirm == "Y" || confirm == "y"){
                cout << "Le produit (" << nomproduit << ") ne fait plus partis du magasin !" << endl;
                _produit.erase(i);
                --i;
            }
            else
                cout << "Le produit (" << nomproduit << ") a ete sauve, pour cette fois.. " << endl;
        }
    // SI LE NOM NE CORRESPOND PAS
    if (!test_nom)
        cout << "Le produit n'existe pas, retour au menu" << endl;
}

//METHODE SUPPRESSION CLIENT SUIVANT NOM
void Magasin::supprimer_client() {
    string idclient;
    bool b = false;
    bool test_id = false;
    string confirm;
    displayclients();
    cout << endl << "quel client (ID) cherchez vous ? Il va etre supprimer.. a tout jamais.." << endl;
    getline(cin, idclient);
    getline(cin, idclient);
    for (auto i = _client.begin(); i != _client.end(); ++i)
        if (idclient == (*i).id()){
            test_id = true;
            (*i).affichclient();
            cout << endl << "Confirmer la suppression du client et en prendre la responsabilite ? [Yes (y) / No (n)]" << endl;
            while (!b) {
                cin >> confirm;
                if (confirm == "Y" || confirm == "y" || confirm == "N" || confirm == "n"){
                    b = true;
                }
                else {
                    cout << "Y OU N ! PAS AUTRE CHOSE, c'est pas possible ca...." << endl;
                    cout << "Allez... on reessaye : " << endl;
                }
            }
            if (confirm == "Y" || confirm == "y"){
                cout << "Le client (" << idclient << ") ne fait plus partis du magasin !" << endl;
                _client.erase(i);
                --i;
            }
            else
                cout << "Le client (" << idclient << ") a ete sauve, pour cette fois.. " << endl;
        }
    if (!test_id)
        cout << "Le client n'existe pas, retour au menu" << endl;
}

// _____________________ Q4 + Q5 __________________________________________________________

//METHODE AJOUT PRODUIT SUIVANT CLIENT
    void Magasin::ajout_produit_client() {
    // SI IL N'Y A PAS DE PRODUITS
    if (_produit.empty())
        cout << "Pas de produit a commander !" << endl;
    else {
        string id_client;
        string nomproduit;
        bool test_produit = false; // TEST LA VALIDITE DU PRODUIT
        bool test_client = false; // TEST LA VALIDITE DU CLIENT
        cout << endl << "Rentrer votre ID de client pour selectionner un produit a ajouter : " << endl;
        cin >> id_client;
        for (auto i = _client.begin(); i != _client.end(); ++i)
            if (id_client == (*i).id()) {
                test_client = true;
                (*i).affichclient();
                displayproduits();
                cout << "Bonjour " << (*i).id() << ", quel produit voulez-vous ?" << endl;
                getline(cin, nomproduit); //getline fainéant
                getline(cin, nomproduit); //getline qui veut fonctionner
                for (auto j = _produit.begin(); j != _produit.end(); ++j)
                    if (nomproduit == (*j).nomproduit() && (*j).nombre() != 0) {
                        (*i).ajout_produit(nomproduit, *j);
                        test_produit = true;
                    }
                // SI LE PRODUIT N'EST PAS VALIDE
                if (!test_produit)
                    cout << "Le produit est en rupture de stock ou n'existe tout simplement pas... retour au menu"
                         << endl;
            }
        // SI LE CLIENT N'EST PAS VALIDE
        if (!test_client)
            cout << "Cet ID de client de me dis rien, vous vous etes trompe je pense.. retour au menu" << endl;
    }
}

// CHANGER LE NOMBRE DE PRODUIT DANS PANIER DE CLIENT
void Magasin::changer_nombre_produit_client() {
    bool test_id = false; // TEST VALIDITE DU CLIENT
    string id_client;
    cout << endl << "Rentrer votre ID de client pour changer le nombre d'un produit du panier : " << endl;
    cin >> id_client;
    for (auto i = _client.begin(); i != _client.end(); ++i)
        if (id_client == (*i).id()) {
            (*i).modif_stock_produit_dans_client(_produit);
            test_id = true;
        }
    // SI LE CLIENT N'EST PAS VALIDE
    if (!test_id)
        cout << "Il n'y a pas de client avec cet ID, appliquez vous svp..." << endl;
        }

//METHODE VIDER LE PANIER DANS CLIENT
    void Magasin::vider_panier_client() {
        string id_client;
        bool test_id = false; // TEST VALIDITE DU CLIENT
        cout << endl << "Quel est votre compte (ID) client ? Nous allons vider votre panier ! " << endl;
        cin >> id_client;
        for (auto i = _client.begin(); i != _client.end(); ++i)
            if (id_client == (*i).id()) {
                cout << "Super " << (*i).id() << ", votre panier est maintenant vide !" << endl;
                if ((*i).panier().empty())
                    cout << "Enfin... meme s'il etait deja vide avant, mais bon..." << endl;
                (*i).vider_panier();
                test_id = true;
            }
    // SI LE CLIENT N'EST PAS VALIDE
    if (!test_id)
        cout << " ERROR 440, pas de client avec cet ID, ..FF.F SEV?A O,,EZA" << endl;
    }

// SUPPRIMER UN PRODUIT DANS PANIER DE CLIENT
void Magasin::supprimer_produit_client(){
    string id_client;
    bool test_id = false; // TEST VALIDITE DU CLIENT
    cout << endl << "Rentrer votre ID de client pour supprimer un article du panier : " << endl;
    cin >> id_client;
    for (auto i = _client.begin(); i != _client.end(); ++i)
        if (id_client == (*i).id()){
            (*i).affichclient();
            (*i).supprimer_produit_dans_client();
            test_id = true;
        }
    // SI LE CLIENT N'EST PAS VALIDE
    if (!test_id)
        cout << "Cet ID ne me dit rien, un ami a vous ?" << endl;
}

//METHODE ADD CLIENT (BASE SUR LE TP1)
void Magasin::addclient() {


    // CREATION DE CLIENT(S)
    int i = 0; // Pour compter le nombre de création
    Client Client;
    string id;
    char choice = '0';
    int b=0;
    int b1 = 0;
    // Forçage de la valeur b pour revenir au menu (et y pour continuer)
    while (b == 0) {
        std::cout << "Continuer ?" << std::endl << "Yes (y) / No (n)" << std::endl;
        std::cin >> choice;
        // Choix entre : continuer à créer et retourner au menu
        switch(choice){
            case 'y' : case 'Y':
                b1=0;
                // PROGRAMME DE CREATION DE CLIENT
                // Boucle While avec b1 pour refaire la création du client en cas de "non-confirmation"
                while (b1 == 0) {
                    std::cout << " " << std::endl << "____Creation d'un nouveau client (" << i+1 <<")____" << std::endl;
                    // GESTION ID
                    std::cout << "ID :";
                    // GESTION DE LA DUPLICATION DE CLIENT AVEC MEME ID
                    // on saute la vérif' si la liste des clients est vide
                    if (_client.empty()){
                        std::cin >> id;
                    }
                        // si la liste des clients n'est pas vide
                    else{
                        int test_id =0;
                        // notre variable test s'incremente de 1 jusqu'a la taille de la liste 'clients'
                        while (test_id != _client.size()){
                            std::cin >> id;
                            test_id = 0;
                            // la variable test va augmenter de 1 chaque fois que idn sera different de l'ID du client
                            for (auto j = _client.begin(); j != _client.end(); ++j) {
                                if (id == (*j).id()){
                                    std::cout << std::endl << "(" << id << ") DEJA PRIS ! PRENEZ-EN UN AUTRE :" << std::endl << std::endl;
                                }
                                else
                                    test_id++;
                            }
                        }
                    }
                    Client.setId(id);
                    // GESTION PRENOM
                    std::string prenom;
                    std::cout << "PRENOM :";
                    std::cin >> prenom;
                    Client.setPrenom(prenom);
                    // GESTION NOM
                    std::string nom;
                    std::cout << "NOM :";
                    std::cin >> nom;
                    Client.setNom(nom);
                    b1 = 1;

                    // CONFIRMATION
                    int b2 = 0;
                    // Forçage de la valeur y et n pour b2
                    while (b2 == 0) {
                        char c;
                        // AFFICHAGE DES VARIABLES DE L'AUTEUR
                        Client.affichclient();
                        std::cout << " " << std::endl;
                        std::cout << "Confirmer ?" << std::endl << "Yes (y) / No (n)" << std::endl;
                        std::cin >> c;
                        switch (c) {
                            case 'y' :
                            case 'Y':
                                // INTEGRATION DE L'AUTEUR DANS LA LISTE DES AUTEURS
                                i = i+1;
                                std::cout << " " << std::endl << "Nouveau client (" << id << ") ajoute !" << std::endl;
                                _client.push_back(Client);
                                b2 = 1;
                                break;
                            case 'n' :
                            case 'N' :
                                // CHANGEMENT DES VARIABLES DE L'AUTEUR | b1 = 0 -> refaire la création
                                b1 = 0;
                                b2 = 1;
                                break;
                            default:
                                std::cout << "Vous devez : 'Y' ou 'N', svp !" << std::endl;
                        }


                    }
                }
                break;
            case 'n' : case 'N':
                b=1;
                break;
            default:
                std::cout << "Vous devez : 'Y' ou 'N', svp !" << std::endl;
        }
    }
    std::cout << "Creation de Client(s) : termine" << std::endl << "Retour au menu" << std::endl << " " << std::endl;
}

//METHODE AFFICHAGE DE TOUS LES CLIENTS
void Magasin::displayclients() {
    cout << "AFFICHAGE DE TOUS LES CLIENTS DANS LE MAGASIN" << endl;
    if (_client.empty())
        cout << "Bahh en faite.. y a pas de client dans votre magasin.." << endl;
    else {
        for (auto i = _client.begin(); i != _client.end(); ++i)
            (*i).affichclient();
    }
}

//METHODE AFFICHAGE D'UN CLIENT A PARTIR DE NOM OU ID
void Magasin::afficher_client_avec_nom_id() {
    string elem;
    bool test_client = false;
    cout << endl << "Quel est votre compte client ? (Rentrer ID ou NOM)" << endl;
    cin >> elem;
    for (auto i = _client.begin(); i != _client.end(); ++i)
        if (elem == (*i).id() || elem == (*i).nom()){
        (*i).affichclient();
        test_client = true;
        }
    // SI LE CLIENT N'EST PAS VALIDE
    if (!test_client)
        cout << "On vous demande le nom ou l'ID et vous arrivez a vous tromper.. alalahhh.." << endl;
}

// _____________________ Q7 __________________________________________________________

// METHODE ADD COMMANDE______
bool test_stock = true;
void Magasin::addcommande(){
    displayclients();
    bool test_id = false; // TEST DE VALIDITE DE CLIENT
    bool b = false; // TEST DE CONFIRMATION
    string confirm;
    cout << endl << "Quel est votre ID de client ? " << endl;
    string id_client;
    cin >> id_client;
    for (auto i = _client.begin(); i != _client.end(); ++i){
        if (id_client == (*i).id()){
            test_id = true;
            // SI LE PANIER EST VIDE
            if ((*i).panier().empty())
                cout << "Votre panier est vide.. petit malin.." << endl;
            else{
                (*i).affichclient();
                // TEST POUR SAVOIR S'IL Y A SUFFISANT DE PRODUIT EN STOCK POUR LA COMMANDE
                if ((*i).valider_commande_stock(_produit)){
            // TEST DE CONFIRMATION
            cout << "Voulez-vous valider votre panier et passer commande ? [Yes (y) / No (n)]" << endl;
            while (!b) {
                cin >> confirm;
                if (confirm == "Y" || confirm == "y" || confirm == "N" || confirm == "n"){
                    b = true;
                }
                else {
                    cout << "Vous savez ce que sont les touche Y et N j'espere ?" << endl;
                    cout << "Le 'Y' est entre le 'T' et le 'U' et le 'N' et entre le 'B' et ',' : " << endl;
                }
            }
            if (confirm == "Y" || confirm == "y") {
                // PHASE DE CREATION DE COMMANDE_______________________
                vector<Produit> sauvegarde_panier;
                sauvegarde_panier = (*i).panier();
                // ICI ON VA ENLEVER LA QUANTITE EXACTE (du panier) DES PRODUITS EN STOCK
                for (auto j = sauvegarde_panier.begin(); j != sauvegarde_panier.end(); ++j){
                    for (auto k = _produit.begin(); k != _produit.end(); ++k){
                        if ((*j).nomproduit() == (*k).nomproduit())
                            (*k).setNombre((*k).nombre() - (*j).nombre());
                    }
                }
                // ON VIDE LE PANIER
                (*i).vider_panier();
                // ON CREE LA COMMANDE
                Commande commande((*i), sauvegarde_panier, false);
                commande.affichcommande();
                _commande.push_back(commande);
                //_____________________________________________________
                }
                }
            }
        }
    }
    // SI LE CLIENT N'EST PAS VALIDE
    if (!test_id && test_stock)
        cout << "Pas d'ID valide, PAS DE COMMANDE !" << endl;
}

//METHODE AFFICHAGE DE TOUTES LES COMMANDES
void Magasin::displaycommandes() {
    cout << endl << "AFFICHAGE DE TOUTES LES COMMANDES PASSEES DANS LE MAGASIN" << endl;
    if (_commande.empty())
        cout << "Bahh en faite.. y a pas de commandes de passees.." << endl;
    else {
        for (auto i = _commande.begin(); i != _commande.end(); ++i)
            (*i).affichcommande();
    }
}

//METHODE AFFICHAGE DE TOUTES LES COMMANDES D'UN CLIENT
void Magasin::displaycommandes_client() {
    cout << "Quel est votre ID de client ? On va afficher toutes les commandes que vous avez passes !" << endl;
    string id_client; // TEST DE VALIDITE DE CLIENT
    bool test_idclient = false;
    cin >> id_client;
    for (auto i = _client.begin(); i != _client.end(); ++i) {
        if (id_client == (*i).id()) {
            test_idclient = true;
            (*i).affichclient();
            cout << "Vos commandes passees sont les suivantes :" << endl;
            for (auto j = _commande.begin(); j != _commande.end(); j++){
                if (id_client == (*j).client().id())
                    (*j).affichcommande();
            }
        }
    }
    // SI LE CLIENT N'EST PAS VALIDE
    if (!test_idclient)
        cout << "Cet ID est completement faux, va falloir trouver mieux pour continuer !" << endl;
}

//METHODE CHANGEMENT DU STATUT D'UNE COMMANDE
void Magasin::changement_statut_commande() {
    cout << "Quel est l'ID du client ? Vous pourrez valider la livraison d'une de ses commandes !" << endl;
    string id_client;
    string confirm;
    bool test_idclient = false; // TEST DE VALIDITE DE CLIENT
    bool test_com_liv = false; // TEST DE VALIDITE DE COMMANDE LIVREE
    cin >> id_client;
    for (auto i = _client.begin(); i != _client.end(); ++i) {
        if (id_client == (*i).id()) {
            test_idclient = true;
            (*i).affichclient();
            cout << "Les commandes passees (non livrees) sont les suivantes :" << endl;
            cout << "(L'affichage se fait au fur et a mesure)" << endl;
            for (auto j = _commande.begin(); j != _commande.end(); j++) {
                if (id_client == (*j).client().id() && !(*j).livree()) {
                    (*j).affichcommande();
                    test_com_liv = true;
                    // PHASE DE CONFIRMATION
                    cout << "Valider la livraison de cette commande ? [Yes (y) / No (n)]" << endl;
                    bool b = false; // TEST DE CONFIRMATION
                    while (!b) {
                        cin >> confirm;
                        if (confirm == "Y" || confirm == "y" || confirm == "N" || confirm == "n") {
                            b = true;
                        } else {
                            cout << "Je crois qu'il y a une difference entre Y/N et " << confirm
                                 << ", vous ne trouvez pas?" << endl;
                            cout << "vous avez encore une chance : " << endl;
                        }
                    }
                    if (confirm == "Y" || confirm == "y") {
                        cout << "COMMANDE LIVREE ! BRAVO !" << endl;
                        (*j).setLivree(true);
                    }
                }
            }
        }
    }
    // SI LE CLIENT N'EXISTE PAS
    if (!test_idclient)
        cout << "Ce client n'a pas pu passer de commande, il n'existe pas..." << endl;
    // SI LE CLIENT N'A PAS COMMANDE NON LIVREE
    if (!test_com_liv && test_idclient)
        cout << "Ce client a deja recu toutes ses commandes !" << endl;
}

//_______________________________ Q8 _____________________________________

// ENREGISTRER LES INFORMATIONS DANS UN FICHIER (FLUX)
void Magasin::enregisrer_fichier(){
// ADAPTER LES CHEMINS DES FICHIERS !

// (PRODUITS)
    string const produitsTXT("C:/Users/admin/Documents/PROJET_TP2_C++/C++ TP2/Fichiers/produits.txt");
    ofstream fluxProduit(produitsTXT.c_str());
    if(fluxProduit) {
        if (_produit.empty())
            fluxProduit << "0 PRODUITS" ;
        else {
            for (auto i = _produit.begin(); i != _produit.end(); ++i)
                fluxProduit << (*i);
        }
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier des produits." << endl;
    }

// (CLIENTS)
    string const clientsTXT("C:/Users/admin/Documents/PROJET_TP2_C++/C++ TP2/Fichiers/clients.txt");
    ofstream fluxClient(clientsTXT.c_str());
    if(fluxClient) {
        if (_client.empty())
            fluxClient << "0 CLIENTS" << endl;
        else {
            for (auto i = _client.begin(); i != _client.end(); ++i) {
                fluxClient << (*i);
            }
        }
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier des clients." << endl;
    }

// (COMMANDES)
    string const commandesTXT("C:/Users/admin/Documents/PROJET_TP2_C++/C++ TP2/Fichiers/commandes.txt");
    ofstream fluxCommandes(commandesTXT.c_str());
    if(fluxCommandes) {
        if (_commande.empty())
            fluxCommandes << "0 COMMANDES" << endl;
        else {
            for (auto i = _commande.begin(); i != _commande.end(); ++i)
                fluxCommandes << (*i);
        }
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier des commandes." << endl;
    }
    cout << "ENREGISTREMENT TERMINE, LE MAGASIN EST SAUVE DANS DES FICHIERS !" << endl;
}

// LIRE LES INFORMATIONS DANS UN FICHIER (FLUX)
void Magasin::lire_fichier(){

// (PRODUITS)
// SUPPRIME LES PRODUITS DANS LE MAGASIN ACTUEL
    while (!_produit.empty()){
        _produit.erase(_produit.begin());
    }
    // INITIALISATION DE VALEURS UTILES
    int i = 1;
    int nb = 0;
    float prix = 0;
    Produit pro;
    string ligne; //Une variable pour stocker les lignes lues
    // CREATION D'UN FLUX AVEC POUR SOURCE LE FICHIER DE DEPART
    ifstream produitsTXT("C:/Users/admin/Documents/PROJET_TP2_C++/C++ TP2/Fichiers/produits.txt");
    if(produitsTXT) {
        while(getline(produitsTXT, ligne)) { //Tant qu'on n'est pas à la fin, on lit
            if (ligne == "0 PRODUITS")
                cout << "Pas de produits a mettre dans le magasin " << endl;
            // CREATION DE PRODUIT ETAPE PAR ETAPE (1, 2, 3 et 4)
            if (i == 1){
                pro.setNomproduit(ligne);
            }
            if (i == 2){
                pro.setDescription(ligne);
            }
            if (i == 3){
                nb = std::stoi(ligne);
                pro.setNombre(nb);
            }
            if (i == 4){
                // ETAPE 4 : ON RENTRE LE PRODUIT DANS LE MAGASIN
                prix = std::stof(ligne);
                pro.setPrix(prix);
                _produit.push_back(pro);
                i = 0;
            }
            ++i;
        }
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier produits.txt en lecture." << endl;
    }

// (CLIENTS)
// SUPPRIME LES CLIENTS DANS LE MAGASIN ACTUEL
    while (!_client.empty()){
        _client.erase(_client.begin());
    }
    // INITIALISATION DE VALEURS UTILES
    bool test_produit = false;
    i = 1;
    vector <Produit> p;
    Client cli;
    // CREATION D'UN FLUX AVEC POUR SOURCE LE FICHIER DE DEPART
    ifstream clientsTXT("C:/Users/admin/Documents/PROJET_TP2_C++/C++ TP2/Fichiers/clients.txt");
    if(clientsTXT) {
        while(getline(clientsTXT, ligne)) { //Tant qu'on n'est pas à la fin, on lit
            if (ligne == "0 CLIENTS")
                cout << "Pas de clients a mettre dans le magasin " << endl;
            if (ligne == "CHANGE"){
                // CHANGE : ON RENTRE LE CLIENT DANS LE MAGASIN
                test_produit = false;
                cli.setPanier(p);
                _client.push_back(cli);
                while (!p.empty()){
                    p.erase(p.begin());
                }
                i = 1;
            }
            else{
                // CREATION DE PRODUIT ETAPE PAR ETAPE (1, 2, 3 et 4)
            if (test_produit){
                if (i == 1){
                    pro.setNomproduit(ligne);
                }
                if (i == 2){
                    pro.setDescription(ligne);
                }
                if (i == 3){
                    nb = std::stoi(ligne);
                    pro.setNombre(nb);
                }
                if (i == 4){
                    // ETAPE 4 : ON RENTRE LE PRODUIT DANS LE MAGASIN
                    prix = std::stof(ligne);
                    pro.setPrix(prix);
                    p.push_back(pro);
                    i = 0;
                }
            }
                // CREATION DE CLIENT ETAPE PAR ETAPE (1, 2, 3 et 4)
            if (i == 1 && !test_produit){
                cli.setId(ligne);
            }
            if (i == 2 && !test_produit){
                cli.setPrenom(ligne);
            }
            if (i == 3 && !test_produit){
                cli.setNom(ligne);
            }
            if (i == 4 && !test_produit){
                if (ligne == "PANIER") {
                    test_produit = true;
                    i = 0;
                }
            }
            ++i;
            }
        }
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier clients.txt en lecture." << endl;
    }

// (COMMANDES)
// SUPPRIME LES COMMANDES DANS LE MAGASIN ACTUEL
    while (!_commande.empty()){
        _commande.erase(_commande.begin());
    }
    // INITIALISATION DE VALEURS UTILES
    i = 1;
    Commande com;
    // CREATION D'UN FLUX AVEC POUR SOURCE LE FICHIER DE DEPART
    ifstream commandesTXT("C:/Users/admin/Documents/PROJET_TP2_C++/C++ TP2/Fichiers/commandes.txt");
    if(commandesTXT) {
        while(getline(commandesTXT, ligne)) { //Tant qu'on n'est pas à la fin, on lit
            if (ligne == "0 COMMANDES")
                cout << "Pas de commandes a mettre dans le magasin " << endl;
            if (ligne == "NON LIVREE" || ligne == "LIVREE"){
                // NON LIVREE OU LIVREE : ON RENTRE LA COMMANDE DANS LE MAGASIN
                if (ligne == "NON LIVREE")
                    com.setLivree(false);
                else
                    com.setLivree(true);
                com.setLProduit(p);
                _commande.push_back(com);
                while (!p.empty()){
                    p.erase(p.begin());
                }
                i = 0;
                test_produit = false;
            }
            if (ligne == "CHANGE"){
                // CHANGE : ON COMMENCE A RENTRER LES PRODUITS
                com.setClient(cli);
                test_produit = true;
                i = 1;
            }
            else{
                // CREATION DE PRODUIT ETAPE PAR ETAPE (1, 2, 3 et 4)
                if (test_produit){
                    if (i == 1){
                        pro.setNomproduit(ligne);
                    }
                    if (i == 2){
                        pro.setDescription(ligne);
                    }
                    if (i == 3){
                        nb = std::stoi(ligne);
                        pro.setNombre(nb);
                    }
                    if (i == 4){
                        // ETAPE 4 : ON RENTRE LE PRODUIT DANS LE MAGASIN
                        prix = std::stof(ligne);
                        pro.setPrix(prix);
                        p.push_back(pro);
                        i = 0;
                    }
                }
                // CREATION DE CLIENT ETAPE PAR ETAPE (1, 2, 3 et 4)
                if (i == 1 && !test_produit){
                    cli.setId(ligne);
                }
                if (i == 2 && !test_produit){
                    cli.setPrenom(ligne);
                }
                if (i == 3 && !test_produit){
                    cli.setNom(ligne);
                }
                if (i == 4 && !test_produit){
                    if (ligne == "PANIER") {
                        test_produit = true;
                        i = 0;
                    }
                }
                ++i;
            }
        }
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier clients.txt en lecture." << endl;
    }
    cout << "LECTURE TERMINEE, LE MAGASIN EST PRET A FONCTIONNE !" << endl;
}