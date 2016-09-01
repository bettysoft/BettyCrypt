//
//  crypt.h
//
//  Created by BettySoft on 15.08.15.
//  Copyright © 2015 BettySoft. All rights reserved.
//

#ifndef H_FILE_CRYPT
#define H_FILE_CRYPT

#include <functional>
#include <stdint.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>


typedef unsigned char BYTE;

std::string intToHex(const unsigned short int i);
int HexToInt(const char hex1, const char hex2);

class Crypt{
protected:
	std::ifstream readFile;
	std::ofstream writeFile;
public:
	virtual bool decrypt(const char *srcPath, const char *dstPath, const char *pass, std::function<void(const unsigned int)> update) = 0;
	virtual bool encrypt(const char *srcPath, const char *dstPath, const char *pass, std::function<void(const unsigned int)> update) = 0;

	static unsigned long long int fileSize(const char *path);
	static int readPadding(const char *path);
	static std::string readCryptVersion(const char *path);
};

#endif