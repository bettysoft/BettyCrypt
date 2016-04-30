//
//  aes.cpp
//
//  Created by BettySoft on 27.07.15.
//  Copyright © 2015 BettySoft. All rights reserved.
//

#include "aes.h"


BYTE BettyCryptModules::AES_128::Rcon[256] = {
	0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 
	0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 
	0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 
	0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 
	0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 
	0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 
	0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 
	0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 
	0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 
	0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 
	0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 
	0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 
	0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 
	0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 
	0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 
	0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d
};

BYTE BettyCryptModules::AES_128::SBox[256] = {
	0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
	0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
	0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
	0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
	0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
	0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
	0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
	0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
	0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
	0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
	0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
	0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
	0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
	0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

BYTE BettyCryptModules::AES_128::InvSBox[256] = {
	0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
	0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
	0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
	0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
	0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
	0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
	0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
	0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
	0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
	0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
	0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
	0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
	0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
	0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
	0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};


BYTE BettyCryptModules::AES_128::xmult(BYTE a){
	return ((a<<1)^(((a>>7)&1) * 0x1B));
}

BYTE BettyCryptModules::AES_128::Multiply(BYTE x, BYTE y){
	return (((y&1)*x) ^ ((y>>1&1)*xmult(x)) ^ ((y>>2&1)*xmult(xmult(x))) ^ ((y>>3&1)*xmult(xmult(xmult(x)))) ^ ((y>>4&1)*xmult(xmult(xmult(xmult(x))))));
}

void BettyCryptModules::AES_128::addRoundKey(const unsigned short int round){
	for (short int i = 0; i < 4; i++)
		for (short int j = 0; j < 4; j++) state[j][i] ^= RoundKey[round*Nb*4 + i*Nb+j];
}

void BettyCryptModules::AES_128::subBytes(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) state[i][j] = SBox[state[i][j]];
}

void BettyCryptModules::AES_128::shiftRows(){
	BYTE temp[4][Nb];
	for (int i = 0; i < 4; i++)
		for (short int j = 0; j < 4; j++) temp[i][j] = state[i][j];

	for (int i=0; i < Nb; i++) state[1][i] = temp[1][(i+1)%Nb];
	for (int i=0; i < Nb; i++) state[2][i] = temp[2][(i+2)%Nb];
	for (int i=0; i < Nb; i++) state[3][i] = temp[3][(i+3)%Nb];
}

void BettyCryptModules::AES_128::mixColumns(){
	BYTE a0, a1, a2, a3;
	for (int i = 0; i < Nb; i++){
		a0 = state[0][i];
		a1 = state[1][i];
		a2 = state[2][i];
		a3 = state[3][i];

		state[0][i] = xmult(a0)^a1^xmult(a1)^a2^a3;
		state[1][i] = a0^xmult(a1)^a2^xmult(a2)^a3;
		state[2][i] = a0^a1^xmult(a2)^a3^xmult(a3);
		state[3][i] = a0^xmult(a0)^a1^a2^xmult(a3);
	}
}

void BettyCryptModules::AES_128::invSubBytes(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) state[i][j] = InvSBox[state[i][j]];
}

void BettyCryptModules::AES_128::invShiftRows(){
	BYTE temp[4][Nb];
	for (int i = 0; i < 4; i++)
		for (short int j = 0; j < Nb; j++) temp[i][j] = state[i][j];

	for (int i=0; i < Nb; i++) state[1][i] = temp[1][(i+3)%Nb];
	for (int i=0; i < Nb; i++) state[2][i] = temp[2][(i+2)%Nb];
	for (int i=0; i < Nb; i++) state[3][i] = temp[3][(i+1)%Nb];
}

void BettyCryptModules::AES_128::invMixColumns(){
	BYTE a0, a1, a2, a3;
	for (int i = 0; i < Nb; i++){
		a0 = state[0][i];
		a1 = state[1][i];
		a2 = state[2][i];
		a3 = state[3][i];

		state[0][i] = Multiply(a0, 0x0e) ^ Multiply(a1, 0x0b) ^ Multiply(a2, 0x0d) ^ Multiply(a3, 0x09);
		state[1][i] = Multiply(a0, 0x09) ^ Multiply(a1, 0x0e) ^ Multiply(a2, 0x0b) ^ Multiply(a3, 0x0d);
		state[2][i] = Multiply(a0, 0x0d) ^ Multiply(a1, 0x09) ^ Multiply(a2, 0x0e) ^ Multiply(a3, 0x0b);
		state[3][i] = Multiply(a0, 0x0b) ^ Multiply(a1, 0x0d) ^ Multiply(a2, 0x09) ^ Multiply(a3, 0x0e);
	}
}

void BettyCryptModules::AES_128::keyExpansion(BYTE key[4*Nk], const short int &Nk){
	BYTE temp[4], b;

	for (short int i = 0; i < Nk; i++){
		RoundKey[i*4]	= key[i*4];
		RoundKey[i*4+1]	= key[i*4+1];
		RoundKey[i*4+2]	= key[i*4+2];
		RoundKey[i*4+3]	= key[i*4+3];
	}

	for (short int i = Nk; i < Nb*(Nr+1); i++){
		for (short int j = 0; j < 4; j++) temp[j] = RoundKey[(i-1)*4 + j];

		if (i%Nk == 0){
			//SubWord(RotWord())
			b		= temp[0];
			temp[0]	= SBox[temp[1]]^Rcon[i/Nk];
			temp[1]	= SBox[temp[2]];
			temp[2]	= SBox[temp[3]];
			temp[3]	= SBox[b];
		}
		else if (Nk > 6 && i%Nk == 4){
			temp[0]	= SBox[temp[0]];
			temp[1]	= SBox[temp[1]];
			temp[2]	= SBox[temp[2]];
			temp[3]	= SBox[temp[3]];
		}
		RoundKey[i*4]	= RoundKey[(i-Nk)*4]^temp[0];
		RoundKey[i*4+1]	= RoundKey[(i-Nk)*4+1]^temp[1];
		RoundKey[i*4+2]	= RoundKey[(i-Nk)*4+2]^temp[2];
		RoundKey[i*4+3]	= RoundKey[(i-Nk)*4+3]^temp[3];
	}
}

