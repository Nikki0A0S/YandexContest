#include <fstream>

using namespace std;

int main()
{
    ifstream input; 

    input.open("input.txt");

    int a;
    input >> a;

    int b;
    input >> b;

    input.close();
    
    ofstream output;

    output.open("output.txt");

    output << a+b;

    output.close();
    
    return 0;
}
