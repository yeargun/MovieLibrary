#ifndef UNTITLED_USER_H
#define UNTITLED_USER_H
#include "Movie.h"


class User {
public:
    User* nextUser = NULL;
    User* previousUser = NULL;
    Movie* checkedMovies = new Movie();
    int id = 0;
    string name;
    User();
    void displayCheckedMovies();
    void checkFilm(int movieId, int userId);
    void checkOutMovie (Movie* movie, int userId,int movieId);
    bool isUniqueUser(int id);
    void addUser(int id, string name);
    void deleteUser(int id, Movie* movie);
    void displayUsers();
    void showUser(int id);
    User* theUserWhoWatchedGivenId(int movieId);
    User* userWithGivenId(int id);
};


#endif //UNTITLED_USER_H
