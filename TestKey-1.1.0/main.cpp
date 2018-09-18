#include <iostream>
#include <iomanip>

#include <key.h>
#include <pubkey.h>
#include <keystore.h>
#include <uint256.h>
#include <script/standard.h>
#include <script/script.h>

// ��ӡn��x�ַ� 
void print_line(int n, char x){
	std::cout<<std::endl<<std::setw(n);
    std::cout<<std::setfill(x)<<" "<<std::endl;
}

// ��ӡ����
template<typename T1>
void print_vector(const T1 pos, int size){
	unsigned char *begin = (unsigned char*)&pos[0];
	for(int ii = 0; ii < size; ii++){
		std::cout<<std::setw(2);
		std::cout<<std::setfill('0')<<std::hex<<(int)(*(begin + ii));
	}
	print_line(20, '-');
} 

/**
 * ������Կ��
 * ˽Կ��9a9a6539856be209b8ea2adbd155c0919646d108515b60b7b13d6a79f1ae5174
 * ��Կ��0340a609475afa1f9a784cad0db5d5ba7dbaab2147a5d7b9bbde4d1334a0e40a5e
 */ 
std::vector<unsigned char> TestPriKey = {
										0x9a, 0x9a, 0x65, 0x39, 0x85, 0x6b, 0xe2, 0x09,
										0xb8, 0xea, 0x2a, 0xdb, 0xd1, 0x55, 0xc0, 0x91,
										0x96, 0x46, 0xd1, 0x08, 0x51, 0x5b, 0x60, 0xb7,
										0xb1, 0x3d, 0x6a, 0x79, 0xf1, 0xae, 0x51, 0x74
										};
std::vector<unsigned char> TestPubKey = {0x03, 
										0x40, 0xa6, 0x09, 0x47, 0x5a, 0xfa, 0x1f, 0x9a,
										0x78, 0x4c, 0xad, 0x0d, 0xb5, 0xd5, 0xba, 0x7d, 
										0xba, 0xab, 0x21, 0x47, 0xa5, 0xd7, 0xb9, 0xbb, 
										0xde, 0x4d, 0x13, 0x34, 0xa0, 0xe4, 0x0a, 0x5e
										};
/**
 * Alice:
 * PriKey: 6bce49ff84094382d822178de357a435f85e8ad8fdfa39bd58aa2e5192267198
 * PubKey: 03e3bd2f408e4415aa57c747f6550937823a8605706c358facdc6325b4a99f2161
 */
std::vector<unsigned char> TestPriKeyA = {
										0x6b, 0xce, 0x49, 0xff, 0x84, 0x09, 0x43, 0x82, 
										0xd8, 0x22, 0x17, 0x8d, 0xe3, 0x57, 0xa4, 0x35, 
										0xf8, 0x5e, 0x8a, 0xd8, 0xfd, 0xfa, 0x39, 0xbd, 
										0x58, 0xaa, 0x2e, 0x51, 0x92, 0x26, 0x71, 0x98
										};
std::vector<unsigned char> TestPubKeyA = {0x03, 
										0xe3, 0xbd, 0x2f, 0x40, 0x8e, 0x44, 0x15, 0xaa, 
										0x57, 0xc7, 0x47, 0xf6, 0x55, 0x09, 0x37, 0x82, 
										0x3a, 0x86, 0x05, 0x70, 0x6c, 0x35, 0x8f, 0xac, 
										0xdc, 0x63, 0x25, 0xb4, 0xa9, 0x9f, 0x21, 0x61
										};
/**
 * Bob:
 * PriKey: 3e46c724c8e9728379a9cab2ec46030563f06d7e0ace2b734b5861b8f64b6f2f
 * PubKey: 020e80933a750e84b4c35c10bc797ca34d1c885e4e65531a7499170a1c78ffdd97
 */	
std::vector<unsigned char> TestPriKeyB = {
										0x3e, 0x46, 0xc7, 0x24, 0xc8, 0xe9, 0x72, 0x83, 
										0x79, 0xa9, 0xca, 0xb2, 0xec, 0x46, 0x03, 0x05, 
										0x63, 0xf0, 0x6d, 0x7e, 0x0a, 0xce, 0x2b, 0x73, 
										0x4b, 0x58, 0x61, 0xb8, 0xf6, 0x4b, 0x6f, 0x2f
										};								
std::vector<unsigned char> TestPubKeyB = {0x02, 
										0x0e, 0x80, 0x93, 0x3a, 0x75, 0x0e, 0x84, 0xb4, 
										0xc3, 0x5c, 0x10, 0xbc, 0x79, 0x7c, 0xa3, 0x4d, 
										0x1c, 0x88, 0x5e, 0x4e, 0x65, 0x53, 0x1a, 0x74, 
										0x99, 0x17, 0x0a, 0x1c, 0x78, 0xff, 0xdd, 0x97
										};
