#include <iostream>
#include <string>
#include<cstdlib>
#include "Movie.h"
#include "User.h"
#include "LibrarySystem.h"

using namespace std;

string charArrayToString(char* a, int size) { //
	int i;
	string s;
	for (i = 0; i < size; i++) {
		s += a[i];
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
string stringSplitter(const string* string1, const char parameter, int index) { // splits the string by the given parameter
//and returns the preffered indexed string from splitted strings
	char* buffer = new char[string1->length()];
	int splitTime = -1;
	int bufferIndex = 0;
	for (char c : *string1) {
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

ofstream output;
int main(int argc,char** argv) {
	string command;
    ifstream commandFile;
    if(argc<2){
        cout<<"Please enter legal arguments\n";
        return 0;
    }
    output.open(argv[2]);
    commandFile.open(argv[1]);
	int userId=0, movieId=0, year=0;
	string userName, movieTitle;
    LibrarySystem* library1 = new LibrarySystem();
	output << "===Movie Library System===\n";
	if (!commandFile) {
		exit(1); // terminate with error
	}
	for (command; getline(commandFile, command); ) {
		if (strCompare(command, "addMovie", 7)) {
			movieId = stoi(stringSplitter(&command, '\t', 1));
			movieTitle = stringSplitter(&command, '\t', 2);
			year = stoi(stringSplitter(&command, '\t', 3));
			library1->addMovie(movieId, movieTitle, year);
		}
		else if (strCompare(command, "deleteMovie", 10)) {
			movieId = stoi(stringSplitter(&command, '\t', 1));
			library1->deleteMovie(movieId);
			library1->updateUsersCheckedMovies(movieId);
			library1->updateNonCheckedMovies();
		}
		else if (strCompare(command, "addUser", 6)) {
			userId = stoi(stringSplitter(&command, '\t', 1));
			userName = stringSplitter(&command, '\t', 2);
			library1->addUser(userId, userName);
		}
		else if (strCompare(command, "deleteUser", 9)) {//deleting user can change nonchecked movie number etc
			userId = stoi(stringSplitter(&command, '\t', 1));
			library1->deleteUser(userId);
            library1->updateNonCheckedMovies();
		}
		else if (strCompare(command, "checkoutMovie", 12)) {
			movieId = stoi(stringSplitter(&command, '\t', 1));
			userId = stoi(stringSplitter(&command, '\t', 2));
			library1->checkoutMovie(movieId, userId);
            library1->updateNonCheckedMovies();
		}
		else if (strCompare(command, "showUser", 7)) {
			userId = stoi(stringSplitter(&command, '\t', 1));
			library1->showUser(userId);
		}
		else if (strCompare(command, "showMovie", 8)) {
			movieId = stoi(stringSplitter(&command, '\t', 1));
			library1->showMovie(movieId);
		}
		else if (strCompare(command, "showAllMovies", 12)) {
			library1->showAllMovies();
		}
		else if (strCompare(command, "returnMovie", 10)) {
			movieId = stoi(stringSplitter(&command, '\t', 1));
			library1->returnMovie(movieId);
            library1->updateNonCheckedMovies();
		}
	}
	output.close();
	library1->~LibrarySystem();
	return 0;
}