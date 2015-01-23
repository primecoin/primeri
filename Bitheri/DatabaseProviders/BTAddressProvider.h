//
//  BTAddressProvider.h
//  bitheri
//
//  Copyright 2014 http://Bither.net
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
#import <Foundation/Foundation.h>
#import "BTHDMBid.h"
#import "BTHDMAddress.h"
#import "BTHDMKeychain.h"
#import "BTAddress.h"

@interface BTAddressProvider : NSObject

#pragma mark - hdm
- (NSArray *)getHDSeedIds;
- (NSString *)getEncryptSeed:(int)hdSeedId;
- (NSString *)getEncryptHDSeed:(int)hdSeedId;
- (void)updateHDSeedWithHDSeedId:(int)hdSeedId andEncryptHDSeed:(NSString *)encryptHDSeed;
- (void)updateHDSeedWithHDSeedId:(int)hdSeedId andEncryptSeed:(NSString *)encryptSeed andEncryptHDSeed:(NSString *)encryptHDSeed;
- (BOOL)isHDSeedFromXRandom:(int)hdSeedId;
- (NSString *)getHDFirstAddress:(int)hdSeedId;
- (int)addHDSeedWithEncryptSeed:(NSString *)encryptSeed andEncryptHDSeed:(NSString *)encryptHDSeed andFirstAddress:(NSString *)firstAddress andIsXRandom:(BOOL)isXRandom;

- (BTHDMBid *)getHDMBid;
- (void)addHDMBid:(BTHDMBid *)hdmBid;
- (void)changeHDMBIdPassword:(BTHDMBid *)hdmBid;

- (NSArray *)getHDMAddressInUse:(BTHDMKeychain *)keychain;
- (void)prepareHDMAddressesWithHDSeedId:(int)hdSeedId andPubs:(NSArray *)pubs;
- (NSArray *)getUncompletedHDMAddressPubs:(int) hdSeedId andCount:(int)count;
- (int)maxHDMAddressPubIndex:(int)hdSeedId;//including completed and uncompleted
- (void)recoverHDMAddressesWithHDSeedId:(int)hdSeedId andHDMAddresses:(NSArray *)addresses;
- (void)completeHDMAddressesWithHDSeedId:(int)hdSeedId andHDMAddresses:(NSArray *)addresses;
- (int)uncompletedHDMAddressCount:(int)hdSeedId;
- (void)syncCompleteHDSeedId:(int)hdSeedId hdSeedIndex:(int)hdSeedIndex;

#pragma mark - normal
- (NSArray *)getAddresses;
- (void)addAddress:(BTAddress *)address;
- (void)updatePrivateKey:(BTAddress *)address;
- (void)removeWatchOnlyAddress:(BTAddress *)address;
- (void)trashPrivKeyAddress:(BTAddress *)address;
- (void)restorePrivKeyAddress:(BTAddress *)address;
- (void)updateSyncComplete:(BTAddress *)address;
@end