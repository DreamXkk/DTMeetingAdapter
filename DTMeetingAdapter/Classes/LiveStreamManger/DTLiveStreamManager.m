//
//  DTAgoraLiveStream.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/29.
//

#import "DTLiveStreamManager.h"
#import "DTMeetingError+liveStreamManager.h"
#import "DTLiveStream.h"
#import "NSString+Utils.h"
#import <CocoaLumberjack/CocoaLumberjack.h>

@interface DTLiveStreamManager()
@property (nonatomic, strong, readwrite) DTLiveStream *liveStream;
@property (nonatomic, assign) DTMeetingSDKServiceType targetLiveStreamType;
@property (nonatomic, strong) DTLiveStreamConfig* streamConfig;
@end

@implementation DTLiveStreamManager

+ (NSString *)versionFromLiveStreamType:(DTMeetingSDKServiceType)type {
    return [DTLiveStream versionFromLiveStreamType:type];
}

- (instancetype)initWithLiveStreamType:(DTMeetingSDKServiceType)type streamConfig:(DTLiveStreamConfig *)streamConfig delegate:(id <DTLiveStreamDelegate>) delegate {
    self = [super init];
    if (self) {
        _targetLiveStreamType = type;
        _streamConfig = streamConfig;
        _delegate = delegate;
        [self setUpLiveStream];
    }
    return self;
}

- (void)updataStreamConfigWithDynamicTokenBeforeJoinChannel:(NSString *)dynamicToken {
    _streamConfig.dynamicToken = dynamicToken;
    if([self setUpLiveStream]){
        [self.liveStream updataStreamConfigWithDynamicTokenBeforeJoinChannel:dynamicToken];
    }
}

- (DTMeetingError * _Nullable)joinChannel:(NSString *)channel userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName {
    if (self.liveStream.inChannel) {
        //        DDLogError(@"DTLiveStreamManager 已经加入channel了");
        return [DTMeetingError liveStreamErrorWithCode:DTLiveStreamErrorCodeInChannel];
    }
    
    if ([NSString isBlankString:channel]) {
        //        DDLogError(@"DTLiveStreamManager channel为空");
        //        DDLogError(@"")
        return [DTMeetingError liveStreamErrorWithCode:DTLiveStreamErrorCodeParameterError];
    }
    if ([self setUpLiveStream]) {
        [self.liveStream joinChannel:channel userId:userId userName:userName];
    }else{
        //        DDLogError(@"DTLiveStreamManager liveStream is nil");
    }
    
    return nil;
}

- (void)leaveChannel {
    
}

- (DTLiveStream *)setUpLiveStream{
    if (self.liveStream) {
        return self.liveStream;
    }
    
    BOOL success = NO;
    do{
        if (self.targetLiveStreamType <= DTMeetingSDKServiceTypeNone && self.targetLiveStreamType >= DTMeetingSDKServiceTypeMax) {
//            DDLogError(@"DTLiveStreamManager 错误的流媒体sdk类型");
            break;
        }
        
        if (self.streamConfig == nil) {
//            DDLogError(@"DTLiveStreamManager 流媒体设置信息为空");
            break;
        }

        self.liveStream = [DTLiveStream liveStreamWithLiveStreamType:self.targetLiveStreamType config:self.streamConfig];
        self.liveStream.delegate = self.delegate;
        success = YES;
    } while(0);
    return self.liveStream;
}

+ (DTLiveStreamConfig *)defaultLiveStreamConfig {
    DTLiveStreamConfig *liveStreamConfig = [DTLiveStreamConfig new];
    liveStreamConfig.encodeResolution = DTVideoResolution640x360;
    liveStreamConfig.fps = DTVideoFrameRateFps15;
    liveStreamConfig.bitRate = DTVideoFrameBitRateDefault;
    liveStreamConfig.orientationMode = DTVideoOutputOrientationModeAdaptative;
    liveStreamConfig.mirrorMode = DTVideoMirrorModeAuto;
    return liveStreamConfig;
}

- (void)destroyResource {
    [self.liveStream destroyResource];
    self.liveStream = nil;
}

@end
