//
//  DTMeetingChanneLocalInvitation.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/8.
//

#import "DTMeetingChanneLocalInvitation.h"

@implementation DTMeetingChanneLocalInvitation
- (instancetype _Nonnull)initWithCalleeId: (NSString * _Nonnull) calleeId {
    self = [super init];
    if(self){
        _calleeId = calleeId;
    }
    return self;
}
@end
