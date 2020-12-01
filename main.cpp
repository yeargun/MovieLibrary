#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include "Movie.h"
#include "User.h"
using namespace std;
ofstream output;
string charArrayToString(char* a, int size) { //
	int i;
	string s;
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
bool strCompare(string s1, string s2, int compareLength) { // returns true if strings are identical
	if (compareLength > s1.length() || compareLength > s2.length()) { return false; }
	for (int i = 0; i < compareLength; i++) {
		if (s1[i] != s2[i]) {
			return false;
		}
	}
	return true;
}
string stringSplitter(const string string1, const char parameter, int index) { // splits the string by the given parameter
//and returns the preffered indexed string from splitted strings
	char* buffer = new char[string1.length()];
	int splitTime = -1;
	int bufferIndex = 0;
	for (char c : string1) {
		if (c != parameter) {
			*(buffer+bufferIndex) = c;
			bufferIndex++;
		}
		else {
			splitTime++;
			if (splitTime == index) {
				return charArrayToString(buffer, bufferIndex);
			}
			bufferIndex = 0;
		}
	}
	return charArrayToString(buffer, bufferIndex);
}

/*template <typename T>
struct doublyLinkedList {
	<T> data;
	<T>* prev;
	<T>* next;
};*/

/*
class Movie {
public:
	Movie* nextMovie = NULL;
	int id;
	int year;
	string name;
    Movie* movieWithGivenId(int movieId){
        if(this->nextMovie==NULL){
            output<<"(inside moviewithgivenidfunct) There s no movie with that id: "<<id<<endl;
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
	bool newMovieIsUnique(const int movieId, const string movieName, const int movieYear) {
       // cout<<"this: "<<this<< "this->id: "<<this->id<<endl;
        if (this->nextMovie == NULL)
            return true;
        if (this->id == movieId)// || (this->name == name && this->year == year)
			return false;
		Movie* tempMovie= this->nextMovie;
		while (this != tempMovie) {
			if (tempMovie->id == movieId || (tempMovie->name == movieName && tempMovie->year == movieYear))
				return false;
			tempMovie = tempMovie->nextMovie;
		}
		return true;
	}
	void addMovie(int id, string name, int year) {
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
	void showMovie(int id) {
		if (this->nextMovie == NULL) {
			output << "There s no movie to be shown\n";
			return;
		}
		if (this->id == id) {
			output << id << " " << this->name << " " << this->year << " Checked out by User -usernumber-\n";
			return;
		}
		Movie* tempMovie = this->nextMovie;
		while (tempMovie != this) {
			if (tempMovie->id == id) {
				output << id << " " << tempMovie->name << " " << tempMovie->year << " Checked out by User -usernumber-\n";
				return;
			}
			tempMovie = tempMovie->nextMovie;
		}
		output << "There s no movie with that id: " << id << endl;

	}
	void deleteMovie(int id) {
		if (this->nextMovie == NULL) { // if there s no movie in list
			output << "There s no movie with dat id: " << id << endl;
			return;
		}
		if (this->id == id) {
			output << "1Movie with this id: " << id << " has been deleted\n";
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
				output << "2Movie with this id: " << id << " has been deleted\n";
				return;
			}
			tempMoviePrev = tempMoviePrev->nextMovie;
			tempMovie = tempMovie->nextMovie;
		} while (tempMovie != this);
		output<< "Movie with this id: " << id << " doesnt exists\n";
	}
	void showAllMovies() {
		output << "Movie id - Movie name - Year - Status\n";
		if (this->nextMovie == NULL) {
			output << "There s no movie\n";
			return;
		}
		output << this->id << " " << this->name << " " << this->year << " STATUS\n";
		Movie* tempMovie = this->nextMovie;
		while (tempMovie != this) {
			output << tempMovie->id << " " << tempMovie->name << " " << tempMovie->year << " STATUS\n";
			tempMovie = tempMovie->nextMovie;
		}
	}

	Movie* checkAndReturn(int id){

	}

};

class User {
public:
	User* nextUser = NULL;
	User* previousUser = NULL;
	Movie* checkedMovies = new Movie();
	int id = 0;
	string name;
	void displayCheckedMovies(){
	    output<<"Movie id - Movie name - Year\n";
	    if(this->checkedMovies->nextMovie==NULL)
            return;
	    Movie* tempMovie = this->checkedMovies;
	    do{
	        output<<tempMovie->id<< " "<<tempMovie->name<<" "<<tempMovie->year<<endl;
	        tempMovie= tempMovie->nextMovie;
	    }while(tempMovie!= this->checkedMovies);
	}

	void checkOutMovie (Movie* movie, int userId) {
	    if(movie == NULL){return;}
	    if(this->nextUser==NULL){
	        output<<"Theres no1 with given userıd: "<<userId<<endl;
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
                output<<"Movie "<<movie->id<< " has been checked out by User "<<tempUser->id<<endl;
                return;
            }
            tempUser = tempUser->nextUser;
	    }while (tempUser != this);
        output<<"Theres the movie but no1 with given userıd: "<<userId<<endl;
	}
	bool isUniqueUser(int id) {
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
	void addUser(int id, string name) {
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
			//cout << "Has been added(id / name): " << newUser->id << "   " << newUser->name << endl;
			//cout << "It's prev is this " << newUser->previousUser->id << "   " << newUser->previousUser->name << endl;
			//cout << "It's next is this " << newUser->nextUser->id << "   " << newUser->nextUser->name << endl;
			//cout << "--------------------------\n";
		}
		else {
			User* secondUser = this->nextUser;
			this->nextUser = newUser;
			this->previousUser = secondUser;
			newUser->previousUser = this;
			newUser->nextUser = secondUser;
			secondUser->previousUser = newUser;
			output << "User " << newUser->id << " has been added\n";
			//cout << "33Has been added(id / name): " << newUser->id << "   " << newUser->name << endl;
			//cout << "It's prev is this " << newUser->previousUser->id << "   " << newUser->previousUser->name << endl;
			//cout << "It's next is this " << newUser->nextUser->id << "   " << newUser->nextUser->name << endl;
			//cout << "--------------------------\n";
		}
	}
	void checkFilm(int movieId, int userId) {
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
	void deleteUser(int id) {//maybe when i delete a user, the noncheckedfilms number can increase tho
		if (this->nextUser == NULL) {
			output << "User "<<id<<" does not exist\n";
			return;
		}

		if (this->nextUser == this) { //Assigning null to head's next, tells the program that, theres no movie in the movielist
			if(this->id == id){
				this->nextUser = NULL;
				this->previousUser = NULL;
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
				output << "User " << id << " has been deleted\n";
				return;
			}
			tempUser = tempUser->nextUser;
		}
		//cout << "there sno1 with that id: " << id << endl;
	}
	void displayUsers() {
		User* tempUser=this;
		output << "Current Users: " << tempUser->id << '\t' << tempUser->name << endl;
		tempUser = this->nextUser;
		if (tempUser == NULL || tempUser == this)
			return;

		while(tempUser != this){
			output << "Current Users: " << tempUser->id << '\t' << tempUser->name << endl;
			tempUser = tempUser->nextUser;
		}
		//User* tempUser = this;

		//do{


		//    tempUser=tempUser->nextUser;
		//}while(tempUser!=NULL || tempUser!=this);
	}
	void showUser(int id) {
		if (this->nextUser == NULL) {
			output << "There s no user\n";
			return;
		}
		if (this->id == id) {
			output << "User id: " << id << " User name: " << this->name << endl;
			output << "User " << id << " checked out the following Movies:\n";
			this->displayCheckedMovies();
			return;
		}
		User* tempUser = this->nextUser;
		while (tempUser != this) {
			if (tempUser->id == id) {
				output << "User id: " << id << " User name: " << tempUser->name << endl;
				output << "User " << id << " checked out the following Movies:\n";
				tempUser->displayCheckedMovies();
				return;
			}
			tempUser=tempUser->nextUser;
		}
		output << "There s no user with that id\n";
	}
};
*/

class LibrarySystem {
private:
	Movie* movies = new Movie();
	User* user = new User();
	Movie* nonCheckedMovies = new Movie();
	int lastCalledFunctionNumber = -1;
public:
	LibrarySystem() {
		this->movies->nextMovie = NULL;
		this->user->nextUser = NULL;
		this->user->previousUser = NULL;
	}
	~LibrarySystem();
	void displayUsers() {
		this->user->displayUsers();
	}
	bool differentThanLastCalledFunction(int functionNumber) {
		if (lastCalledFunctionNumber != functionNumber)
			return true;
		else return false;
	}

	void addMovie(const int movieId, const string movieTitle, const int year) {
		if (differentThanLastCalledFunction(1)) {output << "\n===addMovie() method test===\n";}lastCalledFunctionNumber = 1;
		this->movies->addMovie(movieId, movieTitle, year);
      //  this->nonCheckedMovies->addMovie(movieId, movieTitle, year);
	}
	void deleteMovie(const int movieId) {
		if (differentThanLastCalledFunction(2)) {output << "\n===deleteMovie() method test===\n";}lastCalledFunctionNumber = 2;
		this->movies->deleteMovie(movieId);
     //   this->nonCheckedMovies->deleteMovie(movieId);
	}


	void addUser(const int userId, const string userName) {
		if (differentThanLastCalledFunction(3)) {output << "\n===addUser() method test===\n";}lastCalledFunctionNumber = 3;
		this->user->addUser(userId, userName);
	}
	void deleteUser(const int userId) {
		if (differentThanLastCalledFunction(4)) {output << "\n===deleteUser() method test===\n";}lastCalledFunctionNumber = 4;
		this->user->deleteUser(userId);
	}

	void checkoutMovie(const int movieId, const int userId) {
		if (differentThanLastCalledFunction(5)) {output << "\n===checkoutMovie() method test===\n";}lastCalledFunctionNumber = 5;
		user->checkOutMovie(movies->movieWithGivenId(movieId), userId);

	}
	void returnMovie(const int movieId) {
        if (differentThanLastCalledFunction(6)) {output << "\n===returnMovie() method test===\n";}lastCalledFunctionNumber = 6;
	}


	void showAllMovies() {
		if (differentThanLastCalledFunction(7)) {output << "\n===showAllMovie() method test===\n";}lastCalledFunctionNumber = 7;
		this->movies->showAllMovies();
	}
	void showMovie(const int movieId) {
		if (differentThanLastCalledFunction(8)) {output << "\n===showMovie() method test===\n";}lastCalledFunctionNumber = 8;
		this->movies->showMovie(movieId);
	}
	void showUser(const int userId) {
		if (differentThanLastCalledFunction(9)) {output << "\n===showUser() method test===\n";}lastCalledFunctionNumber = 9;
		this->user->showUser(userId);
	}
	//void updateNonCheckedMovies
};



int main(int argc, char** argv) {
	string command;
	int userId=0, movieId=0, year=0;
	string userName, movieTitle;
	ifstream commandFile;

	User user1;
	Movie movie1;
	LibrarySystem* library1 = new LibrarySystem();
	commandFile.open("commands.txt");
	output.open("Myoutput.txt");
	output << "===Movie Library System===\n";
	if (!commandFile) {
		//exit(1); // terminate with error
	}

	for (command; getline(commandFile, command); ) {
		//output << command<<endl;
		if (strCompare(command, "addMovie", 7)) {
			movieId = stoi(stringSplitter(command, '\t', 1));
			movieTitle = stringSplitter(command, '\t', 2);
			year = stoi(stringSplitter(command, '\t', 3));
			library1->addMovie(movieId, movieTitle, year);
		}
		else if (strCompare(command, "deleteMovie", 10)) {
			movieId = stoi(stringSplitter(command, '\t', 1));
			library1->deleteMovie(movieId);
		}
		else if (strCompare(command, "addUser", 6)) {
			userId = stoi(stringSplitter(command, '\t', 1));
			userName = stringSplitter(command, '\t', 2);
			library1->addUser(userId, userName);
		}
		else if (strCompare(command, "deleteUser", 9)) {//deleting user can change nonchecked movie number etc
			userId = stoi(stringSplitter(command, '\t', 1));
			library1->deleteUser(userId);
		}
		else if (strCompare(command, "checkoutMovie", 12)) {
			movieId = stoi(stringSplitter(command, '\t', 1));
			userId = stoi(stringSplitter(command, '\t', 2));
			library1->checkoutMovie(movieId, userId);
		}
		else if (strCompare(command, "showUser", 7)) {
			userId = stoi(stringSplitter(command, '\t', 1));
			library1->showUser(userId);
		}
		else if (strCompare(command, "showMovie", 8)) {
			movieId = stoi(stringSplitter(command, '\t', 1));
			library1->showMovie(movieId);
		}
		else if (strCompare(command, "showAllMovies", 12)) {
			library1->showAllMovies();
		}
		else if (strCompare(command, "returnMovie", 10)) {
			movieId = stoi(stringSplitter(command, '\t', 1));
			library1->returnMovie(movieId);
		}
	}
	output.close();
	return 0;
}