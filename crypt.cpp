//
//  crypt.cpp
//
//  Created by BettySoft on 15.08.15.
//  Copyright © 2015 BettySoft. All rights reserved.
//

#include "crypt.h"


std::string intToHex(const unsigned short int i){
	std::ostringstream strHex;
	strHex << std::hex << std::setfill('0') << std::setw(2) << i;
	return strHex.str();
};

int HexToInt(const char hex1, const char hex2){
	int i = 0;
	if (hex1 >= '0' && hex1 <= '9') i = 16 * (int (hex1) - '0');
	else if (hex1 >= 'A' && hex1 <= 'F') i = 16 * (int (hex1) - ('A'-10));
	else if (hex1 >= 'a' && hex1 <= 'z') i = 16 * (int (hex1) - ('a'-10));

	if (hex2 >= '0' && hex2 <= '9') i += int (hex2) - '0';
	else if (hex2 >= 'A' && hex2 <= 'F') i += int (hex2) - ('A'-10);
	else if (hex2 >= 'a' && hex2 <= 'z') i += int (hex2) - ('a'-10);

	return i;
};

unsigned long long int Crypt::fileSize(const char *path){
	std::ifstream ifOpenReadLength(path,std::ios::binary);
	ifOpenReadLength.seekg(0,std::ios::end);
	unsigned long long int iFileSize = ifOpenReadLength.tellg();
	ifOpenReadLength.seekg(0,std::ios::beg);
	ifOpenReadLength.close();
	return iFileSize;
};

int Crypt::readPadding(const char *path){
	std::ifstream ifOpenReadVersion(path,std::ios::binary);
	ifOpenReadVersion.seekg(8,std::ios::beg);
	char chPadding[3];
	ifOpenReadVersion.getline(chPadding,3);
	ifOpenReadVersion.seekg(0,std::ios::beg);
	ifOpenReadVersion.close();
	return HexToInt(chPadding[0],chPadding[1]);
};

std::string Crypt::readCryptVersion(const char *path){
	std::ifstream ifOpenReadVersion(path,std::ios::binary);
	ifOpenReadVersion.seekg(0,std::ios::beg);
	char chVersionInFile[9];
	ifOpenReadVersion.getline(chVersionInFile,9);
	ifOpenReadVersion.seekg(0,std::ios::beg);
	ifOpenReadVersion.close();
	return chVersionInFile;
};