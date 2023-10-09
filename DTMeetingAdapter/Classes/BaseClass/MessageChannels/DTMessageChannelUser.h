//
//  DTMessageChannelUser.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTMessageChannelUser : NSObject
@property (nonatomic, copy, nonnull) NSString *userId;
@property (nonatomic, copy, nonnull) NSString *channelId;
@end

NS_ASSUME_NONNULL_END
