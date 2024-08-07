#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

//NAIVE STRING MATCHER
int naive_string_matcher(string pattern, string text){
  for(int i=0; i<=text.length()-pattern.length(); i++){
    int j=0;
    while (j<pattern.length() && text[i+j]==pattern[j])
    {
      j++;
      if(j==pattern.length()){
        return i;
        break;
      }
    }
  }
  return -1;
}

//  ^	The caret anchor matches the beginning of the line.
int check1(string subregex, string text){
  return naive_string_matcher(subregex, text);
}

// . The dot operator matches any single character.
int check2(int index, string subregex, string text){
  int result1 = naive_string_matcher(subregex.substr(0, index), text);
  int result2 = naive_string_matcher(subregex.substr(index + 1, subregex.length() - index - 1), text);
  if (result1 != -1 && result2 != -1) {
      return result1;
  }
  return -1;
}

// []	A box enables a single character to be matched against a character list or character range.
int check3(string subregex, string text) {
    int pos = subregex.find(']');
    string charList = subregex.substr(0, pos);
    int result = -1;

    for (int i = 0; charList[i] != '\0'; i++) {
        string str = charList[i] + subregex.substr(pos + 1);    //b[aeiou]bble
        result = naive_string_matcher(str, text);
        if (result != -1) {
            break;
        }
    }

    return result;
}

// ? preceding character may or may not be present in the string to be matched.
int check4(string subregex, string text){
  int result1, result2;
  int length = subregex.length();  //7
  result1 = naive_string_matcher(subregex, text);  //bubble   //cbubblep
  result2 = naive_string_matcher(subregex.substr(0,length-1), text);
  if(result1!=-1) return result1;
  else if(result2!=-1) return result2;
  else return -1;
}

// $ the match must occur at the end of the string.
int check5(string subregex, string text){                  //end$ hiend
  int length1 = subregex.length();  //3
  int length2 = text.length();   //5
  int result =  naive_string_matcher(subregex, text);
  string temp = text.substr(length2-length1, length2);
  if(result!=-1 && temp==subregex) return result;
}

//CHECK REGEX 
int check_regex(string regex, string text){
  for(int i=0; i<regex.length(); i++){
    if(regex[0]=='^'){
      int pos = regex.find('^');
      return check1(regex.substr(1), text);
    }

    if(regex[i]=='.'){
      return check2(i,regex, text);
    }

    if(regex[i]=='['){
      int result2;
      int result1 =  check3(regex.substr(i+1), text);
      if(result1 != -1){
        string str = regex.substr(0,i-1);
        result2 = naive_string_matcher(str, text);
        if(result2!=-1) return result2;
      }
    }

    if(regex[i]=='?'){
      return check4(regex.substr(0,i), text);
    }

    if(regex[i]=='$'){
      return check5(regex.substr(0, i), text);
    }
  }
}


int main(){
  string pattern;
  string text;

  ifstream myfile1;
  ifstream myfile2;

  string inputFile;
  string patternFile;

  inputFile = "text2.txt";
  patternFile = "pattern2.txt";
  
  myfile1.open(patternFile);
  if(myfile1.is_open()){
    myfile1>>pattern;
  }
  myfile2.open(inputFile);
  if(myfile2.is_open()){
    myfile2>>text;
  }

  ofstream myfile3("output.txt");
  
  myfile3<<"Position where pattern found: "<<check_regex(pattern, text);

}