//
//  DTMeetingChanneUserOnlineStatus.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/9.
//

#import <Foundation/Foundation.h>
#import "DTMessageChannelsTypedef.h"


NS_ASSUME_NONNULL_BEGIN

@interface DTMsgChannelUserOnlineStatus : NSObject
@property (nonatomic, copy, nonnull) NSString *peerId;
@property (nonatomic, assign) BOOL isOnline;
@property (nonatomic, assign) DTMessageChannelPeerOnlineState state;
@end

NS_ASSUME_NONNULL_END
