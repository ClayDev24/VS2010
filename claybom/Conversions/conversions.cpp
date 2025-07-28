// DataRepresentation.pdf (pág 2)
#include <iostream>
#include <sstream>
#include "conversions.h"
#include "utils.h" // Power(), Tokenizer()
#include "mat.h"
using namespace std;

const int MAX = 16;

char *binTable[16] = {
		"0000",	// $0
		"0001",	// $1
		"0010",	// $2
		"0011",	// $3
		"0100",	// $4
		"0101",	// $5
		"0110",	// $6
		"0111",	// $7
		"1000",	// $8
		"1001",	// $9
		"1010",	// $A
		"1011",	// $B
		"1100",	// $C
		"1101",	// $D
		"1110",	// $E
		"1111"	// 4F
};

// Binary to Decimal:
// Simplier (copy straightforward):
unsigned long clb::Conversions::bin2dec(char *bin) {	
	unsigned long out = 0;
	while(*bin) {
		out = out << 1;
		out = (*bin++)-48 | out;
	}
	return  out;
};

// Using power:
unsigned long clb::Conversions::bin2dec2(char *bin) {	
	int cont = 0;
	unsigned long out = 0;
	while(*bin++)
		cont++;
	--bin;
	for(int i = 0; cont--; i++)
		if(*--bin == '1')
			out += static_cast<unsigned long>(math::_power(2, i));// | out;
	return out;
};

// Convert Decimal to Binary Method1 => 
// DataRepresentation.pdf (pág 2)
string clb::Conversions::dec2bin(int dec) {	
	static char ch[128];
	int power = 0;
	int expon = 0;
	memset(ch, '0', 128); // resetin' memory
	while(power <= dec)
		power = static_cast<int>(math::_power(2, ++expon));
	ch[expon] = 0; // zero terminatin' string.
	for(int i = 0; dec >= 0 && expon-- > 0; i++)		
		if((power = static_cast<int>(math::_power(2, expon))) <= dec) {
			ch[i] = '1';
			dec -= power;
		}
	return ch;
}

//DataRepresentation.pdf (pág 2 e 3)
//Method 2 => "even/odd - divide by two" algorithm
char* clb::Conversions::dec2bin2(unsigned int dec) {	
	char		 ch[128];
	static char tmp[128];
	memset(ch, '0', 128); // zerin'out memo...
	// Special case: dec = 0;
	if(dec == 0)
		tmp[0] = '0';
	int i;
	for(i = 0; dec > 0; i++) {
		if(dec % 2 != 0) // even
			ch[i] = '1';
		dec /= 2; // => divide by
	}
	// reverse string order:
	i--;
	for(int i2 = 0; i >= 0; i2++)
		tmp[i2] = ch[i--];		
	return tmp;
};

char* clb::Conversions::dec2bin3(signed int dec) {	
	char *ch  = new char[128];
//	while(*dec++ != 0)
//		ch[i2] = tmp[i--];		
//	ch[i2++] = 0;

	return ch;
};

char *clb::Conversions::hex2bin(char *hex) {
	static char ch[128];
	int index = 0;
	while(int i = (int)*hex++)
		if(i >= 48 && i <= 57) // 0..9
			for(int a = 0; a < 4; a++)
				ch[index++] = (binTable[(i-48)])[a];
		else // A..F && a..f			
			for(int a = 0; a < 4; a++)
				ch[index++] = (binTable[(i|0x20)/*<=tolower*/-87])[a];
			ch[index] = '\0';
			return ch;
}

char* clb::Conversions::bin2hex(char *bin) {
	static char ch[128];
	int index = 0;
	utils::Tokenizer *token = new utils::Tokenizer(bin, " _%");
	for(int i = 0; i < token->get_size(); i++)
		for(int i2 = 0; i2 < 16; i2++)
			if(token->get_at(i) == binTable[i2])
				if(i2 < 10) // 0..9
					ch[index++] = i2+48;
				else // A..F
					ch[index++] = i2+55;
				ch[index] = '\0';
				delete token;
				return ch;
}
	
char* clb::Conversions::zero_extend(char *bin, int sz, char spacer) {	
	static char ch[128];
	int qnt   = 0; 
	int index = -1;
	
	char *tmp = bin;
	while(*tmp++)
		qnt++;
	
	int zero_pads = sz - qnt;
	// truncate the result: 
	if(zero_pads < 0) {
		bin += qnt - sz;
		zero_pads = 0;
	}

	while(zero_pads--)
		if(((index++ + 2)% 5) == 0 && spacer) {
			ch[index] = spacer;
			zero_pads++;
		} else
			ch[index] = '0';
	while(*bin)
		if(((index++ + 2)% 5) == 0 && spacer)
			ch[index] = spacer;
		else
			ch[index] = *bin++;
			
	return ch;
};

char* clb::Conversions::sign_extend(char *bin, int sz, char spacer) {	
	static char ch[128];
	int qnt   = 0; 
	int index = -1;
	char zr   = '0';
	char one  = '1';
	char pads = zr;
	
	char *tmp = bin;
	while(*tmp++)
		qnt++;
	
	int zero_pads = sz - qnt;
	// truncate the result: 
	if(zero_pads < 0) {
		bin += qnt - sz;
		zero_pads = 0;
	}

	// Testin' if number is negative:
	if(qnt % 8 == 0 && bin[0] == '1') // if multiple o'8 n the first is 1
		pads = one;

	while(zero_pads--)
		if(((index++ + 2)% 5) == 0 && spacer) {
			ch[index] = spacer;
			zero_pads++;
		} else
			ch[index] = pads;
	while(*bin)
		if(((index++ + 2)% 5) == 0 && spacer)
			ch[index] = spacer;
		else
			ch[index] = *bin++;
			
	return ch;
};

int clb::Conversions::str2int2(const char* _str) {
	int i;
	stringstream(_str) >> i;
	return i;
};

float clb::Conversions::str2float2(const char* _str) {
	float f;
	stringstream(_str) >> f;
	return f;
};
		
double clb::Conversions::str2double2(const char* _str) {
	double d;
	stringstream(_str) >> d;
	return d;
}

