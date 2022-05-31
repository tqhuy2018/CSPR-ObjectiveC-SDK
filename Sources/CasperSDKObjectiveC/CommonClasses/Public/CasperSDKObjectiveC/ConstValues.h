#ifndef ConstValues_h
#define ConstValues_h
//Casper RPC method
FOUNDATION_EXPORT NSString *const CASPER_ERROR_MESSAGE_NONE;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_GET_STATE_ROOT_HASH;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_INFO_GET_PEERS;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_INFO_GET_DEPLOY;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_INFO_GET_STATUS;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_CHAIN_GET_BLOCK_TRANSFERS;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_CHAIN_GET_BLOCK;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_CHAIN_GET_ERA_BY_SWITCH_BLOCK;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_STATE_GET_ITEM;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_STATE_GET_DICTIONARY_ITEM;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_STATE_GET_BALANCE;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_STATE_GET_AUCTION_INFO;
FOUNDATION_EXPORT NSString *const CASPER_RPC_METHOD_ACCOUNT_PUT_DEPLOY;

//CLType
FOUNDATION_EXPORT NSString *const CLTYPE_BOOL;
FOUNDATION_EXPORT NSString *const CLTYPE_I32;
FOUNDATION_EXPORT NSString *const CLTYPE_I64;
FOUNDATION_EXPORT NSString *const CLTYPE_U8;
FOUNDATION_EXPORT NSString *const CLTYPE_U32;
FOUNDATION_EXPORT NSString *const CLTYPE_U64;
FOUNDATION_EXPORT NSString *const CLTYPE_U128;
FOUNDATION_EXPORT NSString *const CLTYPE_U256;
FOUNDATION_EXPORT NSString *const CLTYPE_U512;
FOUNDATION_EXPORT NSString *const CLTYPE_UNIT;
FOUNDATION_EXPORT NSString *const CLTYPE_STRING;
FOUNDATION_EXPORT NSString *const CLTYPE_KEY;
FOUNDATION_EXPORT NSString *const CLTYPE_UREF;
FOUNDATION_EXPORT NSString *const CLTYPE_PUBLICKEY;
FOUNDATION_EXPORT NSString *const CLTYPE_OPTION;
FOUNDATION_EXPORT NSString *const CLTYPE_LIST;
FOUNDATION_EXPORT NSString *const CLTYPE_LIST_MAP_KEY;
FOUNDATION_EXPORT NSString *const CLTYPE_LIST_MAP_VALUE;
FOUNDATION_EXPORT NSString *const CLTYPE_BYTEARRAY;
FOUNDATION_EXPORT NSString *const CLTYPE_RESULT;
FOUNDATION_EXPORT NSString *const CLTYPE_MAP;
FOUNDATION_EXPORT NSString *const CLTYPE_TUPLE1;
FOUNDATION_EXPORT NSString *const CLTYPE_TUPLE2;
FOUNDATION_EXPORT NSString *const CLTYPE_TUPLE3;
FOUNDATION_EXPORT NSString *const CLTYPE_ANY;
FOUNDATION_EXPORT NSString *const CLTYPE_NULL_VALUE;
FOUNDATION_EXPORT NSString *const CLPARSED_NULL_VALUE;
FOUNDATION_EXPORT NSString *const CLPARSED_RESULT_OK;
FOUNDATION_EXPORT NSString *const CLPARSED_RESULT_ERR;

//ExecutableDeployItem

FOUNDATION_EXPORT NSString *const EDI_MODULEBYTES;
FOUNDATION_EXPORT NSString *const EDI_STORED_CONTRACT_BY_HASH;
FOUNDATION_EXPORT NSString *const EDI_STORED_CONTRACT_BY_NAME;
FOUNDATION_EXPORT NSString *const EDI_STORED_VERSIONED_CONTRACT_BY_HASH;
FOUNDATION_EXPORT NSString *const EDI_STORED_VERSIONED_CONTRACT_BY_NAME;
FOUNDATION_EXPORT NSString *const EDI_TRANSFER;

//Transform
FOUNDATION_EXPORT NSString *const TRANSFORM_IDENTITY;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_CLVALUE;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_ACCOUNT;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_CONTRACT_WASM;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_CONTRACT;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_CONTRACT_PACKAGE;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_DEPLOY_INFO;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_ERA_INFO;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_TRANSFER;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_BID;
FOUNDATION_EXPORT NSString *const TRANSFORM_WRITE_WITHDRAW;
FOUNDATION_EXPORT NSString *const TRANSFORM_ADD_INT32;
FOUNDATION_EXPORT NSString *const TRANSFORM_ADD_UINT64;
FOUNDATION_EXPORT NSString *const TRANSFORM_ADD_UINT128;
FOUNDATION_EXPORT NSString *const TRANSFORM_ADD_UINT256;
FOUNDATION_EXPORT NSString *const TRANSFORM_ADD_UINT512;
FOUNDATION_EXPORT NSString *const TRANSFORM_ADD_KEYS;
FOUNDATION_EXPORT NSString *const TRANSFORM_FAILURE;

//URL FOR TEST AND MAIN NET
FOUNDATION_EXPORT NSString *const URL_TEST_NET;
FOUNDATION_EXPORT NSString *const URL_MAIN_NET;

//PARSE FIXED PREFIX STRING, USED FOR BUILD DEPLOY JSON STRING FOR ACCOUNT_PUT_DEPLOY RPC CALL
FOUNDATION_EXPORT NSString *const PARSED_FIXED_STR;

//ERROR MESSAGE FOR CRYPTO
FOUNDATION_EXPORT NSString *const ERROR_STRING;

// PRC VALUES FOR GETTING RPC OBJECT
// PRC VALUE FOR NONE SET VALUE OBJECT
FOUNDATION_EXPORT NSString *const RPC_VALUE_NOT_SET;
// RPC VALUE FOR GETTING OBJECT ERROR
FOUNDATION_EXPORT NSString *const RPC_VALUE_ERROR_OBJECT;
// RPC VALUE FOR URL OR NETWORK ERROR
FOUNDATION_EXPORT NSString *const RPC_VALUE_ERROR_NETWORK;
// RPC VALUE FOR VALID VALUE OBJECT
FOUNDATION_EXPORT NSString *const RPC_VALID_RESULT;

//CRYPTO PATH
FOUNDATION_EXPORT NSString *const CRYPTO_PATH_SECP256K1;
FOUNDATION_EXPORT NSString *const CRYPTO_PATH_ED25519;
//CRYPTO PEM FILE
FOUNDATION_EXPORT NSString *const ED25519_PRIVATE_KEY_PEMFILE;
FOUNDATION_EXPORT NSString *const ED25519_PUBLIC_KEY_PEMFILE;
FOUNDATION_EXPORT NSString *const SECP256K1_PRIVATE_KEY_PEMFILE;
FOUNDATION_EXPORT NSString *const SECP256K1_PUBLIC_KEY_PEMFILE;
#endif
