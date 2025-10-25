    #include <iostream>
    #include "book.h"

    //Constructeurs par defaut
    Book::Book():
        title = "";
        author = "";
        isbn = "";
        isAvaible = true;
        borrowerName = "";
    {}

    //Constructeur avec param
    Book::Book(const string& titre, const string& auteur, const string& _isbn){
        this->title = titre;
        this->author = auteur;
        this->isbn = _isbn;
        this->isAvailable = true;
        this->borrowerName = "";
    }

    //getters
    Book::string getTitle() const {
        return title;
    }
    Book::string getAuthor() const{
        return author;
    }
    Book::string getISBN() const {
        return isbn;
    }
    Book::bool getAvailability() const {
        return isAvaible;
    }
    Book::string getBorrowerName() const{
        return borrowerName;
    }

    //setters
    Book::void setTitle(const string& titre) {
        title = titre;
    }
    Book::void setAuthor(const string& auteur){
        author = auteur;
    }
    Book::void setISBN(const string& _isbn){
        isbn = _isbn;
    }
    Book::void setAvailability(bool available){
        isAvailable = available;
    }
    Book::void setBorrowerName(const string& name){
        borrowerName = name;
    }

    //Methodes
    //Emprunter un livre, impossible si il n est pas dispo
    Book::void checkOut(const string& borrower){
    if(isAvailable){
            isAvailable = false;
            borrowerName = borrower;
        } else {
            cout << "Le livre n'est pas disponible pour le moment." << endl;
    }

    }
    //Retourner un live, devient disponinle 
    Book::void returnBook(){
        isAvailable = true;
        borrowerName = "";
    }

    //representation du livre (titre, auteur, isbn, disponibilite)
    Book::string toString() const {
        return "Titre: " + title + ", Auteur: " + author + ", ISBN: " + isbn + ", Disponible: " + (isAvailable ? "Disponible" : "Indisponible") + (isAvailable ? "" : ", Emprunte par: " + borrowerName);
    }

    //format comme dans books.txt
    Book::string toFileFormat() const {
    string line = title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerName;
    return line;
    }

    Book::void fromFileFormat(const string& line) {
    size_t position =0 , nextPosition;

    //titre
    nextPosition = line.find('|', position); //va trouver le 1er | a partir de position(0) et ca prendre le titre avant le |
    title = line.substr(position, nextPosition - position); //extrait le titre, ce qui est entre position et nextPosition
    position = nextPosition +1; //deplace position apres le 1er |

    //auteur
    nextPosition = line.find('|', position);
    author = line.substr(position, nextPosition - position);
    position = nextPosition +1;

    //isbn
    nextPosition = line.find('|', position);
    isbn = line.substr(position, nextPosition - position);
    position = nextPosition +1;

    //disponibilite
    nextPosition = line.find('|', position);
    string dispo= line.substr(position, nextPosition - position);
    isAvailable = (dispo == "1"); //si dispo est "1", isAvailable est true, sinon false
    position = nextPosition + 1;

    //emprunte par
    borrowerName = line.substr(position);
    }