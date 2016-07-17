/***********************************************************************************
 *  One Click Installer makes it easy for users to install software, no matter
 *  where that software is located.
 *
 *  Copyright (C) 2016  Shalom <shalomray7@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************************
 *  This program's developed as part of GSoC - 2016
 *  Project: One Click Installer
 *  Mentors: Antonio Larrosa, and Cornelius Schumacher
 *  Organization: OpenSUSE
 *  Previous Contributor(s): Saurabh Sood
 ***********************************************************************************/

#define MAIN_FILE	// Needed for permissions.h to do magic ;)
#include <iostream>
#include <fstream>
#include <sstream>
#include "permissions.h"
#include "backend.h"

using namespace std;

int main( int argc, char *argv[] )
{
    if ( argc < 3 ) {
	cerr << "Usage: main <File Path> <OCI Process UID>" << endl;
	exit( 1 );
    }
    
    /* Set ruid, euid of OCIhelper and ociID of OCI */
    ruid = getuid();
    euid = geteuid();
    ociId = atoi( argv[ 2 ] );
    
    /* Read in repositories and packages from the temporay file created in OCI */
    ifstream inFile( argv[ 1 ] );
    if ( !inFile.good() ) {
	cerr << "Oops! Either file doesn't exist or is corrupted" << endl;
	exit( 2 );
    }
    
    string line;
    while ( getline( inFile, line ) ) {	//addRepository
	if ( line.at( 0 ) == 'R' ) {
	    string repo = line.substr( 2 );
	    cout << repo << endl;
	}
	else if ( line.at( 0 ) == 'P' ) { //addPackage
	    string package = line.substr( 2 );
	    cout << package << endl;
	}
    }
    
    Backend *ptr = new Backend();

    return 0;
}
