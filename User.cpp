
#include "User.h"


extern ofstream output;
User* nextUser = NULL;
User* previousUser = NULL;
Movie* checkedMovies = new Movie();
int id = 0;
string name;
User::User(){

}
void User::displayCheckedMovies(){
    if(this->checkedMovies->nextMovie==NULL)
        return;
    output<<"Movie id - Movie name - Year\n";
    Movie* tempMovie = this->checkedMovies;
    do{
        output<<tempMovie->id<< " "<<tempMovie->name<<" "<<tempMovie->year<<endl;
        tempMovie= tempMovie->nextMovie;
    }while(tempMovie!= this->checkedMovies);
}
User* User::userWithGivenId(int id){
    if(this->nextUser==NULL)
        return NULL;
    User* tempUser= this;
    do{
        if(tempUser->id == id)
            return tempUser;
        tempUser=tempUser->nextUser;
    }while (tempUser!=this);
    return NULL;
}
void User::checkOutMovie (Movie* movie, int userId,int movieId) {
    if(movie == NULL){
        output<<"Movie "<<movieId<<" does not exist for checkout\n";
        return;}
    User* tempUser=userWithGivenId(userId);
    if(tempUser==NULL){
        output<< "User "<<userId<<" does not exist for checkout\n";
        return;
    }
    if(movie->isChecked){
        output<<"Movie "<<movieId<<" does not exist for checkout\n";
        return;
    }
    tempUser->checkedMovies->addMovie(movie->id, movie->name, movie->year,false);
    output<<"Movie "<<movie->id<< " has been checked out by User "<<tempUser->id<<endl;
    movie->isChecked = true;
    movie->checkedBy = tempUser->id;
}
bool User::isUniqueUser(int id) {
    if (this->nextUser == NULL)
        return true;
    User* tempUser=this;
    do{
        if (tempUser->id == id)
            return false;
        tempUser=tempUser->nextUser;
    }while(tempUser!=this);
    return true;
}
void User::addUser(int id, string name) {
    if (!isUniqueUser(id)) {
        output << "User "<<id<<" already exists\n";
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
        output << "User " << this->id << " has been added\n";
        //cout << "Has been added(id / name): " << this->id << "   " << this->name << endl;
        return;

    }
    else if (this->nextUser == this) { //if linkedlist has 1 user
        this->nextUser = newUser;
        this->previousUser = newUser;
        newUser->previousUser = this;
        newUser->nextUser = this;
        output << "User " << newUser->id << " has been added\n";
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
        output << "User " << newUser->id << " has been added\n";
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
        output << "THERE S NO SUCH FILM EXISTS\n";
    }
}
void User::deleteUser(int id, Movie* wholeMovies) {//maybe when i delete a user, the noncheckedfilms number can increase tho
    User* tempUser = userWithGivenId(id);
    if (tempUser == NULL) {
        output << "User "<<id<<" does not exist\n";
        return;
    }
    Movie* tempMovie=tempUser->checkedMovies;
    if(tempMovie->nextMovie!=NULL){
        do{
            wholeMovies->deleteMovie(tempMovie->id,true);
            tempMovie=tempMovie->nextMovie;
        }while (tempMovie!=tempUser->checkedMovies);
    }

    if (this->nextUser == this) { //Assigning null to head's next, tells the program that, theres no movie in the movielist
        if(this->id == id){
            this->nextUser = NULL;
            this->previousUser = NULL;
            output << "User " << id << " has been deleted\n";
            return;
        }
        else {
            output << "User " << id << " does not exist\n";
            return;
        }
    }
    else if (this->id == id) {
        output << "User " << id << " has been deleted\n";
        this->id = this->nextUser->id;
        this->name = this->nextUser->name;
        this->nextUser->nextUser->previousUser = this;
        this->nextUser = this->nextUser->nextUser;
        return;
    }


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
    output << "User " << id << " has been deleted\n";
    return;
}


void User::displayUsers() {
    if(this->nextUser==NULL){
        output<<"theres no users\n";return;
    }
    User* tempUser=this;
    do{
        output << "Current Users: " << tempUser->id << '\t' << tempUser->name << endl;
        tempUser=tempUser->nextUser;
    }while(tempUser!=this);
}
void User::showUser(int id) {
    User* tempUser=userWithGivenId(id);
    if(tempUser==NULL){
        output << "There s no user with that id\n";
        return;
    }
    output<<"User id: "<<tempUser->id<<" User name: "<<tempUser->name<<endl;
    output<<"User "<<tempUser->id<< " checked out the following Movies:\n";
    tempUser->displayCheckedMovies();
}
User* User::theUserWhoWatchedGivenId(int movieId) {
    if(this->nextUser==NULL){
        return NULL;
    }
    User* tempUser=this;
    do{
        //if()
    }while (tempUser!=this);
}