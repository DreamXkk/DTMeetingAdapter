//
//  DTMeetingInvitation.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/2.
//

#import "DTMeetingChannelMessage.h"


@implementation DTMeetingChannelMessage

- (instancetype _Nonnull)initWithText:(NSString * _Nonnull)text {
    self = [super init];
    _text = text;
    return self;
}

@end
