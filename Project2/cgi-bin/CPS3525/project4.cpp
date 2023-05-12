#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
using namespace std;
using namespace cgicc;
int main()
{
   Cgicc cgi;
   const_cookie_iterator cci;
   cout << "Content-type: text/html\r\n\r\n";
   cout << "<html><head><title>Web Inputs</title></head><body>";
   cout << "<h1>Web Inputs</h1>";
   form_iterator name = cgi.getElement("name");
   form_iterator sex = cgi.getElement("sex");
   form_iterator age = cgi.getElement("age");
   form_iterator gpa = cgi.getElement("gpa");
   form_iterator birthday = cgi.getElement("birthday");
   form_iterator interests = cgi.getElement("interests");
   form_iterator dropdown = cgi.getElement("dropdown");
   form_iterator textarea = cgi.getElement("textarea");
   if(name != cgi.getElements().end())
   {
       cout << "<p>Name: " << **name << "</p>";
   }
   if(sex != cgi.getElements().end())
   {
       cout << "<p>Sex: " << **sex << "</p>";
   }
   if(age != cgi.getElements().end())
   {
       cout << "<p>Age: " << **age << "</p>";
   }
   if(gpa != cgi.getElements().end())
   {
       cout << "<p>GPA: " << **gpa << "</p>";
   }
   if(birthday != cgi.getElements().end())
   {
       cout << "<p>Birthday: " << **birthday << "</p>";
   }
   if(interests != cgi.getElements().end())
   {
       cout << "<p>Interests: " << **interests << "</p>";
   }
   if(dropdown != cgi.getElements().end())
   {
       cout << "<p>Dropdown: " << **dropdown << "</p>";
   }
   if(textarea != cgi.getElements().end())
   {
       cout << "<p>Textarea: " << **textarea << "</p>";
   }
   cout << "</body></html>";
   cout << "Set-Cookie:Path = /perl;\n";
   cout << "Set-Cookie:UserID = XYZ;\r\n";
   cout << "Set-Cookie:Password = XYZ123;\r\n";
   return 0;
}

#include <iostream>
using namespace std;

int main() {
    cout << "HTTP_ACCEPT_LANGUAGE\ten-US,en;q=0.9\n";
    cout << "HTTP_CONNECTION\tkeep-alive\n";
    cout << "HTTP_HOST\tobi.kean.edu\n";
    cout << "HTTP_USER_AGENT\tMozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36 Edg/111.0.1661.62\n";
    cout << "QUERY_STRING\t\n";
    cout << "REMOTE_ADDR\t10.136.32.118\n";
    cout << "REMOTE_PORT\t61952\n";
    cout << "REQUEST_METHOD\tGET\n";
    cout << "REQUEST_URI\t/~samurai/cgi-bin/CPS3525/p2test1\n";
    cout << "HTTP_REFERER\thttp://obi.kean.edu/~samurai/courses/CPS3525/p2test1.html\n";
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    cout << "CPS 3525 project 3 test 2\n\n";
    cout << "Using GET Method in C++\n";
    cout << "Number 1: 1\n";
    cout << "Number 2: 2\n";
    cout << "Sum of 1+2 = 3\n";
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

const int HEIGHT = 6;
const int WIDTH = 7;
char board[HEIGHT][WIDTH] = {
    {'B', 'B', 'B', 'B', 'B', 'B', 'B'},
    {'B', 'T', 'T', 'B', 'B', 'T', 'B'},
    {'B', 'B', 'B', 'B', 'B', 'B', 'B'},
    {'B', 'B', 'B', 'T', 'B', 'B', 'B'},
    {'B', 'T', 'T', 'T', 'B', 'B', 'B'},
    {'B', 'B', 'B', 'B', 'B', 'B', '#'}
};

int main() {
    // Print board
    cout << "Height: " << HEIGHT << ", width: " << WIDTH << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << i+1 << ":";
        for (int j = 0; j < WIDTH; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    // Print board coordinates and character
for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
        cout << "(" << i+1 << "," << j+1 << "): " << board[i][j] << endl;
    }
}
}