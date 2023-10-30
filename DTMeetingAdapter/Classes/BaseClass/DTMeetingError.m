//
//  DTMettingError.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/2.
//

#import "DTMeetingError.h"

@implementation DTMeetingError

- (instancetype)initWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(NSDictionary<NSErrorUserInfoKey,id> *)dict {
    if(self = [super initWithDomain:domain code:code userInfo:dict]) {
        
    }
    return self;
}

+ (instancetype)errorWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(NSDictionary<NSErrorUserInfoKey,id> *)dict {
    return [[DTMeetingError alloc] initWithDomain:domain code:code userInfo:dict];
}

@end
