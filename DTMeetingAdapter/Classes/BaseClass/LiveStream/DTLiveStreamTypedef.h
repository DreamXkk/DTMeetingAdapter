//
//  Header.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DTVideoResolution) {
    DTVideoResolution60x60 = 0,  //0
    DTVideoResolution90x90,      //1
    DTVideoResolution120x120,    //2
    DTVideoResolution150x150,    //3
    DTVideoResolution160x90,     //4
    DTVideoResolution160x120,    //5
    DTVideoResolution180x180,    //6
    DTVideoResolution288x288,    //7
    DTVideoResolution320x180,    //8
    DTVideoResolution320x240,    //9
    DTVideoResolution360x360,    //10
    DTVideoResolution480x360,    //11
    DTVideoResolution480x480,    //12
    DTVideoResolution640x360,    //13
    DTVideoResolution640x480,    //14
    DTVideoResolution720x720,    //15
    DTVideoResolution960x540,    //16
    DTVideoResolution960x720,    //17
    DTVideoResolution1280x720    //18
};

typedef NS_ENUM(NSUInteger, DTMeetingSDKServiceType) {
    DTMeetingSDKServiceTypeNone = 0,
    DTMeetingSDKServiceTypeDefault = 1,
    DTMeetingSDKServiceTypeGoogle,
    DTMeetingSDKServiceTypeMax,
};

typedef NS_ENUM(NSInteger, DTVideoOutputOrientationMode) {
    DTVideoOutputOrientationModeAdaptative = 0,
    DTVideoOutputOrientationModeFixedLandscape = 1,
    DTVideoOutputOrientationModeFixedPortrait = 2,  
};

typedef NS_ENUM(NSUInteger, DTNetQuality) {
    DTNetQualityUnknown = 0,
    DTNetQualityExcellent = 1,
    DTNetQualityGood = 2,
    DTNetQualityPoor = 3,
    DTNetQualityBad = 4,
    DTNetQualityVBad = 5,
    DTNetQualityDown = 6
};

/**
 卡顿事件
 
 - DTBufferingEventAudioStart: 音频卡顿开始
 - DTBufferingEventAudioEnd: 音频卡顿结束
 - DTBufferingEventAudioCancel: 音频卡顿取消
 
 - DTBufferingEventVideoStart: 视频卡顿开始
 - DTBufferingEventVideoEnd: 视频卡顿结束
 - DTBufferingEventVideoCancel: 视频卡顿取消
 */
typedef NS_ENUM(NSUInteger, DTBufferingEvent) {
    DTBufferingEventNone = 0,
    
    DTBufferingEventAudioStart,
    DTBufferingEventAudioEnd,
    DTBufferingEventAudioCancel,
    
    DTBufferingEventVideoStart,
    DTBufferingEventVideoEnd,
    DTBufferingEventVideoCancel,
};


/**
 设备类型
 
 - DTLiveStreamDeviceTypeUnknow: 未知
 - DTLiveStreamDeviceTypeCamera: 摄像头
 - DTLiveStreamDeviceTypeMicrophone: 麦克风
 - DTLiveStreamDeviceTypeAudio: 音频设备
 - DTLiveStreamDeviceTypeSpeaker: 扬声器
 - DTLiveStreamDeviceTypeEngineDecoder:引擎解码器
 */
typedef NS_ENUM(NSInteger, DTLiveStreamDeviceType) {
    DTLiveStreamDeviceTypeUnknow = 0,
    DTLiveStreamDeviceTypeCamera,
    DTLiveStreamDeviceTypeMicrophone,
    DTLiveStreamDeviceTypeAudio,
    DTLiveStreamDeviceTypeSpeaker,
    DTLiveStreamDeviceTypeEngineDecoder
};



/**
 前置摄像头镜像模式
 
 - DTMirrorModeNone: 不开启镜像，默认
 - DTMirrorModePreview: 仅本地预览镜像
 - DTMirrorModeRemote: 仅远端结果镜像
 - DTMirrorModeBoth: 本地预览和远端结果均镜像
 */
typedef NS_OPTIONS(NSInteger, DTMirrorMode) {
    DTMirrorModeNone = 0,
    DTMirrorModePreview = 1 << 0,
    DTMirrorModeRemote = 1 << 1,
    DTMirrorModeBoth = DTMirrorModePreview | DTMirrorModeRemote,
};

/**
 填充类型
 
 - DTRTCViewContentModeScaleAspectFit: AspectFit
 - DTRTCViewContentModeScaleAspectFill: AspectFill
 - DTRTCViewContentModeScaleToFill: Fill
 */
typedef NS_ENUM(NSInteger, DTRTCViewContentMode) {
    DTRTCViewContentModeScaleAspectFit = 0,
    DTRTCViewContentModeScaleAspectFill,
    DTRTCViewContentModeScaleToFill,
};

/**
 摄像头位置
 
 - DTCameraPositionBack: 后置摄像头
 - DTCameraPositionFront: 前置摄像头
 */
typedef NS_ENUM(NSInteger, DTCameraPosition) {
    DTCameraPositionFront  = 0,
    DTCameraPositionBack
};


/** Video frame rate */
typedef NS_ENUM(NSInteger, DTVideoFrameRate) {
    /** 1 fps */
    DTVideoFrameRateFps1 = 1,
    /** 7 fps */
    DTVideoFrameRateFps7 = 7,
    /** 10 fps */
    DTVideoFrameRateFps10 = 10,
    /** 15 fps */
    DTVideoFrameRateFps15 = 15,
    /** 24 fps */
    DTVideoFrameRateFps24 = 24,
    /** 30 fps */
    DTVideoFrameRateFps30 = 30,
    /** 60 fps */
    DTVideoFrameRateFps60 = 60,
};

