//
//  DTAgoraLiveStream.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/29.
//


#import "DTLiveStream.h"
#import "DTMessageChannelsTypedef.h"
#import "DTLiveStreamAudioVolumeInfo.h"


NS_ASSUME_NONNULL_BEGIN

@protocol DTLiveStreamManagerDelegate <NSObject>
//- (void)onJoinChannelSuccess;
//- (void)onLeaveChannelSuccess;
//- (void)onReInitStreamService;
@end


@interface DTLiveStreamManager : NSObject
@property (nonatomic, strong, readonly) DTLiveStream *liveStream;
@property (nonatomic, weak, readonly) id<DTLiveStreamDelegate> delegate;
@property (nonatomic, assign, readonly) DTMeetingSDKServiceType targetLiveStreamType;
@property (nonatomic, copy) NSString *serviceStatus;

+ (NSString *)versionFromLiveStreamType:(DTMeetingSDKServiceType)type;
///Do not configure DTLiveStreamConfig for now, this is in convergence。
+ (DTLiveStreamConfig *)defaultLiveStreamConfig;

- (instancetype)initWithLiveStreamType:(DTMeetingSDKServiceType)type streamConfig:(DTLiveStreamConfig *)streamConfig delegate:(id <DTLiveStreamDelegate>) delegate;

- (void)updataStreamConfigWithDynamicTokenBeforeJoinChannel:(NSString *)dynamicToken;

- (DTMeetingError * _Nullable)joinChannel:(NSString *)channel userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName;

- (void)leaveChannel;

- (void)destroyResource;
@end


NS_ASSUME_NONNULL_END
