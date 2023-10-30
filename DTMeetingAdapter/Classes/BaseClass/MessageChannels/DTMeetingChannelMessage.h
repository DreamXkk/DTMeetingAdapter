//
//  DTMeetingInvitation.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/2.
//

#import <Foundation/Foundation.h>
#import "DTMessageChannelsTypedef.h"

NS_ASSUME_NONNULL_BEGIN

@interface DTMeetingChannelMessage : NSObject

@property (nonatomic, assign, readonly) MeetingChannelMessageType type;
@property (nonatomic, copy, nonnull) NSString *text;
@property (nonatomic, assign, readonly) long long serverReceivedTs;
@property (nonatomic, assign, readonly) BOOL isOfflineMessage;

- (instancetype _Nonnull)initWithText:(NSString * _Nonnull)text;
@end

NS_ASSUME_NONNULL_END