/** Video frame rate */
typedef NS_ENUM(NSInteger, DTVideoFrameBitRate) {
    DTVideoFrameBitRateDefault = 1,
};



/** Video mirror mode */
typedef NS_ENUM(NSUInteger, DTVideoMirrorMode) {
    /**
     * 0: The default mirror mode (the SDK determines the mirror mode).
     */
    DTVideoMirrorModeAuto = 0,
    /**
     * 1: Enable the mirror mode.
     */
    DTVideoMirrorModeEnabled = 1,
    /**
     * 2: Disable the mirror mode.
     */
    DTVideoMirrorModeDisabled = 2,
};

/** Encryption mode */
typedef NS_ENUM(NSInteger, DTEncryptionMode) {
    /** 128-bit AES encryption, XTS mode. */
    DTEncryptionModeAES128XTS = 1,
    /** 128-bit AES encryption, ECB mode. */
    DTEncryptionModeAES128ECB = 2,
    /** 256-bit AES encryption, XTS mode. */
    DTEncryptionModeAES256XTS = 3,
    /** 128-bit SM4 encryption, ECB mode. */
    DTEncryptionModeSM4128ECB = 4,
    /** 128-bit AES encryption, GCM mode. */
    DTEncryptionModeAES128GCM = 5,
    /** 256-bit AES encryption, GCM mode. */
    DTEncryptionModeAES256GCM = 6,
    /** 128-bit AES encryption, GCM mode, with KDF salt */
    DTEncryptionModeAES128GCM2 = 7,
    /** 256-bit AES encryption, GCM mode, with KDF salt */
    DTEncryptionModeAES256GCM2 = 8,
    /** Enumerator boundary */
    DTEncryptionModeNone = 1000,
};

/** Reason for the user being offline */
typedef NS_ENUM(NSUInteger, DTUserOfflineReason) {
    
    DTUserOfflineReasonQuit = 0,
    DTUserOfflineReasonDropped = 1,
    DTUserOfflineReasonAudience = 2,
    DTUserOfflineReasonUnknow = 1000,
};


/** Reason for the user being offline */
typedef NS_ENUM(NSUInteger, DTJoinChannelUserType) {
    DTJoinedChannelUserTypeLocalUser = 0,
    DTJoinedChannelUserTypeRemoteUser = 1,
};

/** The state of the remote video. */
typedef NS_ENUM(NSUInteger, DTVideoRemoteState) {
    DTVideoRemoteStateStopped = 0,
    DTVideoRemoteStateStarting = 1,
    DTVideoRemoteStateDecoding = 2,
    DTVideoRemoteStateFrozen = 3,
    DTVideoRemoteStateFailed = 4,
    DTVideoRemoteStateUnknow = 1000,
};


typedef NS_ENUM(NSUInteger, DTVideoRemoteReason) {
    DTVideoRemoteReasonInternal = 0,
    DTVideoRemoteReasonCongestion = 1,
    DTVideoRemoteReasonRecovery = 2,
    DTVideoRemoteReasonLocalMuted = 3,
    DTVideoRemoteReasonLocalUnmuted = 4,
    DTVideoRemoteReasonRemoteMuted = 5,
    DTVideoRemoteReasonRemoteUnmuted = 6,
    DTVideoRemoteReasonRemoteOffline = 7,
    DTVideoRemoteReasonAudioFallback = 8,
    DTVideoRemoteReasonAudioFallbackRecovery = 9,
    DTVideoRemoteReasonUnknow = 1000,
};

/** States of the local video. */
typedef NS_ENUM(NSUInteger, DTVideoLocalState) {
    DTVideoLocalStateStopped = 0,
    DTVideoLocalStateCapturing = 1,
    DTVideoLocalStateEncoding = 2,
    DTVideoLocalStateFailed = 3,
    DTVideoLocalStateUnknow = 1000,
};

typedef NS_ENUM(NSUInteger, DTAudioLocalState) {
    DTAudioLocalStateStopped = 0,
    DTAudioLocalStateRecording = 1,
    DTAudioLocalStateEncoding = 2,
    DTAudioLocalStateFailed = 3,
    DTAudioLocalStateUnknow = 1000,
};

typedef NS_ENUM(NSUInteger, DTAudioRemoteState) {
    DTAudioRemoteStateStopped = 0,
    DTAudioRemoteStateStarting = 1,
    DTAudioRemoteStateDecoding = 2,
    DTAudioRemoteStateFrozen = 3,
    DTAudioRemoteStateFailed = 4,
    DTAudioRemoteStateUnknow = 1000,
};

typedef NS_ENUM(NSUInteger, DTAudioRemoteReason) {
      DTAudioRemoteReasonInternal = 0,
      DTAudioRemoteReasonNetworkCongestion = 1,
      DTAudioRemoteReasonNetworkRecovery = 2,
      DTAudioRemoteReasonLocalMuted = 3,
      DTAudioRemoteReasonLocalUnmuted = 4,
      DTAudioRemoteReasonRemoteMuted = 5,
      DTAudioRemoteReasonRemoteUnmuted = 6,
      DTAudioRemoteReasonRemoteOffline = 7,
      DTAudioRemoteReasonUnknow = 1000,
};
