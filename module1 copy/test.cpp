#include <fstream>

using namespace std;

int main(){

    ofstream outputfile;

    outputfile.open("demotext.txt");

    outputfile << "Third LINE HERE!!!! \n Test stuff";
    outputfile << " ";
    outputfile << 12.3;
    outputfile << "\ntest again \n \t teststuff"<< 21;





    return 0;
}