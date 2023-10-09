//
//  DTLiveStreamConfig.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//

#import <Foundation/Foundation.h>
#import "DTLiveStreamTypedef.h"

NS_ASSUME_NONNULL_BEGIN

@interface DTLiveStreamConfig : NSObject
//共用
@property (nonatomic, assign) DTVideoFrameRate fps;                         ///< 视频帧率
@property (nonatomic, assign) DTVideoFrameBitRate bitRate;  // bitRate == 1/DTVideoFrameBitRateDefault  会取SDK的默认 bitRate
@property (nonatomic, assign) DTVideoOutputOrientationMode orientationMode;  // bitRate == 1/DTVideoFrameBitRateDefault  会取SDK的默认 bitRate
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, assign) DTVideoMirrorMode mirrorMode;  // bitRate == 1/DTVideoFrameBitRateDefault  会取SDK的默认 bitRate


@property (nonatomic, assign) DTVideoResolution encodeResolution;  ///推流推出去的分辨率
///
///
@property (nonatomic, assign) DTVideoResolution captureResolution; ///摄像头采集的分辨率
@property (nonatomic, assign) BOOL enableCaptureMirror;
@property (nonatomic, assign) BOOL enablePreviewMirror;
@property (nonatomic, assign) BOOL enableSoftAEC;///是否启用软件回声消除
@property (nonatomic, copy, nullable) NSString *dynamicToken; //动态令牌

@end

NS_ASSUME_NONNULL_END
