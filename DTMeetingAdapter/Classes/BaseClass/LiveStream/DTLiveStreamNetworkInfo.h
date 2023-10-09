//
//  DTLiveStreamNetworkInfo.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//

#import <Foundation/Foundation.h>
#import "DTLiveStreamTypedef.h"

NS_ASSUME_NONNULL_BEGIN



@interface DTLiveStreamNetworkInfo : NSObject <NSCopying>
/**
推拉流状态获取时间戳
*/
@property (nonatomic, assign) NSTimeInterval timeStamp;
/**
推拉流音频码率
*/
@property (nonatomic, assign) double audioBitrate;
/**
推拉流视频码率
*/
@property (nonatomic, assign) double videoBitrate;
/**
 推拉流速率
 */
@property (nonatomic, assign) double bitrate;
/**
 丢包率
 */
@property (nonatomic, assign) NSInteger lostRate;
/**
 延迟
 */
@property (nonatomic, assign) NSInteger delay;
/**
 网络质量，值为DTNetQualityUnknown表示无法获取数据
 */
@property (nonatomic, assign) DTNetQuality netQuality;
/**
 推拉流音频fps
 */
@property (nonatomic, assign) double audioFps;
/**
 推拉流视频fps
 */
@property (nonatomic, assign) double videoFps;

@property (nonatomic, assign) int avTimestampDiff;

@end

NS_ASSUME_NONNULL_END
