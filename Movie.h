#ifndef MOVIE_H
#define MOVIE_H

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
    int checkedBy;
    bool isChecked;
    Movie();
    void printMovieStatus(Movie* movie);
    Movie* movieWithGivenId(int movieId);
    bool newMovieIsUnique(const int movieId);
    void addMovie(int id, std::string name, int year);
    void showMovie(int id);
    void deleteMovie(int id);
    void showAllMovies();
    int returnMovie(int id);
    void addMovie(int id, std::string name, int year,bool silent);
    void deleteMovie(int id,bool silent);
};
#endif //MOVIE_H
