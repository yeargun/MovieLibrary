#include "LibrarySystem.h"


LibrarySystem::LibrarySystem() {
    this->movies->nextMovie = NULL;
    this->user->nextUser = NULL;
    this->user->previousUser = NULL;
    this->successful = 1;
}
LibrarySystem::~LibrarySystem(){

}
void LibrarySystem::displayUsers() {
    this->user->displayUsers();
}
bool LibrarySystem::differentThanLastCalledFunction(int functionNumber) {
    if (lastCalledFunctionNumber != functionNumber)
        return true;
    else return false;
}

void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {
    if (differentThanLastCalledFunction(1)) {cout << "\n===addMovie() method test===\n";}lastCalledFunctionNumber = 1;
    this->movies->addMovie(movieId, movieTitle, year);
    //  this->nonCheckedMovies->addMovie(movieId, movieTitle, year);
}
void LibrarySystem::deleteMovie(const int movieId) {
    if (differentThanLastCalledFunction(2)) {cout << "\n===deleteMovie() method test===\n";}lastCalledFunctionNumber = 2;
    this->movies->deleteMovie(movieId);
    //   this->nonCheckedMovies->deleteMovie(movieId);
}


void LibrarySystem::addUser(const int userId, const string userName) {
    if (differentThanLastCalledFunction(3)) {cout << "\n===addUser() method test===\n";}lastCalledFunctionNumber = 3;
    this->user->addUser(userId, userName);
}
void LibrarySystem::deleteUser(const int userId) {
    if (differentThanLastCalledFunction(4)) {cout << "\n===deleteUser() method test===\n";}lastCalledFunctionNumber = 4;
    this->user->deleteUser(userId);
}

void LibrarySystem::checkoutMovie(const int movieId, const int userId) {
    if (differentThanLastCalledFunction(5)) {cout << "\n===checkoutMovie() method test===\n";}lastCalledFunctionNumber = 5;
    user->checkOutMovie(movies->movieWithGivenId(movieId), userId);

}
void LibrarySystem::returnMovie(const int movieId) {
    if (differentThanLastCalledFunction(6)) {cout << "\n===returnMovie() method test===\n";}lastCalledFunctionNumber = 6;
    int userId = movies->returnMovie(movieId);
    //if theres a movie with given id which can be returned. else returns -1
    //Return movie function turns that movies' attribute to "non checked movie"
    //And returns the userId which has checked that movie
    //(the person who checked that film)userId = returnMovie
    if(userId!=-1){
        (user->userWithGivenId(userId))->checkedMovies->deleteMovie(movieId);
    }
}

void LibrarySystem::showAllMovies() {
    if (differentThanLastCalledFunction(7)) {cout << "\n===showAllMovie() method test===\n";}lastCalledFunctionNumber = 7;
    this->movies->showAllMovies();
}
void LibrarySystem::showMovie(const int movieId) {
    if (differentThanLastCalledFunction(8)) {cout << "\n===showMovie() method test===\n";}lastCalledFunctionNumber = 8;
    this->movies->showMovie(movieId);
}
void LibrarySystem::showUser(const int userId) {
    if (differentThanLastCalledFunction(9)) {cout << "\n===showUser() method test===\n";}lastCalledFunctionNumber = 9;
    this->user->showUser(userId);
}

