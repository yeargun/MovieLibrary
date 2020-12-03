#ifndef USER_H
#define USER_H
#include "Movie.h"


class User {
public:
    User* nextUser = NULL;
    User* previousUser = NULL;
    Movie* checkedMovies = new Movie();
    int id;
    string name;
    User(int id, string name);
    User();
    void displayCheckedMovies() const;
    void checkOutMovie (Movie* movie, int userId,int movieId);
    void addUser(int id, string name);
    void deleteUser(int id, Movie* movie);
    void showUser(int id);
    User* userWithGivenId(int id);
};
#endif //USER_H
