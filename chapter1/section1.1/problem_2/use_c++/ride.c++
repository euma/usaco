/*
ID: wernheo1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string line;
  if ( fin ) {
    while ( getline( fin , line ) ) {
      cout << linecount << ": " << line << '\n' ;//supposing '\n' to be line end
  //fout << a+b << endl;
  return 0;
}
