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
- (void)onJoinChannelSuccess;
- (void)onLeaveChannelSuccess;
- (void)onReInitStreamService;
@end


@interface DTLiveStreamManager : NSObject
@property (nonatomic, strong, readonly) DTLiveStream *liveStream;
//@property (nonatomic, weak) id<DTLiveStreamManagerDelegate> delegate;
@property (nonatomic, assign, readonly) DTMeetingSDKServiceType targetLiveStreamType;
@property (nonatomic, copy) NSString *serviceStatus;

+ (NSString *)versionFromLiveStreamType:(DTMeetingSDKServiceType)type;

+ (DTLiveStreamConfig *)defaultLiveStreamConfig;

- (instancetype)initWithLiveStreamType:(DTMeetingSDKServiceType)type streamConfig:(DTLiveStreamConfig *)streamConfig;

- (void)updataStreamConfigWithDynamicTokenBeforeJoinChannel:(NSString *)dynamicToken;

- (DTMeetingError * _Nullable)joinChannel:(NSString *)channel userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName;

- (void)leaveChannel;

- (void)destroyResource;
@end


NS_ASSUME_NONNULL_END
