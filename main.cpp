#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include<map>
#include<set>
using namespace std;

// Structure pour stocker une date
struct Date {
    int jour;
    int mois;
    int annee;
};
class Passager;
class Vol;
//class reservation
class Reservation {
private:
    int idReservation;
    Date dateReservation;
    Passager* passager;
    Vol* vol;
    double totalAPayer;

public:
   // Dans la classe Reservation, ajoutez une surcharge de constructeur qui accepte un Vol* plut�t qu'une r�f�rence � Vol
Reservation(int id, Date date, Vol* vol, double Montanttotal)
    : idReservation(id), dateReservation(date), vol(vol), totalAPayer(Montanttotal) {}

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

void afficher()  {
        cout << "ID R�servation: " << idReservation
                  << ", Date: " << dateReservation.jour << "/"
                  << dateReservation.mois << "/" << dateReservation.annee


                  << ", Total � Payer: " << totalAPayer << " dh"
                  << endl;
    }

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
    // M�thode pour afficher les d�tails du passager
void afficherDetails()  {
    cout << "Identifiant passager: " << idPassager << endl;
    cout << "Nom passager: " << nom << endl;
    cout << "T�l�phone: " << telephone << endl;
    cout << "Num�ro de passeport: " << numeroPasseport << endl;
    cout << "Reservations:" << endl;
    for (auto id : reservations) {
        cout << "  " << id << endl;
    }
}

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
    int numeroVol;
    string aeroportDepart;
    string aeroportArrivee;
    Date dateDepart;
    Date dateArrivee;
    int placesDisponibles;
    double prix;
    vector<Reservation*> reservationsvol; // Relation 1 � *
public:
    // Constructeur
    Vol(const int& numVol, const string& depart, const string& arrivee,
        const Date& dateDep, const Date& dateArr, int places, double prix)
        : numeroVol(numVol), aeroportDepart(depart), aeroportArrivee(arrivee),
          dateDepart(dateDep), dateArrivee(dateArr), placesDisponibles(places), prix(prix) {}

    // M�thodes getter et setter pour numeroVol
    const int& getNumeroVol() const { return numeroVol; }
    void setNumeroVol(const int& num) { numeroVol = num; }

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
     // M�thode pour ajouter une r�servation
    void ajouterReservation(Reservation* reservation) {
        reservationsvol.push_back(reservation);
    }
    // M�thode pour afficher les r�servations
void afficherReservations()  {
    cout << "R�servations pour le vol " << numeroVol << ":" << endl;
     for (auto it = reservationsvol.begin(); it != reservationsvol.end(); ++it) {
        cout << "ID R�servation: " << (*it)->getIdReservation() << endl;
        cout << "Date R�servation: " << (*it)->getDateReservation().jour << "/" << (*it)->getDateReservation().mois << "/" << (*it)->getDateReservation().annee << endl;

    }
    }


void affichage()  {
        cout << "Num�ro de vol : " << numeroVol << endl;
        cout << "A�roport de d�part : " << aeroportDepart << endl;
        cout << "A�roport d'arriv�e : " << aeroportArrivee << endl;
        cout << "Date de d�part : " << dateDepart.jour << "/" << dateDepart.mois << "/" << dateDepart.annee << endl;
        cout << "Date d'arriv�e : " << dateArrivee.jour << "/" << dateArrivee.mois << "/" << dateArrivee.annee << endl;
        cout << "Places disponibles : " << placesDisponibles << endl;
        cout << "Prix : " << prix << endl;
    }
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

    // M�thode pour augmenter le prix du vol de 20% si la date de d�part est dans un mois
// et le nombre de places restantes est inf�rieur � 10
void augmenterPrix() {
    // Obtenir la date actuelle
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int moisActuel = now->tm_mon + 1; // tm_mon commence � 0
    int anneeActuelle = now->tm_year + 1900; // tm_year est le nombre d'ann�es depuis 1900

    // V�rifier si la date de d�part est dans un mois et le nombre de places est inf�rieur � 10
    if (dateDepart.annee == anneeActuelle && dateDepart.mois == moisActuel + 1 && placesDisponibles < 10) {
        // Augmenter le prix de 20%
        this->prix = prix + (prix*0.2);
        cout << "Le prix du vol " << numeroVol << " a �t� augment� de 20%." << endl;
    } else {
        // Condition not true , donc l'augmentation de prix n'est pas effectu�e
        cout << "Le prix du vol " << numeroVol << " n'a pas �t� augment�." << endl;
    }
}
};

