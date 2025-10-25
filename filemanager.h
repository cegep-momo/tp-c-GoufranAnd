#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

#include "library.h"

using namespace std;

class FileManager {
private:
    string booksFileName;
    string usersFileName;
    string logsFileName;
public:
    // Constructor
    FileManager(const string& booksFile = "books.txt", 
                const string& usersFile = "users.txt",
                const string& logsFile = "logs.txt");
    
    // File operations
    bool saveLibraryData(Library& library);
    bool loadLibraryData(Library& library);
    bool logActivity(const std::string& message);
    
    // Individual file operations
    bool saveBooksToFile(Library& library);
    bool saveUsersToFile(Library& library);
    bool loadBooksFromFile(Library& library);
    bool loadUsersFromFile(Library& library);
    
    // Utility methods
    bool fileExists(const string& filename);
    void createBackup();

    
};

#endif
