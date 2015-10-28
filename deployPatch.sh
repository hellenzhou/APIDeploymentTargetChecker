#!/bin/bash

set -x

XCODE_PATH=$(xcode-select -print-path)
PLATFORMS="iPhoneOS iPhoneSimulator"
HEADER_TO_REPLACE="/System/Library/Frameworks/CoreFoundation.framework/Headers/CFAvailability.h"

for PLATFORM in $PLATFORMS ; do
    
    SDK=$PLATFORM
    AVAIL_FILE="${XCODE_PATH}/Platforms/${PLATFORM}.platform/Developer/SDKs/${SDK}.sdk${HEADER_TO_REPLACE}"
    if [ ! -f "${AVAIL_FILE}.orig" ];
    then
        mv ${AVAIL_FILE} ${AVAIL_FILE}.orig
    fi

    cp CFAvailability-hacked.h ${AVAIL_FILE}

done
