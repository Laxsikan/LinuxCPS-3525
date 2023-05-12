#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/algorithm/string/split.hpp>
#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;
using namespace boost::gregorian;
using namespace boost::algorithm;

string checkTextData(string mydata) {
   char cstr[mydata.size()+1];
   char *token;
   mydata.copy(cstr,mydata.size()+1);
   string msg="";

   token = strtok(cstr,"\n");
//   msg = msg + "<br>token 1 size: " + to_string(sizeof(token[1])) + ":" + to_string(token[0]) + ":" + token + "\n";
   int height = stoi(strtok(token,","));
   int width = stoi(strtok(NULL,","));
   if (height >0 && width >0) {
     char darray[height][width];
     msg=msg + "<br>Height: " + to_string(height) + ", width: " + to_string(width)+ "\n";

     mydata.copy(cstr,mydata.size()+1);
     token = strtok(cstr,"\n");
     token = strtok(NULL,"\n");
     for (int i=1; i<= height; i++) {
       msg = msg +"<br>" + to_string(i) + ":" + token +"\n";
       for (int j=0;j<width;j++)
           strncpy(darray[i-1],token,width);
       token = strtok(NULL,"\n");
     }

     int numB=0;
     int ct=0;
     for (int i=0; i< height; i++) {
        for (int j=0; j< width; j++) {
           ct++;
           msg = msg + "<br>(" + to_string(j) + "," + to_string(i) + "): " +darray[i][j] + "\n";
           if (darray[i][j]=='B')  numB++;
           if (darray[i][j]=='T')  numT++;
        }
     }
     msg = msg + "<br>Total number of characters: " + to_string(ct) + ", number of B is " + to_string(numB) + ", number of T is " + to_string(numT) + "\n";
   } else {
     msg="<br>The height: " + to_string(height) + ", width: " + to_string(width) + " cannot be negative\n";
   }
   return msg;
}


