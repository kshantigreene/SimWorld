#pragma once
#ifndef RSA
#define RSA
class RSAEncryption {
public:
	RSAEncryption();
	long encryptMsg(int);
	long decryptMsg(int);

private:
	long nn;
	long dd;
	long ee;
};

#endif