#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void readData(string titles[], int runTimes[], string genre[], float userRatings[], int releaseYears[], int DBSIZE);
void showTitles(string titles[], int runTimes[], string genre[], float userRatings[], int releaseYears[], int DBSIZE);
void showGenres(string titles[], int runTimes[], string genre[],float userRatings[],int releaseYears[], int DBSIZE);
void searchTitle(string titles[], int runTimes[], string genre[], float userRatings[], int releaseYears[], int DBSIZE);

int main()
{
	const int DBSIZE = 2000;
	string titles[DBSIZE];
	int runTimes[DBSIZE];
	string genre[DBSIZE];
	float userRatings[DBSIZE];
	int releaseYears[DBSIZE];
	string searchtitle;
	
	readData(titles ,runTimes, genre, userRatings, releaseYears, DBSIZE);

	int choice;
	do {
		cout << "Welcome to the Movie Database!" <<endl;
		cout << "*----------------------------*" << endl;
		cout << "Menu:" << endl;
		cout << "1) Display All Movies" << endl;
		cout << "2) Display Movies by Genre" << endl;
		cout << "3) Search for Movie by Title" << endl;
		cout << "4) Exit Program" << endl;
		cout << ">> ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1: showTitles(titles, runTimes, genre, userRatings, releaseYears, DBSIZE);
			break;
		case 2: showGenres(titles, runTimes, genre, userRatings, releaseYears, DBSIZE);
			break;
		case 3: searchTitle(titles, runTimes, genre, userRatings, releaseYears, DBSIZE);
			break;
		case 4: return 0;
			break;
		default:
			cout << "Please enter a valid option." << endl;
				break;
		}
	} while (choice != 4);
		


	system("pause");
	return 0;
}

void showTitles(string titles[], int runTimes[], string genre[],float userRatings[],int releaseYears[], int DBSIZE) 
{
	cout << left;
	
	cout << setw(5) << "#" <<  "|" << setw(27)<< "Movie Title" << "|" << setw(16) << "Runtimes (min)"  << "|" << setw(16) << "Genre" << "|" << setw(7) << "Rating" << "|" << setw(4) << "Year" << endl;
	cout << setw(80) << setfill('-') << '-' << endl;
	cout << setfill(' ');
	
	int i;
	int counter = 1;
	for (i = 0; i < DBSIZE; i++)
	{
		cout << setw(5) << i+1 <<  "|" << setw(27) << titles[i] << "|" << setw(16) << runTimes[i]  << "|" << setw(16) << genre[i] << "|" << setw(7) << userRatings[i] << "|" << setw(4) << releaseYears[i];
		counter++;

		if (counter == 20)
		{
			cout << endl;
			cout << "Press Enter to continue..." << endl;
			cout << endl;
			cin.ignore();
			counter = 1;
			cout << setw(5) << "#" <<  "|" << setw(27)<< "Movie Title" << "|" << setw(16) << "Runtimes (min)"  << "|" << setw(16) << "Genre" << "|" << setw(7) << "Rating" << "|" << setw(4) << "Year" << endl;
			cout << setw(80) << setfill('-') << '-';
			cout << setfill(' ');
		}
		cout << endl;
	}
}

void showGenres(string titles[], int runTimes[], string genre[],float userRatings[],int releaseYears[], int DBSIZE)
{
	string userGenre;
	int movieCount = 1;
	cout << "Enter a genre: ";
	getline(cin, userGenre);

	cout << left;
	cout << setw(5) << "#" <<  "|" << setw(27)<< "Movie Title" << "|" << setw(16) << "Runtimes (min)"  << "|" << setw(16) << "Genre" << "|" << setw(7) << "Rating" << "|" << setw(4) << "Year" << endl;
	cout << setw(80) << setfill('-') << '-' << endl;
	cout << setfill(' ');
	
	int i;
	int counter = 1;
	for (i = 0; i < DBSIZE; i++)
	{
		
		if (userGenre  == genre[i])
		{
			counter++;
			cout << setw(5) << movieCount <<  "|" << setw(27) << titles[i] << "|" << setw(16) << runTimes[i]  << "|" << setw(16) << userGenre << "|" << setw(7) << userRatings[i] << "|" << setw(4) << releaseYears[i];
			movieCount++;
			if (counter == 20)
			{
				cout << endl;
				cout << "Press Enter to continue..." << endl;
				cout << endl;
				cin.ignore();
				counter = 1;
				cout << setw(5) << "#" <<  "|" << setw(27)<< "Movie Title" << "|" << setw(16) << "Runtimes (min)"  << "|" << setw(16) << "Genre" << "|" << setw(7) << "Rating" << "|" << setw(4) << "Year" << endl;
				cout << setw(80) << setfill('-') << '-';
				cout << setfill(' ');
			}
			cout << endl;
		}
	}
}
void searchTitle(string titles[], int runTimes[], string genre[], float userRatings[], int releaseYears[], int DBSIZE)
{
	int i;
	string movieName;
	cout << "What movie would you like to look for: ";
	cin >> movieName;

	for(i = 0; i < DBSIZE; i++)
	{
		if (movieName == titles[i])
		{
			cout << setw(32) << setfill('*') << "*" << endl;
			cout << setfill(' ');
			cout << "* " << titles[i] << setw(27) << "*" << endl;
			cout << "* " << setw(30) << "*" << endl;
			cout << "* " << "Genre: " << genre[i] << setw(17) << "*" << endl;
			cout << "* " << "Release Year: " << releaseYears[i] << setw(12) << "*" << endl;
			cout << "* " << "Runtime (in minutes): " << runTimes[i] << setw(5) << "*" << endl;
			cout << "* " << setw(30) << "*" << endl;
			cout << "* " << "Average User Rating: " << userRatings[i] << setw(6) << "*" << endl;
			cout << setw(32) << setfill('*') << "*" << endl;
			cout << setfill(' ');
			
			cout << endl;
		}
	}
	cout << "I'm sorry, that movie doesn't exist in the database." << endl;
	cout << endl;
}

void readData(string titles[], int runTimes[], string genre[], float userRatings[], int releaseYears[], int DBSIZE)
{
	ifstream infile;
	infile.open("movies_dataset.txt");
	int i = 0;

	while( !infile.eof() )
	{
		getline(infile, titles[i], '\t');
		infile >> runTimes[i];
		infile.ignore();
		getline(infile, genre[i], '\t');
		infile >> userRatings[i];
		infile.ignore();
		infile >> releaseYears[i];
		infile.ignore();
		i++;
	}

	infile.close();
		
}