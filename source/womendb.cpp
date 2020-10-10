#include "WomenPlayers.h"
#include "womendb.h"

#include "rating.h"

#include <list>
#include <iterator>

std::list<Rating> l_women;

void WomenDb::addPlayers(int fide_id ,std::string name, std::string federation, std::string gender, std::string title, int dob,int std_rating, int rapid_rating, int blitz_rating)
{	
	l_women.push_back(Rating(fide_id, name, federation, gender,title, dob,std_rating,rapid_rating,blitz_rating));
	// true;
}


bool WomenDb::removePlayers(std::string name)
{
	std::list<Rating> :: iterator iter;

   	for(iter=l_women.begin();iter!=l_women.end();iter++)
    	{
        	if(iter->getName()== name)
        	{
           	l_women.erase(iter);
           	return true;
        	}
    	}
    	return false;
	
}

Rating* WomenDb::findWomenById(int fide_id)
{
	std::list<Rating> :: iterator iter;

   	for(iter=l_women.begin();iter!=l_women.end();iter++)
    	{
        	if(iter->getFideId()== fide_id)
        	{
           		return &(*iter);
        	}
    	}
    	return NULL;
}

int WomenDb::countAll()
{
	return l_women.size();
}



int WomenDb::computeMaxRating()
{
	std::list<Rating> :: iterator iter= l_women.begin();
	int maxRat=iter->Rating::computeRating();

   	for(;iter!=l_women.end();iter++)
    	{
        	 if(maxRat < iter->Rating::computeRating())
        	{
            		maxRat = iter->Rating::computeRating();
        	}	

    	}
	return maxRat;
}

int WomenDb::countWomenByFederation(std::string federation)
{
	std::list<Rating> :: iterator iter;
	int countWomen=0;

   	for(iter=l_women.begin();iter!=l_women.end();iter++)
    	{
        	if(iter->getFederation()== federation)
        	{
           		++countWomen;
        	}
    	}
    	return countWomen;
}

  	







