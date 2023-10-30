//
//  DTMeetingChanneLocalInvitation.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTMeetingChanneLocalInvitation : NSObject
///被叫方id
@property (nonatomic, copy, nonnull) NSString *calleeId;
//内容
@property (nonatomic, copy, nullable) NSString *content;

@property (nonatomic, copy, nullable) NSString *channelId;

@property (nonatomic, copy, nullable) NSString *response;

- (instancetype _Nonnull)initWithCalleeId: (NSString * _Nonnull) calleeId;
@end

NS_ASSUME_NONNULL_END
