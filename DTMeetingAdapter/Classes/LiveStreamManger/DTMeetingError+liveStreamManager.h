//
//  DTMeetingError+liveStreamManager.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/29.
//

#import <Foundation/Foundation.h>
#import "DTMeetingError.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, DTLiveStreamErrorCode) {
    DTLiveStreamErrorCodeOK = 0,
    
    DTLiveStreamErrorCodeParameterError,
    DTLiveStreamErrorCodeInChannel,
    DTLiveStreamErrorCodeInitError,
    DTLiveStreamErrorCodeDeviceError,
    
    DTLiveStreamErrorCodeUnknown
};

@interface DTMeetingError(liveStreamManager)
+ (NSString*)errorDescriptionWithCode:(DTLiveStreamErrorCode)code;
+ (instancetype)liveStreamErrorWithCode:(DTLiveStreamErrorCode)code;
@end

NS_ASSUME_NONNULL_END
