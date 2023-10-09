//
//  DTLiveStreamAudioVolumeInfo.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTLiveStreamAudioVolumeInfo : NSObject
@property(assign, nonatomic) NSUInteger uid;

@property(assign, nonatomic) NSUInteger volume;

@property(assign, nonatomic) NSUInteger vad;

@property (assign, nonatomic) double voicePitch;
@end

NS_ASSUME_NONNULL_END
