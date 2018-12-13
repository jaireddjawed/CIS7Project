#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
  int choice;
  string str;
  string keyword;    
  string cipher_text;
  string originalText(string cipher_text, string key) 
{ 
    string orig_text; 
  
    for (int i = 0 ; i < cipher_text.size(); i++) 
    { 
        // converting in range 0-25 
        int x = (cipher_text[i] - key[i] + 26) %26; 
  
        // convert into alphabets(ASCII) 
        x += 'A'; 
        orig_text.push_back(x); 
    } 
    return orig_text; 
}
string generateKey(string str, string key) 
{ 
    int x = str.size(); 
  
    for (int i = 0; ; i++) 
    { 
        if (x == i) 
            i = 0; 
        if (key.size() == str.size()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key; 
} 
  string cipherText(string str, string key) 
{  
  
    for (int i = 0; i < str.size(); i++) 
    { 
        // converting in range 0-25 
        int x = (str[i] + key[i]) %26; 
  
        // converting into alphabet 
        x += 'A'; 
  
        cipher_text.push_back(x); 
    } 
    return cipher_text; 
} 
int main() {
cout<<"(Just some notes, so far cant have KEYWORD be smaller than the message and no spaces,symbols or lowercases)"<<endl<<endl;
cout<<"Welcome to Cap Locks Encrypter press 1 to encrypt and 2 to decrypt"<<endl;
cin>>choice;
  switch (choice){
case 1:
cout<<"You have chosen Encryption please enter the message you would like encrypted"<<endl;
cin>>str;
cin.ignore();
cout<<"Now would you please enter the keyword for the encryption:"<<endl;
cin>>keyword;
cin.ignore();
break;
case 2:
cout<<"You have chosen Decryption please enter the message you would like decrypted:"<<endl;
cin>>str;
cin.ignore();
cout<<"Now the key which you want to use";
cin>>keyword;
cin.ignore();
break;
default:
cout<<"Unfortunately there was an error please restart the program. ";

  }
  string key = generateKey(str, keyword); 
string cipher_text = cipherText(str, key);
cout<<"Thank you your message is: "<<cipher_text<<" also the reverted form is "<<originalText(cipher_text, key);
return 0;
}
