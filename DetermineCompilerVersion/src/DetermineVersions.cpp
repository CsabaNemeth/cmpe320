//============================================================================
// Name        : DetermineVersions.cpp
// Author      : Csaba Nemeth
// Version     :
// Copyright   : Your copyright notice
// Description : Find the current version of the compiler in use.
//============================================================================

// This little program access a "macro" variable, __cplusplus, which in
// newer compilers is used to indicated the compatibility of the compiler
// with ISO standards.
//
// To find the actual compiler version number, run the compiler with the
// -v flag.
#include <iostream>
using namespace std;

int main() {
	cout << "The C++ ISO standard used by this compiler is: ";
    if (__cplusplus == 201703L) cout << "C++17" << endl;
    else if (__cplusplus == 201402L) cout << "C++14" << endl;
    else if (__cplusplus == 201103L) cout << "C++11" << endl;
    else if (__cplusplus == 199711L) cout << "C++98" << endl;
    else cout << "pre-standard C++" << endl;
    return 0;
} // end main
