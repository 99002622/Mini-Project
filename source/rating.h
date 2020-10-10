#ifndef __RATING_H
#define __RATING_H

#include <string>
#include "WomenPlayers.h"
using namespace std;
class Rating : public WomenPlayers
{
    public:
        int std_rating;
        int rapid_rating;
        int blitz_rating;
        
    public:
        //constructors
        
        Rating();
        Rating(int,std::string,std::string,std::string,std::string,int,int,int,int);
        
        
        int computeRating();
        
        int getStdRating();
        int getRapidRating();
        int getBlitzRating();
        
};
#endif
