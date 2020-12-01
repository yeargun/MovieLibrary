#ifndef KINDABORED_MOVIE_H
#define KINDABORED_MOVIE_H

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;
class Movie {

public:
    Movie* nextMovie;
    int year;
    int id;
    string name;
    bool isChecked;
    Movie* movieWithGivenId(int movieId);
    bool newMovieIsUnique(const int movieId, const std::string movieName, const int movieYear);
    void addMovie(int id, std::string name, int year);
    void showMovie(int id);
    void deleteMovie(int id);
    void showAllMovies();
    Movie* checkAndReturn(int id);
};


#endif //KINDABORED_MOVIE_H
