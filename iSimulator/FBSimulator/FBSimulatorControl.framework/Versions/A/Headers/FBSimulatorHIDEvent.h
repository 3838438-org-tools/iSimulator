/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBControlCore.h>

#import <FBSimulatorControl/FBSimulatorHID.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The Action Type for the HID.
 */
extern FBiOSTargetFutureType const FBiOSTargetFutureTypeHID;

/**
 A Value representing a call to the HID System.
 */
@interface FBSimulatorHIDEvent : NSObject <NSCopying, FBiOSTargetFuture>

#pragma mark Initializers

/**
 A HID Event that is a touch-down followed by an immediate touch-up.

 @param x the x-coordinate from the top left.
 @param y the y-coordinate from the top left.
 @return a new HID event.
 */
+ (instancetype)tapAtX:(double)x y:(double)y;

/**
 A HID Event that is a down followed by an immediate up.

 @param button the button to use.
 @return a new HID Event.
 */
+ (instancetype)shortButtonPress:(FBSimulatorHIDButton)button;

/**
 A HID Event for the keyboard is a down followed by an immediate up.

 @param keyCode the Key Code to send.
 @return a new HID Event.
 */
+ (instancetype)shortKeyPress:(unsigned int)keyCode;

#pragma mark Public Methods

/**
 Materializes the event, performing it on the hid object.

 @param hid the hid to perform on.
 @return A future that resolves when the event has been sent.
 */
- (FBFuture<NSNull *> *)performOnHID:(FBSimulatorHID *)hid;

@end

NS_ASSUME_NONNULL_END
