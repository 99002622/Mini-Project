#ifndef __WOMENPLAYERS_H
#define __WOMENPLAYERS_H

#include <string>

using namespace std;
class WomenPlayers{
    public:
        int fide_id;
        string name;
        string federation;
        string gender;
        string title;
        int dob;
        
    public:
        WomenPlayers();
        WomenPlayers(int,std::string,std::string,std::string,std::string,int);
        
        //void printData();
        int getFideId();
         std::string getName();
         std::string getFederation();
         std::string getGender();
         std::string getTitle();
        int getDob();
        void display();
};
#endif
