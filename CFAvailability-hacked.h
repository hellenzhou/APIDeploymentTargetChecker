/*	CFAvailability.h
	Copyright (c) 2013-2015, Apple Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFAVAILABILITY__)
#define __COREFOUNDATION_CFAVAILABILITY__ 1

#include <TargetConditionals.h>

#if (TARGET_OS_MAC || TARGET_OS_EMBEDDED || TARGET_OS_IPHONE || TARGET_OS_WIN32)
#include <Availability.h>

// Even if unused, these must remain here for compatibility, because projects rely on them being included.
#include <AvailabilityMacros.h>
#endif

#ifndef __has_feature
#define __has_feature(x) 0
#endif
#ifndef __has_attribute
#define __has_attribute(x) 0
#endif
#ifndef __has_extension
#define __has_extension(x) 0
#endif

// The arguments to these availability macros is a version number, e.g. 10_6, 3_0 or 'NA'
// To use a deprecation message with the macro, add a string as the last argument.
#if __has_feature(attribute_availability_with_version_underscores) || (__has_feature(attribute_availability_with_message) && __clang__ && __clang_major__ >= 7)
#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
// This section is for compilers targeting OS X which support attribute_availability_with_message

#define CF_AVAILABLE(_mac, _ios) __attribute__((availability(macosx,introduced=_mac)))
#define CF_AVAILABLE_MAC(_mac) __attribute__((availability(macosx,introduced=_mac)))
#define CF_AVAILABLE_IOS(_ios) __attribute__((availability(macosx,unavailable)))
#define CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) __attribute__((availability(macosx,introduced=_macIntro,deprecated=_macDep,message="" __VA_ARGS__)))
#define CF_DEPRECATED_MAC(_macIntro, _macDep, ...) __attribute__((availability(macosx,introduced=_macIntro,deprecated=_macDep,message="" __VA_ARGS__)))
#define CF_DEPRECATED_IOS(_iosIntro, _iosDep, ...) __attribute__((availability(macosx,unavailable)))

#elif (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)
// This section is for compilers targeting iOS which support attribute_availability_with_message

#define CF_AVAILABLE(_mac, _ios) __attribute__((availability(ios,introduced=_ios)))
#define CF_AVAILABLE_MAC(_mac) __attribute__((availability(ios,unavailable)))
#define CF_AVAILABLE_IOS(_ios) __attribute__((availability(ios,introduced=_ios)))
#define CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) __attribute__((availability(ios,introduced=_iosIntro,deprecated=_iosDep,message="" __VA_ARGS__)))
#define CF_DEPRECATED_MAC(_macIntro, _macDep, ...) __attribute__((availability(ios,unavailable)))
#define CF_DEPRECATED_IOS(_iosIntro, _iosDep, ...) __attribute__((availability(ios,introduced=_iosIntro,deprecated=_iosDep,message="" __VA_ARGS__)))

//
//  MJGAvailability start
//
//  Created by Matt Galloway on 18/01/2012.
//  Copyright 2012 Matt Galloway. All rights reserved.
//

/**
* Example usage:
*   If you want to see if you're using methods that are only defined in iOS 4.0 and lower
*   then you would use the following. Replace the __IPHONE_4_0 with whatever other macro
*   you require. See Availability.h for iOS versions these relate to.
*
* YourProjectPrefixHeader.pch:
*   #define __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED __IPHONE_4_0
*   #import "MJGAvailability.h"
*
*   // The rest of your prefix header as normal
*   #import <UIKit/UIKit.h>
*
* For OSX, you also get the warnings:
*
* YourOSXPrefixHeader.pch
*   #define __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED __MAC_10_7
*   #import "MJGAvailability.h"
*
* If you want to suppress a single warning (i.e. because you know that what you're doing is
* actually OK) then you can do something like this:
*
*   UINavigationBar *navBar = self.navigationController.navigationBar;
*   if ([navBar respondsToSelector:@selector(setBackgroundImage:forBarMetrics:)]) {
*   #pragma clang diagnostic push
*   #pragma clang diagnostic ignored "-Wdeprecated-declarations"
*       [navBar setBackgroundImage:[UIImage imageNamed:@"navbar_bg.png"] forBarMetrics:UIBarMetricsDefault];
*   #pragma clang diagnostic pop
*   }
*
* Or you can use the handy macros defined in this file also, like this:
*
*   UINavigationBar *navBar = self.navigationController.navigationBar;
*   if ([navBar respondsToSelector:@selector(setBackgroundImage:forBarMetrics:)]) {
*   API_AVAILABILITY_START_IGNORE_TOO_NEW
*       [navBar setBackgroundImage:[UIImage imageNamed:@"navbar_bg.png"] forBarMetrics:UIBarMetricsDefault];
*   MJG_END_IGNORE_TOO_NEW
*   }
*
*/

