//
//  DTMettingError.m
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/2.
//

#import "DTMessageChannel.h"
#import <objc/message.h>


@implementation DTMessageChannel
+ (instancetype)messageChannelWithServiceType:(DTMeetingSDKServiceType)sdkServiceType with:(DTMessageChannelConfig *)config {
    DTMessageChannel *messageChannel = nil;
    
    if (sdkServiceType == DTMeetingSDKServiceTypeNone) {
        messageChannel = [[DTMessageChannel alloc] init];
    } else if (sdkServiceType == DTMeetingSDKServiceTypeDefault){
        Class classA = NSClassFromString(@"DTDefaultMessageChannel");
        SEL allocSelector = NSSelectorFromString(@"alloc");
        SEL initSelector = NSSelectorFromString(@"initWithConfig:");
        if (classA && allocSelector && initSelector) {
            id instanceA = ((id (*)(Class, SEL))objc_msgSend)(classA, allocSelector);
            messageChannel = ((id (*)(id, SEL, id))objc_msgSend)(instanceA, initSelector, config);
        } else {
            messageChannel = [[DTMessageChannel alloc] init];
        }
        
        
    }
   
    messageChannel.sdkServiceType = sdkServiceType;
    return messageChannel;
}

- (void)loginByToken:(NSString * _Nullable)token
                user:(NSString * _Nonnull)userId
          completion:(MeetingMessageChannelLoginBlock _Nullable)completionBlock {}

- (void)logoutWithCompletion:(MeetingMessageChannelLogoutBlock _Nullable )completionBlock {}

- (void)joinMessageChannel:(NSString *)channelId userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName {}

- (void)leaveMessageChannel {}

- (void)renewToken:(NSString * _Nonnull)token completion:(MeetingMessageChannelRenewTokenBlock _Nullable)completionBlock {}

- (void)sendChannelMessage:(DTMeetingChannelMessage * _Nonnull)message toPeer:(NSString * _Nonnull)peerId completion:(MeetingRtmSendChannelMessageBlock _Nullable)completionBlock {}

- (void)sendBroadcastMessage:(DTMeetingChannelMessage * _Nonnull)message completion:(MeetingRtCSendChannelMessageBlock _Nullable)completionBlock {}

- (void)sendLocalInvitation:(DTMeetingChanneLocalInvitation *)localInvitation completion:(MeetingMessageChannelLocalInvitationSendBlock)completion {}

- (void)cancelLocalInvitation:(DTMeetingChanneLocalInvitation * _Nonnull)localInvitation completion:(MeetingMessageChannelLocalInvitationCancelBlock _Nullable)completion {}

- (void)refuseRemoteInvitation:(DTMeetingChannelRemoteInvitation * _Nonnull)remoteInvitation completion:(MeetingMessageChannelRemoteInvitationRefuseBlock _Nullable)completion {}

- (void)acceptRemoteInvitation:(DTMeetingChannelRemoteInvitation * _Nonnull)remoteInvitation completion:(MeetingMessageChannelRemoteInvitationAcceptBlock _Nullable)completion {}

- (void)queryPeerOnline:(NSArray *)peers completion:(MeetingMessageChannelQueryPeersOnlineBlock _Nullable) completion {}

- (void)getMembersWithCompletion:(MeetingMessageChannelGetMembersBlock) completionBlock {}

- (void)destroyResource {}
@end
