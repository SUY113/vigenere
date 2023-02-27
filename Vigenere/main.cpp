#include <iostream>
#include <string>
#include <vector>

using namespace std;

string generateKey(string m, string k) {
	int x = m.size();
	for (int i = 0; ; i++) {
		if (x == i) {
			i = 0;
		}
		if (k.size() == m.size()) {
			break;
		}
		k.push_back(k[i]);
	}
	return k;
}

string vigenere_cipher_dec(string k, string e_m) {

	string dec_text;
	for (int i = 0; i < e_m.size(); i++) {
		char x = (e_m[i] - k[i] +26) % 26;
		x += 'a';

		dec_text.push_back(x);

	}
	return dec_text;
}

string vigenere_cipher_enc(string  k, string m) {
	//k = generateKey(m,k);
	string ciphterText;
	for (int i = 0; i < m.size(); i++) {
		char x = (m[i]-32 + k[i]-32) % 26;
		x += 'A'+32;
	
		ciphterText.push_back(x);

	}
	return ciphterText;
}

void main() {
	string m = "trannamtuan", k = "ayhus", e_m = "";
	string key = generateKey(m, k);
	cout << "originam message: " << m << endl;
	e_m = vigenere_cipher_enc(key, m);
	cout << "encrypted message: " << e_m << endl;
	m = vigenere_cipher_dec(key, e_m);
	cout << "decrypted message : " << m << endl;
}



