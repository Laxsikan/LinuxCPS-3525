#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

int main () {
   Cgicc cgi;

   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>CPS 3525 project 3 test 2</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
  cout << "<h2>CPS 3525 proejct 3 test 2</h2>\n";
   cout << "<br>Using GET Method in C++\n";

   int n1 = std::stoi(cgi("number1"));
   int n2 = std::stoi(cgi("number2"));
   cout << "<br>Number 1: " << n1 << endl;
   cout << "<br>Number 2: " << n2 << endl;
   int sum=n1+n2;
   cout << "<br>Sum of "<< n1 << "+" << n2 << " = " << sum << "<br>\n";
   cout << "<br/>\n";
   cout << "</body>\n";
   cout << "</html>\n";

   return 0;
}