// Classe VolEconomique (d�riv�e de la classe Vol)
class VolEconomique : public Vol {
public:
    // Constructeur
    VolEconomique(const int& numVol, const string& depart, const string& arrivee,
                  const Date& dateDep, const Date& dateArr, int places, double prix)
        : Vol(numVol, depart, arrivee, dateDep, dateArr, places, prix) {}
};

// Classe VolBusiness (d�riv�e de la classe Vol)
class VolBusiness : public Vol {
private:
    string confort;

public:
    // Constructeur
    VolBusiness(const int& numVol, const string& depart, const string& arrivee,
                const Date& dateDep, const Date& dateArr, int places, double prix, const string& conf)
        : Vol(numVol, depart, arrivee, dateDep, dateArr, places, prix), confort(conf) {}
};

// Classe Reservation


// Classe Paiement
class Paiement {
private:
    int idPaiement;
    double montant;
    Date datePaiement;
    string methodePaiement;
    Reservation& reservation;

public:
    // Constructeur
    Paiement(int id, double mnt,  Date& date,  string& method,  Reservation& res)
        : idPaiement(id), montant(mnt), datePaiement(date), methodePaiement(method), reservation(res) {}

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
    Reservation& getReservation() const { return reservation; }
    void setReservation(Reservation& res) { reservation = res; }


};


