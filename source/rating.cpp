#include "rating.h"
#include "WomenPlayers.h"

Rating::Rating():WomenPlayers(),std_rating(0), rapid_rating(0),blitz_rating(0) { }
        
Rating::Rating(int id,std::string n,std::string fed,std::string gen,std::string tit,int db,int sr, int rr, int br):
WomenPlayers(id, n, fed,tit, gen,db ),std_rating(sr),rapid_rating(rr),blitz_rating(br) { }
               
//opetaions
int Rating::computeRating()
{
	int rat = (std_rating+rapid_rating+blitz_rating)/3;
	return rat;
}
               
  //getters             
int Rating::getStdRating()
{
	return std_rating;
}        
int Rating::getRapidRating()
{
	return rapid_rating;
}
int Rating::getBlitzRating()
{
	return blitz_rating;
}
        
