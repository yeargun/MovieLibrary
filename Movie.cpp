
#include "Movie.h"

extern ofstream output;
Movie::Movie(){
    isChecked=false;
}
void Movie::printMovieStatus(Movie* movie){
    if(movie->isChecked){
        output<<" Checked out by User "<<movie->checkedBy<<endl;
    }
    else{
        output<<" Not checked out\n";
    }
}
Movie* Movie::movieWithGivenId(int movieId){
    if(this->nextMovie==NULL){
        return NULL;
    }
    Movie* tempMovie = this;
    do{
        if(tempMovie->id == movieId)
            return tempMovie;
        tempMovie=tempMovie->nextMovie;
    }while(tempMovie!= this);
    return NULL;
}
bool Movie::newMovieIsUnique(const int movieId, const string movieName, const int movieYear) {
    if(movieWithGivenId(movieId)==NULL)
        return true;
    else
        return false;

}
void Movie::addMovie(int id, string name, int year) {
    if (!newMovieIsUnique(id, name, year)) {
        output << "Movie "<<id<<" already exists\n";
        return;
    }
    if (this->nextMovie == NULL) {
        output<<"Movie "<<id<<" has been added\n";
        this->nextMovie = this;
        this->name = name;
        this->id = id;
        this->year = year;
        return;
    }
    Movie* newMovie = new Movie();
    newMovie->id = id;
    newMovie->year = year;
    newMovie->name = name;
    newMovie->nextMovie = this->nextMovie;
    this->nextMovie = newMovie;
    output<<"Movie "<<id<<" has been added\n";
}
void Movie::showMovie(int id) {
    Movie* tempMovie = movieWithGivenId(id);
    if(tempMovie==NULL){
        output<<"Movie with the id "<<id<<" does not exist\n";
        return;
    }
    if (tempMovie->id == id) {
        output << id << " " << tempMovie->name << " " << tempMovie->year;
        printMovieStatus(tempMovie);
        return;
    }
}
void Movie::deleteMovie(int id) {
    Movie* tempMovie=movieWithGivenId(id);
    if(tempMovie==NULL){
        output<< "Movie " << id << " does not exist\n";
        return;
    }
    if(tempMovie->isChecked){
        output<<"Movie "<<id<<" has been checked out\n";
    }
    else{
        output<<"Movie "<<id<<" has not been checked out\n";
    }


    if (this->id == id) {
        output << "Movie " << id << " has been deleted\n";
        if (this->nextMovie == this) {
            this->nextMovie = NULL;
            this->isChecked=false;
            return;
        }
        else {
            this->id = this->nextMovie->id;
            this->name = this->nextMovie->name;
            this->year = this->nextMovie->year;
            this->nextMovie = this->nextMovie->nextMovie;
            this->isChecked = this->nextMovie->isChecked;
            return;
        }
    }
    Movie* tempMoviePrev = this;
    tempMovie = this->nextMovie;
    do {
        if (tempMovie->id == id) {
            tempMoviePrev->nextMovie = tempMovie->nextMovie;
            output << "Movie " << id << " has been deleted\n";
            return;
        }
        tempMoviePrev = tempMoviePrev->nextMovie;
        tempMovie = tempMovie->nextMovie;
    } while (tempMovie != this);
    output<< "Movie with this id " << id << " doesnt exists\n";
}
void Movie::deleteMovie(int id,bool silent) {
    Movie* tempMovie=movieWithGivenId(id);
    if(tempMovie==NULL){
        return;
    }
    if(tempMovie->isChecked){
    }
    else{
    }
    if (this->nextMovie == NULL) { // if there s no movie in list
        return;
    }

    if (this->id == id) {
        if (this->nextMovie == this) {
            this->nextMovie = NULL;
            this->isChecked = false;
            return;
        }
        else {
            this->id = this->nextMovie->id;
            this->name = this->nextMovie->name;
            this->year = this->nextMovie->year;
            this->nextMovie = this->nextMovie->nextMovie;
            this->isChecked = this->nextMovie->isChecked;
            return;
        }
    }
    Movie* tempMoviePrev = this;
    tempMovie = this->nextMovie;
    do {
        if (tempMovie->id == id) {
            tempMoviePrev->nextMovie = tempMovie->nextMovie;
            return;
        }
        tempMoviePrev = tempMoviePrev->nextMovie;
        tempMovie = tempMovie->nextMovie;
    } while (tempMovie != this);

}
void Movie::showAllMovies() {
    output << "Movie id - Movie name - Year - Status\n";
    if (this->nextMovie == NULL) {
        output << "There s no movie\n";
        return;
    }
    output << this->id << " " << this->name << " " << this->year;
    printMovieStatus(this);
    Movie* tempMovie = this->nextMovie;
    while (tempMovie != this) {
        output << tempMovie->id << " " << tempMovie->name << " " << tempMovie->year;
        printMovieStatus(tempMovie);
        tempMovie = tempMovie->nextMovie;
    }
}
int Movie::returnMovie(int id) {
    Movie* tempMovie = movieWithGivenId(id);
    if(tempMovie==NULL){
        output<<"Movie "<<id<<" not exist in the library\n";
        return -1;
    }
    if(tempMovie->isChecked){
        output<<"Movie "<< tempMovie->id <<" has been returned\n";
        tempMovie->isChecked=false;
        return tempMovie->checkedBy;
    }
    else{
        output<<"Movie "<<id<<" has not been checked out\n";
        return -1;
    }


}
void Movie::addMovie(int id, string name, int year, bool silent) {
    if (!newMovieIsUnique(id, name, year)) {
        return;
    }
    if (this->nextMovie == NULL) {
        this->nextMovie = this;
        this->name = name;
        this->id = id;
        this->year = year;
        return;
    }
    Movie* newMovie = new Movie();
    newMovie->id = id;
    newMovie->year = year;
    newMovie->name = name;
    newMovie->nextMovie = this->nextMovie;
    this->nextMovie = newMovie;
}

Movie* Movie::checkAndReturn(int id){

}