/**
 * Martin:
 * PriKey: bfe5647b87c61058969bbe599879c49372fa0d6e2bfc71125960e3c1de5fbc0b
 * PubKey: 039155f9024807d126be4df4d09273c5fece4767e89b4527c68b48414a2877eddd
 */	
std::vector<unsigned char> TestPriKeyM = {
										0xbf, 0xe5, 0x64, 0x7b, 0x87, 0xc6, 0x10, 0x58, 
										0x96, 0x9b, 0xbe, 0x59, 0x98, 0x79, 0xc4, 0x93, 
										0x72, 0xfa, 0x0d, 0x6e, 0x2b, 0xfc, 0x71, 0x12, 
										0x59, 0x60, 0xe3, 0xc1, 0xde, 0x5f, 0xbc, 0x0b
										};								
std::vector<unsigned char> TestPubKeyM = {0x03, 
										0x91, 0x55, 0xf9, 0x02, 0x48, 0x07, 0xd1, 0x26, 
										0xbe, 0x4d, 0xf4, 0xd0, 0x92, 0x73, 0xc5, 0xfe, 
										0xce, 0x47, 0x67, 0xe8, 0x9b, 0x45, 0x27, 0xc6, 
										0x8b, 0x48, 0x41, 0x4a, 0x28, 0x77, 0xed, 0xdd
										};																				

// ��˽Կ���Գ��� 
int main_keytest() {

	CPrivKey LoadPriKey;	 
	CKey priKey;
	//priKey.MakeNewKey(true);
	ECCVerifyHandle eccVerifyHandle ;
	ECC_Start();
	// ����˽Կ���� 
	priKey.Set(TestPriKey.begin(), TestPriKey.end(), true);	
	LoadPriKey = priKey.GetPrivKey();
	std::cout<<std::setw(2)<<std::hex;
    std::cout<<std::setfill('0');
	// ��ӡ˽Կ 
	std::cout<<"Private key [0x"<<priKey.size()<<"]:";
	for(int ii = 0; ii < priKey.size(); ii++)
    {
        std::cout<<std::setw(2)<<std::hex;
        std::cout<<(int)(*(priKey.begin() + ii));
    }
    print_line(20, '-');
	// ��ȡ��Կ 
	CPubKey pubKey(TestPubKey);	
	// ��ӡ��Կ 
	std::cout<<"Public key  [0x"<<pubKey.size()<<"]:";
	for(int ii = 0; ii < pubKey.size(); ii++)
    {
        std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<(int)(*(pubKey.begin() + ii));
    }
	print_line(20, '-');
	// ��⹫˽Կ�Ƿ�ƥ�� 
	if(priKey.VerifyPubKey(pubKey)){
		std::cout<<"***** Private Key vs. Public Key Match. *****";
	}
	print_line(20, '-');
	// ��ȡ��Կ Hash-160
	CKeyID hash160 = pubKey.GetID(); 
	// ��ӡ��Կ Hash-160
	std::cout<<"Hash-160    [0x"<<hash160.size()<<"]:";
	for(int ii = 0; ii < hash160.size(); ii++)
    {
        std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<(int)(*(hash160.begin() + ii));
    }
	print_line(20, '-');
	// ��ȡ��Կ��ϣֵ 
	uint256 hash = pubKey.GetHash();
	// ��ӡ��Կ��ϣֵ  
	std::cout<<"Hash        [0x"<<hash.size()<<"]:";
	for(int ii = 0; ii < hash.size(); ii++)
    {
        std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<(int)(*(hash.begin() + ii));
    }
	print_line(20, '-');
	std::vector<unsigned char> vchSig; 
	priKey.Sign(hash, vchSig);
	// ��ӡǩ��
	std::cout<<"Sign        [0x"<<vchSig.size()<<"]:"; 
	for(int ii = 0; ii < vchSig.size(); ii++){
		std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<(int)(*(vchSig.begin() + ii));
	}
	print_line(20, '-');
	
	// У��ǩ�� 
	if(pubKey.CheckLowS(vchSig) && pubKey.Verify(hash, vchSig)){
		std::cout<<"**** Public Key Verify Sign Ok. ****";
	}
	print_line(20, '-');
	// ��ȡ��ѹ����Կ 
	pubKey.Decompress();
	// ��ӡ��Կ 
	std::cout<<"**** Public key Decompressed ****"<<std::endl;
	std::cout<<"Public key  [0x"<<pubKey.size()<<"]:";
	for(int ii = 0; ii < pubKey.size(); ii++)
    {
        std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<(int)(*(pubKey.begin() + ii));
    }
	print_line(20, '-');
	
	priKey.SignCompact(hash, vchSig);
	pubKey.RecoverCompact(hash, vchSig);
	// ��ӡ��Կ 
	std::cout<<"**** Public key Recovered From SignCompact ****"<<std::endl;
	std::cout<<"Public key  [0x"<<pubKey.size()<<"]:";
	for(int ii = 0; ii < pubKey.size(); ii++)
    {
        std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<(int)(*(pubKey.begin() + ii));
    }
	print_line(20, '-');
	if(priKey.Load(LoadPriKey, pubKey, true)){
		std::cout<<"**** Load private key ok. ****";
	}
	print_line(20, '-');
	// ��ȡ��˽Կ 
	CKey keyChild;
	CPubKey pubkeyChild;
	ChainCode ccChild;
	unsigned int nChild = 1;
	ChainCode cc = hash;
	while(nChild <= 5){
		std::cout<<"Child key: [0x";
		std::cout<<std::setw(2);
        std::cout<<std::setfill('0')<<std::hex<<nChild<<"]";
        print_line(20, '-');
		if(priKey.Derive(keyChild, ccChild, nChild, cc)){
			// ��ӡ˽Կ 
			std::cout<<"Private key  [0x"<<pubKey.size()<<"]:";
			for(int ii = 0; ii < keyChild.size(); ii++)
		    {
		        std::cout<<std::setw(2);
		        std::cout<<std::setfill('0')<<std::hex<<(int)(*(keyChild.begin() + ii));
		    }
		    std::cout<<std::endl;
		}
		if(pubKey.Derive(pubkeyChild, ccChild, nChild, cc)){
			// ��ӡ��Կ 
			std::cout<<"Public key   [0x"<<pubkeyChild.size()<<"]:";
			for(int ii = 0; ii < pubkeyChild.size(); ii++)
		    {
		        std::cout<<std::setw(2);
		        std::cout<<std::setfill('0')<<std::hex<<(int)(*(pubkeyChild.begin() + ii));
		    }
		}
		// ��֤��Կ˽Կ�Ƿ�ƥ�� 
		if(!priKey.VerifyPubKey(pubKey)){
			break;
		}
		cc = ccChild;
		nChild++;
		print_line(20, '-');
	}	
	ECC_Stop();
	return 0;
}
/* ��˽Կ���Գ������ */ 

