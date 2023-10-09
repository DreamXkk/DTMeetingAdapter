//
//  DTLiveStream.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//

#import "DTLiveStream.h"
#import "DTLiveStreamUtils.h"
@implementation DTLiveStream
+ (NSString *)versionFromLiveStreamType:(DTMeetingSDKServiceType)type {
    if (type == DTMeetingSDKServiceTypeNone) {
        return nil;
    }
    
    #if __has_include("DTAgoraLiveStream.h")
    else if (type == DTMeetingSDKServiceTypeDefault){
        return [DTAgoraLiveStream getVersion];
    }
    #endif
    
    return nil;
}
+ (instancetype)liveStreamWithLiveStreamType:(DTMeetingSDKServiceType)liveStreamType config:(DTLiveStreamConfig *)config {
    DTLiveStream *liveStream = nil;
    
    if (liveStreamType == DTMeetingSDKServiceTypeNone) {
        liveStream = [[DTLiveStream alloc] init];
    }

    #if __has_include("DTAgoraLiveStream.h")
    else if (liveStreamType == DTMeetingSDKServiceTypeDefault){
        liveStream = [[DTAgoraLiveStream alloc] initWithConfig:(DTAgoraLiveStreamConfig *)config];
    }
    #endif
    
    else{
        liveStream = [[DTLiveStream alloc] init];
    }
    liveStream.liveStreamType = liveStreamType;
    
    return liveStream;
}

- (void)updataStreamConfigWithDynamicTokenBeforeJoinChannel:(NSString *)dynamicToken {
    
}

- (void)joinChannel:(NSString *)channel userId:(NSString *)userId userName:(nullable NSString *)userName {
}

- (void)leaveChannel {
}

- (BOOL)startPublish:(NSString *)streamId {
    return NO;
}

- (void)stopPublish {
    
}

- (void)startPreview:(UIView *)view contentMode:(DTRTCViewContentMode)mode {
    
}

- (BOOL)enablePreview:(BOOL)enable {
    return NO;
}

- (BOOL)stopPreview{
    return false;
}

- (BOOL)startPlayStream:(NSString *)streamId inView:(UIView *)view contentMode:(DTRTCViewContentMode)mode{
    return NO;
}

- (void)stopPlayStream:(NSString *)streamId{
}


- (BOOL)rotateCaptureWithOrientation:(UIDeviceOrientation)orientaion {
    return NO;
}

- (BOOL)setCameraPosition:(DTCameraPosition)cameraPosition {
    return NO;
}

- (void)setMirrorMode:(DTMirrorMode)mode {
    
}

//设置音量
- (void)setAudioVolume:(NSString *)streamId voluem:(int)volume {
}

//不拉音频，只拉视频
- (void)setStream:(NSString *)streamId audioMute:(BOOL)mute {
    
}

//不拉视频，只拉音频
- (void)setStream:(NSString *)streamId videoMute:(BOOL)mute {
    
}

- (BOOL)setEnableSpeakerphone:(BOOL)enable {
    return NO;
}

- (BOOL)enableCamera:(BOOL)camera {
    return NO;
}

- (BOOL)muteVideoStream:(BOOL)mute {
    return NO;
}

- (BOOL)switchCamera {
    return NO;
}


- (BOOL)isEnableMicrophone{
    return NO;
}

- (BOOL)isEnableCamera{
    return NO;
}

- (void)renewToken:(NSString * _Nonnull)token {
    
}

- (BOOL)encryptionMode:(DTEncryptionMode)encryptionMode
         encryptionKey:(NSString *)encryptionKey
     encryptionKdfSalt:(NSString *)encryptionKdfSalt {
    return NO;
}

- (void)destroyResource {
    
}



@end
