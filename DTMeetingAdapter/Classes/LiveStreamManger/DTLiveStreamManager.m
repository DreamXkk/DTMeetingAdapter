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

- (instancetype)initWithLiveStreamType:(DTMeetingSDKServiceType)type streamConfig:(DTLiveStreamConfig *)streamConfig {
    self = [super init];
    if (self) {
        _targetLiveStreamType = type;
        _streamConfig = streamConfig;
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
    
    //    self.channel = channel;
    //    self.userId = userId;
    //    self.userName = userName;
    
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
        success = YES;
    } while(0);
    return self.liveStream;
}

+ (DTLiveStreamConfig *)defaultLiveStreamConfig {
    
//    AgoraRtcEngineKit *agoraKit = [AgoraRtcEngineKit sharedEngineWithAppId:RTM_APPID delegate:self];
//    [agoraKit setChannelProfile:AgoraChannelProfileLiveBroadcasting];
//
//    AgoraVideoEncoderConfiguration *conf = [[AgoraVideoEncoderConfiguration alloc] initWithSize:AgoraVideoDimension640x360 frameRate:AgoraVideoFrameRateFps15 bitrate:AgoraVideoBitrateStandard orientationMode:AgoraVideoOutputOrientationModeAdaptative mirrorMode:AgoraVideoMirrorModeAuto];
    
//    [agoraKit setVideoEncoderConfiguration:conf];
//    [agoraKit setAudioProfile:AgoraAudioProfileDefault];
//    [agoraKit setAudioScenario:AgoraAudioScenarioGameStreaming];
//    [agoraKit enableVideo];
//    [agoraKit enableAudio];
//    [agoraKit enableLocalVideo:NO];
//    [agoraKit adjustPlaybackSignalVolume:300];
//    [agoraKit adjustRecordingSignalVolume:300];
//    //开启AI深度降噪
//    //        [agoraKit enableDeepLearningDenoise:YES];
//    //        [agoraKit muteLocalVideoStream:YES];
//    //        [agoraKit muteAllRemoteVideoStreams:NO];
//    [agoraKit setDefaultAudioRouteToSpeakerphone:YES];
//
//    [agoraKit setClientRole:AgoraClientRoleBroadcaster];
//    [agoraKit enableAudioVolumeIndication:800 smooth:3 reportVad:NO];
    
    DTLiveStreamConfig *liveStreamConfig = [DTLiveStreamConfig new];
    liveStreamConfig.encodeResolution = DTVideoResolution640x360;
    liveStreamConfig.fps = DTVideoFrameRateFps15;
    liveStreamConfig.bitRate = DTVideoFrameBitRateDefault;
    liveStreamConfig.orientationMode = DTVideoOutputOrientationModeAdaptative;
    liveStreamConfig.mirrorMode = DTVideoMirrorModeAuto;
    
    return liveStreamConfig;
}

- (void)destroyResource {
    self.liveStream.delegate = nil;
    [self.liveStream destroyResource];
}

@end