#import <Availability.h>

#define __AVAILABILITY_TOO_NEW(x) __attribute__((deprecated(x))) __attribute__((weak_import))

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#ifndef __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED
#define __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED __IPHONE_OS_VERSION_MIN_REQUIRED
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_OS_VERSION_MIN_REQUIRED
#error You cannot ask for a soft max version which is less than the deployment target
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_2_0
#undef __AVAILABILITY_INTERNAL__IPHONE_2_0
#define __AVAILABILITY_INTERNAL__IPHONE_2_0 __AVAILABILITY_TOO_NEW("API only available from iOS 2.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_2_1
#undef __AVAILABILITY_INTERNAL__IPHONE_2_1
#define __AVAILABILITY_INTERNAL__IPHONE_2_1 __AVAILABILITY_TOO_NEW("API only available from iOS 2.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_2_2
#undef __AVAILABILITY_INTERNAL__IPHONE_2_2
#define __AVAILABILITY_INTERNAL__IPHONE_2_2 __AVAILABILITY_TOO_NEW("API only available from iOS 2.2, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_3_0
#undef __AVAILABILITY_INTERNAL__IPHONE_3_0
#define __AVAILABILITY_INTERNAL__IPHONE_3_0 __AVAILABILITY_TOO_NEW("API only available from iOS 3.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_3_1
#undef __AVAILABILITY_INTERNAL__IPHONE_3_1
#define __AVAILABILITY_INTERNAL__IPHONE_3_1 __AVAILABILITY_TOO_NEW("API only available from iOS 3.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_3_2
#undef __AVAILABILITY_INTERNAL__IPHONE_3_2
#define __AVAILABILITY_INTERNAL__IPHONE_3_2 __AVAILABILITY_TOO_NEW("API only available from iOS 3.2, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_4_0
#undef __AVAILABILITY_INTERNAL__IPHONE_4_0
#define __AVAILABILITY_INTERNAL__IPHONE_4_0 __AVAILABILITY_TOO_NEW("API only available from iOS 4.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_4_1
#undef __AVAILABILITY_INTERNAL__IPHONE_4_1
#define __AVAILABILITY_INTERNAL__IPHONE_4_1 __AVAILABILITY_TOO_NEW("API only available from iOS 4.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_4_2
#undef __AVAILABILITY_INTERNAL__IPHONE_4_2
#define __AVAILABILITY_INTERNAL__IPHONE_4_2 __AVAILABILITY_TOO_NEW("API only available from iOS 4.2, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_4_3
#undef __AVAILABILITY_INTERNAL__IPHONE_4_3
#define __AVAILABILITY_INTERNAL__IPHONE_4_3 __AVAILABILITY_TOO_NEW("API only available from iOS 4.3, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_5_0
#undef __AVAILABILITY_INTERNAL__IPHONE_5_0
#define __AVAILABILITY_INTERNAL__IPHONE_5_0 __AVAILABILITY_TOO_NEW("API only available from iOS 5.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_5_1
#undef __AVAILABILITY_INTERNAL__IPHONE_5_1
#define __AVAILABILITY_INTERNAL__IPHONE_5_1 __AVAILABILITY_TOO_NEW("API only available from iOS 5.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_6_0
#undef __AVAILABILITY_INTERNAL__IPHONE_6_0
#define __AVAILABILITY_INTERNAL__IPHONE_6_0 __AVAILABILITY_TOO_NEW("API only available from iOS 6.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_6_1
#undef __AVAILABILITY_INTERNAL__IPHONE_6_1
#define __AVAILABILITY_INTERNAL__IPHONE_6_1 __AVAILABILITY_TOO_NEW("API only available from iOS 6.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_7_0
#undef __AVAILABILITY_INTERNAL__IPHONE_7_0
#define __AVAILABILITY_INTERNAL__IPHONE_7_0 __AVAILABILITY_TOO_NEW("API only available from iOS 7.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_7_1
#undef __AVAILABILITY_INTERNAL__IPHONE_7_1
#define __AVAILABILITY_INTERNAL__IPHONE_7_1 __AVAILABILITY_TOO_NEW("API only available from iOS 7.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_8_0
#undef __AVAILABILITY_INTERNAL__IPHONE_8_0
#define __AVAILABILITY_INTERNAL__IPHONE_8_0 __AVAILABILITY_TOO_NEW("API only available from iOS 8.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_8_1
#undef __AVAILABILITY_INTERNAL__IPHONE_8_1
#define __AVAILABILITY_INTERNAL__IPHONE_8_1 __AVAILABILITY_TOO_NEW("API only available from iOS 8.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_8_2
#undef __AVAILABILITY_INTERNAL__IPHONE_8_2
#define __AVAILABILITY_INTERNAL__IPHONE_8_2 __AVAILABILITY_TOO_NEW("API only available from iOS 8.2, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_8_3
#undef __AVAILABILITY_INTERNAL__IPHONE_8_3
#define __AVAILABILITY_INTERNAL__IPHONE_8_3 __AVAILABILITY_TOO_NEW("API only available from iOS 8.3, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_8_4
#undef __AVAILABILITY_INTERNAL__IPHONE_8_4
#define __AVAILABILITY_INTERNAL__IPHONE_8_4 __AVAILABILITY_TOO_NEW("API only available from iOS 8.4, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_9_0
#undef __AVAILABILITY_INTERNAL__IPHONE_9_0
#define __AVAILABILITY_INTERNAL__IPHONE_9_0 __AVAILABILITY_TOO_NEW("API only available from iOS 9.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __IPHONE_OS_VERSION_SOFT_MAX_REQUIRED < __IPHONE_9_1
#undef __AVAILABILITY_INTERNAL__IPHONE_9_1
#define __AVAILABILITY_INTERNAL__IPHONE_9_1 __AVAILABILITY_TOO_NEW("API only available from iOS 9.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#endif // end of #if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#if defined(__MAC_OS_X_VERSION_MIN_REQUIRED)

