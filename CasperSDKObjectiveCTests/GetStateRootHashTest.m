#import <XCTest/XCTest.h>
#import "BlockIdentifier.h"
#import "GetStateRootHash.h"
#import "CasperErrorMessage.h"
#import "ConstValues.h"
@interface GetStateRootHashTest : XCTestCase

@end

@implementation GetStateRootHashTest
-(void) getStateRootHashWithJsonParam:(NSString*) jsonString {
    XCTestExpectation * requestExpectation = [self expectationWithDescription:@"get state root hash"];
    NSString * casperURL =  @"https://node-clarity-testnet.make.services/rpc";
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableURLRequest *request = [NSMutableURLRequest new];
    request.HTTPMethod = @"POST";
    [request setURL:[NSURL URLWithString:casperURL]];
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [request setHTTPBody:jsonData];
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config delegate:nil delegateQueue:[NSOperationQueue mainQueue]];
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        [requestExpectation fulfill];
        NSDictionary *forJSONObject = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];
        CasperErrorMessage * cem = [[CasperErrorMessage alloc] init];
        [cem fromJsonToErrorObject:forJSONObject];
        if(cem.message == CASPER_ERROR_MESSAGE_NONE) {
            NSString * state_root_hash = [GetStateRootHash fromJsonToStateRootHash: forJSONObject];
            NSLog(@"State root hash:%@",state_root_hash);
        } else {
            NSLog(@"Error get state root hash with error message:%@ and error code:%@",cem.message,cem.code);
        }
    }];
    [task resume];
    [self waitForExpectationsWithTimeout:100 handler:^(NSError *error) {
           // [session closeWithCompletionHandler:nil];
        }];
}
- (void) testGetStateRootHash {
    //Test 1: get state root hash without sending parameter
    //expected result: latest block state root hash
    BlockIdentifier * bi = [[BlockIdentifier alloc] init];
    bi.blockType = USE_NONE;
    NSString * jsonString = [bi toJsonStringWithMethodName:@"chain_get_state_root_hash"];
    [self getStateRootHashWithJsonParam:jsonString];
    //Test 2:get state root hash based on block hash
    //expected result: state root hash of the block with given hash
    bi.blockType = USE_BLOCK_HASH;
    [bi assignBlockHashWithParam:@"d16cb633eea197fec519aee2cfe050fe9a3b7e390642ccae8366455cc91c822e"];
   // [bi assignBlockHashWithParam:@"00b1b35ee5d8bddfc70de6d8d769c49eec81511fee98102e1a6fea3b50524e9e"];
    NSString * jsonString2 = [bi toJsonStringWithMethodName:@"chain_get_state_root_hash"];
    [self getStateRootHashWithJsonParam:jsonString2];
    //Test 3: get state root hash based on block height
    //expected result: state root hash of the block with given height
    bi.blockType = USE_BLOCK_HEIGHT;
    [bi assignBlockHeigthtWithParam:12345];
    NSString * jsonString3 = [bi toJsonStringWithMethodName:@"chain_get_state_root_hash"];
    [self getStateRootHashWithJsonParam:jsonString3];
    //Negative test
    //Test 4: get state root hash based on non-existing block height (too big height)
    //expected result: error thrown with message: block not known, error code: -32001
    bi.blockType = USE_BLOCK_HEIGHT;
    [bi assignBlockHeigthtWithParam:123456789];
    NSString * jsonString4 = [bi toJsonStringWithMethodName:@"chain_get_state_root_hash"];
    [self getStateRootHashWithJsonParam:jsonString4];
    //Test 5: get state root hash based on non-existing block hash
    //expected result: error thrown with message: block not known, error code: -32001
    bi.blockType = USE_BLOCK_HASH;
    [bi assignBlockHashWithParam:@"ccccb633eea197fec519aee2cfe050fe9a3b7e390642ccae8366455cc91c822e"];
    NSString * jsonString5 = [bi toJsonStringWithMethodName:@"chain_get_state_root_hash"];
    [self getStateRootHashWithJsonParam:jsonString5];
}
@end
