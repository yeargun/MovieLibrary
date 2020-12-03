#include "LibrarySystem.h"
#include <fstream>
#include <iostream>

extern ofstream output;
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
void LibrarySystem::updateUsersCheckedMovies(int movieId){
    User* tempUser=this->user;
    Movie* tempMovie;
    do{
        tempMovie=tempUser->checkedMovies->movieWithGivenId(movieId);
        if(tempMovie!=NULL){
            tempUser->checkedMovies->deleteMovie(movieId,true);
            return;
        }
        tempUser=tempUser->nextUser;
    }while (tempUser!=this->user && tempUser!=NULL);
}
bool LibrarySystem::availableForCheckingOut(int movieId){
    if(this->nonCheckedMovies->movieWithGivenId(movieId)==NULL){
        return true;
    }
    return false;
}
void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {
    if (differentThanLastCalledFunction(1)) {output << "\n===addMovie() method test===\n";}lastCalledFunctionNumber = 1;
    this->movies->addMovie(movieId, movieTitle, year);
}
void LibrarySystem::deleteMovie(const int movieId) {
    if (differentThanLastCalledFunction(2)) {output << "\n===deleteMovie() method test===\n";}lastCalledFunctionNumber = 2;
    this->movies->deleteMovie(movieId);
    updateUsersCheckedMovies(movieId);
    updateNonCheckedMovies();
}


void LibrarySystem::addUser(const int userId, const string userName) {
    if (differentThanLastCalledFunction(3)) {output << "\n===addUser() method test===\n";}lastCalledFunctionNumber = 3;
    this->user->addUser(userId, userName);
}
void LibrarySystem::deleteUser(const int userId) {
    if (differentThanLastCalledFunction(4)) {output << "\n===deleteUser() method test===\n";}lastCalledFunctionNumber = 4;
    this->user->deleteUser(userId,this->movies);
}

void LibrarySystem::checkoutMovie(const int movieId, const int userId) {
    if (differentThanLastCalledFunction(5)) {output << "\n===checkoutMovie() method test===\n";}lastCalledFunctionNumber = 5;
    user->checkOutMovie(movies->movieWithGivenId(movieId), userId,movieId);
}
void LibrarySystem::updateNonCheckedMovies() {
    nonCheckedMovies->nextMovie=NULL;
    Movie* tempMovie=this->movies;
    if(tempMovie->nextMovie==NULL)
        return;
    do{
        if(!tempMovie->isChecked){
            nonCheckedMovies->addMovie(tempMovie->id,tempMovie->name, tempMovie->year,true);
        }
        tempMovie=tempMovie->nextMovie;
    }while(tempMovie!=this->movies && tempMovie!=NULL);
}
void LibrarySystem::returnMovie(const int movieId) {
    if (differentThanLastCalledFunction(6)) {output << "\n===returnMovie() method test===\n";}lastCalledFunctionNumber = 6;
    int userId = movies->returnMovie(movieId);
    //if theres a "movie with given id" which can be returned.
    // if it doesnt exists returns -1
    //Also Return movie function turns that movies' attribute to "non checked movie"
    //And returns the userId which has checked that movie
    //(the person who checked that film)userId = returnMovie(movieId)
    if(userId!=-1){
        (user->userWithGivenId(userId))->checkedMovies->deleteMovie(movieId,true);
    }
}

void LibrarySystem::showAllMovies() {
    if (differentThanLastCalledFunction(7)) {output << "\n===showAllMovie() method test===\n";}lastCalledFunctionNumber = 7;
    this->movies->showAllMovies();
}
void LibrarySystem::showMovie(const int movieId) {
    if (differentThanLastCalledFunction(8)) {output << "\n===showMovie() method test===\n";}lastCalledFunctionNumber = 8;
    this->movies->showMovie(movieId);
}
void LibrarySystem::showUser(const int userId) {
    if (differentThanLastCalledFunction(9)) {output << "\n===showUser() method test===\n";}lastCalledFunctionNumber = 9;
    this->user->showUser(userId);
}