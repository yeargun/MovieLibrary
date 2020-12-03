#include "User.h"
extern ofstream output;

User::User(int id,string name){
    this->id = id;
    this->name = name;
}
User::User()=default;
void User:: displayCheckedMovies()const{
    //prints out the all checkedMovies by that user
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
    //returns the User's pointer with given id.
    //if there s no user with given id, returns NULL
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
void User::addUser(int id, string name) {
    //lets say we have 3 users and the way their nextpointers work is like that
    // User1 -> User2 -> User3 ->User1
    //when we try to add User4 to this linked list
    //it adds like this : User1->User4->User2->User3->User1
    if (userWithGivenId(id)!=NULL) {
        output << "User "<<id<<" already exists\n";
        return;
    }
    if (this->nextUser == NULL) {//if there s no user
        this->id = id;
        this->name = name;
        this->previousUser = this;
        this->nextUser = this;
        output << "User " << this->id << " has been added\n";
        return;
    }
    User* newUser = new User(id,name);
    if (this->nextUser == this) { //if there s only 1 user
        this->nextUser = newUser;
        this->previousUser = newUser;
        newUser->previousUser = this;
        newUser->nextUser = this;
        output << "User " << newUser->id << " has been added\n";
    }
    else {
        User* oldSecondUser = this->nextUser;
        this->nextUser = newUser;
        newUser->previousUser = this;
        newUser->nextUser = oldSecondUser;
        oldSecondUser->previousUser = newUser;
        output << "User " << newUser->id << " has been added\n";
    }
}
void User::deleteUser(int id, Movie* wholeMovies) {
    User* tempUser = userWithGivenId(id);
    if (tempUser == NULL) {
        output << "User "<<id<<" does not exist\n";
        return;
    }
    Movie* tempMovie=tempUser->checkedMovies;
    //when an user has deleted, the movies he checkedOut, gets removed from LibrarySystem
    if(tempMovie->nextMovie!=NULL){
        do{
            wholeMovies->deleteMovie(tempMovie->id,true);
            //deleteMovie(int id, bool something), if deleteMovie has called with bool variable, that means that
            //it wont print out the deletion details.
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
}
void User::showUser(int id) {
    User* tempUser=userWithGivenId(id);
    if(tempUser==NULL){
        output << "User "<<id<<" does not exist\n";
        return;
    }
    output<<"User id: "<<tempUser->id<<" User name: "<<tempUser->name<<endl;
    output<<"User "<<tempUser->id<< " checked out the following Movies:\n";
    tempUser->displayCheckedMovies();
}