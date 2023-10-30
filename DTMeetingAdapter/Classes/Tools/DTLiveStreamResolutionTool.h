//
//  DTLiveStreamResolutionTool.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//

#import <Foundation/Foundation.h>
#import "DTLiveStreamTypedef.h"

NS_ASSUME_NONNULL_BEGIN

@interface DTLiveStreamResolutionTool : NSObject
/**
 将DTVideoResolution转换成CGSizey形式
 
 @param resolution DTVideoResolution形式分辨率
 @return CGSize形式的分辨率
 */
+ (CGSize)sizeVideoResolutionWithRTCVideoResolution:(DTVideoResolution)resolution;
@end

NS_ASSUME_NONNULL_END
