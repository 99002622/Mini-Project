
#include "WomenPlayers.h"
#include <iostream>

WomenPlayers::WomenPlayers(): fide_id(0), name(""),federation(""), gender(""),title(""), dob(0) { }
    
    
WomenPlayers::WomenPlayers(int id,std::string n,std::string fed,std::string gen,std::string tit,int db):  fide_id(id), name(n), federation(fed),title(tit), gender(gen),dob(db) { } 
     
 int WomenPlayers::getFideId()
{
	return fide_id;
}
std::string WomenPlayers::getName()
{
	return name;
}
std::string WomenPlayers::getFederation()
{
	return federation;
}
std::string WomenPlayers::getGender()
{
	return gender;

}
std::string WomenPlayers::getTitle()
{
	return title;
}     
//Issue resolved
 int WomenPlayers::getDob()
 {
 	return dob;
 }    
void WomenPlayers:: display()
{
    std:: cout << fide_id<<","<<name<<"," <<federation << ","<<gender<< ","<<dob <<std::endl;
}
