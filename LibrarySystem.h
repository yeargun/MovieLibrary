#ifndef UNTITLED_LIBRARYSYSTEM_H
#define UNTITLED_LIBRARYSYSTEM_H
#include "Movie.h"
#include "User.h"
class LibrarySystem {
private:
    Movie* movies = new Movie();
    User* user = new User();
    Movie* nonCheckedMovies = new Movie();
    int lastCalledFunctionNumber = -1;
    int successful;
public:
    LibrarySystem();
    ~LibrarySystem();
    void displayUsers();
    bool differentThanLastCalledFunction(int functionNumber);

    void addMovie(const int movieId, const string movieTitle, const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId, const string userName);
    void deleteUser(const int userId);
    void checkoutMovie(const int movieId, const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);
};


#endif //UNTITLED_LIBRARYSYSTEM_H
