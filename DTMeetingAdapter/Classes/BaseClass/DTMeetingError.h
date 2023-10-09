//
//  DTMettingError.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTMeetingError : NSError

- (instancetype)initWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey,id> *)dict;

+ (instancetype)errorWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey,id> *)dict;
@end

NS_ASSUME_NONNULL_END