#ifndef __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED
#define __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED __MAC_OS_X_VERSION_MIN_REQUIRED
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_OS_X_VERSION_MIN_REQUIRED
#error You cannot ask for a soft max version which is less than the deployment target
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_0
#undef __AVAILABILITY_INTERNAL__MAC_10_0
#define __AVAILABILITY_INTERNAL__MAC_10_0 __AVAILABILITY_TOO_NEW("API only available from OS X 10.0, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_1
#undef __AVAILABILITY_INTERNAL__MAC_10_1
#define __AVAILABILITY_INTERNAL__MAC_10_1 __AVAILABILITY_TOO_NEW("API only available from OS X 10.1, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_2
#undef __AVAILABILITY_INTERNAL__MAC_10_2
#define __AVAILABILITY_INTERNAL__MAC_10_2 __AVAILABILITY_TOO_NEW("API only available from OS X 10.2, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_3
#undef __AVAILABILITY_INTERNAL__MAC_10_3
#define __AVAILABILITY_INTERNAL__MAC_10_3 __AVAILABILITY_TOO_NEW("API only available from OS X 10.3, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_4
#undef __AVAILABILITY_INTERNAL__MAC_10_4
#define __AVAILABILITY_INTERNAL__MAC_10_4 __AVAILABILITY_TOO_NEW("API only available from OS X 10.4, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_5
#undef __AVAILABILITY_INTERNAL__MAC_10_5
#define __AVAILABILITY_INTERNAL__MAC_10_5 __AVAILABILITY_TOO_NEW("API only available from OS X 10.5, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_6
#undef __AVAILABILITY_INTERNAL__MAC_10_6
#define __AVAILABILITY_INTERNAL__MAC_10_6 __AVAILABILITY_TOO_NEW("API only available from OS X 10.6, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_7
#undef __AVAILABILITY_INTERNAL__MAC_10_7
#define __AVAILABILITY_INTERNAL__MAC_10_7 __AVAILABILITY_TOO_NEW("API only available from OS X 10.7, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_8
#undef __AVAILABILITY_INTERNAL__MAC_10_8
#define __AVAILABILITY_INTERNAL__MAC_10_8 __AVAILABILITY_TOO_NEW("API only available from OS X 10.8, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_9
#undef __AVAILABILITY_INTERNAL__MAC_10_9
#define __AVAILABILITY_INTERNAL__MAC_10_9 __AVAILABILITY_TOO_NEW("API only available from OS X 10.9, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_10
#undef __AVAILABILITY_INTERNAL__MAC_10_10
#define __AVAILABILITY_INTERNAL__MAC_10_10 __AVAILABILITY_TOO_NEW("API only available from OS X 10.10, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#if __MAC_OS_X_VERSION_SOFT_MAX_REQUIRED < __MAC_10_11
#undef __AVAILABILITY_INTERNAL__MAC_10_11
#define __AVAILABILITY_INTERNAL__MAC_10_11 __AVAILABILITY_TOO_NEW("API only available from OS X 10.11, use API_AVAILABILITY_START_IGNORE_TOO_NEW macro to validate this API usage")
#endif

