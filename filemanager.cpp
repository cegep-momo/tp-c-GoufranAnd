#include <fstream>
#include <iostream>
#include <filesystem>
#include "filemanager.h"
#include <ctime>
using namespace std;

// Constructor
FileManager::FileManager(const string& booksFile, const string& usersFile, const string& logsFile)
    : booksFileName(booksFile), usersFileName(usersFile), logsFileName(logsFile) {}

// Save all library data
bool FileManager::saveLibraryData(Library& library) {
    return saveBooksToFile(library) && saveUsersToFile(library);
}

// Load all library data
bool FileManager::loadLibraryData(Library& library) {
    bool booksLoaded = loadBooksFromFile(library);
    bool usersLoaded = loadUsersFromFile(library);
    return booksLoaded || usersLoaded; // Return true if at least one file was loaded
}

// Save books to file
bool FileManager::saveBooksToFile(Library& library) {
    ofstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << booksFileName << " en écriture.\n";
        return false;
    }
    
    auto books = library.getAllBooks();
    for (Book* book : books) {
        file << book->toFileFormat() << "\n";
    }
    
    file.close();
    return true;
}

// Save users to file
bool FileManager::saveUsersToFile(Library& library) {
    ofstream file(usersFileName);
    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << usersFileName << " en écriture.\n";
        return false;
    }
    
    auto users = library.getAllUsers();
    for (User* user : users) {
        file << user->toFileFormat() << "\n";
    }
    
    file.close();
    return true;
}

// Load books from file
bool FileManager::loadBooksFromFile(Library& library) {
    ifstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier de livres existant trouvé. Démarrage avec une bibliothèque vide.\n";
        return false;
    }
    
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            Book book;
            book.fromFileFormat(line);
            library.addBook(book);
            count++;
        }
    }
    
    file.close();
    cout << "Chargé " << count << " livre(s) depuis le fichier.\n";
    return true;
}

// Load users from file
bool FileManager::loadUsersFromFile(Library& library) {
    ifstream file(usersFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier d'utilisateurs existant trouvé. Démarrage sans utilisateurs enregistrés.\n";
        return false;
    }
    
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            User user;
            user.fromFileFormat(line);
            library.addUser(user);
            count++;
        }
    }
    
    file.close();
    cout << "Chargé " << count << " utilisateur(s) depuis le fichier.\n";
    return true;
}

// Check if file exists
bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

// Create backup
void FileManager::createBackup() {
    if (fileExists(booksFileName)) {
        filesystem::copy_file(booksFileName, booksFileName + ".backup");
    }
    
    if (fileExists(usersFileName)) {
        filesystem::copy_file(usersFileName, usersFileName + ".backup");
    }
    
    cout << "Fichiers de sauvegarde créés.\n";
}


bool FileManager::logActivity(const std::string& message){
        //ouvre le fichiers logs en mode ajout(ios:app, va permettre d ecrire a la fin du fichier sans ecraser le contenu)
        ofstream file(logsFileName, ios::app);
        if(!file.is_open()){
           cout << "Erreur : Impossible d'ouvrir " << logsFileName << " en écriture.\n";
            return false;
        }

        time_t now = time(nullptr); //recupere le temps actuel dans la variable now (nullptr = recupere directement)
        tm* localTime = localtime(&now); //convertit le temps en heure locale

        file << "[" << put_time(localTime, "%Y-%m-%d %H:%M:%S") << "] " << message << "\n"; //ecrit la date et l heure au format YYYY-MM-DD HH:MM:SS suivi du message

        file.close();
        return true;
}