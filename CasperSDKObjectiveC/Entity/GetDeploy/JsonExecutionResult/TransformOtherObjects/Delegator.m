#import <Foundation/Foundation.h>
#import "Delegator.h"
@implementation Delegator
+(Delegator*) fromJsonDictToDelegator:(NSDictionary *)fromDict {
    Delegator * ret = [[Delegator alloc] init];
    ret.bonding_purse = (NSString*) fromDict[@"bonding_purse"];
    NSLog(@"bonding_purse:%@",ret.bonding_purse);
    ret.staked_amount = [U512Class fromStrToClass:(NSString*)fromDict[@"staked_amount"]];
    NSLog(@"staked_amount:%@",ret.staked_amount.itsValue);
    ret.delegator_public_key = (NSString*) fromDict[@"delegator_public_key"];
    NSLog(@"delegator_public_key:%@",ret.delegator_public_key);
    ret.validator_public_key = (NSString*) fromDict[@"validator_public_key"];
    NSLog(@"validator_public_key:%@",ret.validator_public_key);
    if(!(fromDict[@"vesting_schedule"] == nil)) {
        NSObject * obj = fromDict[@"vesting_schedule"];
        if([obj isKindOfClass:[NSString class]]) {
            NSString * vs = (NSString *) fromDict[@"vesting_schedule"];
            if(vs==(id) [NSNull null] || [vs length]==0 || [vs isEqualToString:@""]) {
                ret.is_vesting_schedule_existed = false;
            }
        } else {
            NSLog(@"VestingSchedule json:%@",fromDict[@"vesting_schedule"]);
            if(obj==(id) [NSNull null]) {
                ret.is_vesting_schedule_existed = false;
            } else {
                ret.vesting_schedule = [[VestingSchedule alloc] init];
                ret.vesting_schedule = [VestingSchedule fromJsonDictToVestingSchedule:(NSDictionary*) fromDict[@"vesting_schedule"]];
                ret.is_vesting_schedule_existed = true;
            }
        }
    } else {
        ret.is_vesting_schedule_existed = false;
    }
    NSLog(@"Done");
    return ret;
}
-(void) logInfo {
    NSLog(@"Delegator, itsPublicKey:%@",self.itsPublicKey);
    NSLog(@"Delegator, bonding_purse:%@",self.bonding_purse);
    NSLog(@"Delegator, delegator_public_key:%@",self.delegator_public_key);
    NSLog(@"Delegator, validator_public_key:%@",self.validator_public_key);
    NSLog(@"Delegator, staked_amount:%@",self.staked_amount.itsValue);
    if(self.is_vesting_schedule_existed) {
        NSLog(@"Delegator, vesting schedule");
        [self.vesting_schedule logInfo];
    } else {
        NSLog(@"Vesting schedule: NULL");
    }

}
@end