#endif // end of #if defined(__MAC_OS_X_VERSION_MIN_REQUIRED)

// next redefinitions required since SDK 7
#include <CoreFoundation/CFAvailability.h>
#undef CF_AVAILABLE
#define CF_AVAILABLE(_mac, _ios) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_##_ios)
#undef CF_AVAILABLE_MAC
#define CF_AVAILABLE_MAC(_mac) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_NA)
#undef CF_AVAILABLE_IOS
#define CF_AVAILABLE_IOS(_ios) __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_##_ios)

//
//  MJGAvailability end
//

#endif

#elif (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)
// This section is for OS X or iOS, and compilers without support for attribute_availability_with_message. We fall back to Availability.h.

#ifndef __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0 __AVAILABILITY_INTERNAL_DEPRECATED
#endif

#define CF_AVAILABLE(_mac, _ios) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_##_ios)
#define CF_AVAILABLE_MAC(_mac) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_NA)
#define CF_AVAILABLE_IOS(_ios) __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_##_ios)
#define CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_##_macIntro, __MAC_##_macDep, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)
#define CF_DEPRECATED_MAC(_macIntro, _macDep, ...) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_##_macIntro, __MAC_##_macDep, __IPHONE_NA, __IPHONE_NA)
#define CF_DEPRECATED_IOS(_iosIntro, _iosDep, ...) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA, __MAC_NA, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)

#endif // __has_feature(attribute_availability_with_message)

#ifndef CF_AVAILABLE
// This section is for platforms which do not support availability
#define CF_AVAILABLE(_mac, _ios)
#define CF_AVAILABLE_MAC(_mac)
#define CF_AVAILABLE_IOS(_ios)
#define CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...)
#define CF_DEPRECATED_MAC(_macIntro, _macDep, ...)
#define CF_DEPRECATED_IOS(_iosIntro, _iosDep, ...)
#endif

