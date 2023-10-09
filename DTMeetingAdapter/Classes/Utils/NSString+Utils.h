//
//  NSString+Utils.h
//  DTMeetingAdapter
//
//  Created by Hornet-H on 10/1/2023.
//  Copyright (c) 2023 Hornet-H. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
/**
 常用的NSString工具方法
 */
@interface NSString (Utils)

/**
 当前字符串是否为空字符串，包括@""、nil、NSNull等

 @param string 需要判断的字符串
 @return YES/NO
 */
+ (BOOL)isBlankString:(NSString*)string;

/**
 字典转json字符串
 
 @param jsonDictionary 字典
 @return json字符串
 */
+(NSString *_Nullable)jsonFromDictionary:(NSDictionary *)jsonDictionary;


+ (nullable NSData *)dataFromBase64String:(NSString *)aString;


@end
NS_ASSUME_NONNULL_END