int main() {
    system("COLOR 5f");
	cout<<"\n\t\t\t\t AYMAN IBNOUENNADRE AND YASSINE KHABICH PRESENTE : \n \t\t\t\t\t GESTION RESERVATION DE VOL "<<endl;
    vector<Vol*> vols; // Vecteur pour stocker les vols
    deque<Passager> passagers; // deque pour stocker les passagers
    set<Paiement*> paiements;
     int nombrepassagers,numvol,idpass,choix=0,choix1=0,choix2=0,choix3=0,nombreDeVols, nombreReservations;
     multimap<int, Reservation> reservationMap;
    int fonctionnalite=0;
    do {
    cout<<" *****MENU***** "<<endl;
    cout<<" Saisir tout d'abord un vol , passager , reservation puis paiement pour utiliser tous les fonctions "<<endl;
    cout<<"1.GESTION DES VOLS"<<endl;
    cout<<"2.GESTION DES PASSAGERS"<<endl;
    cout<<"3.GESTION DES RESERVATIONS"<<endl;
    cout<<"4.GESTION& DES PAIEMENTS"<<endl;
    cout<<"5.QUITTER"<<endl;
    cout<<"Choisir la fonctionnalite : ";
    cin>>fonctionnalite;
switch(fonctionnalite) {
case 1 : {
    do {
    cout<< "*****Gestion des vols***** " <<endl;
    cout<< "0. saisir des vols "<<endl;
    cout<< "1. afficher la liste des vols "<<endl;
    cout<< "2. modifier un vol "<<endl;
    cout<< "3. supprimer un vol "<<endl;
    cout<<"4. afficher  les nombres de places des vols dont la date de depart dans 12 mois "<<endl;
    cout<<"5. activer l'augementation de prix de vol de 20% si date de depart dans un mois et le nombre de place < 10"<<endl;
    cout<<"6. quitter"<<endl;
    cout<< "entrer votre choix : ";
    cin >>choix;

switch (choix) {
case 0 : {
    cout << "Combien de vols souhaitez-vous ajouter ? ";
    cin >> nombreDeVols;
    for (int i = 0; i < nombreDeVols; i++) {
        // Demander les d�tails du vol � l'utilisateur
        string aeroportDepart, aeroportArrivee;
        Date dateDepart, dateArrivee;
        int placesDisponibles,numeroVol;
        double prix;

        cout << "Vol " << i+1 << ":" << endl;
        cout << "Num�ro de vol : ";
        cin >> numeroVol;
        cout << "A�roport de d�part : ";
        cin >> aeroportDepart;
        cout << "A�roport d'arriv�e : ";
        cin >> aeroportArrivee;
        cout << "Date de d�part (jour mois ann�e) : ";
        cin >> dateDepart.jour >> dateDepart.mois >> dateDepart.annee;
        cout << "Date d'arriv�e (jour mois ann�e) : ";
        cin >> dateArrivee.jour >> dateArrivee.mois >> dateArrivee.annee;
        cout << "Nombre de places disponibles : ";
        cin >> placesDisponibles;
        cout << "Prix : ";
        cin >> prix;

        // Cr�er un nouvel objet Vol avec les d�tails fournis
        Vol* nouveauVol = new Vol(numeroVol, aeroportDepart, aeroportArrivee,
                              dateDepart, dateArrivee, placesDisponibles, prix);
        // Ajouter le vol au vecteur
        vols.push_back(nouveauVol);
    }
     break;
}
case 1: {
for (auto it = vols.begin(); it != vols.end(); it++) {
    (*it)->affichage();
}
break;
}
case 2: {
    int numvol = 0;
    cout << "Saisir le num�ro du vol que vous voulez modifier : ";
    cin >> numvol;
     for (auto it = vols.begin(); it != vols.end(); it++) {
        if ((*it)->getNumeroVol() == numvol) {
                cout<<"vol trouv� "<<endl;
            int attribut;
            do {
                cout << "**** Menu Modification **** : " << endl;
                cout << "1. Num�ro de vol" << endl;
                cout << "2. A�roport de d�part" << endl;
                cout << "3. A�roport d'arriv�e" << endl;
                cout << "4. Date de d�part" << endl;
                cout << "5. Date d'arriv�e" << endl;
                cout << "6. Places disponibles" << endl;
                cout << "7. Prix" << endl;
                cout << "8. Pour finir la modification" << endl;
                cout << "Choisir l'attribut que vous voulez modifier selon son num�ro : ";
                cin >> attribut;

                switch (attribut) {
                    // Cas de modification du num�ro de vol
                    case 1: {
                        int nouveau_numerodevol;
                        cout << "Saisir le nouveau num�ro de vol : ";
                        cin >> nouveau_numerodevol;
                        (*it)->setNumeroVol(nouveau_numerodevol);
                        cout << "Modification effectu�e" << endl;
                        break;
                    }
                    // Cas de modification de l'a�roport de d�part
                    case 2: {
                        string nouveau_aeoroport_depart;
                        cout << "Saisir le nouveau a�roport de d�part : ";
                        cin >> nouveau_aeoroport_depart;
                        (*it)->setAeroportDepart(nouveau_aeoroport_depart);
                        cout << "Modification effectu�e" << endl;
                        break;
                    }
                    case 3 : {
                    string nouveau_aeoroport_darrive;
                   cout<<"saisir le nouveau aeoroport d'arrive : ";
                   cin>>nouveau_aeoroport_darrive;
                   (*it)->setAeroportArrivee(nouveau_aeoroport_darrive) ;
                    cout<<"done"<<endl;
                   break;
                   }
        case 4 : {
        Date nouveau_datedepart;
        cout<<"saisir la nouvelle date de depart : ";
        cout<<"jour : ";
        cin>>nouveau_datedepart.jour;
        cout<<"mois : ";
        cin>>nouveau_datedepart.mois;
        cout<<"annee : ";
        cin>>nouveau_datedepart.annee;
        (*it)->setDateDepart(nouveau_datedepart) ;
        cout<<"done"<<endl;
        break;
        }
          case 5 : {
        Date nouveau_datedarrive;
        cout<<"saisir la nouvelle date d'arrive : ";
        cout<<"jour : ";
        cin>>nouveau_datedarrive.jour;
        cout<<"mois : ";
        cin>>nouveau_datedarrive.mois;
        cout<<"annee : ";
        cin>>nouveau_datedarrive.annee;
        (*it)->setDateDepart(nouveau_datedarrive) ;
        cout<<"done"<<endl;
        break;
        }
        case 6 : {
        int nouveau_nbrdeplace;
        cout<<"saisir le nouveau nombre de place disponible: ";
        cin>>nouveau_nbrdeplace;
        (*it)->setPlacesDisponibles(nouveau_nbrdeplace);
        cout<<"done"<<endl;
        break;
        }
         case 7 : {
        double nouveau_prix;
        cout<<"saisir le nouveau prix ";
        cin>>nouveau_prix;
        (*it)->setPrix(nouveau_prix);
        cout<<"done"<<endl;
        break;
        }
                    case 8:
                        cout << "Modification termin�e" << endl;
                        break;

                    // Cas par d�faut en cas de choix invalide
                    default:
                        cout << "Choix invalide" << endl;
                        break;
                }
            } while (attribut != 8);

        }


    if ((*it)->getNumeroVol() != numvol) {
        cout << "Vol non trouv�" << endl;
    }
}
break;
}

case 3 : {
    int num_vol;
    cout<<"saisir numero de vol que tu veux supprim� : ";
    cin>>num_vol;
for (auto it = vols.begin(); it != vols.end(); /* Pas d'incr�mentation ici */) {
    if ((*it)->getNumeroVol() == num_vol) {
        it = vols.erase(it); // Supprimer l'�l�ment et obtenir un nouvel it�rateur valide
        cout << "Vol supprim� avec succ�s." << endl;
    } else {
        ++it; // Avancez seulement si vous ne supprimez pas cet �l�ment
    }
}
break;
}
case 4 : {
 // Obtenez la date actuelle
    time_t now = time(nullptr);
    tm* current = localtime(&now);
    int currentYear = current->tm_year + 1900;
    int currentMonth = current->tm_mon + 1;

    // Calculez la date dans 12 mois
    int futureYear = currentYear + 1;
    int futureMonth = currentMonth;

    if (futureMonth > 12) {
        futureMonth -= 12;
        futureYear++;
    }

    bool found = false; // Variable pour suivre si un vol a �t� trouv� ou non

    // Parcourez chaque vol dans le vecteur et affichez uniquement ceux dont la date de d�part est dans les 12 prochains mois
    for (auto it = vols.begin(); it != vols.end(); ++it) {
        if (((*it)->getDateDepart().annee == futureYear && (*it)->getDateDepart().mois >= currentMonth) ||
            ((*it)->getDateDepart().annee == futureYear + 1 && (*it)->getDateDepart().mois <= futureMonth)) {
            cout << "Vol " << (*it)->getNumeroVol() << ": Places disponibles = " << (*it)->getPlacesDisponibles() << endl;
            found = true;
        }
    }

    // Si aucun vol n'a �t� trouv�, afficher un message
    if (found==false) {
        cout << "Aucun vol trouv� dont la date de d�part est dans les 12 prochains mois." << endl;
    }
    break;
}



case 5 : {
// Boucle pour parcourir tous les vols et augmenter le prix si n�cessaire
for (auto it = vols.begin(); it != vols.end(); it++) {
    (*it)->augmenterPrix();
}
break;
}
case 6 : {
    cout<<"****by****"<<endl;
    break;
}
 default:
        cout << "Choix invalide" << endl;
        break;


}
}while(choix!=6);
break;
}

case 2 :
    {
     do {
    cout<< "*****Gestion des Passagers***** " <<endl;
    cout<< "1. saisir des Passager "<<endl;
    cout<< "3. trier la liste des vols par nom passager "<<endl;
    cout<<"4. effectuer une reduction 20% si le nombre de passage > 5 "<<endl;
    cout<<"5. afficher pour chaque passager la facture de paiement"<<endl;
    cout<<"6. quitter"<<endl;
    cout<< "entrer votre choix : ";
    cin >>choix1;
switch(choix1) {
    case 1 : {
     cout<<"Combien de passager souhaitez-vous ajouter ?  ";
     cin>>nombrepassagers;
     for(int i=0 ;i < nombrepassagers ; i++)
     {
         int idPassager;
        string nom, telephone, numeroPasseport;

        cout << "Passager " << (i + 1) << " :" << endl;
        cout << "ID du passager: ";
        cin >> idPassager;
        cout << "Nom: ";
        cin >> nom;
        cout << "T�l�phone: ";
        cin >> telephone;
        cout << "Num�ro de passeport: ";
        cin >> numeroPasseport;
         // Affichage des coordonn�es saisies
        cout << "Coordonn�es saisies pour le passager " << (i + 1) << " :" << endl;
        cout << "ID du passager: " << idPassager << endl;
        cout << "Nom: " << nom << endl;
        cout << "T�l�phone: " << telephone << endl;
        cout << "Num�ro de passeport: " << numeroPasseport << endl;
        }
        break;
    }
    case 3 :
        {
            sort(vols.begin(), vols.end(), [](const Vol* a, const Vol* b) {
        return a->getNumeroVol() < b->getNumeroVol();});

         break;

        }


case 4 : {
    double montant;
    auto range = reservationMap.equal_range(1);
    int nombreReservations = distance(range.first, range.second);
    if (nombreReservations > 5) {
        cout << "Passager 1 a plus de 5 r�servations. R�duction de 20 % appliqu�e." << endl;
        for (auto it = range.first; it != range.second; it++) {
            double reduction = montant * 0.2;  // 20 % de r�duction
            double rmontant=(montant - reduction);  // Appliquer la r�duction
        }
    }
    break;
}
case 5:
{
    int idPassager;
    cout << "Saisir l'ID du passager pour afficher sa facture: ";
    cin >> idPassager;

    auto range = reservationMap.equal_range(idPassager);  // Obtenir toutes les r�servations associ�es � cet ID
    if (range.first == range.second) {  // Si la plage est vide
        cout << "Aucune r�servation trouv�e pour le passager avec ID " << idPassager << endl;
    } else {
        double totalPayer = 0;  // Total � payer pour ce passager
        cout << "Facture pour le passager avec ID " << idPassager << ":" << endl;
        for (auto it = range.first; it != range.second; ++it) {  // Parcourir les r�servations associ�es
            it->second.afficher();  // Afficher les d�tails de chaque r�servation
            totalPayer += it->second.getTotalAPayer();  // Ajouter le montant au total
        }
        cout << "Total � payer: " << totalPayer << " dh" << endl;
    }
    break;
}


    case 6 :
        cout<< "*** By ***"<<endl;
        break;
    default :
        cout<<" choix invalide "<<endl;
        break;
}
}while(choix1!=6);
break;
    }
case 3 : {
 do {
    cout<< "*****Gestion des Reservation ***** " <<endl;
    cout<< "1. saisir une reservation "<<endl;
    cout<< "2. afficher la liste des Reservation "<<endl;
    cout<< "3. Modifier une Reservation "<<endl;
    cout<<"4. Supprimer une reservation "<<endl;
    cout<<"5. activer la reduction du 15% au montant global si le paiement est par espece"<<endl;
    cout<<"6. quitter"<<endl;
    cout<< "entrer votre choix : ";
    cin >>choix2;
switch(choix2) {
    case 1 : {
     // Demander � l'utilisateur de remplir le map
 cout << "Donner le num�ro de vol que vous souhaitez r�server : ";
    cin >> numvol;
    for ( auto ir=vols.begin();ir!=vols.end();ir++)  {
      if ((*ir)->getNumeroVol() == numvol && (*ir)->getPlacesDisponibles() > 0) {
            cout << "Vol trouv� et les places sont disponibles" << endl;

        // Demander l'ID du passager
        cout << "Saisir l'ID du passager : ( un vrai id d'un vrai passager d�ja saisi ) ";
        cin >> idpass;

        cout << " vous pouvez r�server votre vol maintenant" << endl;
        cout << "Combien de r�servations au total souhaitez-vous faire pour ce vol ? ";
        cin >> nombreReservations;

        // Saisir les d�tails de chaque r�servation
        for (int i = 0; i < nombreReservations; ++i) {
            // Demander les d�tails de la r�servation
            int idres;
            Date datereser;

            // Demander l'identifiant de la r�servation
            cout << "Entrez l'identifiant de la r�servation : ";
            cin >> idres;
            cout << "Saisir la date (jour mois ann�e) : ";
            cin >> datereser.jour >> datereser.mois >> datereser.annee;

            // Cr�er une nouvelle r�servation
            Reservation nouvelleReservation(idres, datereser, *ir, (*ir)->getPrix());
            // Ins�rer la nouvelle r�servation dans la map
            reservationMap.insert({idpass, nouvelleReservation}); // Utilisez getIdPassager() directement via *ip

            // Mettre � jour le nombre de places disponibles dans le vol
            (*ir)->setPlacesDisponibles(((*ir)->getPlacesDisponibles() - 1));
        }




      }

     else {
        cout << "D�sol�, vol non trouv� ou places �puis�es" << endl;

    }
    }


 break;
}


    case 2 :
        {
            // Parcourir la map reservationMap pour afficher les d�tails de chaque r�servation
cout << "Liste des r�servations : " << endl;
for (const auto& pair : reservationMap) {
    cout << "ID Passager associ� : " << pair.first << endl; // ID du passager associ�
    Reservation reservation = pair.second;
    cout << "  ID R�servation : " << reservation.getIdReservation() << endl; // ID de la r�servation
    cout << "  Date de r�servation : " << reservation.getDateReservation().jour << "/" << reservation.getDateReservation().mois << "/" << reservation.getDateReservation().annee << endl; // Date de r�servation
    cout << "  ID Vol associ� : " << reservation.getVol()->getNumeroVol() << endl; // ID du vol associ�
    cout<<" le Montant Total a paye est : "<<reservation.getTotalAPayer()<<" MAD "<<endl;
}
         break;

        }
        case 3 : {
        // Demander l'ID de la r�servation � modifier
int idReservation;
cout << "Entrez l'ID de la r�servation � modifier : ";
cin >> idReservation;

// Recherche de la r�servation dans la map
auto reservationIt = reservationMap.find(idReservation);
if (reservationIt != reservationMap.end()) {
    // R�servation trouv�e
    Reservation& reservation = reservationIt->second;

    // Demander le nouvel ID du passager
    int nouvelIdPassager;
    cout << "Entrez le nouvel ID du passager : ";
    cin >> nouvelIdPassager;

    // Recherche du nouveau passager dans le deque des passagers
    auto passagerIt = find_if(passagers.begin(), passagers.end(), [nouvelIdPassager](const Passager& passager) {
        return passager.getIdPassager() == nouvelIdPassager;
    });

    if (passagerIt != passagers.end()) {
        // Nouveau passager trouv�
        Passager& nouveauPassager = *passagerIt;

        // Mettre � jour le passager associ� � la r�servation
        reservation.setPassager(&nouveauPassager);

        cout << "Passager associ� � la r�servation mis � jour avec succ�s !" << endl;
    } else {
        // Nouveau passager non trouv�
        cout << "Erreur : Passager avec l'ID " << nouvelIdPassager << " non trouv�." << endl;
    }
} else {
    // R�servation non trouv�e
    cout << "Erreur : R�servation avec l'ID " << idReservation << " non trouv�e." << endl;
}
break;
        }
        case 4 : {
         // Demander l'ID de la r�servation � supprimer
int idReservation;
cout << "Entrez l'ID de la r�servation � supprimer : ";
cin >> idReservation;

// Recherche de la r�servation dans la map
auto reservationIt = reservationMap.find(idReservation);
if (reservationIt != reservationMap.end()) {
    // R�servation trouv�e
    Reservation& reservation = reservationIt->second;

    // R�cup�rer le vol associ� � la r�servation
    Vol* volAssocie = reservation.getVol();

    // Mettre � jour le nombre de places disponibles dans le vol
    volAssocie->setPlacesDisponibles(volAssocie->getPlacesDisponibles() + 1);

    // Supprimer la r�servation de la map
    reservationMap.erase(reservationIt);

    cout << "R�servation avec l'ID " << idReservation << " supprim�e avec succ�s." << endl;
} else {
    // R�servation non trouv�e
    cout << "Erreur : R�servation avec l'ID " << idReservation << " non trouv�e." << endl;
}
       break;
        }

    case 6 :
        cout<< "*** By ***"<<endl;
        break;
    default :
        cout<<" choix invalide "<<endl;
        break;
}
}while(choix2!=6);
break;
}
case 4 :{
          do {
        cout << "***** Menu des Paiements *****"<<endl;
        cout << "1. Ajouter un paiement"<<endl;
        cout << "2. Supprimer un paiement"<<endl;
        cout << "3. Afficher les paiements avec un montant sup�rieur � 3000 dh"<<endl;
        cout << "4. Quitter"<<endl;
        cout << "Entrez votre choix: ";
        cin>>choix3;
          switch(choix3)
{
    case 1 :{
                // Demander l'ID de la r�servation pour effectuer le paiement
                 int idReservation,idPaiement;
                double montant;
                Date datePaiement;
                string methode;
                 cout << "Entrez l'ID de la r�servation pour effectuer le paiement : ";
                 cin >> idReservation;
                 // V�rifier si l'ID de r�servation existe dans la map
auto reservationIt = reservationMap.find(idReservation);
if (reservationIt != reservationMap.end()) {
    cout << "R�servation trouv�e !" << endl;
    cout << "Saisir l'ID du paiement: ";
                cin >> idPaiement;
                cout << "Saisir le montant: ";
                cin >> montant;
                cout << "Saisir la m�thode de paiement: ";
                cin >> methode;
                // V�rifier si la m�thode de paiement est "cash"
if (methode == "cash") {
    // Appliquer la r�duction de 15%
    montant *= 0.85; // Soustraire 15%
}
                cout << "Saisir la date du paiement (jour mois ann�e) : ";
cin >> datePaiement.jour >> datePaiement.mois >> datePaiement.annee;
Reservation& reservation = reservationIt->second;
                // Cr�er un nouvel objet Paiement avec les valeurs saisies
                 Paiement* nouveauPaiement = new Paiement(idPaiement,montant,datePaiement,methode,reservation);
                paiements.insert(nouveauPaiement);
break;
}
else
    cout << "R�servation non trouv�e." << endl;

break;
    }
case 2 :{
          int id_paiement;
                cout << "Saisir l'ID du paiement � supprimer: ";
                cin >> id_paiement;
                 auto it = find_if(paiements.begin(), paiements.end(),
                    [id_paiement](Paiement* paiement) { return paiement->getIdPaiement() == id_paiement; });

                if (it != paiements.end()) {
                    delete *it;  // Supprime le paiement allou� dynamiquement
                    paiements.erase(it);  // Retire le pointeur du set
                    cout << "Paiement supprim� avec succ�s." << endl;
                } else {
                    cout << "Aucun paiement trouv� avec cet ID." << endl;
                }

break;
    }
case 3:
{
    for (const auto& pair : reservationMap) {
        const Reservation& reservation = pair.second;
        if (reservation.getTotalAPayer() > 3000) {  // Condition pour v�rifier le montant
           cout << "Liste des r�servations : " << endl;
    cout << "ID Passager associ� : " << pair.first << endl; // ID du passager associ�
    Reservation reservation = pair.second;
    cout << "  ID R�servation : " << reservation.getIdReservation() << endl; // ID de la r�servation
    cout << "  Date de r�servation : " << reservation.getDateReservation().jour << "/" << reservation.getDateReservation().mois << "/" << reservation.getDateReservation().annee << endl; // Date de r�servation
    cout << "  ID Vol associ� : " << reservation.getVol()->getNumeroVol() << endl; // ID du vol associ�
    cout<<" le Montant Total a paye est : "<<reservation.getTotalAPayer()<<" MAD "<<endl;
}
            }


    break;
}

    case 4:{
        cout << "****by****" << endl;
                break;

    }
}

          }while (choix!=4);
          break;
          }

          case 5 :
            cout<<"****BY****";
            break;



    default:
                        cout << "Choix invalide" << endl;
                        break;
    }
}while(fonctionnalite!=5);

 return 0;
    }
