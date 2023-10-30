//
//  DTMeetingChannelRemoteInvitation.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/8.
//

#import "DTMeetingChannelRemoteInvitation.h"

@implementation DTMeetingChannelRemoteInvitation
- (instancetype _Nonnull)initWithCallerId: (NSString * _Nonnull) callerId {
    self = [super init];
    if(self){
        _callerId = callerId;
    }
    return self;
}
@end