void BettyCryptModules::AES_128::cipher(BYTE in[4*Nb], BYTE out[4*Nb]){
	for (int i= 0; i < 4; i++)
		for (int j = 0; j < Nb; j++) state[j][i] = in[i*4+j];

	addRoundKey(0);
	for (int round = 1; round < Nr; round++){
		subBytes();
		shiftRows();
		mixColumns();
		addRoundKey(round);
	}

	subBytes();
	shiftRows();
	addRoundKey(Nr);

	for (int i= 0; i < 4; i++)
		for (int j = 0; j < Nb; j++) out[i*4+j] = state[j][i];
}

void BettyCryptModules::AES_128::invCipher(BYTE in[4*Nb], BYTE out[4*Nb]){
	for (int i= 0; i < 4; i++)
		for (int j = 0; j < Nb; j++) state[j][i] = in[i*4+j];

	addRoundKey(Nr);
	for (int round = Nr-1; round > 0; round--){
		invShiftRows();
		invSubBytes();
		addRoundKey(round);
		invMixColumns();
	}

	invShiftRows();
	invSubBytes();	
	addRoundKey(0);

	for (int i= 0; i < 4; i++)
		for (int j = 0; j < Nb; j++) out[i*4+j] = state[j][i];
}

bool BettyCryptModules::AES_128::decrypt(const char *oldPath, const char *newPath, const char *pass, const HWND hParent){
	unsigned short int iPercent = 0;
	unsigned long long int iCharCounter = 0;
	unsigned long long int iFileSize = fileSize(oldPath);
	short int iPadding = 0;
	BYTE BKey[BlockSize], BIn[BlockSize], BOut[BlockSize];
	char chIn[BlockSize*2];
	int iCount = 0;

	for (int i = 0; i < BlockSize; i++) BKey[i] = 0;
	for (int i = 0; i < strlen(pass); i++) BKey[i] = BYTE (pass[i]);
	keyExpansion(BKey, Nk);

	readFile.open(oldPath,std::ios::binary);
	if (strcmp(readCryptVersion(oldPath).c_str(),"20141229") >= 0){
		readFile.seekg(10);
		iPadding = readPadding(oldPath)%16;
	}
	else readFile.seekg(8);
	writeFile.open(newPath,std::ios::binary);

	readFile.get(chIn[0]);

	while(!readFile.eof()){
		for (int i = 1; i < BlockSize*2; i++){
			if (!readFile.eof()) readFile.get(chIn[i]);
			else{
				chIn[i-1] = 0;
				chIn[i] = 0;
			};
		}

		for (int i = 0; i < BlockSize; i++) BIn[i] = BYTE (HexToInt(chIn[i*2],chIn[i*2+1]));
		
		invCipher(BIn,BOut);

		iCharCounter = readFile.tellg();

		if (iFileSize > iCharCounter)
			for (int i = 0; i < BlockSize; i++) writeFile << char (BOut[i]);
		else
			for (int i = 0; i < BlockSize-iPadding; i++) writeFile << char (BOut[i]);

		if (hParent != 0 && iPercent != (100*iCharCounter)/iFileSize){
			iPercent = (100*iCharCounter)/iFileSize;
			SendMessage(hParent,PBM_SETPOS,iPercent,0);
		};
		readFile.get(chIn[0]);
	};

	writeFile.close();
	readFile.close();

	return true;
}

bool BettyCryptModules::AES_128::encrypt(const char *oldPath, const char *newPath, const char *pass, const HWND hParent){
	unsigned short int iPercent = 0;
	unsigned long long int iCharCounter = 0;
	unsigned long long int iFileSize = fileSize(oldPath);
	BYTE BKey[BlockSize], BIn[BlockSize], BOut[BlockSize];
	char chIn[BlockSize];

	for (int i = 0; i < BlockSize; i++) BKey[i] = 0;
	for (int i = 0; i < strlen(pass); i++) BKey[i] = BYTE (pass[i]);
	keyExpansion(BKey, Nk);

	readFile.open(oldPath,std::ios::binary);
	writeFile.open(newPath,std::ios::binary);
	writeFile << "20141229";//VER_DATE;
	writeFile << intToHex(16 - (iFileSize%16)).c_str();

	readFile.get(chIn[0]);

	while(!readFile.eof()){
		for (int i = 1; i < BlockSize; i++){
			if (!readFile.eof()) readFile.get(chIn[i]);
			else{
				chIn[i-1] = 0;
				chIn[i] = 0;
			};
		}

		for (int i = 0; i < BlockSize; i++) BIn[i] = BYTE (chIn[i]);

		cipher(BIn, BOut);

		for (int i = 0; i < BlockSize; i++) writeFile << std::hex << std::setfill('0') << std::setw(2) << int (BOut[i]);

		iCharCounter = readFile.tellg();
		if (hParent != 0 && iPercent != (100*iCharCounter)/iFileSize){
			iPercent = (100*iCharCounter)/iFileSize;
			SendMessage(hParent,PBM_SETPOS,iPercent,0);
		};
		readFile.get(chIn[0]);
	};

	writeFile.close();
	readFile.close();

	return true;
}