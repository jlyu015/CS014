#include <iostream>
#include <iomanip>
using namespace std;
#include "Playlist.h"


void PrintMenue(const string);

void PrintMenu(const string playlistTitle) {
   char menuOp = ' ';
   string uniqueID;
   string songName;
   string artistName;
   int songLength = 0;
   int numNodes = 0;
   int songPosition = 0;
   int newPosition = 0;
   int totalTime;
   int initialIndex = 1;
   int count = 0;
   PlaylistNode* newSong = 0;
   PlaylistNode* currNode = 0;
   PlaylistNode* songNode = 0;
   PlaylistNode* prevNode = 0;
   PlaylistNode* insertPosNode = 0;
   PlaylistNode* headNode = 0;
   PlaylistNode* tailNode = 0;
   PlaylistNode* currPrintNode = 0;
   PlaylistNode* temp = nullptr;
              


   // Output menu option, prompt users for valid selection
   while(menuOp != 'q') {
      menuOp = ' ';
      cout << playlistTitle << " PLAYLIST MENU" << endl;
      cout << "a - Add song" << endl;
      cout << "d - Remove song" << endl;
      cout << "c - Change position of song" << endl;
      cout << "s - Output songs by specific artist" << endl;
      cout << "t - Output total time of playlist (in seconds)" << endl;
      cout << "o - Output full playlist" << endl;
      cout << "q - Quit" << endl << endl;
      while (menuOp != 'a' && menuOp != 'd' && menuOp != 'c' &&
             menuOp != 's' && menuOp != 't' && menuOp != 'o' && menuOp != 'q') {
         cout << "Choose an option:" << endl;
         cin >> menuOp;
      }
      // Call corresponding menu action
      switch (menuOp) {
         case 'a':
            //Prompt user for song information
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueID;
            cin.ignore();
            cout << "Enter song's name:" << endl;
            getline(cin, songName);
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;
            cin.ignore();
               // Create a new node for playlist
               
            newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);
           
            if (headNode == 0) {
               headNode = newSong;
               tailNode = newSong;
            }
            else {
               tailNode->InsertAfter(newSong);
               tailNode = tailNode->GetNext();
            }
            cout << endl;

            numNodes++;
            break;
         
            //addSong()
         case 'd':
            cout << "REMOVE SONG" <<  endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueID;
            cin.ignore();
            prevNode = headNode;
            currNode = headNode->GetNext();
            for(unsigned i = 0; i < numNodes; ++i) {
               if(currNode->GetID() == uniqueID) {
                  PlaylistNode* tempNode = currNode;
                  delete tempNode;
                  cout << "\"" << currNode->GetSongName() << "\" removed." << endl << endl;
                  prevNode->SetNext(currNode->GetNext());
                  numNodes--;
                  break;
               }
               currNode = currNode->GetNext();
               prevNode = currNode;
            }
            break;
         case 'c':
         
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:";
            cin >> songPosition;
            cout << endl;
            currNode = headNode;
            temp = headNode;
            count = 1;
            //finds what the node that needs to be moved
            while (count < songPosition) {
                temp = currNode;
                currNode = currNode->GetNext();
                ++count;
            }
            //take out curr node from the list
            if (headNode == currNode) {
                headNode = currNode->GetNext();
            }
            else if (tailNode == currNode) {
               //sets the second the last node as the tail
                 temp->SetNext(tailNode->GetNext());
                 tailNode = temp;
            }
            else {//takes the node out from the middle 
                temp->SetNext(currNode->GetNext());
            }       
            currNode->SetNext(nullptr);
            cout << "Enter new position for song:";
            cin >> songPosition;
            cout << endl;
            temp = headNode;
            count = 2;
            //finds new position of node as temp
            while (count < songPosition) {
                temp = temp->GetNext();
                ++count;
            }
            // cout << "this is temp node" << endl;
            // temp->PrintPlaylistNode();
            //puts it in the front of the list
            if (songPosition <= 1) {
                currNode->SetNext(headNode);
                headNode = currNode;
            }
            //put it at the end of the list
            else if (songPosition > (numNodes - 1) ) {
                tailNode = currNode;
                temp->InsertAfter(currNode);
                //cout << "inserted to the back" << endl;
            }
            else {
               //insert in the middle of the list
                currNode->SetNext(temp->GetNext())    ;
                temp->SetNext(currNode);
                //cout << "INSERTED IN THE MIDDLE" << endl;
            }
            cout << "\"" << currNode->GetSongName() << "\" moved to position " << songPosition << endl << endl;
            break; 

         case 's':
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl << endl;
            cin.ignore();
            getline(cin, artistName);
            currNode = headNode;
            for(unsigned i = 0; i < numNodes; ++i) {
               if(currNode->GetArtistName() == artistName) {
                  cout << i + 1 << '.' << endl;
                  currNode->PrintPlaylistNode();
                  cout << endl;
               }
               currNode = currNode->GetNext();
            }
            break;

         case 't':
            totalTime = 0;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            currNode = headNode;
            for (unsigned i = 0; i < numNodes; ++i) {
               totalTime += currNode->GetSongLength();
               currNode = currNode->GetNext();
            }
            cout << "Total time: " << totalTime << " seconds" << endl << endl;
            break;
            
         case 'o':
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if(headNode == nullptr) {
               cout << "Playlist is empty" << endl << endl;
            }

            currNode = headNode;
            for(unsigned i = 0; i < numNodes; ++i) {
               cout << i + 1 << '.' << endl;
               currNode->PrintPlaylistNode();
               if(currNode->GetNext() != nullptr) {
                  currNode = currNode->GetNext();
               }
               cout << endl;
            }
            break;
            //... HIDDEN ... (you do the rest)
      }
   }
}




int main() {
   string playlistTitle;
   // Prompt user for playlist title
   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   cout << endl;
   // Output play list menu options
   PrintMenu(playlistTitle);
   return 0;
}