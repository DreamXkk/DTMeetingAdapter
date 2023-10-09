//
//  NSString+Utils.h
//  DTMeetingAdapter
//
//  Created by Hornet-H on 10/1/2023.
//  Copyright (c) 2023 Hornet-H. All rights reserved.
//


#import "NSString+Utils.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSString (Utils)

+ (BOOL)isBlankString:(NSString*)string {
    BOOL isBlankString = YES;
    do {
        if (string == nil || string == NULL) {
            break;
        }
        if ([string isKindOfClass:[NSNull class]]) {
            break;
        }
        if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length] == 0) {
            break;
        }
        isBlankString = NO;
    } while (false);
    return isBlankString;
}

+ (NSString *_Nullable)jsonFromDictionary:(NSDictionary *)jsonDictionary {
    NSString *jsonString = nil;
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:jsonDictionary
                                                       options:NSJSONWritingPrettyPrinted // Pass 0 if you don't care about the readability of the generated string
                                                         error:&error];
    if (jsonData) {
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        jsonString =  [jsonString stringByReplacingOccurrencesOfString:@"\r" withString:@""];
        jsonString = [jsonString stringByReplacingOccurrencesOfString:@"\n" withString:@""];
    }
    return jsonString;
}

+ (nullable NSData *)dataFromBase64String:(NSString *)aString {
    return [[NSData alloc] initWithBase64EncodedString:aString options:NSDataBase64DecodingIgnoreUnknownCharacters];
}

@end
