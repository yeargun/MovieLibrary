#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include "Movie.h"
#include "User.h"
#include "LibrarySystem.h"
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



/*
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
*/


int main(int argc, char** argv) {
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
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
	cout<<"-----------------------------------------------------------------------------------------------------------\n";
	return 0;
}