#ifndef WOMENDB_H_INCLUDED
#define WOMENDB_H_INCLUDED
#include "WomenPlayers.h"
#include "rating.h"
#include <list>

class WomenDb
{
	std::list<Rating> l_women;
  public:
 	void addPlayers(int, std::string, std::string, std::string, std::string, int,int,int,int);
    	bool removePlayers(std::string);
    	Rating* findWomenById(int);
    	int countAll();
    	int computeMaxRating();
   
    	int countWomenByFederation(std::string);
  	
};

#endif
