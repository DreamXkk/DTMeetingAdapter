//
//  DTLiveStream.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//

#import "DTLiveStream.h"
#import <objc/message.h>
@implementation DTLiveStream
+ (NSString *)versionFromLiveStreamType:(DTMeetingSDKServiceType)type {
    if (type == DTMeetingSDKServiceTypeNone) {
        return nil;
    }
    return nil;
}
+ (instancetype)liveStreamWithLiveStreamType:(DTMeetingSDKServiceType)liveStreamType config:(DTLiveStreamConfig *)config {
    DTLiveStream *liveStream = nil;
    
    if (liveStreamType == DTMeetingSDKServiceTypeNone) {
        liveStream = [[DTLiveStream alloc] init];
    }
        else if (liveStreamType == DTMeetingSDKServiceTypeDefault){
            Class classA = NSClassFromString(@"DTAgoraLiveStream");
            SEL allocSelector = NSSelectorFromString(@"alloc");
            SEL initSelector = NSSelectorFromString(@"initWithConfig:");
            if (classA && allocSelector && initSelector) {
                id instanceA = ((id (*)(Class, SEL))objc_msgSend)(classA, allocSelector);
                liveStream = ((id (*)(id, SEL, id))objc_msgSend)(instanceA, initSelector, config);

                // 释放对象
//                SEL releaseSelector = NSSelectorFromString(@"release");
//                ((void (*)(id, SEL))objc_msgSend)(instanceA, releaseSelector);
            } else {
                liveStream = [[DTLiveStream alloc] init];
            }
        }
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

- (int)stopPreview{
    return 1;
}

//- (BOOL)startPlayStream:(NSString *)streamId inView:(UIView *)view contentMode:(DTRTCViewContentMode)mode{
//    return NO;
//}

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

- (BOOL)enableMicrophone:(BOOL)micro {
    return NO;
}

- (int)enableLocalVideo:(BOOL)enabled {
    return 1;
}

- (int)muteLocalVideoStream:(BOOL)mute {
    return 1;
}

- (int)muteLocalAudioStream:(BOOL)mute {
    return 1;
}


- (int)startPreview {
    return 1;
}
- (int)setupLocalVideo:(NSUInteger)uid renderView:(UIView *)renderView renderMode:(DTRTCViewContentMode)renderMode {
    return 1;
}
- (int)setupRemoteVideo:(NSUInteger)uid renderView:(UIView *)renderView renderMode:(DTRTCViewContentMode)renderMode {
    return 1;
}
- (BOOL)enableCamera:(BOOL)camera {
    return NO;
}

- (BOOL)muteVideoStream:(BOOL)mute {
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

- (BOOL)switchCamera {
    return NO;
}

- (BOOL)encryptionMode:(DTEncryptionMode)encryptionMode
         encryptionKey:(NSString *)encryptionKey
     encryptionKdfSalt:(NSString *)encryptionKdfSalt {
    return NO;
}

- (void)destroyResource {
    
}

@end
