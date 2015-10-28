//
//  MJGAvailability start
//
//  Created by Matt Galloway on 18/01/2012.
//  Copyright 2012 Matt Galloway. All rights reserved.
//

#import <Availability.h>

#define API_AVAILABILITY_START_IGNORE_TOO_NEW _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") _Pragma("clang diagnostic ignored \"-Wdeprecated-implementations\"")
#define API_AVAILABILITY_END_IGNORE_TOO_NEW _Pragma("clang diagnostic pop")

//#define MJG_START_IGNORE_TOO_NEW _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored  \"-Wdeprecated-declarations\"") _Pragma("clang diagnostic ignored \"-Wdeprecated-implementations\"")
//#define MJG_END_IGNORE_TOO_NEW _Pragma("clang diagnostic pop")
