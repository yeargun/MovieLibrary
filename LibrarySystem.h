#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include "Movie.h"
#include "User.h"
#include <fstream>

class LibrarySystem {
private:
    Movie* movies = new Movie();
    User* user = new User();
    Movie* nonCheckedMovies = new Movie();
    int lastCalledFunctionNumber = -1;
public:
    LibrarySystem();
    ~LibrarySystem();
    bool differentThanLastCalledFunction(int functionNumber);
    void updateUsersCheckedMovies(int movieId);
    void addMovie(const int movieId, const string movieTitle, const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId, const string userName);
    void deleteUser(const int userId);
    void checkoutMovie(const int movieId, const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);
    void updateNonCheckedMovies();
};
#endif //LIBRARYSYSTEM_H
