#ifndef DisabledVersion_h
#define DisabledVersion_h
/**Class built for storing DisabledVersion information
 */
@interface DisabledVersion:NSObject
@property UInt32 contract_version;
@property UInt32 protocol_version_major;
/**This function parse the Dictionary object (as part of the JSON object taken from server RPC method call) to DisabledVersion object
 */
+(DisabledVersion*) fromJsonDictToDisabledVersion:(NSDictionary*) fromDict;
-(void) logInfo;
@end

#endif
