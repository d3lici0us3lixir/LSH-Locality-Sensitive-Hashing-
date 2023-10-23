#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include "ARIA.h"
#include "BLOWFISH.h"
#include "CAMELLIA.h"
#include "GIFT.h"
#include "hash.h"
#include "LEA.h"
#include "PRESENT.h"
#include "SEED.h"
#include "Shingle.h"
#include "LSH.h"
using namespace std;


int main() {
	uint8_t Plain[16] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff };
	uint32_t Plain2[2] = { 0x0011223344556677, 0x8899aabbccddeeff };
	uint32_t Plaintext4[4] = { 0x00112233, 0x44556677,0x8899aabb, 0xccddeeff };
	uint8_t Plain10[10] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99 };
	uint8_t Key[16] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f };
	uint32_t Key4[4] = { 0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f };
	uint8_t Key8[8] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07 };
	uint8_t Key10[10] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09 };
	uint8_t Cipher[16] = { 0, };

	int shingleing_size = 5;
	const int number_of_input = 6;
	vector<string> LSH_input[number_of_input];
	int num_permutation = 100;
	int num_bands = 10;
	int band_size = num_permutation / num_bands;
	const int test_size = 100;
	string ROUND_CT;
	


	ARIA aria(Plain, Cipher, Key);
	BLOWFISH blowfish(Plain2, Key8, 8);
	CAMELLIA camellia(Plain, Key);
	GIFT gift(Plain, Key);
	LEA lea(Plain, Key);
	PRESENT present(Plain10, Key10);
	SEED seed(Plaintext4, Key4);


	/*
	aria:uint8 12 uint8
lea:uint8 24 uint8
seed:uint32 16 uint32(uint8)
blowfish: uint32_t 2 16���� uint32_t 2
 ī�� 8_t 16
���� 8_t 16
���� 8_t 8
*/


/*
 //ARIA
	vector<string> unique_test[12];
	for (int i = 0; i < 12; i++) {
		ROUND_CT = aria.ARIA_EnCrypt(i);
		cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
		unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
		sort(unique_test[i].begin(), unique_test[i].end());
		unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
	}


	HashFunction hash_function(num_permutation);
	vector<vector<string>> minHashSignatures;
	vector<string> tmp;
	for (int i = 0; i < 10; i++) {
		tmp = hash_function.ComputeSignature(unique_test[i]);
		minHashSignatures.push_back(tmp);

	}
	bucket_hash(minHashSignatures, num_bands, band_size);
*/

/* //blowfish
	vector<string> unique_test[16];
	for (int i = 0; i < 16; i++) {
		ROUND_CT = blowfish.ROUND_Blowfish_Enc(i);
		cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
		unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
		sort(unique_test[i].begin(), unique_test[i].end());
		unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
	}


	HashFunction hash_function(num_permutation);
	vector<vector<string>> minHashSignatures;
	vector<string> tmp;
	for (int i = 0; i < 10; i++) {
		tmp = hash_function.ComputeSignature(unique_test[i]);
		minHashSignatures.push_back(tmp);

	}
	bucket_hash(minHashSignatures, num_bands, band_size);
	*/

/*
	//seed
	vector<string> unique_test[16];
	for (int i = 0; i < 16; i++) {
		ROUND_CT = seed.SEED_Enc(i);
		cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
		unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
		sort(unique_test[i].begin(), unique_test[i].end());
		unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
	}


	HashFunction hash_function(num_permutation);
	vector<vector<string>> minHashSignatures;
	vector<string> tmp;
	for (int i = 0; i < 10; i++) {
		tmp = hash_function.ComputeSignature(unique_test[i]);
		minHashSignatures.push_back(tmp);

	}
	bucket_hash(minHashSignatures, num_bands, band_size);
	*/

/*
//LEA
	vector<string> unique_test[24];
	for (int i = 0; i < 24; i++) {
		ROUND_CT = lea.LEA_Round_Encrypt(i);
		cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
		unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
		sort(unique_test[i].begin(), unique_test[i].end());
		unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
	}


	HashFunction hash_function(num_permutation);
	vector<vector<string>> minHashSignatures;
	vector<string> tmp;
	for (int i = 0; i < 10; i++) {
		tmp = hash_function.ComputeSignature(unique_test[i]);
		minHashSignatures.push_back(tmp);

	}
	bucket_hash(minHashSignatures, num_bands, band_size);
*/	

/*
//camellia
vector<string> unique_test[16];
for (int i = 0; i < 16; i++) {
	ROUND_CT = camellia.camelia_encrypt(i);
	cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
	unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
	sort(unique_test[i].begin(), unique_test[i].end());
	unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
}


HashFunction hash_function(num_permutation);
vector<vector<string>> minHashSignatures;
vector<string> tmp;
for (int i = 0; i < 10; i++) {
	tmp = hash_function.ComputeSignature(unique_test[i]);
	minHashSignatures.push_back(tmp);

}
bucket_hash(minHashSignatures, num_bands, band_size);
*/

/*
//gift
vector<string> unique_test[16];
for (int i = 0; i < 16; i++) {
	ROUND_CT = gift.giftb128_8(i);
	cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
	unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
	sort(unique_test[i].begin(), unique_test[i].end());
	unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
}


HashFunction hash_function(num_permutation);
vector<vector<string>> minHashSignatures;
vector<string> tmp;
for (int i = 0; i < 10; i++) {
	tmp = hash_function.ComputeSignature(unique_test[i]);
	minHashSignatures.push_back(tmp);

}
bucket_hash(minHashSignatures, num_bands, band_size);
*/

/*
//present
vector<string> unique_test[16];
for (int i = 0; i < 16; i++) {
	ROUND_CT = present.PRESENT_ENC(i);
	cout << "ROUNT "<<i<<": " << ROUND_CT << endl;
	unique_test[i] = string_shingle(ROUND_CT, shingleing_size);
	sort(unique_test[i].begin(), unique_test[i].end());
	unique_test[i].erase(unique(unique_test[i].begin(), unique_test[i].end()), unique_test[i].end());
}


HashFunction hash_function(num_permutation);
vector<vector<string>> minHashSignatures;
vector<string> tmp;
for (int i = 0; i < 10; i++) {
	tmp = hash_function.ComputeSignature(unique_test[i]);
	minHashSignatures.push_back(tmp);

}
bucket_hash(minHashSignatures, num_bands, band_size);
*/

	return 0;
}