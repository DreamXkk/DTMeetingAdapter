//
//  DTLiveStreamUserInfo.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTMeetingUserInfo : NSObject
/** The user ID
 */
@property(assign, nonatomic) NSUInteger uid;

/** The user account
 */
@property (copy, nonatomic) NSString * _Nullable userAccount;

@end

NS_ASSUME_NONNULL_END
