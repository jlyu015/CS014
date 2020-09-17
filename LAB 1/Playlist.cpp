#include "Playlist.h"


PlaylistNode::PlaylistNode() {
	this->uniqueID = "none";
	this->songName = "none";
	this->artistName = "none";
	this->songLength = 0;
	this->nextNodePtr = nullptr;
}
PlaylistNode::PlaylistNode(string initID, string tuneName, string singer, int length, PlaylistNode* nextLoc) {
	this->uniqueID = initID;
	this->songName = tuneName;
	this->artistName = singer;
	this->songLength = length;
	this->nextNodePtr = nextLoc;
}


void PlaylistNode::InsertAfter(PlaylistNode* newSong) {
	this->nextNodePtr = newSong;
}
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
	this->nextNodePtr = nodePtr;
}

string PlaylistNode::GetID() const {
	return uniqueID;

}
string PlaylistNode::GetSongName() const {
	return songName;
}

string PlaylistNode::GetArtistName() const {
	return artistName;
}

int PlaylistNode::GetSongLength() const {
	return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
	/*
	Unique ID: S123
	Song Name: Peg
	Artist Name: Steely Dan
	Song Length (in seconds): 237
	*/

	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl;
	cout << "Song Length (in seconds): " << songLength << endl;
	
}





