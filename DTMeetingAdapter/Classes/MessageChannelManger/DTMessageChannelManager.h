//
//  DTAgoraLiveStream.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/29.
//


#import "DTMessageChannelManager.h"
#import "DTLiveStreamTypedef.h"
#import "DTMessageChannel.h"
@class DTMeetingError;

NS_ASSUME_NONNULL_BEGIN

@protocol DTMessageChannelManagerDelegate <NSObject>

@end


@interface DTMessageChannelManager : NSObject
@property (nonatomic, strong, readonly) DTMessageChannel *messageChannel;
//@property (nonatomic, weak) id<DTMessageChannelDelegate> delegate;
@property (nonatomic, copy) NSString *serviceStatus;

- (instancetype)initWithMessageChannelType:(DTMeetingSDKServiceType)type with:(DTMessageChannelConfig *)config;

- (void)joinMessageChannel:(NSString * _Nullable)channelId userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName;

- (void)leaveMessageChannel;

////在推拉流前，通过该通道进行消息交换 ⚠️ RTM ⚠️通道
//- (void)sendMeetingRtmChannelMessage:(DTMeetingChannelMessage * _Nonnull)message completion:(MeetingRtmSendChannelMessageBlock _Nullable)completionBlock;
//
////进入频道后，通过该通道进行消息交换 ⚠️ RTC ⚠️ 通道
//- (void)sendMeetingRtcChannelMessage:(DTMeetingChannelMessage * _Nonnull)message completion:(MeetingRtCSendChannelMessageBlock _Nullable)completionBlock;

//释放资源
- (void)destroyResource;

+ (DTMessageChannelConfig *)defaultMessageChannelConfig;
@end


NS_ASSUME_NONNULL_END
