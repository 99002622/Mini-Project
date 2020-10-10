#include "WomenPlayers.h"
#include "rating.h"
#include "womendb.h"
#include <gtest/gtest.h>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

namespace {

class WomenDbTest : public ::testing::Test {


	public:
	WomenDb w;
	void loadcsv()
	{
		std::list<string> res;
		     		std::list<string> ::iterator iter;
		     		std::string name="",federation="",gender="",title="";
		     		int fide_id=0,dob=0,std_rating=0,rapid_rating=0,blitz_rating=0;
		     	//	double fib=0.0,carb=0.0,rate=0.0;
		    		std::string S, T;
		    		fstream fin;
		    		int count=1;
		    		std::string substr; 
		    		fin.open("top_women_chess_players_aug_2020.csv", ios::in);
		    		while(getline(fin, S))
		    		{
		    			stringstream X(S);
		    			while (getline(X, T,'\n'))
		   			 {
		   	 			res.push_back(T);
		    			 }
		   	        }
		    		iter=res.begin();
		   		 
		    		for(;iter!=res.end();++iter)
		    		{
		    			stringstream ss(*iter); 
		    			
		    			while (ss.good()) 
		    			{ 
						
						getline(ss, substr, ','); 
						//
						switch(count)
						{
							case 1:
								fide_id=std::stoi(substr);
								break;
							case 2:
								name=substr;
								break;
							case 3:
								federation=substr;
								break;
							case 4:
								gender=substr;
								break;
							case 5:
								title=substr;
								break;
							case 6:
								dob=std::stoi(substr);
								break;
							case 7:
								std_rating=std::stoi(substr);
								break;
							case 8:
								rapid_rating=std::stoi(substr);
								break;
							case 9:
								blitz_rating=std::stoi(substr);
								
							
											
								
w.addPlayers(fide_id,name,federation,gender,title,dob,std_rating,rapid_rating,blitz_rating);
fide_id=0,name="",federation="",gender="",title="",dob=0,std_rating=0,rapid_rating=0,blitz_rating=0,count=0;
								break;
						
						}
						++count;
						
		    			}
		    			
		    			
		  		}
	
	}

 
  void SetUp() { 
  	loadcsv();	
    players.WomenDb::addPlayers(13600036,"Chiburdanidze Maia","GEO","F","GM",1961,2500,2432,2437);
    players.WomenDb::addPlayers(13700090,"Saduakassova Dinara","KAZ","F","IM",1996,2500,2412,2378);
    players.WomenDb::addPlayers(198026,"Kashlinskaya Alina","RUS","F","IM",1993,2494,2384,2364);
    players.WomenDb::addPlayers(12512214,"Khademalsharieh Sarasadat","IRI","F","IM",1997,2494,2393,2431);
   
  }
  void TearDown() {}
  public:
  WomenDb players;
};

TEST_F(WomenDbTest, AddPlayersTest) {
   players.addPlayers(8602727,"Ruan Lufei","CHN","F","WGM",1987,2491,2345,2654);
  //EXPECT_NE((Trip*)NULL, players.findTripById("SG304"));
  EXPECT_EQ(5, players.countAll());
}
TEST_F(WomenDbTest, RemovePlayers) {
  players.removePlayers("8601283");
  EXPECT_EQ(NULL, players.findWomenById(8601283));
  EXPECT_EQ(4, players.countAll());
}
TEST_F(WomenDbTest, CountTest) {             //Just After Setup
  EXPECT_EQ(4, players.countAll());
}
/*TEST_F(FlightTripDbTest, CountByOperatorTest) {  //Just After Setup
  int count = players.countTripsByOperator("Indigo");
  EXPECT_EQ(2, count);*/

TEST_F(WomenDbTest, MaxRating) {           //Just After Setup
  int maxRate = players.computeMaxRating();
  //int minTime = players.computeMinTravelTime();
  //EXPECT_EQ(12000, maxFare);         //For trip with distance of 1200 miles
  EXPECT_EQ(2456, maxRate);            //For trip with distance of 350 miles   
}

TEST_F(WomenDbTest, FindWomen) {
 // players.removePlayers("8601283");
  EXPECT_EQ(1, players.countWomenByFederation("RUS"));
  EXPECT_EQ(4, players.countAll());
}



/*TEST_F(WomenDbTest, AnotherTest) {         //Just After Setup
  players.addTrip("Chennai","Delhi","SG308", "Spicejet", 1300);
  players.addTrip("Chennai","Bengaluru", "AI848", "AirIndia", 200);
  int count = players.countTripsByOperator("Spicejet");
  double maxFare = players.computeMaxFare();
  double minTime = players.computeMinTravelTime();
  EXPECT_EQ(8, players.countAll());  
  EXPECT_EQ(3, count);  
  EXPECT_EQ(13000, maxFare);  
  EXPECT_EQ(24, minTime);  */

}// namespace
