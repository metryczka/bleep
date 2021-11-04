#include <iostream>
#include <string>
using namespace std;


string bleep(string word, string& text, string stars);
string to_lower(string& word, int from, int to);
string to_upper(string& word, int from, int to);

int main(){
  //Asking for the sentence in which we bleep
  string text; 
  cout << "Which sentence do you want me to bleep" << "\n";
  getline(cin, text);
  
  //Asking for the word, that should be bleep
  string word;
  cout << "What should I bleep?" << "\n";
  cin >> word;
  word = to_lower(word, 0, word.length());
  
  //preparing proper number of stars
  string stars;
  for (int i = 0; i < word.length(); i++){
    stars.append("*");
  }

  //adding spaces, to avoid bleeping characters beeing part of another world
  word.append(" ");
  word.insert(0, " ");

  //adding space befor star
  stars.insert(0, " ");

  //bleeping words inside sentence
  bleep(word, text, stars);
  //bleeping capitalized words inside the sentence
  to_upper(word, 0, word.length());
  bleep(word, text, stars);
  to_lower(word, 0, word.length());
  //bleeping words starting with Uppercase
  to_upper(word, 1, 2);
  bleep(word, text, stars);
  to_lower(word, 1, 2);
 
  //bleeping words after which there are some punctuation mark, lowercase
  word.erase(word.length() - 1);
  word.append(".");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append("?");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append(",");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append("!");
  bleep(word, text, stars);
  word.erase(word.length() - 1);

  //bleeping words after which there are some punctuation mark, uppercase
  to_upper(word, 0, word.length());
  word.append(".");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append("?");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append(",");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append("!");
  bleep(word, text, stars);
  word.erase(word.length() - 1);

  //bleeping words after which there are some punctuation mark, starting with upper
  to_lower(word, 2, word.length());
  word.append(".");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append("?");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append(",");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  word.append("!");
  bleep(word, text, stars);
  word.erase(word.length() - 1);
  
  //bleeping first word
  word.erase(0, 1);
  to_lower(word, 0, word.length());
 
  string first_word = text.substr(0,word.length());
  to_lower(first_word, 0, word.length());
 
  stars.erase(0,1);
  if (first_word == word){
    if (text[word.length()] >= 32 && text[word.length()] <= 47 ){
      text.replace(0, word.length(), stars);
    }

  }
  //bleeping last word, in case if there is no punctuation
  string last_word = text.substr(text.length()-word.length(), text.length());
  to_lower(last_word, 0, word.length());
  cout << last_word<< endl; 
  if (last_word == word){
    if (text[text.length() - word.length() - 1] == 32){
      text.replace(text.length()-word.length(), word.length(), stars);
    }
  }

  cout << text << endl;
  return 0;
}


//Recursive function for bleeping, words in the middle of sentence will be bleeped
string bleep(string word, string& text, string stars){
  if (text.find(word) != string::npos){
    int ind = text.find(word);
      text.replace(ind, word.length()-1, stars);
      bleep(word, text, stars);
    }

  return text;  
}

//Bleeping first word (if necessary)   
//string bleep_first(string word, string& text, string stars){

//}   

//to lowercase function 
string to_lower(string& word, int from, int to){
  for (int i = from; i < to; i++){
    if (word[i] >= 65 && word[i] <= 90){
      word[i]= word[i] + 32;
    }
  
  }
  return word;
}
//to uppercase function
string to_upper(string& word, int from, int to){
  for (int i = from; i<to; i++){
    if (word[i] >= 97 && word[i] <= 122){
      word[i]= word[i] - 32;
    }
  
  }
  return word;
}
