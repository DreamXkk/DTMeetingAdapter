//
//  DTMeetingError+liveStreamManager.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/29.
//

#import "DTMeetingError+liveStreamManager.h"

NSString* const kDTLiveStreamManagerErrorDomain = @"org.difft.chative.DTMeetingAdapter.LiveStreamManager";

static NSString* const kDTLiveStreamErrorDescriptions[] = {
    @"无错误",             //DTLiveStreamErrorCodeOK
    
    @"加入channel参数错误,检查channel或者userId是否为空", //DTLiveStreamErrorCodeParameterError
    @"已经在channel中，请先离开频道", //DTLiveStreamErrorCodeInChannel
    @"流媒体初始化失败，请退出教室重试", //DTLiveStreamErrorCodeInitError
    @"流媒体设备报错，请检查设备状态", //DTLiveStreamErrorCodeDeviceError
    
    @"未知错误"             //DTLiveStreamErrorCodeUnknown
};

@implementation DTMeetingError(liveStreamManager)
+ (NSString*)errorDescriptionWithCode:(DTLiveStreamErrorCode)code{
    if(code < DTLiveStreamErrorCodeOK || code > DTLiveStreamErrorCodeUnknown) {
        return @"未定义对应的错误描述";
    }
    return kDTLiveStreamErrorDescriptions[code];
}

+ (instancetype)liveStreamErrorWithCode:(DTLiveStreamErrorCode)code{
    NSDictionary* userInfo = @{
                               NSLocalizedDescriptionKey:[DTMeetingError errorDescriptionWithCode:code]
                               };
    return [DTMeetingError errorWithDomain:kDTLiveStreamManagerErrorDomain code:code userInfo:userInfo];
}
@end
