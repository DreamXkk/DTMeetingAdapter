//
//  DTAgoraLiveStream.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/29.
//

#import "DTMessageChannelManager.h"
#import "DTMessageChannel.h"

@interface DTMessageChannelManager()
@property (nonatomic, strong) DTMessageChannel *messageChannel;
@property (nonatomic, assign) DTMeetingSDKServiceType targetLiveStreamType;
@end

@implementation DTMessageChannelManager

- (instancetype)initWithMessageChannelType:(DTMeetingSDKServiceType)type {
    self = [super init];
    if (self) {
        _targetLiveStreamType = type;
        [self setUpMessageChannel];
    }
    return self;
}

- (void)joinMessageChannel:(NSString * _Nullable)channelId userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName {
    if([self setUpMessageChannel]){
        [self.messageChannel joinMessageChannel:channelId userId:userId userName:userName];
    }   
}

- (void)leaveMessageChannel {
    if(!self.messageChannel){
        return;
    }
    [self.messageChannel leaveMessageChannel];
}

- (DTMessageChannel *)setUpMessageChannel{
    if (self.messageChannel) {
        return self.messageChannel;
    }

    BOOL success = NO;
    do {
        if (self.targetLiveStreamType <= DTMeetingSDKServiceTypeNone && self.targetLiveStreamType >= DTMeetingSDKServiceTypeMax) {
            break;
        }
        
        self.messageChannel = [DTMessageChannel messageChannelWithServiceType:self.targetLiveStreamType];
        success = YES;
    } while(0);

    return self.messageChannel;
}

- (void)destroyResource {
    [self.messageChannel destroyResource];
}

@end
