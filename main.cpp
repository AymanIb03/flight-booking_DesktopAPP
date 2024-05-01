#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Structure pour stocker une date
struct Date {
    int jour;
    int mois;
    int annee;
};

// Classe Passager
class Passager {
private:
    int idPassager;
    string nom;
    string telephone;
    string numeroPasseport;
    vector<int> reservations; // Stocke les identifiants des r�servations

public:
    // Constructeur
    Passager(int id, const string& nom, const string& tel, const string& passeport)
        : idPassager(id), nom(nom), telephone(tel), numeroPasseport(passeport) {}

    // M�thodes getter et setter pour idPassager
    int getIdPassager() const { return idPassager; }
    void setIdPassager(int id) { idPassager = id; }

    // M�thodes getter et setter pour nom
    const string& getNom() const { return nom; }
    void setNom(const string& n) { nom = n; }

    // M�thodes getter et setter pour telephone
    const string& getTelephone() const { return telephone; }
    void setTelephone(const string& tel) { telephone = tel; }

    // M�thodes getter et setter pour numeroPasseport
    const string& getNumeroPasseport() const { return numeroPasseport; }
    void setNumeroPasseport(const string& num) { numeroPasseport = num; }

    // M�thode pour ajouter une r�servation
    void ajouterReservation(int idReservation) {
        reservations.push_back(idReservation);
    }

    // M�thode pour afficher la facture de paiement
    void afficherFacture()  {
        // Afficher les informations du passager
        cout << "Identifiant passager: " << idPassager << endl;
        cout << "Nom passager: " << nom << endl;

        // Afficher les r�servations
        cout << "Reservations:" << endl;
        for (int id : reservations) {
            cout << "  " << id << endl;
        }
    }

};

// Classe Vol
class Vol {
protected:
    string numeroVol;
    string aeroportDepart;
    string aeroportArrivee;
    Date dateDepart;
    Date dateArrivee;
    int placesDisponibles;
    double prix;

public:
    // Constructeur
    Vol(const string& numVol, const string& depart, const string& arrivee,
        const Date& dateDep, const Date& dateArr, int places, double prix)
        : numeroVol(numVol), aeroportDepart(depart), aeroportArrivee(arrivee),
          dateDepart(dateDep), dateArrivee(dateArr), placesDisponibles(places), prix(prix) {}

    // M�thodes getter et setter pour numeroVol
    const string& getNumeroVol() const { return numeroVol; }
    void setNumeroVol(const string& num) { numeroVol = num; }

    // M�thodes getter et setter pour aeroportDepart
    const string& getAeroportDepart() const { return aeroportDepart; }
    void setAeroportDepart(const string& aeroport) { aeroportDepart = aeroport; }

    // M�thodes getter et setter pour aeroportArrivee
    const string& getAeroportArrivee() const { return aeroportArrivee; }
    void setAeroportArrivee(const string& aeroport) { aeroportArrivee = aeroport; }

    // M�thodes getter et setter pour dateDepart
    const Date& getDateDepart() const { return dateDepart; }
    void setDateDepart(const Date& date) { dateDepart = date; }

    // M�thodes getter et setter pour dateArrivee
    const Date& getDateArrivee() const { return dateArrivee; }
    void setDateArrivee(const Date& date) { dateArrivee = date; }

    // M�thodes getter et setter pour placesDisponibles
    int getPlacesDisponibles() const { return placesDisponibles; }
    void setPlacesDisponibles(int places) { placesDisponibles = places; }

    // M�thodes getter et setter pour prix
    double getPrix() const { return prix; }
    void setPrix(double prix) { prix = prix; }

    // M�thode pour r�server un vol
    virtual bool reserver() {
        if (placesDisponibles > 0) {
            placesDisponibles--;
            cout<< "reservation effectu�e";
            return true;
        } else {
            cout << "Plus de places disponibles sur ce vol." << endl;
            return false;
        }
    }
};

// Classe VolEconomique (d�riv�e de la classe Vol)
class VolEconomique : public Vol {
public:
    // Constructeur
    VolEconomique(const string& numVol, const string& depart, const string& arrivee,
                  const Date& dateDep, const Date& dateArr, int places, double prix)
        : Vol(numVol, depart, arrivee, dateDep, dateArr, places, prix) {}
};

// Classe VolBusiness (d�riv�e de la classe Vol)
class VolBusiness : public Vol {
private:
    string confort;

public:
    // Constructeur
    VolBusiness(const string& numVol, const string& depart, const string& arrivee,
                const Date& dateDep, const Date& dateArr, int places, double prix, const string& conf)
        : Vol(numVol, depart, arrivee, dateDep, dateArr, places, prix), confort(conf) {}
};

// Classe Reservation
class Reservation {
private:
    int idReservation;
    Date dateReservation;
    Passager* passager;
    Vol* vol;
    double totalAPayer;

public:
    // Constructeur
    Reservation(int id, const Date& date, Passager* p, Vol* v, double total)
        : idReservation(id), dateReservation(date), passager(p), vol(v), totalAPayer(total) {}

    // M�thodes getter et setter pour idReservation
    int getIdReservation() const { return idReservation; }
    void setIdReservation(int id) { idReservation = id; }

    // M�thodes getter et setter pour dateReservation
    const Date& getDateReservation() const { return dateReservation; }
    void setDateReservation(const Date& date) { dateReservation = date; }

    // M�thodes getter et setter pour passager
    Passager* getPassager() const { return passager; }
    void setPassager(Passager* p) { passager = p; }

