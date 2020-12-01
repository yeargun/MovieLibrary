
#include "User.h"

User* nextUser = NULL;
User* previousUser = NULL;
Movie* checkedMovies = new Movie();
int id = 0;
string name;
void User::displayCheckedMovies(){
    cout<<"Movie id - Movie name - Year\n";
    if(this->checkedMovies->nextMovie==NULL)
        return;
    Movie* tempMovie = this->checkedMovies;
    do{
        cout<<tempMovie->id<< " "<<tempMovie->name<<" "<<tempMovie->year<<endl;
        tempMovie= tempMovie->nextMovie;
    }while(tempMovie!= this->checkedMovies);
}

void User::checkOutMovie (Movie* movie, int userId) {
    if(movie == NULL){return;}
    if(this->nextUser==NULL){
        cout<<"Theres no1 with given userıd: "<<userId<<endl;
        return;
    }
    User* tempUser = this;
    do{
        //cout<<"user ccheckoutmovie func ici, tempuser->id: "<<tempUser->id<<endl;
        if(tempUser->id == userId){
            const int movieId = movie->id;
            const int movieYear = movie->year;
            const string movieName = movie->name;
            //  cout<<"sdfhdhdfh"<<movieId<<movieName<<movieYear;
            tempUser->checkedMovies->addMovie(movieId, movieName, movieYear);
            // cout<<"sadgsagaa";
            cout<<"Movie "<<movie->id<< " has been checked out by User "<<tempUser->id<<endl;
            return;
        }
        tempUser = tempUser->nextUser;
    }while (tempUser != this);
    cout<<"Theres the movie but no1 with given userıd: "<<userId<<endl;
}
bool User::isUniqueUser(int id) {
    if (this->nextUser == NULL)
        return true;
    else if (this->nextUser == this)
        if (this->id != id)
            return true;
    User* tempUser = new User();
    tempUser = this->nextUser;
    while (tempUser != this) {
        if (tempUser->id == id)
            return false;
        tempUser = tempUser->nextUser;
    }
    return true;
}
void User::addUser(int id, string name) {
    if (!isUniqueUser(id)) {
        cout << "User "<<id<<" already exists\n";
        return;
    }
    User* newUser = new User();
    newUser->id = id;
    newUser->name = name;
    if (this->nextUser == NULL) {
        this->id = id;
        this->name = name;
        this->previousUser = this;
        this->nextUser = this;
        cout << "User " << this->id << " has been added\n";
        //cout << "Has been added(id / name): " << this->id << "   " << this->name << endl;
        return;

    }
    else if (this->nextUser == this) { //if linkedlist has 1 user
        this->nextUser = newUser;
        this->previousUser = newUser;
        newUser->previousUser = this;
        newUser->nextUser = this;
        cout << "User " << newUser->id << " has been added\n";
        /*cout << "Has been added(id / name): " << newUser->id << "   " << newUser->name << endl;
        cout << "It's prev is this " << newUser->previousUser->id << "   " << newUser->previousUser->name << endl;
        cout << "It's next is this " << newUser->nextUser->id << "   " << newUser->nextUser->name << endl;
        cout << "--------------------------\n";*/
    }
    else {
        User* secondUser = this->nextUser;
        this->nextUser = newUser;
        this->previousUser = secondUser;
        newUser->previousUser = this;
        newUser->nextUser = secondUser;
        secondUser->previousUser = newUser;
        cout << "User " << newUser->id << " has been added\n";
        /*cout << "33Has been added(id / name): " << newUser->id << "   " << newUser->name << endl;
        cout << "It's prev is this " << newUser->previousUser->id << "   " << newUser->previousUser->name << endl;
        cout << "It's next is this " << newUser->nextUser->id << "   " << newUser->nextUser->name << endl;
        cout << "--------------------------\n";*/
    }
}
void User::checkFilm(int movieId, int userId) {
    User* firstUserPointer = this;
    bool filmHasChecked = false;
    if (this->nextUser == this) {
        if(this->id == userId)
            //this->checkedMovies.add
            return;
    }
    while (this->nextUser != firstUserPointer) {
        if (this->id == userId) {
            //this->checkedMovies.add(moviedId)
        }
    }
    if (filmHasChecked) {
        //
    }
    else {
        cout << "THERE S NO SUCH FILM EXISTS\n";
    }
}
void User::deleteUser(int id) {//maybe when i delete a user, the noncheckedfilms number can increase tho
    if (this->nextUser == NULL) {
        cout << "User "<<id<<" does not exist\n";
        return;
    }

    if (this->nextUser == this) { //Assigning null to head's next, tells the program that, theres no movie in the movielist
        if(this->id == id){
            this->nextUser = NULL;
            this->previousUser = NULL;
            return;
        }
        else {
            cout << "User " << id << " does not exist\n";
            return;
        }
    }
    else if (this->id == id) {
        cout << "User " << id << " has been deleted\n";
        this->id = this->nextUser->id;
        this->name = this->nextUser->name;
        this->nextUser->nextUser->previousUser = this;
        this->nextUser = this->nextUser->nextUser;
        return;
    }
    User* tempUser = this->nextUser;
    while(tempUser != this){
        if (tempUser->id == id) {
            //copying the values from head's next class to head node, and removing the heads next from sequence
            if (tempUser->nextUser == this) {
                tempUser->previousUser->nextUser = this;
                this->previousUser = tempUser->previousUser;
            }
            else {
                tempUser->id = tempUser->nextUser->id;
                tempUser->name = tempUser->nextUser->name;
                tempUser->nextUser->nextUser->previousUser = tempUser;
                tempUser->nextUser = tempUser->nextUser->nextUser;
            }
            cout << "User " << id << " has been deleted\n";
            return;
        }
        tempUser = tempUser->nextUser;
    }
    //cout << "there sno1 with that id: " << id << endl;
}
void User::displayUsers() {
    User* tempUser=this;
    cout << "Current Users: " << tempUser->id << '\t' << tempUser->name << endl;
    tempUser = this->nextUser;
    if (tempUser == NULL || tempUser == this)
        return;

    while(tempUser != this){
        cout << "Current Users: " << tempUser->id << '\t' << tempUser->name << endl;
        tempUser = tempUser->nextUser;
    }/*
		User* tempUser = this;

		do{


		    tempUser=tempUser->nextUser;
		}while(tempUser!=NULL || tempUser!=this);*/
}
void User::showUser(int id) {
    if (this->nextUser == NULL) {
        cout << "There s no user\n";
        return;
    }
    if (this->id == id) {
        cout << "User id: " << id << " User name: " << this->name << endl;
        cout << "User " << id << " checked out the following Movies:\n";
        this->displayCheckedMovies();
        return;
    }
    User* tempUser = this->nextUser;
    while (tempUser != this) {
        if (tempUser->id == id) {
            cout << "User id: " << id << " User name: " << tempUser->name << endl;
            cout << "User " << id << " checked out the following Movies:\n";
            tempUser->displayCheckedMovies();
            return;
        }
        tempUser=tempUser->nextUser;
    }
    cout << "There s no user with that id\n";
}