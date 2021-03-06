/* Profile.h created by helmut on Fri 25-Jun-1999 */

/* Copyright (C) 1998-2000  Helmut Maierhofer <helmut.maierhofer@chello.at>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

//#import <AppKit/AppKit.h>
#import "EventFilter.h"
#import "rfbproto.h"

// Dictionary Keys
extern NSString *kProfile_PixelFormat_Key;
extern NSString *kProfile_EnableCopyrect_Key;
extern NSString *kProfile_Encodings_Key;
extern NSString *kProfile_EncodingValue_Key;
extern NSString *kProfile_EncodingEnabled_Key;
extern NSString *kProfile_LocalAltModifier_Key;
extern NSString *kProfile_LocalCommandModifier_Key;
extern NSString *kProfile_LocalControlModifier_Key;
extern NSString *kProfile_LocalShiftModifier_Key;
extern NSString *kProfile_Button2EmulationScenario_Key;
extern NSString *kProfile_Button3EmulationScenario_Key;
extern NSString *kProfile_ClickWhileHoldingModifierForButton2_Key;
extern NSString *kProfile_ClickWhileHoldingModifierForButton3_Key;
extern NSString *kProfile_MultiTapModifierForButton2_Key;
extern NSString *kProfile_MultiTapModifierForButton3_Key;
extern NSString *kProfile_MultiTapDelayForButton2_Key;
extern NSString *kProfile_MultiTapDelayForButton3_Key;
extern NSString *kProfile_MultiTapCountForButton2_Key;
extern NSString *kProfile_MultiTapCountForButton3_Key;
extern NSString *kProfile_TapAndClickModifierForButton2_Key;
extern NSString *kProfile_TapAndClickModifierForButton3_Key;
extern NSString *kProfile_TapAndClickButtonSpeedForButton2_Key;
extern NSString *kProfile_TapAndClickButtonSpeedForButton3_Key;
extern NSString *kProfile_TapAndClickTimeoutForButton2_Key;
extern NSString *kProfile_TapAndClickTimeoutForButton3_Key;
extern NSString *kProfile_IsDefault_Key;

// Modifier Key Mapping
typedef enum {
	kRemoteAltModifier		= 0,
	kRemoteMetaModifier		= 1,
	kRemoteControlModifier	= 2,
	kRemoteShiftModifier	= 3,
	kRemoteWindowsModifier	= 4
} ModifierKeyIdentifier;

// Encodings
#define NUMENCODINGS					8
extern const unsigned int gEncodingValues[];

// Jason added the following constants that represent the different possible modifier key popup choices
typedef enum {
	kCommmandKeyPopupIndex	= 0,
	kOptionKeyPopupIndex	= 1,
	kControlKeyPopupIndex	= 2,
	kShiftKeyPopupIndex		= 3, 
	kWindowsKeyPopupIndex		= 4
} ModifierKeyIndex;

#define kMetaKeyCode 0xffe7
#define kControlKeyCode 0xffe3
#define kAltKeyCode 0xffe9
#define kShiftKeyCode 0xffe1
#define kWindowsKeyCode 0xffeb

// end of Jason's addition

@interface Profile : NSObject
{
    NSMutableDictionary* info;
//    CARD32 commandKeyCode, altKeyCode, shiftKeyCode, controlKeyCode;
    CARD16 numberOfEnabledEncodings;
    CARD32 enabledEncodings[20];
	EventFilterEmulationScenario _button2EmulationScenario;
	EventFilterEmulationScenario _button3EmulationScenario;
	unsigned int _clickWhileHoldingModifier[2];
	unsigned int _multiTapModifier[2];
	NSTimeInterval _multiTapDelay[2];
	unsigned int _multiTapCount[2];
	unsigned int _tapAndClickModifier[2];
	NSTimeInterval _tapAndClickButtonSpeed[2];
	NSTimeInterval _tapAndClickTimeout[2];
}

+ (NSString *)nameForEncodingType: (CARD32)type;
+ (CARD32)modifierCodeForPreference: (id)preference;

+ (Profile *)defaultProfile;

- (id)initWithDictionary:(NSDictionary*)d name: (NSString *)name;
- (NSString*)profileName;
- (CARD32)commandKeyCode;
- (CARD32)altKeyCode;
- (CARD32)shiftKeyCode;
- (CARD32)controlKeyCode;
- (CARD16)numberOfEnabledEncodings;
- (CARD32)encodingAtIndex:(unsigned)index;
- (BOOL)useServerNativeFormat;
- (void)getPixelFormat:(rfbPixelFormat*)format;
- (EventFilterEmulationScenario)button2EmulationScenario;
- (EventFilterEmulationScenario)button3EmulationScenario;
- (unsigned int)clickWhileHoldingModifierForButton: (unsigned int)button;
- (unsigned int)multiTapModifierForButton: (unsigned int)button;
- (NSTimeInterval)multiTapDelayForButton: (unsigned int)button;
- (unsigned int)multiTapCountForButton: (unsigned int)button;
- (unsigned int)tapAndClickModifierForButton: (unsigned int)button;
- (NSTimeInterval)tapAndClickButtonSpeedForButton: (unsigned int)button;
- (NSTimeInterval)tapAndClickTimeoutForButton: (unsigned int)button;

@end
