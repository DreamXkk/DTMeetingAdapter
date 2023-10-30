#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "DTMeetingError.h"
#import "DTLiveStream.h"
#import "DTLiveStreamAudioInfo.h"
#import "DTLiveStreamAudioVolumeInfo.h"
#import "DTLiveStreamConfig.h"
#import "DTLiveStreamNetworkInfo.h"
#import "DTLiveStreamTypedef.h"
#import "DTLiveStreamUtils.h"
#import "DTLiveStreamVideoInfo.h"
#import "DTMeetingUserInfo.h"
#import "DTMeetingChannelMessage.h"
#import "DTMeetingChanneLocalInvitation.h"
#import "DTMeetingChannelRemoteInvitation.h"
#import "DTMessageChannel.h"
#import "DTMessageChannelsTypedef.h"
#import "DTMessageChannelUser.h"
#import "DTMessageChannelUtils.h"
#import "DTMsgChannelUserOnlineStatus.h"
#import "DTLiveStreamManager.h"
#import "DTMeetingError+liveStreamManager.h"
#import "DTMessageChannelManager.h"
#import "DTMeetingAdapterMacro.h"
#import "DTLiveStreamResolutionTool.h"
#import "DTMeetingAdapter.h"
#import "NSString+Utils.h"

FOUNDATION_EXPORT double DTMeetingAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char DTMeetingAdapterVersionString[];

