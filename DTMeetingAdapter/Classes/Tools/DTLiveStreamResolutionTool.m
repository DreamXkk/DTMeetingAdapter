//
//  DTLiveStreamResolutionTool.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//



#import "DTLiveStreamResolutionTool.h"

@implementation DTLiveStreamResolutionTool

+ (CGSize)sizeVideoResolutionWithRTCVideoResolution:(DTVideoResolution)resolution {
    CGSize size = CGSizeZero;
    switch (resolution) {
        case DTVideoResolution60x60:
            size = CGSizeMake(60, 60);
            break;
        case DTVideoResolution90x90:
            size = CGSizeMake(90, 90);
            break;
        case DTVideoResolution120x120:
            size = CGSizeMake(120, 120);
            break;
        case DTVideoResolution150x150:
            size = CGSizeMake(150, 150);
            break;
        case DTVideoResolution160x90:
            size = CGSizeMake(160, 90);
            break;
        case DTVideoResolution160x120:
            size = CGSizeMake(160, 120);
            break;
        case DTVideoResolution180x180:
            size = CGSizeMake(180, 180);
            break;
        case DTVideoResolution320x180:
            size = CGSizeMake(320, 180);
            break;
        case DTVideoResolution320x240:
            size = CGSizeMake(320, 240);
            break;
        case DTVideoResolution360x360:
            size = CGSizeMake(360, 360);
            break;
        case DTVideoResolution480x360:
            size = CGSizeMake(480, 360);
            break;
        case DTVideoResolution480x480:
            size = CGSizeMake(480, 480);
            break;
        case DTVideoResolution640x360:
            size = CGSizeMake(640, 360);
            break;
        case DTVideoResolution640x480:
            size = CGSizeMake(640, 480);
            break;
        case DTVideoResolution720x720:
            size = CGSizeMake(720, 720);
            break;
        case DTVideoResolution960x540:
            size = CGSizeMake(960, 540);
            break;
        case DTVideoResolution960x720:
            size = CGSizeMake(960, 720);
            break;
        case DTVideoResolution1280x720:
            size = CGSizeMake(1280, 720);
            break;
        default:
            break;
    }
    return size;
}
@end