// �ű����ɲ��Գ���
int main_scripttest(){	
	// ���ù�Կ 
	CPubKey pubKey(TestPubKey);	
	/** �ӹ�Կ����һ��P2PK�ű� */
	CScript P2PK = GetScriptForRawPubKey(pubKey);
	std::cout<<"**** P2PK:"<<std::endl;
	for(int ii = 0; ii < P2PK.size(); ii++){
		std::cout<<std::setw(2);
		std::cout<<std::setfill('0')<<std::hex<<(int)(*(P2PK.begin() + ii));
	}
	print_line(20, '-'); 
	/** ����һ��P2WPKH�ű� */
	CScript P2WPKH = GetScriptForWitness(P2PK);
	std::cout<<"**** P2WPKH:"<<std::endl;	
	for(int ii = 0; ii < P2WPKH.size(); ii++){
		std::cout<<std::setw(2);
		std::cout<<std::setfill('0')<<std::hex<<(int)(*(P2WPKH.begin() + ii));
	}
	print_line(20, '-');
	/* ����һ���ű���Կ */
	CScript scriptPubKey = GetScriptForDestination(P2WPKH);
	std::cout<<"**** Bitcoin scriptPubKey:"<<std::endl;
	if(!scriptPubKey.IsPayToScriptHash()){
		std::cout<<" Error :";
	}
	for(int ii = 0; ii < scriptPubKey.size(); ii++){
		std::cout<<std::setw(2);
		std::cout<<std::setfill('0')<<std::hex<<(int)(*(scriptPubKey.begin() + ii));
	}
	print_line(20, '-'); 
	/** ����һ����ǩ���ű� */
	std::vector<CPubKey> keys ={CPubKey(TestPubKeyA), CPubKey(TestPubKeyB), CPubKey(TestPubKeyM)};
	CScript mnScript = GetScriptForMultisig(2, keys);
	std::cout<<"**** Multisig script:"<<std::endl;
	for(int ii = 0; ii < mnScript.size(); ii++){
		std::cout<<std::setw(2);
		std::cout<<std::setfill('0')<<std::hex<<(int)(*(mnScript.begin() + ii));
	}
	print_line(20, '-');
	/* �Ӷ�ǩ���ű����ɽű���Կ */
	scriptPubKey = GetScriptForDestination(mnScript);
	std::cout<<"**** Bitcoin scriptPubKey:"<<std::endl;
	for(int ii = 0; ii < scriptPubKey.size(); ii++){
		std::cout<<std::setw(2);
		std::cout<<std::setfill('0')<<std::hex<<(int)(*(scriptPubKey.begin() + ii));
	}
	print_line(20, '-');
	/* ������ǩ���ű���Ϣ */
	txnouttype typeRet;							// �ű����� 
	std::vector<CTxDestination> addressRet;		// �ű���ַ��Ϣ 
	int nRequiredRet;							// ��Ҫǩ������ 
	if(ExtractDestinations(mnScript, typeRet, addressRet, nRequiredRet)){
		std::cout<<"**** Type:"<<GetTxnOutputType(typeRet)<<std::endl;
		std::cout<<"**** Required: "<<nRequiredRet<<" / "<<addressRet.size();	
		print_line(20, '-');	
		for(int ii = 0; ii < addressRet.size(); ii++){
			std::cout<<"**** Address script: "<<ii<<": "<<std::endl;
			if(!IsValidDestination(addressRet[ii])){
				break;
			}
			CScript script = GetScriptForDestination(addressRet[ii]);
			P2WPKH = GetScriptForWitness(script);
			for(int ij = 0; ij < P2WPKH.size(); ij++){
				std::cout<<std::setw(2);
				std::cout<<std::setfill('0')<<std::hex<<(int)(*(P2WPKH.begin() + ij));
			}
			print_line(20, '-');
		}
	}
	return 0;
} 
/** �ű����ɲ��Գ������ */ 