// Older versions of these macros; use iOS versions instead
#define CF_AVAILABLE_IPHONE(_ios) CF_AVAILABLE_IOS(_ios)
#define CF_DEPRECATED_IPHONE(_iosIntro, _iosDep) CF_DEPRECATED_IOS(_iosIntro, _iosDep)

// Enum availability macros
#if __has_feature(enumerator_attributes) && __has_attribute(availability)
#define CF_ENUM_AVAILABLE(_mac, _ios) CF_AVAILABLE(_mac, _ios)
#define CF_ENUM_AVAILABLE_MAC(_mac) CF_AVAILABLE_MAC(_mac)
#define CF_ENUM_AVAILABLE_IOS(_ios) CF_AVAILABLE_IOS(_ios)
#define CF_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, __VA_ARGS__)
#define CF_ENUM_DEPRECATED_MAC(_macIntro, _macDep, ...) CF_DEPRECATED_MAC(_macIntro, _macDep, __VA_ARGS__)
#define CF_ENUM_DEPRECATED_IOS(_iosIntro, _iosDep, ...) CF_DEPRECATED_IOS(_iosIntro, _iosDep, __VA_ARGS__)
#else
#define CF_ENUM_AVAILABLE(_mac, _ios)
#define CF_ENUM_AVAILABLE_MAC(_mac)
#define CF_ENUM_AVAILABLE_IOS(_ios)
#define CF_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...)
#define CF_ENUM_DEPRECATED_MAC(_macIntro, _macDep, ...)
#define CF_ENUM_DEPRECATED_IOS(_iosIntro, _iosDep, ...)
#endif

// Enums and Options
#define __CF_ENUM_GET_MACRO(_1, _2, NAME, ...) NAME
#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || (!__cplusplus && __has_feature(objc_fixed_enum))
#define __CF_NAMED_ENUM(_type, _name)     enum _name : _type _name; enum _name : _type
#define __CF_ANON_ENUM(_type)             enum : _type
#if (__cplusplus)
#define CF_OPTIONS(_type, _name) _type _name; enum : _type
#else
#define CF_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#endif
#else
#define __CF_NAMED_ENUM(_type, _name) _type _name; enum
#define __CF_ANON_ENUM(_type) enum
#define CF_OPTIONS(_type, _name) _type _name; enum
#endif

/* CF_ENUM supports the use of one or two arguments. The first argument is always the integer type used for the values of the enum. The second argument is an optional type name for the macro. When specifying a type name, you must precede the macro with 'typedef' like so:

typedef CF_ENUM(CFIndex, CFComparisonResult) {
    ...
};

If you do not specify a type name, do not use 'typdef', like so:

CF_ENUM(CFIndex) {
    ...
};
*/
#define CF_ENUM(...) __CF_ENUM_GET_MACRO(__VA_ARGS__, __CF_NAMED_ENUM, __CF_ANON_ENUM)(__VA_ARGS__)

// Extension availability macros
#define CF_EXTENSION_UNAVAILABLE(_msg)      __OS_EXTENSION_UNAVAILABLE(_msg)
#define CF_EXTENSION_UNAVAILABLE_MAC(_msg)  __OSX_EXTENSION_UNAVAILABLE(_msg)
#define CF_EXTENSION_UNAVAILABLE_IOS(_msg)  __IOS_EXTENSION_UNAVAILABLE(_msg)

// Swift availability macro
#if __has_feature(attribute_availability_swift)
#define CF_SWIFT_UNAVAILABLE(_msg) __attribute__((availability(swift, unavailable, message=_msg)))
#else
#define CF_SWIFT_UNAVAILABLE(_msg)
#endif

#endif // __COREFOUNDATION_CFAVAILABILITY__
