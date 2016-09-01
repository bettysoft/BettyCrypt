//
//  aes.h
//
//  Created by BettySoft on 27.07.15.
//  Copyright © 2015 BettySoft. All rights reserved.
//

#ifndef H_FILE_AES_128
#define H_FILE_AES_128

#include "../crypt.h"
#include <functional>
#include <stdint.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>


namespace BettyCryptModules{

class AES_128 : public Crypt{
private:
	BYTE xmult(BYTE a);
	BYTE Multiply(BYTE x, BYTE y);

	static const unsigned short int Nb = 4, Nk = 4, Nr = Nk+6, BlockSize = 16;
	static BYTE Rcon[256], SBox[256], InvSBox[256];

	BYTE state[4][Nb], RoundKey[240];

	void addRoundKey(const unsigned short int round);
	void subBytes();
	void shiftRows();
	void mixColumns();
	void invSubBytes();
	void invShiftRows();
	void invMixColumns();
	void keyExpansion(BYTE key[4*Nk], const short int &Nk);
	void cipher(BYTE in[4*Nb], BYTE out[4*Nb]);
	void invCipher(BYTE in[4*Nb], BYTE out[4*Nb]);
public:
	bool decrypt(const char *srcPath, const char *dstPath, const char *pass, std::function<void(const unsigned int)> update);
	bool encrypt(const char *srcPath, const char *dstPath, const char *pass, std::function<void(const unsigned int)> update);
};

};

#endif