// ��Կ�洢���Գ���
int main_keystoretest(){
	ECCVerifyHandle eccVerifyHandle ;
	ECC_Start();
	// ����һ����Կ�洢 
	CBasicKeyStore keystore; 
	CKey priKey;
	CPubKey pubKey;
	// ���һ����Կ��
	priKey.Set(TestPriKey.begin(), TestPriKey.end(), true);
	pubKey.Set(TestPubKey.begin(), TestPubKey.end());
	keystore.AddKeyPubKey(priKey, pubKey);
	priKey.Set(TestPriKeyA.begin(), TestPriKeyA.end(), true);
	pubKey.Set(TestPubKeyA.begin(), TestPubKeyA.end());
	keystore.AddKeyPubKey(priKey, pubKey);
	priKey.Set(TestPriKeyB.begin(), TestPriKeyB.end(), true);
	pubKey.Set(TestPubKeyB.begin(), TestPubKeyB.end());
	keystore.AddKeyPubKey(priKey, pubKey);
	// ��ȡ������Կ�� 
	CKey priKey1;
	CPubKey pubKey1;
	int count = 0;
	std::set<CKeyID> keys = keystore.GetKeys(); 
	for(std::set<CKeyID>::iterator it = keys.begin(); it != keys.end(); it++){
		std::cout<<"**** Key "<<count++<<std::endl;
		if(keystore.GetKey(*it, priKey1)){
			std::cout<<"Private key:";
			print_vector(priKey1.begin(), priKey1.size());
		}
		if(keystore.GetPubKey(*it, pubKey1)){
			std::cout<<"Public key:";
			print_vector(pubKey1, pubKey.size());
		}
	}

	pubKey.Set(TestPubKey.begin(), TestPubKey.end());
	CKeyID address = pubKey.GetID(); 
	// ��ӽű�
	CScript script = GetScriptForDestination(WitnessV0KeyHash(address)); 
	CScriptID hash(script);
	// ���ݽű���ȡkey 
	address = GetKeyForDestination(keystore, script);
	std::cout<<"**** Address: ";
	print_vector(address.begin(), address.size());
	// �����Կ��ʱ����Ӷ�Ӧ�ýű������Դ洢���Ѵ��ڽű� 
	if(keystore.HaveCScript(hash)){
		std::cout<<"**** Have script: ";
		print_vector(hash.begin(), hash.size());
	}
	// ͨ���ű���ϣֵ��ȡ�ű�	
	if(keystore.GetCScript(hash, script)){
		std::cout<<"**** Get script: ";
		print_vector(script, script.size());
	} 
	
	// ֻ���ű�
	if(!keystore.HaveWatchOnly(script)){
		keystore.AddWatchOnly(script);
		if(keystore.HaveWatchOnly(script)){
			std::cout<<"**** Watch:";
			print_vector(script, script.size());
		}		
	}
	
	ECC_Stop();
	return 0;
} 
/** ��Կ�洢���Գ������ */ 
int main(int argc, char** argv){
	/** ��˽Կ���Գ��� */
	/* 
	print_line(100, '='); 
	std::cout<<"Private Key & Public Key";
	print_line(100, '=');
	main_keytest();
	print_line(100, '=');
	*/
	/** �ű����ɲ��Գ��� */ 
	/*
	print_line(100, '=');
	std::cout<<"Script";
	print_line(100, '=');
	main_scripttest();
	print_line(100, '=');
	*/
	/** ��Կ�洢 */ 
	print_line(100, '=');
	std::cout<<"Keystore";
	print_line(100, '=');
	main_keystoretest();
	print_line(100, '=');
	return 0;
}
