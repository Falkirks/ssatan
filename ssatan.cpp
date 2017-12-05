#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility> 
#include <algorithm> 
#include <random>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

std::vector<string> readData(){
	std::vector<string> names;


	ifstream fin;
	string dir, filepath;
	DIR *dp;
	struct dirent *dirp;
	struct stat filestat;

	dir = "./people";

	dp = opendir( dir.c_str() );
	while ((dirp = readdir( dp ))){
		filepath = dir + "/" + dirp->d_name;

		// If the file is a directory (or is in some way invalid) we'll skip it 
		if (stat( filepath.c_str(), &filestat )) continue;
		if (S_ISDIR( filestat.st_mode ))         continue;

		names.push_back(dirp->d_name);
	}

	closedir( dp );

	return names;
}

int simpleRandom (int i) { 
	return rand()%i;
}

int main(){
	srand(unsigned(time(NULL)));

	vector<string> names = readData();

	cout << "Secret Satan v1\n";
	cout << "There are " << names.size() << " participants." << endl;

	cout << "Their names are: \n ";


	for(auto const& name: names){
		cout << "	" << name << "\n";
	}



	random_shuffle ( names.begin(), names.end(), simpleRandom);

	vector< tuple<string, string> > pairings;

	for(int i = 0; i < names.size(); i++){
		int target = (i + 1) % names.size();
		//cout << names[i] << " ----> " << names[target] << endl;
		pairings.push_back(tuple<string, string>(names[i], names[target]));
	}

	cout << endl;

	random_shuffle ( pairings.begin(), pairings.end(), simpleRandom);

	for(auto const& pair : pairings){
		//cout << get<0>(pair) << " ----> " << get<1>(pair) << endl;
		cout << "Copy to " << get<0>(pair) << endl << endl;
		system(("pbcopy < ./people/" + get<1>(pair)).c_str());
		cin.ignore();
	}



	system("echo \"Nothing here\" |  pbcopy");
	return 0;
}