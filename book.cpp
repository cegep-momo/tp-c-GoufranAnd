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
Book::Book(const string& titre, const string& auteur, const string& isbn){
    this->title = titre;
    this->author = auteur;
    this->isbn = isbn;
    this->isAvailable = true;
    this->borrowerName = "";
}