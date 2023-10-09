//
//  DTLiveStreamVideoStatus.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTLiveStreamVideoInfo : NSObject

/// 流id
@property (nonatomic, copy) NSString *streamId;

/// 视频流宽度 pixels
@property (nonatomic, assign) NSUInteger width;

/// 视频流高度 pixels
@property (nonatomic, assign) NSUInteger height;

/// 丢包率
@property (nonatomic, assign) NSInteger packetLossRate;

/// 渲染帧率
@property (nonatomic, assign) NSInteger rendererOutputFrameRate;
@end

NS_ASSUME_NONNULL_END
