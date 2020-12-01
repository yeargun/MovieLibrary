
#include "Movie.h"
Movie::Movie(){
    isChecked=false;
}
void Movie::printMovieStatus(Movie* movie){
    if(movie->isChecked){
        cout<<" Checked out by User "<<movie->checkedBy<<endl;
    }
    else{
        cout<<" Not checked out\n";
    }
}
Movie* Movie::movieWithGivenId(int movieId){
    if(this->nextMovie==NULL){
        cout<<"(inside moviewithgivenidfunct) There s no movie with that id: "<<id<<endl;
        return NULL;
    }
    Movie* tempMovie = this;
    do{
        if(tempMovie->id == movieId)
            // cout<<tempMovie<<endl;
            return tempMovie;
        tempMovie=tempMovie->nextMovie;
    }while(tempMovie!= this);
    return NULL;
}
bool Movie::newMovieIsUnique(const int movieId, const string movieName, const int movieYear) {
    // cout<<"this: "<<this<< "this->id: "<<this->id<<endl;
    /*if (this->nextMovie == NULL)
        return true;
    if (this->id == movieId)// || (this->name == name && this->year == year)
        return false;
    Movie* tempMovie= this->nextMovie;
    while (this != tempMovie) {
        if (tempMovie->id == movieId || (tempMovie->name == movieName && tempMovie->year == movieYear))
            return false;
        tempMovie = tempMovie->nextMovie;
    }*/

    if(movieWithGivenId(movieId)==NULL)
        return true;
    else
        return false;

}
void Movie::addMovie(int id, string name, int year) {
    if (!newMovieIsUnique(id, name, year)) {
        cout << "Movie "<<id<<" already exists\n";
        return;
    }
    if (this->nextMovie == NULL) {
        cout<<"Movie "<<id<<" has been added\n";
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
    cout<<"Movie "<<id<<" has been added\n";
}
void Movie::showMovie(int id) {
    Movie* tempMovie = movieWithGivenId(id);
    if(tempMovie==NULL){
        return;
    }
    if (tempMovie->id == id) {
        cout << id << " " << tempMovie->name << " " << tempMovie->year;
        printMovieStatus(tempMovie);
        return;
    }
}
void Movie::deleteMovie(int id) {
    if (this->nextMovie == NULL) { // if there s no movie in list
        cout << "There s no movie with dat id: " << id << endl;
        return;
    }
    if (this->id == id) {
        cout << "1Movie with this id: " << id << " has been deleted\n";
        if (this->nextMovie == this) {
            this->nextMovie = NULL;
            return;
        }
        else {
            this->id = this->nextMovie->id;
            this->name = this->nextMovie->name;
            this->year = this->nextMovie->year;
            this->nextMovie = this->nextMovie->nextMovie;
            return;
        }
    }
    Movie* tempMovie = new Movie();
    Movie* tempMoviePrev = this;
    tempMovie = this->nextMovie;
    do {
        if (tempMovie->id == id) {
            tempMoviePrev->nextMovie = tempMovie->nextMovie;
            cout << "2Movie with this id: " << id << " has been deleted\n";
            return;
        }
        tempMoviePrev = tempMoviePrev->nextMovie;
        tempMovie = tempMovie->nextMovie;
    } while (tempMovie != this);
    cout<< "Movie with this id: " << id << " doesnt exists\n";
}
void Movie::showAllMovies() {
    cout << "Movie id - Movie name - Year - Status\n";
    if (this->nextMovie == NULL) {
        cout << "There s no movie\n";
        return;
    }
    cout << this->id << " " << this->name << " " << this->year;
    printMovieStatus(this);
    Movie* tempMovie = this->nextMovie;
    while (tempMovie != this) {
        cout << tempMovie->id << " " << tempMovie->name << " " << tempMovie->year;
        printMovieStatus(tempMovie);
        tempMovie = tempMovie->nextMovie;
    }
}
int Movie::returnMovie(int id) {
    Movie* tempMovie = movieWithGivenId(id);
    if(tempMovie==NULL){
        cout<<"Movie "<<id<<" not exist in the library\n";
        return -1;
    }
    if(tempMovie->isChecked){
        cout<<"Movie "<< tempMovie->id <<" has been returned\n";
        tempMovie->isChecked=false;
        return tempMovie->checkedBy;
    }
    else{
        cout<<"Movie "<<id<<" has not been checked out\n";
        return -1;
    }


}

Movie* Movie::checkAndReturn(int id){

}


