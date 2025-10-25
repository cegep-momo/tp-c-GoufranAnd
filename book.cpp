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