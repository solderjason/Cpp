/* scrabble.cpp
   CSC 116 - Fall 2019

   Complete the implementations of each of the functions below (declared in scrabble.hpp)

   Your Name Here - MM/DD/YYYY
*/

#include <iostream>
#include <set>
#include "scrabble.hpp"



/* Member functions */
ScrabbleSolver::ScrabbleSolver(){


}

void ScrabbleSolver::add_word( std::string const& word ){
//std::set<std::string> dictionary;
dictionary1.insert(word);
//std::cout << "Initial Contents: ";
//	for( auto s: dictionary1 ){
//		std::cout << s << std::endl;
//	}


}

ScoreMap ScrabbleSolver::get_score_map(){
std::map<std::string,int> scoremap;
//for( auto s: dictionary1 ){
  //std::cout << s << std::endl;
//}
for(auto itert=dictionary1.begin(); itert !=dictionary1.end(); itert++){
scoremap[*itert]=compute_score(*itert);
}
//for(auto elem:scoremap){
//  std::cout<<elem.first<< ", " <<elem.second<<std::endl;
//}

return scoremap;

}

ScoreMap ScrabbleSolver::find_words( TileSet const& tiles ){
//  std::map< char, int > letters {};
  std::map<std::string,int> possiblewords;
  // std::string word;

//  for(auto itert=tiles.begin(); itert !=tiles.end(); itert++){
//  letters[*itert]++;
//  }
std::set<std::string> wordset;

 for(auto el:dictionary1){

	if(can_make_word(el, tiles)){

wordset.insert(el);

	 //std::cout<<""<<std::endl;
	 	 //std::cout<<""<<std::endl;
	//const	int score=compute_score(el);
	//	  possiblewords[el]=score;

		}
}

//set ot std::map<

for(auto iters=wordset.begin(); iters!=wordset.end(); iters++){
	possiblewords[*iters]=compute_score(*iters);
}






//for(auto itert=letters.begin(); itert!=letters.end();itert++){


//}


//  }
  return possiblewords;
}

ScoreMap ScrabbleSolver::find_best_words( TileSet const& tiles ){
  std::map<std::string,int> scoremap;
	int max{0};
	 max=find_words(tiles).begin()->second;
	 std::map<std::string,int> bestscoremap;
//std::cout<<"first max is"<<max<<std::endl;
/*for(auto iterm=dictionary1.begin(); iterm!=dictionary1.end(); iterm++){

  if(can_make_word(*iterm, tiles)){

    scoremap[*iterm]=compute_score(*iterm);
  }
}*/

auto scoremapbest=find_words(tiles);
for(auto el:scoremapbest){
	if(el.second>=max){
		max=el.second;
	}
}
//std::cout<<"biggest number is"<<max<<std::endl;
for(auto el:scoremapbest){
	if(el.second>=max){
		bestscoremap[el.first]=max;
	}
}
return bestscoremap;
}

/* Static member functions */


int ScrabbleSolver::compute_score( std::string const& word ){
  //word ot std::map<key, value> map;
std::map< char, int > words {};
  int score=0;
  for(auto el:word){
    words[el]++;

  }

  for (auto elem:words){
    if(elem.first=='a' ||elem.first=='e'||elem.first=='i'||elem.first=='l'||elem.first=='n'||elem.first=='o'|| elem.first=='r'||elem.first=='s'||elem.first=='t'||elem.first=='u'){
    score=score+(1*elem.second);
  }

  else if(elem.first=='d'||elem.first=='g'){
    score=score+(2*elem.second);
  }
  else if(elem.first=='b'||elem.first=='c'||elem.first=='m'||elem.first=='p'){
    score=score+(3*elem.second);
  }
  else if(elem.first=='f'||elem.first=='h'||elem.first=='v'||elem.first=='w'||elem.first=='y'){
    score=score+(4*elem.second);
  }
  else if(elem.first=='k'){
    score=score+(5*elem.second);

  }
  else if(elem.first=='j'||elem.first=='x'){
    score=score+(8*elem.second);
  }
  else{
    score=score+(10*elem.second);
  }
}
  return score;
}

bool ScrabbleSolver::can_make_word( std::string const& word, TileSet const& tiles ){
  auto result=word;
  //std::cout<<word<<std::endl;
  std::map< char, int > letters {};
  std::map< char, int > words {};
//for(unsigned int j=0; j<word.size(); j++){
//  std::cout<<word.at(j);
//}

//std::cout <<" " <<std::endl;
//for(auto itert=tiles.begin(); itert !=tiles.end(); itert++){
//if(*itert){

//}
//  std::cout<<*itert<<std::endl;
//}

// tile to map
for(auto itert=tiles.begin(); itert !=tiles.end(); itert++){
letters[*itert]++;
}
//prints map of letters
//for(auto elem:letters){
//  std::cout<<elem.first<< ", " <<elem.second<<std::endl;
//}

//word to map
for(auto el:word){
  words[el]++;

}
//for(auto ele:words){
//  std::cout<<ele.first<< ", " <<ele.second<<std::endl;
//}


// compare the 2 maps
bool letterokay=true;

if(letterokay==true){
for(auto elem:words ){
bool exists=false;
  for(auto elements:letters){
    if(elem.first==elements.first){
      exists=true;
//std::cout<<"elem.first is "<<elem.first<<"elements first is "<<elements.first<<std::endl;
if(elem.second<=elements.second){
//letterokay==true;

//std::cout<<"elem.second is "<<elem.second<<"elements seonc is "<<elements.second<<std::endl;
}
else{
  letterokay=false;
  return false;
}
}
else{
  letterokay=false;

 }
    }
    if(exists==false){
      return false;
    }

}
return true;
}
//std::cout<<"false line"<<std::endl;
return false;
 }
