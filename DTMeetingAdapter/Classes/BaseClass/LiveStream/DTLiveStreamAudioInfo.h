//
//  DTLiveStreamAudioInfo.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTLiveStreamAudioInfo : NSObject
/// 音频通道数
@property(assign, nonatomic) NSUInteger numChannels;
/// 音频采样率
@property(assign, nonatomic) NSUInteger sentSampleRate;
/// 上行比特率 （Kbps）
@property(assign, nonatomic) NSUInteger sentBitrate;
/// 内部有效负载类型
@property(assign, nonatomic) NSUInteger internalCodec;
/// 上行丢包率
@property(assign, nonatomic) NSUInteger packetLossRate;
/// 设备的音频延迟，包括录制和播放延迟
@property(assign, nonatomic) NSUInteger audioDeviceDelay;
@end

NS_ASSUME_NONNULL_END