    // M�thodes getter et setter pour vol
    Vol* getVol() const { return vol; }
    void setVol(Vol* v) { vol = v; }

    // M�thodes getter et setter pour totalAPayer
    double getTotalAPayer() const { return totalAPayer; }
    void setTotalAPayer(double total) { totalAPayer = total; }

    // M�thode pour afficher les d�tails de la r�servation
    void afficherDetails() const {
        cout << "identifiant Passager: " << passager->getIdPassager();
        cout << " Passport: " << passager->getNumeroPasseport()<< endl;
        cout << " Nom Passager: " << passager->getNom() << endl;
        cout<<"Reservation :";
        cout << "ID Reservation: " << idReservation << endl;
        cout << "Date Reservation: " << dateReservation.jour << "/" << dateReservation.mois << "/" << dateReservation.annee << endl;
        cout << "Num�ro de Vol: " << vol->getNumeroVol() << endl;
        cout << "prix: " << vol->getPrix() << endl;
        cout << "Total a payer: " << totalAPayer << endl;
    }
};

// Classe Paiement
class Paiement {
private:
    int idPaiement;
    double montant;
    Date datePaiement;
    string methodePaiement;
    Reservation* reservation;

public:
    // Constructeur
    Paiement(int id, double montant, const Date& date, const string& methode, Reservation* res)
        : idPaiement(id), montant(montant), datePaiement(date), methodePaiement(methode), reservation(res) {}

    // M�thodes getter et setter pour idPaiement
    int getIdPaiement() const { return idPaiement; }
    void setIdPaiement(int id) { idPaiement = id; }

    // M�thodes getter et setter pour montant
    double getMontant() const { return montant; }
    void setMontant(double montant) { montant = montant; }

    // M�thodes getter et setter pour datePaiement
    const Date& getDatePaiement() const { return datePaiement; }
    void setDatePaiement(const Date& date) { datePaiement = date; }

    // M�thodes getter et setter pour methodePaiement
    const string& getMethodePaiement() const { return methodePaiement; }
    void setMethodePaiement(const string& methode) { methodePaiement = methode; }

    // M�thodes getter et setter pour reservation
    Reservation* getReservation() const { return reservation; }
    void setReservation(Reservation* res) { reservation = res; }
    // M�thode pour effectuer le paiement
    void effectuerPaiement() {
        // V�rifier la m�thode de paiement
        if (methodePaiement == "carte") {
            cout << "Paiement par carte effectu� pour un montant de " << montant << " euros." << std::endl;
        } else if (methodePaiement == "espece") {
            cout << "Paiement en esp�ces effectu� pour un montant de " << montant << " euros." << std::endl;
        } else if (methodePaiement == "virement") {
            cout << "Paiement par virement bancaire effectu� pour un montant de " << montant << " euros." << std::endl;
        } else {
            cout << "M�thode de paiement non reconnue." << std::endl;
        }
    }
};

int main() {

    vector<Vol*> vols; // Vecteur pour stocker les vols
    int nombreDeVols;
    cout << "Combien de vols souhaitez-vous ajouter ? ";
    cin >> nombreDeVols;

    for (int i = 0; i < nombreDeVols; i++) {
        // Demander les d�tails du vol � l'utilisateur
        string numeroVol, aeroportDepart, aeroportArrivee;
        Date dateDepart, dateArrivee;
        int placesDisponibles;
        double prix;

        cout << "Vol " << i+1 << ":" << endl;
        cout << "Num�ro de vol : "<<endl;
        cin >> numeroVol;
        cout << "A�roport de d�part : "<<endl;
        cin >> aeroportDepart;
        cout << "A�roport d'arriv�e : "<<endl;
        cin >> aeroportArrivee;
        cout << "Date de d�part (jour mois ann�e) : "<<endl;
        cin >> dateDepart.jour >> dateDepart.mois >> dateDepart.annee;
        cout << "Date d'arriv�e (jour mois ann�e) : "<<endl;
        cin >> dateArrivee.jour >> dateArrivee.mois >> dateArrivee.annee;
        cout << "Nombre de places disponibles : "<<endl;
        cin >> placesDisponibles;
        cout << "Prix : "<<endl;
        cin >> prix;

        // Cr�er un nouvel objet Vol avec les d�tails fournis
        Vol* nouveauVol = new Vol(numeroVol, aeroportDepart, aeroportArrivee,
                                  dateDepart, dateArrivee, placesDisponibles, prix);

        // Ajouter le vol au vecteur
        vols.push_back(nouveauVol);
    }
for (auto it = vols.begin(); it != vols.end(); it++) {
    cout << "Num�ro de vol : " << (*it)->getNumeroVol() << endl;
    cout << "A�roport de d�part : " << (*it)->getAeroportDepart() << endl;
    cout << "A�roport d'arriv�e : " << (*it)->getAeroportArrivee() << endl;
    cout << "Date de d�part : " << (*it)->getDateDepart().jour << "/" << (*it)->getDateDepart().mois << "/" << (*it)->getDateDepart().annee << endl;
    cout << "Date d'arriv�e : " << (*it)->getDateArrivee().jour << "/" << (*it)->getDateArrivee().mois << "/" << (*it)->getDateArrivee().annee << endl;
    cout << "Places disponibles : " << (*it)->getPlacesDisponibles() << endl;
    cout << "Prix : " << (*it)->getPrix() << endl;
}



    return 0;
}
